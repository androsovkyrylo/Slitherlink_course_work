#include "puzzle.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <numeric>

Puzzle::Puzzle(int r, int c, const std::vector<std::string>& cell_values)
    : rows(r), cols(c), changed(false), change_count(0) {

    board_width  = 2 * (cols + 1) + 1;
    board_height = 2 * (rows + 1) + 1;
    dsu_key_mult = board_width;

    board.resize(board_width * board_height);
    board_colors.resize((rows + 2) * (cols + 2));

    std::string top_bottom_row = "#";
    for (int i = 0; i < cols + 1; i++) top_bottom_row += "x#";

    std::string dot_row = "x";
    for (int i = 0; i < cols; i++) dot_row += ". ";
    dot_row += ".x";

    int idx = 0;
    for (char ch : top_bottom_row) board[idx++] = ch;

    for (int row = 0; row < rows; row++) {
        for (char ch : dot_row)   board[idx++] = ch;

        std::string cell_row = "# ";
        for (int i = 0; i < cols; i++) {
            cell_row += cell_values[row][i];
            cell_row += " ";
        }
        cell_row += "#";
        for (char ch : cell_row) board[idx++] = ch;
    }

    for (char ch : dot_row)        board[idx++] = ch;
    for (char ch : top_bottom_row) board[idx++] = ch;

    for (int row = 1; row < rows + 2; row++)
        for (int col = 1; col < cols + 2; col++)
            set_board_color(row, col, 'i');

    for (int row = 0; row < rows + 2; row++) {
        set_board_color(row, 0, OUTSIDE_COLOR);
        set_board_color(row, cols + 1, OUTSIDE_COLOR);
    }
    for (int col = 0; col < cols + 2; col++) {
        set_board_color(0, col, OUTSIDE_COLOR);
        set_board_color(rows + 1, col, OUTSIDE_COLOR);
    }
}

int Puzzle::count_adjacent_links(int row, int col) const {
    int count = 0;
    char t  = get_board(row - 1, col);
    char b  = get_board(row + 1, col);
    char l  = get_board(row, col - 1);
    char rr = get_board(row, col + 1);
    if (t == '-' || t == '|') count++;
    if (b == '-' || b == '|') count++;
    if (l == '-' || l == '|') count++;
    if (rr == '-' || rr == '|') count++;
    return count;
}

int Puzzle::count_adjacent_xes(int row, int col) const {
    return (get_board(row - 1, col) == 'x') +
           (get_board(row + 1, col) == 'x') +
           (get_board(row, col - 1) == 'x') +
           (get_board(row, col + 1) == 'x');
}

void Puzzle::cond_set_x(int row, int col) {
    if (get_board(row, col) == ' ') {
        set_board(row, col, 'x');
        set_changed();
        change_count++;
    }
}

void Puzzle::cond_set_link(int row, int col, char value) {
    if (get_board(row, col) != ' ') return;

    set_board(row, col, value);
    set_changed();
    change_count++;

    int r1, c1, r2, c2;
    if (value == '-') {
        r1 = row; c1 = col - 1;
        r2 = row; c2 = col + 1;
    } else {
        r1 = row - 1; c1 = col;
        r2 = row + 1; c2 = col;
    }

    int k1 = dot_key(r1, c1);
    int k2 = dot_key(r2, c2);

    dsu.make(k1);
    dsu.make(k2);

    bool ok = dsu.unite(k1, k2);
    if (!ok) {
        if (dsu.component_count() > 1) {
            throw MoveError("Can't join dots");
        }
    }
}

void Puzzle::cellfunc_fill_in_xes(int row, int col) {
    char cellval = get_board(row, col);
    if (cellval < '0' || cellval > '3') return;
    int links_required = cellval - '0';
    int num_links = count_adjacent_links(row, col);
    int num_xes   = count_adjacent_xes(row, col);

    if (links_required == num_links && (num_links + num_xes) != 4) {
        cond_set_x(row - 1, col);
        cond_set_x(row + 1, col);
        cond_set_x(row, col - 1);
        cond_set_x(row, col + 1);
    }
}

