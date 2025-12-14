class Solution:
    def minMoves(self, balance: List[int]) -> int:
        s = sum(balance)
        if s < 0:
            return -1

        ind = -1
        n = len(balance)
        val = 10**9
        cnt = 0
        for i in range(n):
            if balance[i] < 0:
                ind = i
                val = abs(balance[i])
                cnt += 1
                if cnt > 1:
                    return -1
                
        if ind == -1:
            return 0

        j, k = ind - 1, ind + 1

        if j == -1:
            j = n-1
        if k == n:
            k = 0

        ans = 0
        while val > 0:
            if j == k :
                if k > ind :
                    ans += val + val*((k - ind) - 1)
                else:
                    ans += val + val*((ind - j) - 1)
                val = 0
            else:
                t = min(val, balance[k])
                ans += t
                val -= t
                
                if t > 0 and k > ind :
                    ans += t*((k - ind) - 1)
                elif t > 0:
                    ans += t*((n-ind) + k - 1)

                if val > 0:
                   t = min(val, balance[j])
                   ans += t
                   val -= t
                   if t > 0 and j > ind :
                       ans += t*(n - j - 1 + ind)
                   elif t > 0:
                       ans += t*(ind - j - 1)

            j -= 1
            k += 1

            if j == -1:
                j = n-1
            if k == n:
                k = 0

        return ans 
                