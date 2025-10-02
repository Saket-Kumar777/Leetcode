class Solution {
public:
    int maxBottlesDrunk(int n, int m) {
         int ans = 0;

         while(n >= m)
         {
              ans += m;
              n = n-m+1 ;
              m += 1;
         }

         ans += n ;

         return ans ;
    }
};