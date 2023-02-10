// Name:       ZHANG Zhirui
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

// stringcoin-game.cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "stringcoin.h"
#include <iostream>
using namespace std;

//bool stringState(long long network, int pos);
//void printNetwork(long long network);
//int playerScore(long long network, int p);
//void updateNetwork(long long& network, int pos, int p);

int main()

{
    long long network = 1111111111111111100;
    int p = 1;
    int pos;
    int time, num;
    int tp;
    long long var;
    for (num = 0; num < 18; num++) {
        printNetwork(network);
        if (num == 17)
            break;
        while (true) {

            cout << "Player " << p << "'s move (1-17): ";
            cin >> pos;

            var = network;
            for (time = 0; time < (19 - pos); time++)
                var = var / 10;
            var = var % 10;

            if ((pos < 1 or pos > 17) or (var == 0)) {
                cout << "Invalid. Try again!\n";
            }
            else
                break;
        }

        tp = playerScore(network, p);

        updateNetwork(network, pos, p);

        if (num < 16) {
            if (p == 1) {
                if (playerScore(network, p) != tp) {
                    cout << "Player 1 scores! Gets extra turn.\n";
                }
                else {
                    p = 2;
                }
            }
            else {
                if (playerScore(network, p) != tp) {
                    cout << "Player 2 scores! Gets extra turn.\n";
                }
                else {
                    p = 1;
                }
            }
        }
    }
    int p1, p2;
    p1 = playerScore(network, 1);
    p2 = playerScore(network, 2);
    if (p1 > p2)
        cout << "Player 1 wins!";
    if (p1 < p2)
        cout << "Player 2 wins!";
    if (p1 == p2)
        cout << "Draw game!";


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
