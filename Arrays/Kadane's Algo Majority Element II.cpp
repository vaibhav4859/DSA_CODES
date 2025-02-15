// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto it : nums){
            if(num1 == it) count1++;
            else if(num2 == it) count2++;
            else if(count1 == 0) num1 = it, count1 = 1;
            else if(count2 == 0) num2 = it, count2 = 1;
            else count1--, count2--;
        }

        vector<int> ans;
        int temp = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto it : nums){
            if(num1 == it) count1++;
            if(num2 == it) count2++;
        }

        if(count1 > temp) ans.push_back(num1);
        if(count2 > temp) ans.push_back(num2);
        return ans;
    }
};
