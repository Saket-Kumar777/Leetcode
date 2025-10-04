class Solution {
public:
    bool possible(string s, string t)
    {
          int i=0, j= 0;

          int n = t.size() ;

          while(i < n+1 and j < n)
          {
             if(s[i] == t[j]) i++, j++ ;
             else i++ ;
          }

          return j == n;
    }
    
    struct comp{
        bool operator()(string a, string b)
        {
            return a.size() < b.size() ;
        }
    };
    int longestStrChain(vector<string>& words) {
        int n = words.size() ;
        sort(words.begin(), words.end(), comp()) ;

        vector<int> dp(n, 1) ;
        
        int ans = 1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(words[i].size() == words[j].size()+1)
                {
                    if(possible(words[i], words[j])) dp[i] = max(dp[i], 1+dp[j]) ;
                }
            }

             ans = max(ans, dp[i]) ;
        }

        return ans ;
    }
};