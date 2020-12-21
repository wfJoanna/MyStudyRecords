'''
dijkstra
迪克斯特拉算法
求长度最短的路径（条件：路径不为负数）
'''


def findShortestPath(parents):  # 返回最短路径
    node = "end"
    shortestPath = ["end"]
    while parents[node] != "start":
        shortestPath.append(parents[node])
        node = parents[node]
    shortestPath.append("start")
    shortestPath.reverse()
    return shortestPath


def findLowestCostNode(costs, processed):  # 找到costs表中未处理过的离起点路径最短的点
    lowestCost = infinity
    lowestCostNode = None
    for node in costs:
        cost = costs[node]
        if cost < lowestCost and node not in processed:
            lowestCost = cost
            lowestCostNode = node
    return lowestCostNode


def dijkstra(graph, costs, parents):
    processed = []  # 记录处理过的点
    node = findLowestCostNode(costs, processed)
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            newCost = cost + neighbors[n]
            if costs[n] > newCost:
                costs[n] = newCost
                parents[n] = node
        processed.append(node)
        node = findLowestCostNode(costs, processed)
    shortestPath = findShortestPath(parents)
    return shortestPath


if __name__ == "__main__":
    graph = {}
    graph["start"] = {}
    graph["start"]["a"] = 6
    graph["start"]["b"] = 2
    graph["a"] = {}
    graph["a"]["end"] = 1
    graph["b"] = {}
    graph["b"]["a"] = 3
    graph["b"]["end"] = 5
    graph["end"] = {}

    infinity = float("inf")  # 通过这种方式可以表示无穷大
    costs = {}  # 从起点前往该节点的目前的最短长度
    costs["a"] = 6
    costs["b"] = 2
    costs["end"] = infinity

    parents = {}  # 父节点
    parents["a"] = "start"
    parents["b"] = "start"
    parents["end"] = None

    print(dijkstra(graph, costs, parents))
    print("从start到end的最短路径长度：", costs["end"])
