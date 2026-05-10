#include "puzzle.h"
#include <iostream>
#include <deque>
#include <unordered_set>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

bool solve_puzzle(Puzzle p, const std::string& label) {
    std::cout << "\n========================================\n";
    std::cout << "Solving: " << label << "\n";
    std::cout << "========================================\n";
    p.pretty_print();

    auto start_time = std::chrono::high_resolution_clock::now();

    struct Attempt { Puzzle puzzle; int depth; Puzzle::Move move; };
    std::deque<Attempt> attempts;

    std::unordered_set<size_t> board_set;

    std::mt19937 rng(std::time(nullptr));

    Puzzle::Move dummy_move = {0, 0, ' ', 0};
    attempts.push_back({p, 1, dummy_move});

    int iteration = 0, max_depth = 0;

    while (!attempts.empty()) {
        iteration++;

        if (iteration % 1000 == 0) {
            auto now = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();
            std::cout << iteration << " iterations, queue: " << attempts.size()
                      << ", depth: " << max_depth << ", time: " << elapsed << "s\n";
        }

        int idx = 0;
        if (attempts.size() > 5) {
            std::uniform_int_distribution<int> dist(0, std::min(4, (int)attempts.size() - 1));
            idx = dist(rng);
        }

        Attempt info = std::move(attempts[idx]);
        if (idx != 0) std::swap(attempts[0], attempts[idx]);
        attempts.pop_front();

        Puzzle current = std::move(info.puzzle);
        int depth = info.depth;
        if (depth > max_depth) max_depth = depth;

        try {
            current.iter_solve();
        } catch (const MoveError&) {
            continue;
        }

        if (current.is_solved()) {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            std::cout << "DEPTH " << depth << ": SOLVED after " << iteration
                      << " iterations in " << (ms / 1000.0) << " seconds\n";
            current.pretty_print();
            return true;
        }

        if (!current.can_solve()) continue;

        auto moves = current.enumerate_moves();
        if (moves.empty()) continue;

        std::vector<Attempt> move_infos;
        move_infos.reserve(moves.size());

        for (auto& mv : moves) {
            Puzzle p_copy = current;
            p_copy.clear_changed_count();
            p_copy.apply_move(mv);

            size_t h = p_copy.get_board_hash();
            if (!board_set.insert(h).second) continue;

            move_infos.push_back({std::move(p_copy), depth + 1, mv});
        }

        if (move_infos.size() > 10) {
            std::shuffle(move_infos.begin(), move_infos.end(), rng);
            move_infos.erase(move_infos.begin() + 10, move_infos.end());
        }

        for (auto& mi : move_infos)
            attempts.push_back(std::move(mi));

        if (attempts.size() > 10000) {
            std::shuffle(attempts.begin(), attempts.end(), rng);
            attempts.erase(attempts.begin() + 5000, attempts.end());
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Couldn't solve puzzle after " << iteration
              << " iterations in " << (ms / 1000.0) << " seconds.\n";
    return false;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        Puzzle p = load_puzzle(argv[1]);
        solve_puzzle(p, argv[1]);
    } else {
        solve_puzzle(load_hardcoded_puzzle_8x8(),   "8x8 puzzle");
        solve_puzzle(load_hardcoded_puzzle_7x7(),   "7x7 puzzle");
        solve_puzzle(load_hardcoded_puzzle_10x10(), "10x10 puzzle (hard)");
    }
    return 0;
}
