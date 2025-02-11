bool armstrongNumber(int n) {
        // code here
        int num = n, sum = 0;
        while(num) {
            int digi = num % 10;
            sum += digi * digi * digi;
            num /= 10;
        }
        
        if(sum == n) return true;
        else return false;
    }

// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1
