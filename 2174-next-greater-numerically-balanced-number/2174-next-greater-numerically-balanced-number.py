class Solution:
    def nextBeautifulNumber(self, n: int) -> int:

        n = n+1

        while True:
        
            f = [0]*10
            m = n
            while m > 0:
                f[m%10] += 1
                m = m//10
            
            flag = True
            for i in range(10):
                if f[i] > 0 and f[i] != i:
                    flag = False 
                    break
            if flag:
                return n
            n += 1

        return -1
        