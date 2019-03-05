'''
Created on 2019年3月1日

'''
def solve_(n, array):
    '''
    时间复杂度O(n)
    '''
    if array[n] != None:
        return array[n]
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    elif n <= 0:
        return 0
    
    array[n] = solve_(n-1, array) + solve_(n-2, array) + solve_(n-3, array)
    return array[n]
    
def improved_solve(n):
    array = [None]*(n+1)
    return solve_(n, array)

if __name__ == '__main__':
    n = int(input('Input the number of stairs:'))
    print(improved_solve(n))