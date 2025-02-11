class Solution {  
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int temp = n, count = 0;
        while(temp) {
            int digit = temp % 10;
            if(digit != 0 && n % digit == 0) count++;
            temp /= 10;
        }
        
        return count;
    }
};

// https://www.geeksforgeeks.org/problems/count-digits5716/1
