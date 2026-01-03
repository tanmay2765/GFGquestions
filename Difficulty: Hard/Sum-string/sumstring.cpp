class Solution {
  public:
  string sm(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool check(string &s, int i, int j, int k) {
        if ((s[i] == '0' && j - i > 1) || (s[j] == '0' && k - j > 1)) return false;
        string a = (s.substr(i, j - i));
        string b = (s.substr(j, k - j));
        string sum = sm(a ,b);
        if (s.substr(k, sum.size()) != sum) return false;
        if (k + sum.size() == s.size()) return true;
        return check(s, j, k, k + sum.size());
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(s, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
