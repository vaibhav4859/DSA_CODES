// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int idx = 0, ans = 0;
        while(idx < nums.size()){
            ans = ans ^ nums[idx];
            idx++;
        }

        return ans;
    }
};

// We apply the extended version of this gate in our bitwise XOR operator.
// If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).
// Similarly , if we observe ,

// A^A=0
// A^B^A=B
// (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
// Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a

// Why does this work ??
// Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.
