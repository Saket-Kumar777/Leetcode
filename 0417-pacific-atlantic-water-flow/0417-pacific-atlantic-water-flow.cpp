class Solution {
public:
int n, m ;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
         n = height.size() ;
         m = height[0].size() ;

        vector<vector<bool>> pacific(n, vector<bool>(m, false)) ;
        vector<vector<bool>> atlantic = pacific ;
        vector<vector<int>> ans ;

        for(int i=0; i<n; i++) dfs(height, pacific, i, 0), dfs(height, atlantic, i, m-1) ;
        for(int i=0; i<m; i++) dfs(height, pacific, 0, i), dfs(height, atlantic, n-1, i) ;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans ;
    }

    void dfs(vector<vector<int>>&height, vector<vector<bool>>& vis, int i, int j)
    {
          if(vis[i][j]) return ;

          vis[i][j] = true ;

          if(i-1 >= 0 and height[i-1][j] >= height[i][j]) dfs(height, vis, i-1, j);
          if(i+1 < n and height[i+1][j] >= height[i][j]) dfs(height, vis, i+1, j);
          if(j-1 >= 0 and height[i][j-1] >= height[i][j]) dfs(height, vis, i, j-1);
          if(j+1 < m and height[i][j+1] >= height[i][j]) dfs(height, vis, i, j+1);
    }
};