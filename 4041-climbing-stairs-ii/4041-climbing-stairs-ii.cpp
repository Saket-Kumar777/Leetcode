class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0) ;

        dp[1] = costs[0] + 1;
       if(n >= 2) dp[2] = costs[1] + min(dp[1] + 1, dp[0] + 4) ;

       for(int i=3; i<=n; i++)
       {
            int st1 = dp[i-1] + 1;
            int st2 = dp[i-2] + 4;
            int st3 = dp[i-3] + 9;

            dp[i] = costs[i-1] + min({st1, st2, st3}) ;
       }
       return dp[n] ;
    }
};