// millionaire.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Name: ZHANG Zhirui
//SID: 1155174021
//E-mail: 1155174021@link.cuhk.edu.hk

#include <iostream>
#include <random>

using namespace std;

int main() {
    int seed;
    cout << "Enter seed: ";
    cin >> seed;

    mt19937 gen(seed);  // seed the generator
    uniform_int_distribution<> distr1(1, 100);   // random int in [0, 9]
    uniform_int_distribution<> distr2(0, 3);  // random int in [1, 50]

    int award = 0;//总奖金
    int i;
    int v = 0;
    int opt = 0;
    for (i = 0; i < 15; i++) {

        int m;//一次的钱

        if (i == 0)
            m = 1000;
        if (i == 1)
            m = 2000;
        if (i == 2)
            m = 3000;
        if (i == 3)
            m = 4000;
        if (i == 4)
            m = 8000;
        if (i == 5)
            m = 10000;
        if (i == 6)
            m = 20000;
        if (i == 7)
            m = 30000;
        if (i == 8)
            m = 40000;
        if (i == 9)
            m = 60000;
        if (i == 10)
            m = 80000;
        if (i == 11)
            m = 150000;
        if (i == 12)
            m = 250000;
        if (i == 13)
            m = 500000;
        if (i == 14)
            m = 1000000;

        cout << "Question " << i + 1 << " ($" << m;
        if (i == 4 or i == 9) 
            cout << "#";
        cout << "):" << "\n";

        int x = distr1(gen); // 1st operand [1, 100]
        int y = distr1(gen); // 2nd operand [1, 100]
        int z = distr2(gen); // choice of operator (+, -, *, /)
        int c = distr2(gen); // position of correct answer (A, B, C, D)
        int soln = 0;
        char ans;

        if (z == 0) {
            soln = x + y;
        }
        if (z == 1) {
            soln = x - y;
        }
        if (z == 2) {
            soln = x * y;
        }
        if (z == 3) {
            soln = x / y;
        }
        if (z == 0) {
            cout << x << " + " << y << " = ?\n";
        }
        if (z == 1) {
            cout << x << " - " << y << " = ?\n";
        }
        if (z == 2) {
            cout << x << " * " << y << " = ?\n";
        }
        if (z == 3) {
            cout << x << " / " << y << " = ?\n";
        }
        int k;

        for (k = 0; k < 4; k++) {//显示ABCD
            char choice = 'A' + k;

            if (k == c) {
                cout << choice << ". " << soln << "  ";
            }
            else {
                int r;
                do {
                    r = distr1(gen);
                } while (r == soln);
                cout << choice << ". " << r << "  ";
            }
        }
        if (opt == 0 and i != 14) {//显示E
            cout << "E. Jump  ";
        }
        cout << "F. Withdraw\n";//显示withdraw
        cout << "Final answer: ";
        cin >> ans;

        if (ans >= 97 and ans <= 122)
            ans = ans - 32;

        if (ans == 'A' + c) {
            cout << "Right!\n";

            v = i + 1;

            if (i >= 4 and i < 9) {
                award = 8000;
            }
            if (i >= 9 and i < 14) {
                award = 60000;
            }
            if (i == 14) {
                award = 1000000;
            }
        }
        if (ans != 'A' + c and ans != 'F' and ans != 'E') {
            cout << "Wrong!\n";
            break;
        }
        if (ans == 'E' and opt == 0) {
            opt++;
            continue;
        }
        if (ans == 'F') {
            if (v == 0)
                award = 0;
            if (v == 1)
                award = 1000;
            if (v == 2)
                award = 2000;
            if (v == 3)
                award = 3000;
            if (v == 4)
                award = 4000;
            if (v == 5)
                award = 8000;
            if (v == 6)
                award = 10000;
            if (v == 7)
                award = 20000;
            if (v == 8)
                award = 30000;
            if (v == 9)
                award = 40000;
            if (v == 10)
                award = 60000;
            if (v == 11)
                award = 80000;
            if (v == 12)
                award = 150000;
            if (v == 13)
                award = 250000;
            if (v == 14)
                award = 500000;
            break;
        }
    }
    cout << "Game over!\n";
    cout << "You got $" << award << "!\n";
    if (award == 1000000)
        cout << "Congrats! You are a millionaire!";
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
