// Name:       ZHANG ZHIRUI
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <limits>
#include "reversi.h"

/* You may include more headers here if necessary. */

using namespace std;

// Return true if console input fails (e.g., the user enters alphabets while 
// an integer is expected.) or false otherwise
// This function bypasses any weird input by skipping to the next newline  
bool cin_failed() {
    bool failed = cin.fail();
    if (failed) {
        cin.clear();  // clear the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip to next newline
    }
    return failed;    
}

// Print the game board
void print_board(char board[][N]) {
    cout << "  ";
    for (int i = 0; i < N; i++)
        cout << setw(2) << char('A'+i);
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(2) << i + 1 << ' ';
        for (int j = 0; j < N; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}
//empty is 0 .
//block is 1 #
//black is 2 X
//white is 3 O
// 
//第一个数字是行，第二个数字是列
// 
// Return true if the move by player p at cell (y, x) is valid, or false otherwise 
// If flip is passed as true, the move is made on the board
bool valid_move(char board[][N], char p, int y, int x, bool flip) {//xy是从0开始记的
    // TODO:

    int i = 0, j = 0;//i是行，j是列

//新建array lp复制board的值用于test for all vaild pos

    int lp[N][N];
    bool et = 0;//existing of vaild pos
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            lp[i][j] = board[i][j];
        }
    }
    //检查是否有valid pos对于p2
    if (p == 'X') {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (lp[i][j] == '.') {
                    lp[i][j] = 'X';

                    //左上

                    if (lp[i - 1][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j - num] == 'O'; num++);
                        if (lp[i - num][j - num] == 'X' and (i - num >= 0 and i - num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中上

                    if (lp[i - 1][j] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j] == 'O'; num++);
                        if (lp[i - num][j] == 'X' and (i - num >= 0 and i - num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右上

                    if (lp[i - 1][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j + num] == 'O'; num++);
                        if (lp[i - num][j + num] == 'X' and (i - num >= 0 and i - num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左中

                    if (lp[i][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i][j - num] == 'O'; num++);
                        if (lp[i][j - num] == 'X' and (i >= 0 and i < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //右中

                    if (lp[i][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i][j + num] == 'O'; num++);
                        if (lp[i][j + num] == 'X' and (i >= 0 and i < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左下

                    if (lp[i + 1][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j - num] == 'O'; num++);
                        if (lp[i + num][j - num] == 'X' and (i + num >= 0 and i + num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中下

                    if (lp[i + 1][j] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j] == 'O'; num++);
                        if (lp[i + num][j] == 'X' and (i + num >= 0 and i + num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右下

                    if (lp[i + 1][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j + num] == 'O'; num++);
                        if (lp[i + num][j + num] == 'X' and (i + num >= 0 and i + num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }
                    lp[i][j] = board[i][j];
                }
                else
                    continue;
            }
        }
    }
    //检查是否有valid pos对于p3
    if (p == 'O') {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (lp[i][j] == '.') {
                    lp[i][j] = 'O';

                    //左上

                    if (lp[i - 1][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j - num] == 'X'; num++);
                        if (lp[i - num][j - num] == 'O' and (i - num >= 0 and i - num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中上

                    if (lp[i - 1][j] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j] == 'X'; num++);
                        if (lp[i - num][j] == 'O' and (i - num >= 0 and i - num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右上

                    if (lp[i - 1][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j + num] == 'X'; num++);
                        if (lp[i - num][j + num] == 'O' and (i - num >= 0 and i - num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左中

                    if (lp[i][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i][j - num] == 'X'; num++);
                        if (lp[i][j - num] == 'O' and (i >= 0 and i < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //右中

                    if (lp[i][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i][j + num] == 'X'; num++);
                        if (lp[i][j + num] == 'O' and (i >= 0 and i < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左下

                    if (lp[i + 1][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j - num] == 'X'; num++);
                        if (lp[i + num][j - num] == 'O' and (i + num >= 0 and i + num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中下

                    if (lp[i + 1][j] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j] == 'X'; num++);
                        if (lp[i + num][j] == 'O' and (i + num >= 0 and i + num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右下

                    if (lp[i + 1][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j + num] == 'X'; num++);
                        if (lp[i + num][j + num] == 'O' and (i + num >= 0 and i + num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }
                    lp[i][j] = board[i][j];
                }
                else
                    continue;
            }
        }
    }
    //检查player输入的pos是不是vaild的in advanced of 存在vaild pos
    if (et == 1) {

         bool vd = 0;//若player的input是vaild的，则vd=1，反之为0
        int lu = 0, mu = 0, ru = 0, lm = 0, rm = 0, ld = 0, md = 0, rd = 0;//哪个方向上改变了多少
        if (p == 'X') {
            lp[y][x] = 'X';

            //左上

            if (lp[y - 1][x - 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y - num][x - num] == 'O'; num++);
                if (lp[y - num][x - num] == 'X' and (y - num >= 0 and y - num < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    lu = num - 1;
                }
            }

            //中上

            if (lp[y - 1][x] == 'O') {
                int num = 1;
                for (num = 1; lp[y - num][x] == 'O'; num++);
                if (lp[y - num][x] == 'X' and (y - num >= 0 and y - num < N) and (x >= 0 and x < N)) {
                    vd = 1;
                    mu = num - 1;
                }
            }

            //右上

            if (lp[y - 1][x + 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y - num][x + num] == 'O'; num++);
                if (lp[y - num][x + num] == 'X' and (y - num >= 0 and y - num < N) and (x + num >= 0 and x + num < N)) {
                    vd = 1;
                    ru = num - 1;
                }
            }

            //左中

            if (lp[y][x - 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y][x - num] == 'O'; num++);
                if (lp[y][x - num] == 'X' and (y >= 0 and y < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    lm = num - 1;
                }
            }

            //右中

            if (lp[y][x + 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y][x + num] == 'O' and (y>=0 and y < N) and (x + num>=0 and x + num<N); num++);
                if (lp[y][x + num] == 'X' and (y >= 0 and y < N) and (x + num >= 0 and x + num < N)){
                    vd = 1;
                    rm = num - 1;
                }
            }

            //左下

            if (lp[y + 1][x - 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y + num][x - num] == 'O'; num++);
                if (lp[y + num][x - num] == 'X' and (y + num >= 0 and y + num < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    ld = num - 1;
                }
            }

            //中下

            if (lp[y + 1][x] == 'O') {
                int num = 1;
                for (num = 1; lp[y + num][x] == 'O'; num++);
                if (lp[y + num][x] == 'X' and (y + num >= 0 and y + num < N) and (x >= 0 and x < N)) {
                    vd = 1;
                    md = num - 1;
                }
            }

            //右下

            if (lp[y + 1][x + 1] == 'O') {
                int num = 1;
                for (num = 1; lp[y + num][x + num] == 'O'; num++);
                if (lp[y + num][x + num] == 'X' and (y + num >= 0 and y + num < N) and (x + num >= 0 and x + num < N)) {
                    vd = 1;
                    rd = num - 1;
                }
            }
            lp[y][x] = board[y][x];
        }
        
        if (p == 'O') {
            lp[y][x] = 'O';

            //左上

            if (lp[y - 1][x - 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y - num][x - num] == 'X'; num++);
                if (lp[y - num][x - num] == 'O' and (y - num >= 0 and y - num < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    lu = num - 1;
                }
            }

            //中上

            if (lp[y - 1][x] == 'X') {
                int num = 1;
                for (num = 1; lp[y - num][x] == 'X'; num++);
                if (lp[y - num][x] == 'O' and (y - num >= 0 and y - num < N) and (x >= 0 and x < N)) {
                    vd = 1;
                    mu = num - 1;
                }
            }

            //右上

            if (lp[y - 1][x + 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y - num][x + num] == 'X'; num++);
                if (lp[y - num][x + num] == 'O' and (y - num >= 0 and y - num < N) and (x + num >= 0 and x + num < N)) {
                    vd = 1;
                    ru = num - 1;
                }
            }

            //左中

            if (lp[y][x - 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y][x - num] == 'X'; num++);
                if (lp[y][x - num] == 'O' and (y >= 0 and y < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    lm = num - 1;
                }
            }

            //右中

            if (lp[y][x + 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y][x + num] == 'X'; num++);
                if (lp[y][x + num] == 'O' and (y >= 0 and y < N) and (x + num >= 0 and x + num < N)) {
                    vd = 1;
                    rm = num - 1;
                }
            }

            //左下

            if (lp[y + 1][x - 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y + num][x - num] == 'X'; num++);
                if (lp[y + num][x - num] == 'O' and (y + num >= 0 and y + num < N) and (x - num >= 0 and x - num < N)) {
                    vd = 1;
                    ld = num - 1;
                }
            }

            //中下

            if (lp[y + 1][x] == 'X') {
                int num = 1;
                for (num = 1; lp[y + num][x] == 'X'; num++);
                if (lp[y + num][x] == 'O' and (y + num >= 0 and y + num < N) and (x >= 0 and x < N)) {
                    vd = 1;
                    md = num - 1;
                }
            }

            //右下

            if (lp[y + 1][x + 1] == 'X') {
                int num = 1;
                for (num = 1; lp[y + num][x + num] == 'X'; num++);
                if (lp[y + num][x + num] == 'O' and (y + num >= 0 and y + num < N) and (x + num >= 0 and x + num < N)) {
                    vd = 1;
                    rd = num - 1;
                }
            }
            lp[y][x] = board[y][x];
        }


        if (board[y][x] != '.' or vd == 0) {
            return 0;
        }
        else {
            while (lu > 0) {
                if (p == 'X')
                    board[y - lu][x - lu] = 'X';
                if (p == 'O')
                    board[y - lu][x - lu] = 'O';
                lu--;
            }
            while (mu > 0) {
                if (p == 'X')
                    board[y - mu][x] = 'X';
                if (p == 'O')
                    board[y - mu][x] = 'O';
                mu--;
            }
            while (ru > 0) {
                if (p == 'X')
                    board[y - ru][x + ru] = 'X';
                if (p == 'O')
                    board[y - ru][x + ru] = 'O';
                ru--;
            }
            while (lm > 0) {
                if (p == 'X')
                    board[y][x - lm] = 'X';
                if (p == 'O')
                    board[y][x - lm] = 'O';
                lm--;
            }
            while (rm > 0) {
                if (p == 'X')
                    board[y][x + rm] = 'X';
                if (p == 'O')
                    board[y][x + rm] = 'O';
                rm--;
            }
            while (ld > 0) {
                if (p == 'X')
                    board[y + ld][x - ld] = 'X';
                if (p == 'O')
                    board[y + ld][x - ld] = 'O';
                ld--;
            }
            while (md > 0) {
                if (p == 'X')
                    board[y + md][x] = 'X';
                if (p == 'O')
                    board[y + md][x] = 'O';
                md--;
            }
            while (rd > 0) {
                if (p == 'X')
                    board[y + rd][x + rd] = 'X';
                if (p == 'O')
                    board[y + rd][x + rd] = 'O';
                rd--;
            }
            if (p == 'X')
                board[y][x] = 'X';
            if (p == 'O')
                board[y][x] = 'O';
            return 1;
        }
    }
    else
    return 0;
}

// Return true if player p still has valid move(s) on the board, or false otherwise
bool has_valid_moves(char board[][N], char p) {
    // TODO: 
    int lp[N][N];
    bool et = 0;//existing of vaild pos, if existing, et=1, else, et=0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            lp[i][j] = board[i][j];
        }
    }
    //检查是否有valid pos对于p2
    if (p == 'X') {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (lp[i][j] == '.') {
                    lp[i][j] = 'X';

                    //左上

                    if (lp[i - 1][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j - num] == 'O'; num++);
                        if (lp[i - num][j - num] == 'X' and (i - num >= 0 and i - num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中上

                    if (lp[i - 1][j] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j] == 'O'; num++);
                        if (lp[i - num][j] == 'X' and (i - num >= 0 and i - num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右上

                    if (lp[i - 1][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i - num][j + num] == 'O'; num++);
                        if (lp[i - num][j + num] == 'X' and (i - num >= 0 and i - num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左中

                    if (lp[i][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i][j - num] == 'O'; num++);
                        if (lp[i][j - num] == 'X' and (i >= 0 and i < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //右中

                    if (lp[i][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i][j + num] == 'O'; num++);
                        if (lp[i][j + num] == 'X' and (i >= 0 and i < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左下

                    if (lp[i + 1][j - 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j - num] == 'O'; num++);
                        if (lp[i + num][j - num] == 'X' and (i + num >= 0 and i + num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中下

                    if (lp[i + 1][j] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j] == 'O'; num++);
                        if (lp[i + num][j] == 'X' and (i + num >= 0 and i + num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右下

                    if (lp[i + 1][j + 1] == 'O') {
                        int num = 1;
                        for (num = 1; lp[i + num][j + num] == 'O'; num++);
                        if (lp[i + num][j + num] == 'X' and (i + num >= 0 and i + num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }
                    lp[i][j] = board[i][j];
                }
                else
                    continue;
            }
        }
    }
    //检查是否有valid pos对于p3
    if (p == 'O') {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (lp[i][j] == '.') {
                    lp[i][j] = 'O';

                    //左上

                    if (lp[i - 1][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j - num] == 'X'; num++);
                        if (lp[i - num][j - num] == 'O' and (i - num >= 0 and i - num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中上

                    if (lp[i - 1][j] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j] == 'X'; num++);
                        if (lp[i - num][j] == 'O' and (i - num >= 0 and i - num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右上

                    if (lp[i - 1][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i - num][j + num] == 'X'; num++);
                        if (lp[i - num][j + num] == 'O' and (i - num >= 0 and i - num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左中

                    if (lp[i][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i][j - num] == 'X'; num++);
                        if (lp[i][j - num] == 'O' and (i >= 0 and i < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //右中

                    if (lp[i][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i][j + num] == 'X'; num++);
                        if (lp[i][j + num] == 'O' and (i >= 0 and i < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }

                    //左下

                    if (lp[i + 1][j - 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j - num] == 'X'; num++);
                        if (lp[i + num][j - num] == 'O' and (i + num >= 0 and i + num < N) and (j - num >= 0 and j - num < N)) {
                            et = 1;
                        }
                    }

                    //中下

                    if (lp[i + 1][j] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j] == 'X'; num++);
                        if (lp[i + num][j] == 'O' and (i + num >= 0 and i + num < N) and (j >= 0 and j < N)) {
                            et = 1;
                        }
                    }

                    //右下

                    if (lp[i + 1][j + 1] == 'X') {
                        int num = 1;
                        for (num = 1; lp[i + num][j + num] == 'X'; num++);
                        if (lp[i + num][j + num] == 'O' and (i + num >= 0 and i + num < N) and (j + num >= 0 and j + num < N)) {
                            et = 1;
                        }
                    }
                    lp[i][j] = board[i][j];
                }
                else
                    continue;
            }
        }
    }
    if (et == 1)
        return 1;
    else
        return 0;
}

// Return true if the game board still has empty cell(s), or false otherwise
bool has_empty_cells(char board[][N]) {
    // TODO:
    bool ey = 0;//checking for if existing empty cells or not, if existing, ey=1, else, ey=0;
    int lp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            lp[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lp[i][j] == '.')
                ey = 1;
        }
    }
    if (ey == 1)
        return 1;
    else
        return 0;
}
