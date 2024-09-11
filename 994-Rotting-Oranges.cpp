class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    freshCount++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; 
                        freshCount--; 
                        q.push({newX, newY}); 
                    }
                }
            }
            minutes++; 
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};