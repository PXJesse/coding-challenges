#include <algorithm>
#include <iostream>
#include <vector>

#include "../util.h"

using namespace std;

int maxProductDifference(vector<int>& nums);
int maxProductDifferenceSort(vector<int>& nums);

int main() {
    vector<int> nums = { 4, 4, 2, 6, 8, 9, 8, 2 };

    int output = maxProductDifference(nums);
    cout << "Result: " << output << endl;

    return 0;
}

/**
 * @brief Calculate the maximum product difference between two pairs of
 * the input using sorting.
 *
 * Sort the array and combine the two max elements for first pair, two min
 * elements for second pair.
 *
 * Time complexity: O(n * log n)
 * Runtime: 68ms
 * Memory: 20.3mb
 *
 * @param nums
 * @return int
 */
int maxProductDifferenceSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int p1 = nums[0] * nums[1];
    int p2 = nums[n - 1] * nums[n - 2];

    return p2 - p1;
}

/**
 * @brief Calculate the maximum product difference between two pairs of
 * the input without sorting.
 *
 * For-loop over the array (once!) to achieve a linear complexity O(n).
 *
 * Time complexity: O(n)
 * Runtime: 54ms
 * Memory: 20.4mb
 *
 * @param nums
 * @return int
 */
int maxProductDifference(vector<int>& nums) {
    int min = INT_MAX;
    int mi1 = INT_MAX;
    int ma1 = INT_MIN;
    int max = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) {
            ma1 = max;
            max = nums[i];
        } else if (nums[i] <= max && nums[i] > ma1) {
            ma1 = nums[i];
        }

        if (nums[i] < min) {
            mi1 = min;
            min = nums[i];
        } else if (nums[i] >= min && nums[i] < mi1) {
            mi1 = nums[i];
        }
    }

    return max * ma1 - min * mi1;
}
