// User function template for C++
class Solution {
  public:
    // Helper recursive function
    int s(vector<int>& a, int n){
        if(n < 0) return 0;
        return a[n] + s(a, n-1);
    }

    int arraySum(vector<int>& arr) {
        return s(arr, arr.size()-1);
    }
};