void Puzzle::dotfunc_fill_in_xes_links(int row, int col) {
    int num_links = count_adjacent_links(row, col);
    int num_xes   = count_adjacent_xes(row, col);

    if (num_links == 2 && num_xes < 2) {
        cond_set_x(row - 1, col);
        cond_set_x(row + 1, col);
        cond_set_x(row, col - 1);
        cond_set_x(row, col + 1);
    } else if (num_xes == 2 && num_links == 1) {
        cond_set_link(row - 1, col, '|');
        cond_set_link(row + 1, col, '|');
        cond_set_link(row, col - 1, '-');
        cond_set_link(row, col + 1, '-');
    } else if (num_xes == 3) {
        cond_set_x(row - 1, col);
        cond_set_x(row + 1, col);
        cond_set_x(row, col - 1);
        cond_set_x(row, col + 1);
    }
}

void Puzzle::cellfunc_fill_in_links(int row, int col) {
    char cellval = get_board(row, col);
    if (cellval < '0' || cellval > '3') return;
    int links_required = cellval - '0';
    int num_links = count_adjacent_links(row, col);
    int num_xes   = count_adjacent_xes(row, col);

    if (num_links < links_required && (4 - num_xes) == links_required) {
        cond_set_link(row - 1, col, '-');
        cond_set_link(row + 1, col, '-');
        cond_set_link(row, col - 1, '|');
        cond_set_link(row, col + 1, '|');
    }
}

void Puzzle::cellfunc_handle_adjacent_threes(int row, int col) {
    if (get_board(row, col) != '3') return;

    int prev_row = row - 2;
    int next_row = row + 2;
    int next_col = col + 2;

    if (next_row < board_height && get_board(next_row, col) == '3') {
        cond_set_link(row - 1, col, '-');
        cond_set_link(row + 1, col, '-');
        cond_set_link(row + 3, col, '-');
        cond_set_x(row + 1, col - 2);
        cond_set_x(row + 1, col + 2);
    } else if (next_col < board_width && get_board(row, next_col) == '3') {
        cond_set_link(row, col - 1, '|');
        cond_set_link(row, col + 1, '|');
        cond_set_link(row, col + 3, '|');
        cond_set_x(row - 2, col + 1);
        cond_set_x(row + 2, col + 1);
    } else if (next_row < board_height && next_col < board_width &&
               get_board(next_row, next_col) == '3') {
        cond_set_link(row - 1, col, '-');
        cond_set_link(row, col - 1, '|');
        cond_set_link(row + 2, col + 3, '|');
        cond_set_link(row + 3, col + 2, '-');
    } else if (prev_row >= 0 && next_col < board_width &&
               get_board(prev_row, next_col) == '3') {
        cond_set_link(row + 1, col, '-');
        cond_set_link(row, col - 1, '|');
        cond_set_link(row - 2, col + 3, '|');
        cond_set_link(row - 3, col + 2, '-');
    }
}

void Puzzle::cellfunc_handle_diagonal_ones(int row, int col) {
    if (get_board(row, col) != '1') return;
    for (int dr : {-1, 1}) {
        for (int dc : {-1, 1}) {
            int next_row = row + 2 * dr;
            int next_col = col + 2 * dc;
            if (next_row < 0 || next_row >= board_height ||
                next_col < 0 || next_col >= board_width) continue;
            if (get_board(next_row, next_col) != '1') continue;
            if (get_board(row, col - dc) == 'x' && get_board(row - dr, col) == 'x') {
                cond_set_x(next_row, next_col + dc);
                cond_set_x(next_row + dr, next_col);
            } else if (get_board(row, col + dc) == 'x' && get_board(row + dr, col) == 'x') {
                cond_set_x(next_row, next_col - dc);
                cond_set_x(next_row - dr, next_col);
            }
        }
    }
}

void Puzzle::cellfunc_handle_closed_corners(int row, int col) {
    char cellval = get_board(row, col);
    if (cellval == ' ') return;
    for (int dr : {-1, 1}) {
        for (int dc : {-1, 1}) {
            bool corner = get_board(row + 2 * dr, col + dc) == 'x' &&
                          get_board(row + dr, col + 2 * dc) == 'x';
            if (corner) {
                if (cellval == '1') {
                    cond_set_x(row + dr, col);
                    cond_set_x(row, col + dc);
                } else if (cellval == '2' &&
                           get_board(row + 2 * dr, col - dc) == 'x' &&
                           get_board(row - dr, col + 2 * dc) == 'x') {
                    cond_set_link(row + dr, col - 2 * dc, '-');
                    cond_set_link(row - 2 * dr, col + dc, '|');
                } else if (cellval == '3') {
                    cond_set_link(row + dr, col, '-');
                    cond_set_link(row, col + dc, '|');
                }
            }
        }
    }
}

