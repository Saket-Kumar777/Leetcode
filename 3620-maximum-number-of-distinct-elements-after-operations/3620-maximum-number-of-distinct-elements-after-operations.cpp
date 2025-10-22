class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()) ;

        int last = INT_MIN ;
        int cnt = 0;
        
        for(int i=0; i<n; i++)
        {
            int mn = nums[i] - k;
            int mx = nums[i] + k;

            if(mn > last )
            {
               cnt++;
               last = mn ;
            }
            else if(last < mx)
            {
               cnt++;
               last += 1;
            }
        }
        return cnt ;
    }
};