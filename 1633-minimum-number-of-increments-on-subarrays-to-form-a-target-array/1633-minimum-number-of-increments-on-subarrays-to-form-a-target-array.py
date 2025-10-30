class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
       
        n = len(target)
        
        steps = target[0]
        for i in range(1, n):
            if target[i-1] < target[i]  :
                steps += target[i] - target[i-1]

        return steps
