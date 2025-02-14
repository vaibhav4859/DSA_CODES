// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, i = 0, ans = 0;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if(sum == k) ans = j+1; // subarray starting from 0 index
            if(!mp[sum]) mp[sum] = j; // // store index when this sum is first appeared because it will help to create longest subarray, occurunce of same sum afterwards won't help in creating longest subarray
            if(mp.find(sum - k) != mp.end()) ans = max(ans, j - mp[sum - k]); // if sum - k the required sum is present somwhere behind then consider this subarray length
        }

        return ans;
    }
};

