class Solution {
  public:
    int factorial(int x) {
        // code here
        if(x==0) return 1;
        return x*factorial(x-1);
    }
};