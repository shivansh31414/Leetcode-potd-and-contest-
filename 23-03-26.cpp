// 643. Maximum Average Subarray I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // Step 1: Initialize DP tables
        vector<vector<long long>> maxDP(m, vector<long long>(n, 0));
        vector<vector<long long>> minDP(m, vector<long long>(n, 0));

        // Step 2: Base case
        maxDP[0][0] = grid[0][0];
        minDP[0][0] = grid[0][0];

        // Step 3: Fill first row
        for (int j = 1; j < n; j++) {
            maxDP[0][j] = maxDP[0][j-1] * grid[0][j];
            minDP[0][j] = maxDP[0][j]; // only one path
        }

        // Step 4: Fill first column
        for (int i = 1; i < m; i++) {
            maxDP[i][0] = maxDP[i-1][0] * grid[i][0];
            minDP[i][0] = maxDP[i][0]; // only one path
        }

        // Step 5: Fill rest of DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                vector<long long> candidates = {
                    maxDP[i-1][j] * val,
                    minDP[i-1][j] * val,
                    maxDP[i][j-1] * val,
                    minDP[i][j-1] * val
                };
                maxDP[i][j] = *max_element(candidates.begin(), candidates.end());
                minDP[i][j] = *min_element(candidates.begin(), candidates.end());
            }
        }

        // Step 6: Final answer
        long long result = maxDP[m-1][n-1];
        if (result < 0) return -1;
        return result % MOD;
    }
};

    
