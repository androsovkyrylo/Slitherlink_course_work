#include "puzzle.h"

void Puzzle::apply_pattern_rules(int r, int c) {
        if (c-1>=0 &&
                get_board(r,c) == '0') {
            cond_set_x(r,c-1);
        }
        if (c+1<board_width &&
                get_board(r,c) == '0') {
            cond_set_x(r,c+1);
        }
        if (r+1<board_height &&
                get_board(r,c) == '0') {
            cond_set_x(r+1,c);
        }
        if (r-1>=0 &&
                get_board(r,c) == '0') {
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c+1) == '|') {
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c-1) == '|') {
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-1,c) == '-') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+1,c) == '-') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-1,c) == 'x' &&
                get_board(r,c-1) == 'x' &&
                get_board(r+1,c) == 'x') {
            cond_set_link(r,c+1,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+1,c) == 'x' &&
                get_board(r,c+1) == 'x' &&
                get_board(r-1,c) == 'x') {
            cond_set_link(r,c-1,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c-1) == 'x' &&
                get_board(r+1,c) == 'x' &&
                get_board(r,c+1) == 'x') {
            cond_set_link(r-1,c,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c+1) == 'x' &&
                get_board(r-1,c) == 'x' &&
                get_board(r,c-1) == 'x') {
            cond_set_link(r+1,c,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '2' &&
                get_board(r,c+1) == '|' &&
                get_board(r-1,c) == '-') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '2' &&
                get_board(r,c-1) == '|' &&
                get_board(r+1,c) == '-') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '2' &&
                get_board(r-1,c) == '-' &&
                get_board(r,c-1) == '|') {
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '2' &&
                get_board(r+1,c) == '-' &&
                get_board(r,c+1) == '|') {
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c-1) == 'x' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r,c-2) == '2') {
            cond_set_link(r+1,c-2,'-');
            cond_set_link(r,c-3,'|');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r,c+2) == '2') {
            cond_set_link(r-1,c+2,'-');
            cond_set_link(r,c+3,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+2,c) == '2') {
            cond_set_link(r+2,c+1,'|');
            cond_set_link(r+3,c,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-2,c) == '2') {
            cond_set_link(r-2,c-1,'|');
            cond_set_link(r-3,c,'-');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c-1) == 'x' &&
                get_board(r,c-2) == '2' &&
                get_board(r,c-3) == 'x') {
            cond_set_link(r-1,c-2,'-');
            cond_set_link(r+1,c-2,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r,c+2) == '2' &&
                get_board(r,c+3) == 'x') {
            cond_set_link(r+1,c+2,'-');
            cond_set_link(r-1,c+2,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+2,c) == '2' &&
                get_board(r+3,c) == 'x') {
            cond_set_link(r+2,c-1,'|');
            cond_set_link(r+2,c+1,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-2,c) == '2' &&
                get_board(r-3,c) == 'x') {
            cond_set_link(r-2,c+1,'|');
            cond_set_link(r-2,c-1,'|');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r,c-2) == '2' &&
                get_board(r,c-3) == '|') {
            cond_set_x(r-1,c-2);
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == '|' &&
                get_board(r,c+2) == '2' &&
                get_board(r,c+3) == '|') {
            cond_set_x(r+1,c+2);
            cond_set_x(r-1,c+2);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+2,c) == '2' &&
                get_board(r+3,c) == '-') {
            cond_set_x(r+2,c-1);
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-2,c) == '2' &&
                get_board(r-3,c) == '-') {
            cond_set_x(r-2,c+1);
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-1,c) == 'x') {
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_link(r,c-1,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+1,c) == 'x') {
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_link(r,c+1,'|');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-1) == 'x') {
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_link(r+1,c,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+1) == 'x') {
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_link(r-1,c,'-');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c-1) == '|' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r+1,c);
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c+1) == '|' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r-1,c);
            cond_set_x(r-1,c+2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r,c+1);
            cond_set_x(r+2,c+1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r,c-1);
            cond_set_x(r-2,c-1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r-1,c);
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c+1) == '|' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r+1,c);
            cond_set_x(r+2,c+1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c+2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c-1) == 'x' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+1,c-2) == '-') {
            cond_set_link(r+1,c,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-1,c+2) == '-') {
            cond_set_link(r-1,c,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r+2,c+1) == '|') {
            cond_set_link(r,c+1,'|');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r-2,c-1) == '|') {
            cond_set_link(r,c-1,'|');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c-1) == 'x' &&
                get_board(r+2,c-1) == '|' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_link(r+1,c,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r-2,c+1) == '|' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_link(r-1,c,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+1,c+2) == '-' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_link(r,c+1,'|');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-1,c-2) == '-' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_link(r,c-1,'|');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c-1) == 'x' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_x(r+1,c);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_x(r,c+1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_x(r,c-1);
        }
        if (c+2<board_width &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c) == '3') {
            cond_set_x(r+1,c+2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r+1,c,'-');
            cond_set_link(r+3,c,'-');
            cond_set_x(r+1,c-2);
        }
        if (c+2<board_width &&
                c-2>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c) == '3') {
            cond_set_x(r-1,c-2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r-1,c,'-');
            cond_set_link(r-3,c,'-');
            cond_set_x(r-1,c+2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                r+2<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+2) == '3') {
            cond_set_x(r-2,c+1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r,c+1,'|');
            cond_set_link(r,c+3,'|');
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+2<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-2) == '3') {
            cond_set_x(r+2,c-1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r,c-1,'|');
            cond_set_link(r,c-3,'|');
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r-1,c+2);
            cond_set_x(r-2,c+1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r+1,c-2);
            cond_set_x(r+2,c-1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_x(r-1,c+2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r-2,c-1);
            cond_set_x(r-1,c-2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r+2,c+1);
            cond_set_x(r+1,c+2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-2) == '3') {
            cond_set_x(r-1,c+2);
            cond_set_x(r-2,c+1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_link(r+3,c-2,'-');
            cond_set_link(r+2,c-3,'|');
            cond_set_x(r+4,c-3);
            cond_set_x(r+3,c-4);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+2) == '3') {
            cond_set_x(r+1,c-2);
            cond_set_x(r+2,c-1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_link(r-3,c+2,'-');
            cond_set_link(r-2,c+3,'|');
            cond_set_x(r-4,c+3);
            cond_set_x(r-3,c+4);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c+2) == '3') {
            cond_set_x(r-2,c-1);
            cond_set_x(r-1,c-2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_link(r+2,c+3,'|');
            cond_set_link(r+3,c+2,'-');
            cond_set_x(r+3,c+4);
            cond_set_x(r+4,c+3);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c-2) == '3') {
            cond_set_x(r+2,c+1);
            cond_set_x(r+1,c+2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_link(r-2,c-3,'|');
            cond_set_link(r-3,c-2,'-');
            cond_set_x(r-3,c-4);
            cond_set_x(r-4,c-3);
        }
        if (c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c) == '1' &&
                get_board(r+2,c) == '1' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_x(r+1,c);
        }
        if (c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-2,c) == '1' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+2<board_height &&
                get_board(r,c) == '1' &&
                get_board(r,c+2) == '1' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_x(r,c+1);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c-2) == '1' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_x(r,c-1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+2,c) == '3' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
            cond_set_link(r+2,c-1,'|');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-2,c) == '3' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
            cond_set_link(r-2,c+1,'|');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c+2) == '3' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
            cond_set_link(r+1,c+2,'-');
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c-2) == '3' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
            cond_set_link(r-1,c-2,'-');
        }
        if (c+1<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+2,c) == '3' &&
                get_board(r+2,c-2) == '1') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
            cond_set_x(r+3,c-2);
            cond_set_x(r+2,c-3);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-2,c) == '3' &&
                get_board(r-2,c+2) == '1') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
            cond_set_x(r-3,c+2);
            cond_set_x(r-2,c+3);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c+2) == '3' &&
                get_board(r+2,c+2) == '1') {
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
            cond_set_x(r+2,c+3);
            cond_set_x(r+3,c+2);
        }
        if (c+1<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '1' &&
                get_board(r,c-2) == '3' &&
                get_board(r-2,c-2) == '1') {
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
            cond_set_x(r-2,c-3);
            cond_set_x(r-3,c-2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c) == '1' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_x(r+1,c);
            cond_set_x(r,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_x(r-1,c);
            cond_set_x(r,c+1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c) == '1' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_x(r,c+1);
            cond_set_x(r+1,c);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_x(r,c-1);
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+1,c-2) == '-') {
            cond_set_x(r,c+1);
            cond_set_x(r-1,c);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-1,c+2) == '-') {
            cond_set_x(r,c-1);
            cond_set_x(r+1,c);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '1' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r+2,c+1) == '|') {
            cond_set_x(r-1,c);
            cond_set_x(r,c-1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '1' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r-2,c-1) == '|') {
            cond_set_x(r+1,c);
            cond_set_x(r,c+1);
        }
        if (c+2<board_width &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c) == '2' &&
                get_board(r+3,c) == 'x') {
            cond_set_x(r+1,c+2);
            cond_set_link(r-1,c,'-');
            cond_set_x(r+1,c-2);
        }
        if (c+2<board_width &&
                c-2>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c) == '2' &&
                get_board(r-3,c) == 'x') {
            cond_set_x(r-1,c-2);
            cond_set_link(r+1,c,'-');
            cond_set_x(r-1,c+2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                r+2<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+2) == '2' &&
                get_board(r,c+3) == 'x') {
            cond_set_x(r-2,c+1);
            cond_set_link(r,c-1,'|');
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+2<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-2) == '2' &&
                get_board(r,c-3) == 'x') {
            cond_set_x(r+2,c-1);
            cond_set_link(r,c+1,'|');
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+3,c) == '-' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-3,c) == '-' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r-2,c-1);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+3) == '|' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r-1,c+2);
        }
        if (c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-3) == '|' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c-2>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+3,c) == '-' &&
                get_board(r+2,c-2) == '3') {
            cond_set_x(r+2,c+1);
        }
        if (c+2<board_width &&
                c-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-3,c) == '-' &&
                get_board(r-2,c+2) == '3') {
            cond_set_x(r-2,c-1);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+3) == '|' &&
                get_board(r+2,c+2) == '3') {
            cond_set_x(r-1,c+2);
        }
        if (c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-3) == '|' &&
                get_board(r-2,c-2) == '3') {
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+2<board_height &&
                r+4<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+4,c) == '3' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-2>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-4,c) == '3' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r-2,c-1);
        }
        if (c+2<board_width &&
                c+4<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+4) == '3' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r-1,c+2);
        }
        if (c-2>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-4) == '3' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c-2>=0 &&
                r+2<board_height &&
                r+4<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+4,c) == '3' &&
                get_board(r+2,c-2) == '3') {
            cond_set_x(r+2,c+1);
        }
        if (c+2<board_width &&
                c-1>=0 &&
                r-2>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-4,c) == '3' &&
                get_board(r-2,c+2) == '3') {
            cond_set_x(r-2,c-1);
        }
        if (c+2<board_width &&
                c+4<board_width &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c+4) == '3' &&
                get_board(r+2,c+2) == '3') {
            cond_set_x(r-1,c+2);
        }
        if (c-2>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r,c-4) == '3' &&
                get_board(r-2,c-2) == '3') {
            cond_set_x(r+1,c-2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-1) == 'x' &&
                get_board(r+1,c-2) == 'x') {
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c-1,'|');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+1) == 'x' &&
                get_board(r-1,c+2) == 'x') {
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c+1,'|');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                get_board(r,c) == '3' &&
                get_board(r+1,c+2) == 'x' &&
                get_board(r+2,c+1) == 'x') {
            cond_set_link(r,c+1,'|');
            cond_set_link(r+1,c,'-');
        }
        if (c-1>=0 &&
                c-2>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-1,c-2) == 'x' &&
                get_board(r-2,c-1) == 'x') {
            cond_set_link(r,c-1,'|');
            cond_set_link(r-1,c,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-2) == '2' &&
                get_board(r+3,c-2) == 'x') {
            cond_set_x(r-1,c+2);
            cond_set_x(r-2,c+1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_link(r+2,c-3,'|');
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+2) == '2' &&
                get_board(r-3,c+2) == 'x') {
            cond_set_x(r+1,c-2);
            cond_set_x(r+2,c-1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_link(r-2,c+3,'|');
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c+2) == '2' &&
                get_board(r+2,c+3) == 'x') {
            cond_set_x(r-2,c-1);
            cond_set_x(r-1,c-2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_link(r+3,c+2,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c-2) == '2' &&
                get_board(r-2,c-3) == 'x') {
            cond_set_x(r+2,c+1);
            cond_set_x(r+1,c+2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_link(r-3,c-2,'-');
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-2) == '2' &&
                get_board(r+4,c-3) == '|') {
            cond_set_x(r-1,c+2);
            cond_set_x(r-2,c+1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_x(r+3,c-4);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+2) == '2' &&
                get_board(r-4,c+3) == '|') {
            cond_set_x(r+1,c-2);
            cond_set_x(r+2,c-1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_x(r-3,c+4);
        }
        if (c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c+2) == '2' &&
                get_board(r+3,c+4) == '-') {
            cond_set_x(r-2,c-1);
            cond_set_x(r-1,c-2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_x(r+4,c+3);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c-2) == '2' &&
                get_board(r-3,c-4) == '-') {
            cond_set_x(r+2,c+1);
            cond_set_x(r+1,c+2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_x(r-4,c-3);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-4>=0 &&
                c-5>=0 &&
                c-6>=0 &&
                r+2<board_height &&
                r+4<board_height &&
                r+5<board_height &&
                r+6<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c-2) == '2' &&
                get_board(r+4,c-4) == '3') {
            cond_set_x(r-1,c+2);
            cond_set_x(r-2,c+1);
            cond_set_link(r,c+1,'|');
            cond_set_link(r-1,c,'-');
            cond_set_link(r+5,c-4,'-');
            cond_set_link(r+4,c-5,'|');
            cond_set_x(r+6,c-5);
            cond_set_x(r+5,c-6);
        }
        if (c+2<board_width &&
                c+4<board_width &&
                c+5<board_width &&
                c+6<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-4>=0 &&
                r-5>=0 &&
                r-6>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c+2) == '2' &&
                get_board(r-4,c+4) == '3') {
            cond_set_x(r+1,c-2);
            cond_set_x(r+2,c-1);
            cond_set_link(r,c-1,'|');
            cond_set_link(r+1,c,'-');
            cond_set_link(r-5,c+4,'-');
            cond_set_link(r-4,c+5,'|');
            cond_set_x(r-6,c+5);
            cond_set_x(r-5,c+6);
        }
        if (c+2<board_width &&
                c+4<board_width &&
                c+5<board_width &&
                c+6<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+2<board_height &&
                r+4<board_height &&
                r+5<board_height &&
                r+6<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c) == '3' &&
                get_board(r+2,c+2) == '2' &&
                get_board(r+4,c+4) == '3') {
            cond_set_x(r-2,c-1);
            cond_set_x(r-1,c-2);
            cond_set_link(r-1,c,'-');
            cond_set_link(r,c-1,'|');
            cond_set_link(r+4,c+5,'|');
            cond_set_link(r+5,c+4,'-');
            cond_set_x(r+5,c+6);
            cond_set_x(r+6,c+5);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-2>=0 &&
                c-4>=0 &&
                c-5>=0 &&
                c-6>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r-2>=0 &&
                r-4>=0 &&
                r-5>=0 &&
                r-6>=0 &&
                get_board(r,c) == '3' &&
                get_board(r-2,c-2) == '2' &&
                get_board(r-4,c-4) == '3') {
            cond_set_x(r+2,c+1);
            cond_set_x(r+1,c+2);
            cond_set_link(r+1,c,'-');
            cond_set_link(r,c+1,'|');
            cond_set_link(r-4,c-5,'|');
            cond_set_link(r-5,c-4,'-');
            cond_set_x(r-5,c-6);
            cond_set_x(r-6,c-5);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+2,c) == '2' &&
                get_board(r+4,c-1) == '|') {
            cond_set_link(r+2,c+1,'|');
            cond_set_x(r+3,c-2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-2,c) == '2' &&
                get_board(r-4,c+1) == '|') {
            cond_set_link(r-2,c-1,'|');
            cond_set_x(r-3,c+2);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r,c+2) == '2' &&
                get_board(r+1,c+4) == '-') {
            cond_set_link(r-1,c+2,'-');
            cond_set_x(r+2,c+3);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c-1) == 'x' &&
                get_board(r,c-2) == '2' &&
                get_board(r-1,c-4) == '-') {
            cond_set_link(r+1,c-2,'-');
            cond_set_x(r-2,c-3);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r+1,c) == 'x' &&
                get_board(r+2,c) == '2' &&
                get_board(r+3,c-2) == '-') {
            cond_set_link(r+2,c+1,'|');
            cond_set_x(r+4,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r-1,c) == 'x' &&
                get_board(r-2,c) == '2' &&
                get_board(r-3,c+2) == '-') {
            cond_set_link(r-2,c-1,'|');
            cond_set_x(r-4,c+1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == 'x' &&
                get_board(r,c+2) == '2' &&
                get_board(r+2,c+3) == '|') {
            cond_set_link(r-1,c+2,'-');
            cond_set_x(r+1,c+4);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                r-2>=0 &&
                get_board(r,c-1) == 'x' &&
                get_board(r,c-2) == '2' &&
                get_board(r-2,c-3) == '|') {
            cond_set_link(r+1,c-2,'-');
            cond_set_x(r-1,c-4);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+3,c) == '-' &&
                get_board(r+2,c-1) == '|') {
            cond_set_x(r+2,c+1);
        }
        if (c+1<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-3,c) == '-' &&
                get_board(r-2,c+1) == '|') {
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == '|' &&
                get_board(r,c+3) == '|' &&
                get_board(r+1,c+2) == '-') {
            cond_set_x(r-1,c+2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-1>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r,c-3) == '|' &&
                get_board(r-1,c-2) == '-') {
            cond_set_x(r+1,c-2);
        }
        if (c+1<board_width &&
                c-2>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+3,c) == '-' &&
                get_board(r+2,c-2) == '3') {
            cond_set_x(r+2,c+1);
        }
        if (c+2<board_width &&
                c-1>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-3,c) == '-' &&
                get_board(r-2,c+2) == '3') {
            cond_set_x(r-2,c-1);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                r+2<board_height &&
                r-1>=0 &&
                get_board(r,c+1) == '|' &&
                get_board(r,c+3) == '|' &&
                get_board(r+2,c+2) == '3') {
            cond_set_x(r-1,c+2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                r+1<board_height &&
                r-2>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r,c-3) == '|' &&
                get_board(r-2,c-2) == '3') {
            cond_set_x(r+1,c-2);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+2,c-2) == '2' &&
                get_board(r+4,c-3) == '|') {
            cond_set_x(r,c-1);
            cond_set_x(r+3,c-4);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-2,c+2) == '2' &&
                get_board(r-4,c+3) == '|') {
            cond_set_x(r,c+1);
            cond_set_x(r-3,c+4);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r,c+1) == '|' &&
                get_board(r+2,c+2) == '2' &&
                get_board(r+3,c+4) == '-') {
            cond_set_x(r+1,c);
            cond_set_x(r+4,c+3);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r-2,c-2) == '2' &&
                get_board(r-3,c-4) == '-') {
            cond_set_x(r-1,c);
            cond_set_x(r-4,c-3);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r+1,c) == '-' &&
                get_board(r+2,c-2) == '2' &&
                get_board(r+3,c-4) == '-') {
            cond_set_x(r,c-1);
            cond_set_x(r+4,c-3);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r-1,c) == '-' &&
                get_board(r-2,c+2) == '2' &&
                get_board(r-3,c+4) == '-') {
            cond_set_x(r,c+1);
            cond_set_x(r-4,c+3);
        }
        if (c+1<board_width &&
                c+2<board_width &&
                c+3<board_width &&
                c+4<board_width &&
                r+1<board_height &&
                r+2<board_height &&
                r+3<board_height &&
                r+4<board_height &&
                get_board(r,c+1) == '|' &&
                get_board(r+2,c+2) == '2' &&
                get_board(r+4,c+3) == '|') {
            cond_set_x(r+1,c);
            cond_set_x(r+3,c+4);
        }
        if (c-1>=0 &&
                c-2>=0 &&
                c-3>=0 &&
                c-4>=0 &&
                r-1>=0 &&
                r-2>=0 &&
                r-3>=0 &&
                r-4>=0 &&
                get_board(r,c-1) == '|' &&
                get_board(r-2,c-2) == '2' &&
                get_board(r-4,c-3) == '|') {
            cond_set_x(r-1,c);
            cond_set_x(r-3,c-4);
        }
}