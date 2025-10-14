class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(k == 1) return true ;
        int curr = 1 ;
        for(int i=k+1; i<n; i++)
        {
              if(nums[i-k] > nums[i-k-1] and nums[i] > nums[i-1]) curr++;
              else curr = 1;
              if(curr == k) return true ;
        }
        return false ;
    }
};