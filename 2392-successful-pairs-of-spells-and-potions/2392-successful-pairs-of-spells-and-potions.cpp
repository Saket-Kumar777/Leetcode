class Solution {
public:
    int solve(int spell , auto& potions, long long success)
    {
          int n = potions.size() ;
           int s = 0, e = n-1 ;
         int ind = n ;
           while(s <= e)
           {
               int m = s + (e-s)/2 ;
               
               if(1ll*potions[m]*spell >= success) 
               {
                   ind = m ;
                   e = m-1;
               }
               else s = m+1;
           }

           return n-ind ;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
         vector<int>ans ;    

         sort(potions.begin(), potions.end()) ;
         int n = spells.size() ;
         for(int i=0; i<n; i++)
         {
              int successful_potion = solve(spells[i], potions, success) ;
              ans.push_back(successful_potion) ;
         }

         return ans ;
    }
};