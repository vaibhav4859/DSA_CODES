// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
// Examples:
// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> nums;
        int i = 0, j = 0, n = a.size(), m = b.size();
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                nums.push_back(a[i]);
                i++, j++;
                while(i < n && a[i] == a[i-1]) i++;
                while(j < m && b[j] == b[j-1]) j++;
            }
            else if(a[i] < b[j]) {
                nums.push_back(a[i++]);
                while(i < n && a[i] == a[i-1]) i++;
            } else {
                nums.push_back(b[j++]);
                while(j < m && b[j] == b[j-1]) j++;
            }
        }
        
        while(i < a.size()) {
            nums.push_back(a[i++]);
            while(i < n && a[i] == a[i-1]) i++;
        }
        
        while(j < b.size()) {
            nums.push_back(b[j++]);
            while(j < m && b[j] == b[j-1]) j++;
        }
        
        return nums;
    }


// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
