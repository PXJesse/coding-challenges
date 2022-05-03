#include <iostream>

using namespace std;

int arrangeCoins(int n);

int main() {
    int n = 2147483647;
    int output = arrangeCoins(n);
    cout << output;

    return 0;
}


/**
 * @brief Calculate the amount complete coin rows in the staircase
 * 
 * Runtime: 18ms
 * Memory: 5.9mb
 * 
 * @param n  the amount of coins
 * @return int  the amount of complete coin stacks
 */
int arrangeCoins(int n) {
    int t = n;
    int c = 0;

    while (t > 0) {
        c++;
        t -= c;
    }

    return t == 0 ? c : c - 1;
}