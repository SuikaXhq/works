'''
Created on 2019年3月1日

@author: SuikaXhq
'''
import time

def fib(n):
    if n <= 0:
        return 0
    
    m = [1,1,1,0]
    res = [1,0,0,1]
    n -= 1
    while n != 0:
        if n&1 == 1:
            res = mat_mul(res, m)
        n >>= 1
        m = mat_mul(m, m)
    
    return res[0]

def mat_mul(m, n): #矩阵平方
    return [m[0]*n[0] + m[1]*n[2],
            m[0]*n[1] + m[1]*n[3],
            m[2]*n[0] + m[3]*n[2],
            m[2]*n[1] + m[3]*n[3]]
    
def fib_2(n):
    a,b = 1, 1
    for i in range(n-2):
        a, b = b, a+b
    return b

if __name__ == '__main__':
    n = int(input(':'))
    start = time.clock()
    res = fib(n)
    stop = time.clock()
#    print(res)
    print(stop - start, 's')