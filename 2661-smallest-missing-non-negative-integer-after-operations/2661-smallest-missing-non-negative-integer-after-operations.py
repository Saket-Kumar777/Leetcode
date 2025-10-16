class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        n = len(nums)

        freq = [0]*n 
        
        for i in range(n):
            if nums[i] % value < n:
                freq[nums[i] % value] += 1

        if value < n :
            for i in range(value, n):
                if freq[i - value] > 1:
                    freq[i] += freq[i - value] - 1
                    freq[i - value] = 1

        for i in range(n):
            if freq[i] == 0:
                return i

        return n