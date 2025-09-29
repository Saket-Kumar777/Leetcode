class Solution {
public:
    int dp[51][51] ;
    int solve(int i, int j, vector<int>& values)
    {
        if(j - i < 2) return 0;

        if(dp[i][j] != -1) return dp[i][j] ;

        int score = INT_MAX;

        for(int k= i+1; k<j; k++)
        {
            int curr = values[i]*values[k]*values[j] + solve(i,k, values) + solve(k, j, values) ;
            score = min(curr, score);
        }

        return dp[i][j] = score ;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp, -1 , sizeof(dp)) ;
        int n = values.size() ;

        return solve(0, n-1, values) ;
    }
};