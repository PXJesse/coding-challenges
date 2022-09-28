#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Utility: Print a given vector v
 *
 * @param v  vector
 * @returns  none
 */
void printVector(vector<int> v) {
    for (auto& i : v) {
        cout << i << " ";
    }
}

/**
 * @brief Utility: Print a given deque d
 *
 * @param d  deque
 * @returns  none
 */
void printDeque(deque<int> d) {
    for (auto& i : d) {
        cout << i << " ";
    }
}
