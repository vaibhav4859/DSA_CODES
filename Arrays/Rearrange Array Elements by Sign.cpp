// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1;
        vector<int> ans(nums.size());
        for(auto it : nums){
            if(it > 0) ans[i] = it, i+= 2;
            else ans[j] = it, j += 2;
        }
        return ans;
    }
};
