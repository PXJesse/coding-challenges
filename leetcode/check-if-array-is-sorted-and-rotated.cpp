#include <iostream>
#include <string>
#include <vector>

#include "../util.h"

using namespace std;

bool checkArray(vector<int> nums);

int main() {
    vector<int> nums = { 2, 1, 3, 4 };

    bool result = checkArray(nums);
    string res = result ? "true" : "false";
    cout << "Output: " << res;

    return 0;
}


/**
 * @brief Checks if the given array is sorted non-decreasingly and rotated
 *
 * It checks this by finding the amount of _pivots_ in the array. A pivot
 * is any number that's smaller than the minimum. This would indicate a new
 * "start" of the array, the rotation point. If there is more than one pivot,
 * the array was never sorted and rotated.
 *
 * The areas between the pivots must be sorted non-decreasingly as well. If
 * there are no pivots, the entire array must be sorted from start to end.
 *
 * @param nums  the given array
 * @return true  if the array was sorted non-decreasingly and rotated
 * @return false  if the array was not sorted non-decreasingly and rotated
 */
bool checkArray(vector<int> nums) {
    int pivots = 0;
    int min = 0;
    int prev = 0;

    for (int i = 0; i < nums.size(); i++) {
        int el = nums[i];
        bool isPivot = false;

        // Setup min el
        if (i == 0) {
            min = el;
        }

        // Force single pivot
        if (el < min) {
            isPivot = true;
            min = el;

            if (pivots < 1) {
                pivots++;
            } else {
                return false;
            }
        }

        // Strict ordering: Make sure that any element is larger than the
        // previous one (if it's not a pivot, aka smaller than the minimum)
        if (i != 0 && isPivot == false && el < prev) {
            return false;
        }

        prev = el;
    }

    // If there's one pivot, check that it connects across the end-to-beginning
    // boundary (no pivots between final and first item)
    if (pivots == 1) {
        if (nums[0] < nums[nums.size() - 1]) {
            return false;
        }
    }

    return true;
}