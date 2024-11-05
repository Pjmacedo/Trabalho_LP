//1351. Count Negative Numbers in a Sorted Matrix

#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row);
                col--;
            } else {
                row++;
            }
        }

        return count;
    }
};
