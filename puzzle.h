#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "dsu.h"

const char OUTSIDE_COLOR = 'o';

class MoveError : public std::runtime_error {
public:
    explicit MoveError(const std::string& msg) : std::runtime_error(msg) {}
};

class Puzzle {
private:
    int rows, cols;
    int board_width, board_height;
    std::vector<char> board;
    std::vector<char> board_colors;

    DSU dsu;
    int dsu_key_mult;

    bool changed;

    int dot_key(int r, int c) const { return r * dsu_key_mult + c; }

public:
    int change_count;

    struct Move {
        int r, c;
        char type;
        int score;
    };

    Puzzle(int r, int c, const std::vector<std::string>& cell_values);

    char get_board(int r, int c) const { return board[r * board_width + c]; }
    void set_board(int r, int c, char val) { board[r * board_width + c] = val; }
    void set_board_color(int r, int c, char val) { board_colors[r * (cols + 2) + c] = val; }
    char get_board_color(int r, int c) const { return board_colors[r * (cols + 2) + c]; }

    bool is_changed() const { return changed; }
    void set_changed(bool val = true) { changed = val; }
    void clear_changed_count() { changed = false; change_count = 0; }

    int  count_adjacent_links(int row, int col) const;
    int  count_adjacent_xes(int row, int col) const;
    void cond_set_x(int row, int col);
    void cond_set_link(int row, int col, char value);

    void cellfunc_fill_in_xes(int row, int col);
    void dotfunc_fill_in_xes_links(int row, int col);
    void cellfunc_fill_in_links(int row, int col);
    void cellfunc_handle_adjacent_threes(int row, int col);
    void cellfunc_handle_diagonal_ones(int row, int col);
    void cellfunc_handle_closed_corners(int row, int col);

    void apply_pattern_rules(int r, int c);
    void apply_all_pattern_rules();

    void iter_cells(void (Puzzle::*func)(int, int));
    void iter_dots(void (Puzzle::*func)(int, int));
    void check_row_links();
    void check_col_links();

    void fill_in_xes();
    void fill_in_links();
    void update_dot_state();
    void handle_threes();
    void handle_ones();
    void handle_closed_corners();

    bool can_solve(bool verbose = false) const;
    bool is_solved() const;
    void iter_solve();

    void pretty_print() const;
    std::string get_board_as_string() const;
    size_t get_board_hash() const;

    bool dots_are_connected(int r1, int c1, int r2, int c2) const;
    int  score_move(int cell_r, int cell_c) const;
    std::vector<Move> enumerate_moves() const;
    void apply_move(const Move& move);

    friend Puzzle load_puzzle(const std::string& filename);
};

Puzzle load_puzzle(const std::string& filename);
Puzzle load_hardcoded_puzzle_8x8();
Puzzle load_hardcoded_puzzle_7x7();
Puzzle load_hardcoded_puzzle_10x10();