void Puzzle::apply_all_pattern_rules() {
    for (int r = 2; r < 2 * rows + 1; r += 2)
        for (int c = 2; c < 2 * cols + 1; c += 2)
            apply_pattern_rules(r, c);
}

void Puzzle::iter_cells(void (Puzzle::*func)(int, int)) {
    for (int r = 2; r < 2 * rows + 1; r += 2)
        for (int c = 2; c < 2 * cols + 1; c += 2)
            (this->*func)(r, c);
}

void Puzzle::iter_dots(void (Puzzle::*func)(int, int)) {
    for (int r = 1; r < 2 * rows + 2; r += 2)
        for (int c = 1; c < 2 * cols + 2; c += 2)
            (this->*func)(r, c);
}

void Puzzle::check_row_links() {
    for (int r = 2; r < 2 * rows + 1; r += 2) {
        int num_links = 0, num_unknowns = 0;
        int unknown_r = -1, unknown_c = -1;
        for (int c = 1; c < 2 * cols + 2; c += 2) {
            char val = get_board(r, c);
            if (val == '|')      num_links++;
            else if (val == ' ') { num_unknowns++; if (num_unknowns == 1) { unknown_r = r; unknown_c = c; } }
        }
        if (num_unknowns == 1) {
            if (num_links % 2 == 0) cond_set_x(unknown_r, unknown_c);
            else                    cond_set_link(unknown_r, unknown_c, '|');
        }
    }
}

void Puzzle::check_col_links() {
    for (int c = 2; c < 2 * cols + 1; c += 2) {
        int num_links = 0, num_unknowns = 0;
        int unknown_r = -1, unknown_c = -1;
        for (int r = 1; r < 2 * rows + 2; r += 2) {
            char val = get_board(r, c);
            if (val == '-')      num_links++;
            else if (val == ' ') { num_unknowns++; if (num_unknowns == 1) { unknown_r = r; unknown_c = c; } }
        }
        if (num_unknowns == 1) {
            if (num_links % 2 == 0) cond_set_x(unknown_r, unknown_c);
            else                    cond_set_link(unknown_r, unknown_c, '-');
        }
    }
}

void Puzzle::fill_in_xes()         { iter_cells(&Puzzle::cellfunc_fill_in_xes); }
void Puzzle::fill_in_links()       { iter_cells(&Puzzle::cellfunc_fill_in_links); }
void Puzzle::update_dot_state()    { iter_dots(&Puzzle::dotfunc_fill_in_xes_links); }
void Puzzle::handle_threes()       { iter_cells(&Puzzle::cellfunc_handle_adjacent_threes); }
void Puzzle::handle_ones()         { iter_cells(&Puzzle::cellfunc_handle_diagonal_ones); }
void Puzzle::handle_closed_corners() { iter_cells(&Puzzle::cellfunc_handle_closed_corners); }

bool Puzzle::can_solve(bool verbose) const {
    for (int r = 2; r < 2 * rows + 1; r += 2) {
        for (int c = 2; c < 2 * cols + 1; c += 2) {
            char val = get_board(r, c);
            if (val < '0' || val > '3') continue;
            int required = val - '0';
            int actual   = count_adjacent_links(r, c);
            int xes      = count_adjacent_xes(r, c);
            if (4 - xes < required) {
                if (verbose) std::cout << "ERROR at cell (" << r/2 << "," << c/2 << ")\n";
                return false;
            }
            if (actual + xes == 4 && required != actual) {
                if (verbose) std::cout << "ERROR at cell (" << r/2 << "," << c/2 << ")\n";
                return false;
            }
        }
    }
    return true;
}

bool Puzzle::is_solved() const {
    if (dsu.component_count() > 1) return false;

    for (int r = 2; r < 2 * rows + 1; r += 2) {
        for (int c = 2; c < 2 * cols + 1; c += 2) {
            char val = get_board(r, c);
            if (val < '0' || val > '3') continue;
            if ((val - '0') != count_adjacent_links(r, c)) return false;
        }
    }

    if (dsu.empty()) return false;

    for (int r = 1; r < 2 * rows + 2; r += 2) {
        for (int c = 1; c < 2 * cols + 2; c += 2) {
            int lk = count_adjacent_links(r, c);
            if (lk != 0 && lk != 2) return false;
        }
    }
    return true;
}

