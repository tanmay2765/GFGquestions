// User function Template for C++
class Solution {
  public:
    void rev(string &s, int l, int r) {  
        if (l >= r) return;
        swap(s[l], s[r]);
        rev(s, l + 1, r - 1);
    }

    string reverseString(string s) {
        rev(s, 0, s.size() - 1);
        return s;  
    }
};



