'''
Created on 2019年3月1日

'''
import time
def fast_solve(n):
    '''
    时间复杂度O(n)
    '''
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    elif n <= 0:
        return 0
    
    a,b,c = 1, 2, 4 #n=1为1，n=2为2，n=3为4
    for i in range(4,n+1):
        a,b,c = b,c,a+b+c
    
    return c

if __name__ == '__main__':
    n = int(input('Input the number of stairs:'))
    start = time.clock()
    res = fast_solve(n)
    stop = time.clock()
    print(res)
    print(stop - start, 's')