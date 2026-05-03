/*
    Problem: 3Sum Closest

    Given an integer array nums and an integer target,
    return the sum of three integers in nums such that
    the sum is closest to target.

    ----------------------------------------------------

    Approach (Two-Pointer + Sorting):

    1. Sort the array.
    2. Fix one element nums[i].
    3. Use two pointers:
        - st = i + 1 (left pointer)
        - end = last index (right pointer)
    4. Calculate current sum = nums[i] + nums[st] + nums[end].
    5. Compare with target:
        - If equal → return target immediately.
        - If smaller → move st forward.
        - If larger → move end backward.
    6. Track the closest sum using minimum difference.

    ----------------------------------------------------

    Time Complexity:
        Sorting: O(n log n)
        Two-pointer loop: O(n^2)
        Total: O(n^2)

    Space Complexity:
        O(1) (ignoring sorting space)

    ----------------------------------------------------

    Example:
        nums = [-1, 2, 1, -4], target = 1
        Output = 2  (closest sum)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int END = nums.size() - 1;
        int INF = 2 * (int)1e4;

        int min_diff = INF;
        int closest = INF;

        for(int i = 0; i < nums.size() - 2; i++) {
            int st = i + 1;
            int end = END;

            while(st < end) {
                int number = nums[st] + nums[end] + nums[i];

                if(number == target) return target;

                else if(number < target) {
                    int differ = target - number;
                    if(differ < min_diff) {
                        min_diff = differ;
                        closest = number;
                    }
                    st++;
                }
                else {
                    int differ = number - target;
                    if(differ < min_diff) {
                        min_diff = differ;
                        closest = number;
                    }
                    end--;
                }
            }
        }

        return closest;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << sol.threeSumClosest(nums, target) << endl;

    return 0;
}