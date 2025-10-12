 set<int> col;
  set<int> d1;
   set<int> d2;
class Solution {
public:
    void solve(int r, int n, auto temp, auto& ans)
    {
          if(r == n)
          {
               ans.push_back(temp);
               return ;
          }

          for(int i=0; i<n; i++)
          {
              if(col.find(i) == col.end() and d1.find(r-i) == d1.end() 
                                 and d2.find(r+i) == d2.end() )
                {
                      string t (n, '.') ;
                      t[i] = 'Q';
                      temp.push_back(t);
                      col.insert(i);
                      d1.insert(r-i);
                      d2.insert(r + i);

                      solve(r+1, n, temp, ans);
                      col.erase(i);
                       d1.erase(r-i);
                       d2.erase(r+i);
                       temp.pop_back();
                }
          }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans ;
         vector<string> temp;

         solve(0, n, temp, ans);

         return ans ;
    }
};