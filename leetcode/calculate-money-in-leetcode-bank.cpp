#include <iostream>

using namespace std;

int totalMoney(int n);

int main() {
    int n = 20;
    cout << totalMoney(n);

    return 0;
}


/**
 * @brief Calculate the amount of money on the LeetCode bank after n days
 * 
 * Runtime: 0ms
 * Memory: 5.9mb
 * 
 * @param n  the day
 * @return int  the amount of money on the bank
 */
int totalMoney(int n) {
    int w = n / 7;
    int r = n % 7;
    int k = 28 * w + 7 * (w * (w - 1) / 2) + (r * (w + 1)) + (r * (r - 1) / 2);

    return k;
}