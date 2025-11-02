class Solution {
public:
    void mark(int m, int n, int i, int j, auto& mat)
    {
          for(int k = i-1; k>= 0; k--)
          {
              if(mat[k][j] == 0 or mat[k][j] == 3) mat[k][j] = 3;
              else break;
          }
            
          for(int k = i+1; k < m; k++)
          {
              if(mat[k][j] == 0 or mat[k][j] == 3) mat[k][j] = 3;
              else break;
          }

          for(int k = j-1; k>= 0; k--)
          {
              if(mat[i][k] == 0 or mat[i][k] == 3) mat[i][k] = 3;
              else break;
          }

          for(int k = j+1; k < n; k++)
          {
              if(mat[i][k] == 0 or mat[i][k] == 3) mat[i][k] = 3;
              else break;
          }

    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
           
           vector<vector<int>> mat(m, vector<int> (n, 0)) ;

           for(auto g : guards) mat[g[0]][g[1]] = 1;
           for(auto w : walls) mat[w[0]][w[1]] = 2;

           for(auto g: guards)
           {
                mark(m, n, g[0], g[1], mat) ;
           }
           
           int cnt = 0;
           for(int i=0; i<m; i++)
           {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0) 
                {
                    cnt += 1;
                }
            }
           }

           return cnt ;
    }
};