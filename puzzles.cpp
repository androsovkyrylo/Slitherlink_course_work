#include "puzzle.h"
#include <fstream>
#include <stdexcept>

Puzzle load_puzzle(const std::string& filename) {
    std::ifstream f(filename);
    if (!f) throw std::runtime_error("Cannot open file");
    int rows, cols;
    f >> rows >> cols;
    f.ignore();
    std::vector<std::string> cell_values;
    for (int i = 0; i < rows; i++) {
        std::string line;
        std::getline(f, line);
        cell_values.push_back(line);
    }
    return Puzzle(rows, cols, cell_values);
}

Puzzle load_hardcoded_puzzle_8x8() {
    int rows = 8, cols = 8;
    std::vector<std::string> cell_values = {
        " 2 32 3 ", " 11 3 2 ", "22 11   ", "321 2 1 ",
        " 2 3 222", "   23 23", " 3 2 13 ", " 2 11 2 ",
    };
    return Puzzle(rows, cols, cell_values);
}

Puzzle load_hardcoded_puzzle_7x7() {
    int rows = 7, cols = 7;
    std::vector<std::string> cell_values = {
        "  121 3",
        "  2  3 ",
        "    222",
        "  3 32 ",
        "2 3  1 ",
        "211    ",
        " 12    ",
    };
    return Puzzle(rows, cols, cell_values);
}

Puzzle load_hardcoded_puzzle_10x10() {
    int rows = 10, cols = 10;
    std::vector<std::string> cell_values = {
        " 2   3  3 ", "3 32   3  ", "31 12013 3", "  12   20 ",
        "221     2 ", "2  2   2  ", " 122322 22", "1 3  2    ",
        " 2  2   0 ", " 233 32  0",
    };
    return Puzzle(rows, cols, cell_values);
}
