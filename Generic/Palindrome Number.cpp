// https://leetcode.com/problems/palindrome-number/

// Approach-1 : (Reverse full number)
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        
        return rev;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = reverse(x);
        if(x == rev) return true;
        return false;
    }
};


// Approach-2: (Reverse half number)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return (x == rev) || (x == rev / 10);
    }
};