void Puzzle::iter_solve() {
    int iter = 0;
    const int max_iterations = 1000;

    while (iter < max_iterations) {
        iter++;
        bool made_change = false;

        for (int pass = 0; pass < 3; pass++) {
            auto run = [&](auto fn) {
                set_changed(false);
                (this->*fn)();
                if (is_changed()) made_change = true;
            };
            run(&Puzzle::handle_closed_corners);
            run(&Puzzle::fill_in_xes);
            run(&Puzzle::fill_in_links);
            run(&Puzzle::handle_threes);
            run(&Puzzle::handle_ones);
            run(&Puzzle::update_dot_state);
            run(&Puzzle::apply_all_pattern_rules);
        }

        set_changed(false);
        check_row_links();
        check_col_links();
        if (is_changed()) made_change = true;

        if (!can_solve()) throw MoveError("Invalid configuration");
        if (!made_change) break;
    }
}

void Puzzle::pretty_print() const {
    std::cout << "Puzzle size: " << rows << " * " << cols << "\n";
    for (int r = 1; r < 2 * rows + 2; r++) {
        for (int c = 1; c < 2 * cols + 2; c++) {
            std::cout << get_board(r, c);
            if (c < 2 * cols + 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}

std::string Puzzle::get_board_as_string() const {
    return std::string(board.begin(), board.end());
}

size_t Puzzle::get_board_hash() const {
    size_t h = 14695981039346656037ULL;
    for (char ch : board) {
        h ^= static_cast<unsigned char>(ch);
        h *= 1099511628211ULL;
    }
    return h;
}

bool Puzzle::dots_are_connected(int r1, int c1, int r2, int c2) const {
    return dsu.connected(dot_key(r1, c1), dot_key(r2, c2));
}

int Puzzle::score_move(int cell_r, int cell_c) const {
    char cellval = get_board(cell_r, cell_c);
    if (cellval >= '0' && cellval <= '3') {
        int val       = cellval - '0';
        int links     = count_adjacent_links(cell_r, cell_c);
        int xes       = count_adjacent_xes(cell_r, cell_c);
        int remaining = val - links;
        int available = 4 - links - xes;
        if (remaining == available && remaining > 0) return 1000 + val * 10;
        return 100 - remaining * 10 + links * 5;
    }
    return 0;
}

std::vector<Puzzle::Move> Puzzle::enumerate_moves() const {
    std::vector<Move> moves;
    moves.reserve(64);

    bool has_paths = !dsu.empty();

    for (int r = 1; r < 2 * rows + 2; r += 2) {
        for (int c = 1; c < 2 * cols + 2; c += 2) {
            int num_links = count_adjacent_links(r, c);

            if ((has_paths && num_links == 1) || (!has_paths && num_links == 0)) {
                int constraint_bonus = 0;
                if (!has_paths) {
                    for (int dr : {-1, 1}) {
                        for (int dc : {-1, 1}) {
                            int cell_r = r + dr, cell_c = c + dc;
                            if (cell_r >= 2 && cell_r < 2*rows+1 &&
                                cell_c >= 2 && cell_c < 2*cols+1) {
                                char val = get_board(cell_r, cell_c);
                                if (val == '3') constraint_bonus += 100;
                                if (val == '0') constraint_bonus += 50;
                            }
                        }
                    }
                }

                auto try_add = [&](int mr, int mc, char mtype) {
                    if (get_board(mr, mc) != ' ') return;
                    int neighbor_r = (mtype == '-') ? r  : (mr == r-1 ? r-2 : r+2);
                    int neighbor_c = (mtype == '|') ? c  : (mc == c-1 ? c-2 : c+2);
                    if (dots_are_connected(r, c, neighbor_r, neighbor_c)) return;
                    int s;
                    if (mtype == '-') {
                        s = score_move(mr - 1, mc) + score_move(mr + 1, mc) + constraint_bonus;
                    } else {
                        s = score_move(mr, mc - 1) + score_move(mr, mc + 1) + constraint_bonus;
                    }
                    moves.push_back({mr, mc, mtype, s});
                };

                try_add(r,   c-1, '-');
                try_add(r,   c+1, '-');
                try_add(r-1, c,   '|');
                try_add(r+1, c,   '|');
            }
        }
    }

    std::sort(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
        if (a.r != b.r) return a.r < b.r;
        if (a.c != b.c) return a.c < b.c;
        return a.type < b.type;
    });
    moves.erase(std::unique(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
        return a.r == b.r && a.c == b.c && a.type == b.type;
    }), moves.end());

    std::sort(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
        return a.score > b.score;
    });

    return moves;
}

void Puzzle::apply_move(const Move& move) {
    cond_set_link(move.r, move.c, move.type);
}
