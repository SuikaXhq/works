'''
Created on 2019年3月1日

'''
def bottom_up_solve(n):
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
    
    array = [None]*(n+1)
    array[1], array[2], array[3] = [1,2,4]  #n=1为1，n=2为2，n=3为4
    for i in range(4, n+1):
        array[i] = array[i-1] + array[i-2] + array[i-3]
        
    return array[n]

if __name__ == '__main__':
    n = int(input('Input the number of stairs:'))
    print(bottom_up_solve(n))