'''
Created on 2019年3月1日

'''
def solve(n):#n为台阶数
    '''
    时间复杂度O(3^n)
    '''
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    elif n <= 0:
        return 0
    return solve(n-1) + solve(n-2) + solve(n-3)

if __name__ == '__main__':
    n = int(input('Input the number of stairs:'))
    print(solve(n))