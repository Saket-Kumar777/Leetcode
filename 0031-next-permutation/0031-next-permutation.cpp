class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size() ;
         int ind = -1;

         for(int i=n-1; i > 0; i--)
         {
              if(nums[i] > nums[i-1])
              {
                 ind = i-1;
                 break;
              }
         }
         if(ind == -1)
         {
             reverse(nums.begin(), nums.end());
             return ;
         }

         for(int j=n-1; j> ind; j--)
         {
            if(nums[j] > nums[ind]) 
            {
                swap(nums[j], nums[ind]) ;
                break;
            }
         }
         sort(nums.begin()+ind+1 , nums.end());

         return ;

    }
};