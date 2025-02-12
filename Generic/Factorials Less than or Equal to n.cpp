void func(long long i, long long n, long long fac, vector<long long>& ans) {
       if(i * fac > n) return;
       ans.push_back(i * fac);
       func(i+1, n, i * fac, ans);
    }
    
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        func(1, n, 1, ans);
        return ans;
    }


// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0
