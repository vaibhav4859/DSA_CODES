// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Example 1:
// Input: nums = [3,0,1]
// Output: 2

//Approach - 1 : (SUM)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto it : nums) sum += it;
        return (n*(n+1))/2 - sum;
    }
};

//Approach - 2 : (XOR) **IMP
public int missingNumber(int[] nums) {
    int res = nums.length;
    for(int i=0; i<nums.length; i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}
