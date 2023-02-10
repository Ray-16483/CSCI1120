#ifndef TWINKNIGHTSTOUR_H
#define TWINKNIGHTSTOUR_H

#include <string>
using namespace std;

class TwinKnightsTour {
public:
    TwinKnightsTour(int r1, int c1, int r2, int c2);
    void print() const;
    bool isValid(char knight, int r, int c) const;
    bool hasMoreMoves() const;
    bool move(char knight, int r, int c);
    static const int N = 8;
private:
    string board[N][N];
    int posR1, posC1, posR2, posC2;
    int steps1, steps2;
    int consec1, consec2;
};

#endif    // TWINKNIGHTSTOUR_H
