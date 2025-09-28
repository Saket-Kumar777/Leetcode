class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return -1;
        long long sum = 0;

        for(auto num: nums) sum += num ;

        long long ans = 1e18;
        long long left = nums[0];
        
        int i=1;
        while(i < n and nums[i] > nums[i-1])
        {
              left += nums[i] ;
              i++;
        }

        if(i == n) return abs(left - 2*nums[n-1]) ;

        if(i == 1 or nums[i] == nums[i-1]) ans = abs(left - (sum - left)) ;
        else
        {
            int prev = nums[i-1] ;
            ans = min(abs(left - (sum-left)), abs(left-prev - (sum-left + prev))) ;
        }
 
        for(int j=i; j<n-1; j++) 
        {
            if(nums[j+1] >= nums[j]) return -1;
        }

        return ans ;
    }
};