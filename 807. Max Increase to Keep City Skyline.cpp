class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        unordered_map<int,int>rows_max,cols_max;
        
        for(int i = 0; i < grid.size(); i++)
        {
            int row_max_val = 0;
            
            for(int j = 0; j < grid[0].size(); j++)
            {
                row_max_val = max(row_max_val,grid[i][j]);
            }
            
            rows_max[i] = row_max_val;
        }
        
        for(int i = 0; i < grid[0].size(); i++)
        {
            int col_max_val = 0;
            
            for(int j = 0; j < grid.size(); j++)
            {
                col_max_val = max(col_max_val, grid[j][i]);
            }
            
            cols_max[i] = col_max_val;
        }
        
        int res = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int row_max = rows_max[i];
                int col_max = cols_max[j];
                
                int minimum_among_these = min(row_max,col_max);
                
                res = res + (minimum_among_these - grid[i][j]);
            }
        }
        
        return res;
    }
};
