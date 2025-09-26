class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans ;
        unordered_map<int, int> m;
        int n = nums.size() ;
        for(int i=0; i<n; i++)
        {
            int an = target - nums[i] ;
            if(m.count(an)) 
            {
                 ans.push_back(m[an]);
                   ans.push_back(i);
                 return ans;
            }
            m[nums[i]]=i;
        }
       return {};
    }
};