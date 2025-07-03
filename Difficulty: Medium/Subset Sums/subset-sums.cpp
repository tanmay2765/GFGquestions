class Solution {
public:
    void fun(vector<int>& arr, vector<int>& res, int inx, int sum) {
        if (inx == arr.size()) {
            res.push_back(sum);
            return;
        }
        // include arr[inx]
        fun(arr, res, inx + 1, sum + arr[inx]);
        // exclude arr[inx]
        fun(arr, res, inx + 1, sum);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> res;
        fun(arr, res, 0, 0);
        return res;
    }
};