// Name:       ZHANG Zhirui
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

#include "stringcoin.h"
#include <iostream>
#include <string>
using namespace std;

/* Returns true if position pos of the game network still has a string (not cut
   yet); returns false otherwise (that is, string was already cut). */
bool stringState(long long network, int pos) {
    // TO DO; add a return statement in order to compile
    long long c;
    int a, b;
    c = network;
    for (b = 0; b < (19 - pos); b++) {
        c = c / 10;
    }
    c = c % 10;
    if (c == 1)
        return true;
    else
        return false;

}

/* Prints the network to the screen. Do NOT modify! Do NOT use any arrays
   outside this function! */
void printNetwork(long long network) {
    int i;
    string s[18];    // Do NOT use any arrays outside this function!

    for (i = 1; i <= 17; i++)
        if (i <= 3 || i >= 15 || (i >= 8 && i <= 10))
            s[i] = stringState(network, i) ? "|" : " ";
        else
            s[i] = stringState(network, i) ? "--" : "  ";

    cout << "*************\n";
    for (i = 1; i <= 17; i += 7) {
        cout << "*  " << s[i] << "  " << s[i + 1] << "  " << s[i + 2]
             << "  *\n";
        if (i < 15)
            cout << "*" << s[i + 3] << "$" << s[i + 4] << "$" << s[i + 5]
                 << "$" << s[i + 6] << "*\n";
    }
    cout << "*************\n";
    cout << "Player 1 score: " << network / 10 % 10 << endl;
    cout << "Player 2 score: " << network % 10 << endl;
}

/* Returns the score of Player p in network. (Either the 18th or 19th digit in
   network.) */
int playerScore(long long network, int p) {
    // TO DO; add a return statement in order to compile
    int score;
    if (p == 1) 
        score = network / 10 % 10;
    else
        score = network % 10;
    return score;

}

/* Performs the task of Player p cutting a string in position pos of network.
   The reference parameter network should get updated, and if any coins are
   disconnected, the score of Player p shall be incremented, to reflect the new
   network configuration. */
//1. 更新network
//2. 更新score
void updateNetwork(long long &network, int pos, int p) {
    // TO DO
    long long c;
    long long a;
    int b, d, e, f, g, h, i;
    int Os = 0, Ns = 0;
    c = network;

    a = 1;
    for (b = 0; b < (19 - pos); b++)
        a = a * 10;
    network = network - a;

    for (b = 0; b < 3; b++) {
        if (stringState(c, 1 + b) == 0 && stringState(c, 4 + b) == 0 && stringState(c, 5 + b) == 0 && stringState(c, 8 + b) == 0) {
            Os++;
        }
        if (stringState(c, 8 + b) == 0 && stringState(c, 11 + b) == 0 && stringState(c, 12 + b) == 0 && stringState(c, 15 + b) == 0) {
            Os++;
        }
    }
    for (b = 0; b < 3; b++) {
        if (stringState(network, 1 + b) == 0 && stringState(network, 4 + b) == 0 && stringState(network, 5 + b) == 0 && stringState(network, 8 + b) == 0) {
            Ns++;
        }
        if (stringState(network, 8 + b) == 0 && stringState(network, 11 + b) == 0 && stringState(network, 12 + b) == 0 && stringState(network, 15 + b) == 0) {
            Ns++;
        }
    }
    if (Os != Ns) {
        if (p == 1) {
            network = network + 10 * long long (Ns - Os);
        }
        if (p == 2) {
            network = network + long long (Ns - Os);
        }
    }
}
