#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        // Step 1: Build heights
        for (int j = 0; j < n; j++) {
            heights[0][j] = matrix[0][j];
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == 1)
                    heights[i][j] = heights[i-1][j] + 1;
                else
                    heights[i][j] = 0;
            }
        }

        int maxArea = 0;

        // Step 2 & 3: Sort each row and compute max area
        for (int i = 0; i < m; i++) {
            vector<int> row = heights[i];
            sort(row.begin(), row.end(), greater<int>());
            for (int k = 0; k < n; k++) {
                maxArea = max(maxArea, row[k] * (k + 1));
            }
        }

        return maxArea;
    }
};
