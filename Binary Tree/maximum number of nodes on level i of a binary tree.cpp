class Solution {
    public:
      int countNodes(int i) {
          // your code here
          return pow(2, i-1);
      }
      // 1 - 1
      // 2 - 2
      // 3 -  4
      // 4 - 8
      // 5 - 16
  };