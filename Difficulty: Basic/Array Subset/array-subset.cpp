class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int> freq;
        for(int i=0;i<a.size();i++) freq[a[i]]++;
        for(int i=0;i<b.size();i++){
            if(freq[b[i]]==0) return false;
            freq[b[i]]--;
        } 
        return true;
    }
};