class Solution {
    int solve(string t,int i, int n, string& s, auto& st, auto& dp)
    {
         if(i == n)
         {
             return true ;
         }
         
         if(dp[i] != -1) return dp[i] ;
         
         int f = 0;
         for(int j = i; j<n; j++)
         {
              if(st.count(s.substr(i, j-i+1)))
              {
                 f = f |solve(t, j+1, n, s, st, dp);
                  
              }
         }
         return dp[i] = f;
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.size() ;
        
        set<string> st(dict.begin(), dict.end()) ;
        
        vector<int> dp(n, -1) ;
        if(solve("", 0, n, s, st, dp) == 1) return true ;
        return false ;
    }
};