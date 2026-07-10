class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long cost = prefix[i]; 
            int limit = arr[i] + k;
            int idx = upper_bound(arr.begin(), arr.end(), limit) - arr.begin();
            long long suffixSum = prefix[n] - prefix[idx];
            long long cnt = n - idx;
            cost += suffixSum - cnt * limit;
            ans = min(ans, cost);
        }
        return (int)ans;
    }
};