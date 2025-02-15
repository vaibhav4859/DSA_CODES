// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// ** IMP

class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            ans = Math.max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
}


// print maximum sum subarray also
pair<int, vector<int>> maxSubarraySum(vector<int>& arr) {
    int maxSum = arr[0], currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    return {maxSum, subarray};
}
