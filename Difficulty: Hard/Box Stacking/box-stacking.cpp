class Solution {
public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        struct Box {
            int base1, base2, h;
        };

        vector<Box> boxes;

        // Step 1: Generate all 3 rotations
        for (int i = 0; i < height.size(); i++) {
            int h = height[i], w = width[i], l = length[i];

            boxes.push_back({max(w, l), min(w, l), h});
            boxes.push_back({max(h, l), min(h, l), w});
            boxes.push_back({max(h, w), min(h, w), l});
        }

        // Step 2: Sort by base area descending
        sort(boxes.begin(), boxes.end(), [](Box &a, Box &b) {
            return (a.base1 * a.base2) > (b.base1 * b.base2);
        });

        int n = boxes.size();
        vector<int> dp(n);

        // Step 3: LIS-style DP
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = boxes[i].h;
            for (int j = 0; j < i; j++) {
                if (boxes[j].base1 > boxes[i].base1 &&
                    boxes[j].base2 > boxes[i].base2) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
