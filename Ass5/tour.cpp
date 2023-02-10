// tour.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// Name:       ZHANG ZHIRUI
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <string>
#include "TwinKnightsTour.h"
using namespace std;

int main()
{
    int r1, c1, r2, c2;//initialize the position of p1 and p2
    bool vpn = false;//not vaild input at the begining
    bool nvm = false;//not vaild move
    char knight;
    int r, c;//row and colum the player inputs after the game begin
    

    do {//check whether the input is vaild
        vpn = false;
        cout << "Knights' starting positions (row1 col1 row2 col2): ";
        cin >> r1 >> c1 >> r2 >> c2;
        if ((r1 < 0 || r1 >= TwinKnightsTour::N) || (c1 < 0 || c1 >= TwinKnightsTour::N) || (r2 < 0 || r2 >= TwinKnightsTour::N) || (c2 < 0 || c2 >= TwinKnightsTour::N) || (r1 == r2 && c1 == c2)) {
            cout << "Invalid position(s)!\n";
            vpn = true;
        }
    } while (vpn);

    TwinKnightsTour obj = TwinKnightsTour(r1, c1, r2, c2);
    obj.print();

    do {


        do {//check whether the move is vaild
            nvm = false;
            cout << "Move (knight row col): ";
            cin >> knight >> r >> c;
            if (obj.isValid(knight, r, c) == 0) {
                cout << "Invalid move!\n";
                nvm = true;
            }
        } while (nvm);

        obj.move(knight, r, c);

        obj.print();
    } while (obj.hasMoreMoves() == true);
    cout << "No more moves!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
