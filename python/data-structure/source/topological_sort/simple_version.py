#状态标识符
UNVISITED = 0   #尚未访问
VISITING = 1    #访问中
VISITED = 2     #已经访问完毕

#边的分类
TREE_EDGE = 0
BACK_EDGE = 1
FORWARD_EDGE = 2
CROSS_EDGE = 3

status = {}     # 存放节点的状态
time = {}       # 存放节点访问的顺序
clock = 0       # 时刻 用于记录顺序
parents = {}    # 存放遍历中节点的直接前序
edge_type = {}  # 存放边的类型

back_edges = [] # 存放所有back edge


def initial_DFS(V):
    for v in V:
        status[v] = UNVISITED
            
def close():
    status.clear()
    time.clear()
    global clock
    clock = 0
    parents.clear()
    edge_type.clear()
    back_edges.clear()

def cycle_test(V, Adj):
    initial_DFS(V)
    for s in V:
        if status[s] == UNVISITED:
            single_DFS(s, Adj)

    if back_edges:  # if back edge exists
        print(len(back_edges), 'cycle(s) found in the graph. Printed below:')
        for edge in back_edges:
            v = edge[0]
            stack = [v]
            while v != edge[1]:
                v = parents[v]
                stack.append(v)
            # print cycle
            while stack:
                print(stack.pop(), '->', end=' ')
            print(edge[1])
    else:
        print('No cycle in the graph.')

    close()


def single_DFS(s, Adj, is_sort=False, stack=[]):   #DFS for a single node, 后两个参数为拓扑排序使用
    status[s] = VISITING
    global clock
    time[s] = clock
    clock += 1
    for v in Adj[s]:
        if status[v] == UNVISITED:
            parents[v] = s
            edge_type[(s,v)] = TREE_EDGE
            single_DFS(v, Adj, is_sort, stack)
        elif status[v] == VISITING:
            edge_type[(s,v)] = BACK_EDGE
            back_edges.append((s,v))
        elif time[v] > time[s]:
            edge_type[(s,v)] = FORWARD_EDGE
        else:
            edge_type[(s,v)] = CROSS_EDGE
    if is_sort:     # 存入拓扑排序的栈内
        stack.append(s)
    status[s] = VISITED



def topo_sort(V, Adj):
    initial_DFS(V)
    stack = []
    for s in V:
        if status[s] == UNVISITED:
            single_DFS(s, Adj, is_sort=True, stack=stack)
    
    if back_edges:      # if the graph contains cycle
        print('Cycle(s) found in the graph. Topological sort failed.')
        return

    while stack:
        print(stack.pop(), end=' ')

    close()



def read_graph(file_name, V, Adj):
    V.clear()
    Adj.clear()
    with open(file_name, mode='r') as graph:
        num_v = int(graph.readline().strip())     # 读取节点数量
        for i in range(num_v):
            V.append(graph.readline().split()[0])
            Adj[V[i]] = []
        num_e = int(graph.readline().strip())     # 读取边数量
        for i in range(num_e):
            edge = graph.readline().split()
            Adj[edge[0]].append(edge[1])




if __name__ == '__main__':
    V = []
    Adj = {}

    # 测试是否有环, cycle.txt是由graph.txt将边(o,v)改为(v,o)得到的
    read_graph('cycle.txt', V, Adj)
    cycle_test(V, Adj)

    # 拓扑排序
    read_graph('graph.txt', V, Adj)
    cycle_test(V, Adj)
    topo_sort(V, Adj)
    