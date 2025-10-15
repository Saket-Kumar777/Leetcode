class Solution:
    def possible(self, nums, k) -> bool:
        n = len(nums)
        cnt = 1
        if k == 1:
            return True

        for i in range(k+1, n):
            if nums[i] >nums[i-1] and nums[i-k] > nums[i-k-1]:
                cnt += 1
                if cnt == k:
                    return True
            else:
                cnt = 1

        return False 

    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = 1
        st = 1
        end = len(nums)//2 

        while st <= end:
            mid = (st+end)//2
            if(self.possible(nums, mid)):
                ans = mid 
                st = mid+1
            else:
                end = mid-1 

        return ans 