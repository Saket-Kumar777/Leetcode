class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        int m = time.size() ;

        int ans = 0;

        for(int i=0; i<n-1; i++)
        {
            if(colors[i] == colors[i+1])
            {
                if(time[i] > time[i+1]) swap(time[i], time[i+1]) ;
                ans += time[i] ;
            } 
        }
        return ans ;
    }
};