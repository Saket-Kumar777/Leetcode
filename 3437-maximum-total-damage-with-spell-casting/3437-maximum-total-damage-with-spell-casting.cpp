class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        unordered_map<int,int> freq;
        
        for(auto key: power) freq[key] += 1;

        vector<int> spell ;

        for(auto it: freq) spell.push_back(it.first) ;

        sort(spell.begin(), spell.end()) ;
        int n = spell.size() ;

        vector<long long> dp(n, 0) ;
        dp[0] = 1ll*freq[spell[0]]* spell[0] ;

        for(int i=1; i<n; i++)
        {
            int curr = freq[spell[i]]*spell[i] ;
            dp[i] = curr ;
            for(int k=i-1 ; k >= max(0, i - 3) ; k--)
            {
                 if(spell[i] - spell[k] > 2)
                 {
                     dp[i] = max(dp[i], (curr + dp[k])) ;
                     break ;
                 }
                 else
                 {
                     dp[i] = max(dp[i], dp[k]) ;
                 }
            }
        }
       return dp[n-1] ;
    }
};