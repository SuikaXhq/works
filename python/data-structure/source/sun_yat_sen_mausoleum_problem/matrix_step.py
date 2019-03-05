'''
Created on 2019年3月3日

'''
import time
def matrix_solve(n):
    '''
    时间复杂度O(logn)
    '''
    if n <= 0:
        return 0
    
    p = [[1,1,1],
         [1,0,0],
         [0,1,0]]#本题的递推矩阵
    
    res = [[1,0,0],
           [0,1,0],
           [0,0,1]]#初始化为单位矩阵
    
    while n != 0:
        if n&1 == 1:
            res = matrix_multiply(res, p)
        n >>= 1
        p = matrix_multiply(p, p)
    
    return res[0][0]

def matrix_multiply(m, n):#矩阵乘法
    res = [[0,0,0],
           [0,0,0],
           [0,0,0]]
    for i in range(3):
        for j in range(3):
            for k in range(3):
                res[i][j] += m[i][k] * n[k][j]
    return res

if __name__ == '__main__':
    n = int(input('Input the number of stairs:'))
    start = time.clock()
    res = matrix_solve(n)
    stop = time.clock()
    print(res)
    print(stop - start, 's')