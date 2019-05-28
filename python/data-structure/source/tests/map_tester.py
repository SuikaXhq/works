adj = {
    0:[1,3,4],
    1:[0],
    2:[4],
    3:[0,4,5],
    4:[0,2,3,5],
    5:[3,4]
}

def dfs(adjl, s, parents={}):
    if parents == {}: parents[s] = None
    print(s, end=' ')
    for v in adjl[s]:
        if v not in parents:
            parents[v] = s
            dfs(adjl, v, parents)

def main():
    print('Traversal of a simple map:')
    dfs(adj, 0)


if __name__ == '__main__':
    main()