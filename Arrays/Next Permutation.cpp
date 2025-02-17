// https://leetcode.com/problems/next-permutation/
// ** IMP

class Solution {
public:
 void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        } // find the breakpoint for eg 1 in below example

    	if (k < 0) { // our expection case of 321 -> 123
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } // find the number just greater than breakpoint 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

// thr next permutation will be a higher number than the current number (excpetion if we are at highest number possible from current given number combinatipn then the next permuation will be the smallest number eg 321 -> 123)

// so we tend to match the maximum prefix possible that we can and generate the next permuation then for eg:
// 2 1 5 4 3 0 0
// like in this if take 5 4 3 0 0 if i arrange it in any possible order it wil still not create a larger number bcz they are sorted in decreasing order already
// so i take 1 5 4 3 0 0 then i can create some combination like 543100 but that still isn't the correct way as other combination like 453100 are smaller and occurs before that in the permuation order 
// so right now we have matched a prefix 2 and from the suffix 154300 we'll re-arraneg and generate our next permutaion

// so now in suffix i want someone greater than 1 but just greater than 1 not very much greater or a smaller because the number that is just greater than 1 will generate my next permuation, so we need to find the brealkpount like a[i] < a[i+1] the moment this condition becomes false we gets our number just greater than 1
// now we have made a number 2 3 _ _ _ _ _ and left with 5 4 1 0 0 so in order to generate next permutation it should be close to the previous number not very greater so we reverse ths and make 0 0 1 4 5 and our number becomes 2 3 0 0 1 4 5 which is our answer
