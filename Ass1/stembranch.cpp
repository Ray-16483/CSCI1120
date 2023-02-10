// Assignment_1.cpp
//
// Name: ZHANG Zhirui
// Student ID: 1155174021
// E-mail address: 1155174021@link.cuhk.edu.hk
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a date (D M Y): ";
    int D, M, Y;
    cin >> D >> M >> Y;
    int PY, QY;
    PY = (Y - 3) % 10;
    if (PY == 0)
        PY = 10;
    QY = (Y - 3) % 12;
    if (QY == 0)
        QY = 12;
    int t, r, C, a, g, i, z, PD, QD;
    if (M > 2)
        t = Y;
    else
        t = Y - 1;
    if (M > 2)
        r = M;
    else
        r = M + 12;
    C = t / 100;
    a = t % 100;
    g = 4 * C + C / 4 + 5 * a + a / 4 + (3 * (r + 1)) / 5 + D - 3;
    if (r % 2 == 1)
        i = 6;
    else
        i = 0;
    z = 8 * C + C / 4 + 5 * a + a / 4 + (3 * (r + 1)) / 5 + D + 1 + i;
    PD = g % 10;
    if (PD == 0)
        PD = 10;
    QD = z % 12;
    if (QD == 0)
        QD = 12;
    cout << "Year:  S" << PY << "-B" << QY << "\n";
    cout << "Month: " << M << "\n";
    cout << "Day:   S" << PD << "-B" << QD << "\n";
}

