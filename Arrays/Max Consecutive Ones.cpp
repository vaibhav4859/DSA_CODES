// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, j = 0, ans = 0;
        while(j < nums.size()) {
            if(nums[j] == 1) count++;
            else {
                ans = max(ans, count);
                count = 0;
            }
            j++;
        }

        return max(ans, count);
    }
};

// https://leetcode.com/problems/max-consecutive-ones/
