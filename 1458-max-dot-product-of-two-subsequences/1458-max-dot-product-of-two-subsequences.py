class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        dp = [[None]*m for _ in range(n)]

        def solve(i, j):
            if i < 0 or j < 0:
                return -10**9

            if dp[i][j] is not None:
                return dp[i][j]

            p = max(nums1[i]*nums2[j], nums1[i]*nums2[j] + solve(i-1, j-1))
            np1 = solve(i, j-1) 
            np2 = solve(i-1, j)

            dp[i][j] = max(p, np1, np2)
            return dp[i][j]

        solve(n-1, m-1)

        return dp[n-1][m-1]


