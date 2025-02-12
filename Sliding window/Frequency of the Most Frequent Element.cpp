class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long i = 0, j = 0, sum = 0, ans = 0;
        while(j < nums.size()) {
            sum += nums[j];
            while((j - i + 1) * nums[j] - sum > k) {
                sum -= nums[i];
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};

// As you can see, the number of operations required is simply the difference between target and the numbers we are incrementing. Let's say that the final frequency of target was 4. We would have a sum of 4 * target. The number of operations would be this sum minus the sum of the elements before we incremented them.
// https://assets.leetcode.com/static_assets/media/original_images/1838/5.png
// The size of the window is right - left + 1. That means we would have a final sum of (right - left + 1) * target. If we track the sum of our window in a variable curr, then we can calculate the required operations as (right - left + 1) * target - curr. If it requires more than k operations, we must shrink our window.



// Approach - 2 : 
// Notice that the only thing we care about is the length of the longest window. We don't need to know what the window itself is. As we slide the window over the array, let's say we find a valid window with a length of len. We no longer care about any windows with lengths less than len, because they could not possibly improve on our answer.
// The purpose of the while loop in the previous approach is to shrink the window until it is valid again. In this approach, we will not shrink the window - we will just try to grow it as large as we can.
// We will keep the same condition in the while loop that checks if the current window [left, right] is valid, but instead of using a while loop, we will just use an if statement. This means left never increases by more than 1 per iteration. Because right also increases by 1 per iteration, if we cannot find a valid window, we will simply be sliding a window with static size across the array.
// However, if we add an element nums[right] to the window and the window is valid, then the if statement will not trigger, and left will not be incremented. Thus, we will increase our window size by 1. In this scenario, it implies the current window [left, right] is the best window we have seen so far.
// As you can see, it is actually impossible for our window size to decrease, since each iteration increases right by 1 and left by either 0 or 1.
// Because our window size cannot decrease, it also means that the size of the window always represents the length of the best window we have found so far - analogous to ans from the previous approach.
// At the end of the iteration, the size of our window is n - left. We return this as the answer.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        
        return nums.size() - left;
    }
};
