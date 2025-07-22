class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> map;
        int s=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(s==0||arr[i]==0) return true;
            if(map.find(s)!=map.end()) return true;
            map[s]=1;
        }
        return false;
    }
};