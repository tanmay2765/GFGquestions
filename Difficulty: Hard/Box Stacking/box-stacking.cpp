#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {

        int n = height.size();
        vector<vector<int>> boxes;

        // Generate exactly 3 valid rotations per box
        for (int i = 0; i < n; i++) {
            // height as vertical
            boxes.push_back({
                max(width[i], length[i]),
                min(width[i], length[i]),
                height[i]
            });

            // width as vertical
            boxes.push_back({
                max(height[i], length[i]),
                min(height[i], length[i]),
                width[i]
            });

            // length as vertical
            boxes.push_back({
                max(height[i], width[i]),
                min(height[i], width[i]),
                length[i]
            });
        }

        // Sort by base area (descending)
        sort(boxes.begin(), boxes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] * a[1] > b[0] * b[1];
             });

        int m = boxes.size();
        vector<int> dp(m);

        int ans = 0;

        // LIS-style DP
        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i][2]; // height of current box

            for (int j = 0; j < i; j++) {
                if (boxes[i][0] < boxes[j][0] &&
                    boxes[i][1] < boxes[j][1]) {

                    dp[i] = max(dp[i], boxes[i][2] + dp[j]);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
