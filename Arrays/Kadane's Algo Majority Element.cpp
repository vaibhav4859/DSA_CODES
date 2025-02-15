// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, num = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) count = 1, num = nums[i];
            else if(nums[i] == num) count++;
            else count--;
        }

        return num;
    }
};
