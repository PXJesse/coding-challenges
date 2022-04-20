#include <iostream>
#include <vector>

#include "../util.h"

using namespace std;

vector<int> finalPrices(vector<int>& input);

int main() {
    vector<int> input = { 10, 1, 1, 6 };
    printVector(finalPrices(input));

    return 0;
}

/**
 * @brief Calculate and return the prices from an array of input prices
 * given a special discount.
 * 
 * The discount is calculated from the ith element onwards. The
 * discount is equivalent to the value of the first item after i
 * that is cheaper or of the same price.
 * 
 * @param input vector int array of prices
 * @returns vector int array of modified prices
 */
vector<int> finalPrices(vector<int>& input) {
    int len = input.size();

    // For each price, loop through the remainder of the array
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {

            // As soon as the price of a future index j <= the price of i, apply
            // the discount (subtract price of j) and move on to the next price
            if (input[j] <= input[i]) {
                input[i] -= input[j];
                break;
            }
        }
    }

    return input;
}