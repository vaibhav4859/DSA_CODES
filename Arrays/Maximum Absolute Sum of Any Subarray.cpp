// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description
// So just run kadane twice, once calculating the max sum and once calculating the min sum.

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = INT_MIN, minsum = INT_MAX, sum = 0;
        for(auto it : nums) {
            sum += it;
            maxsum = max(maxsum, sum);
            if(sum < 0) sum = 0;
        }

        sum = 0;

        for(auto it : nums) {
            sum += it;
            minsum = min(minsum, sum);
            if(sum > 0) sum = 0;
        }

        return max(abs(maxsum), abs(minsum));
    }
};
