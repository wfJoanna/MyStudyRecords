'''
bfs
breadth-first search
广度优先搜索
求段数最少的路径
'''
from collections import deque


def thisIsMyTarget(one):
    if one == 'johnny':
        return True
    else:
        return False


def bfs(first, graph):
    searchQueue = deque()  # 双队列
    searchQueue += graph[first]  # 因为只有双队列才可以这样直接把列表里的元素一个一个添加到队列里，所以我们采用双队列。否则就是直接添加了一个列表到队列里
    searched = []  # 用于记录检查过的人

    while searchQueue:
        one = searchQueue.popleft()
        if not one in searched:
            if thisIsMyTarget(one):
                print(one + " is my target")
                return
            else:
                searched.append(one)
                searchQueue += graph[one]

    print("not found")


if __name__ == '__main__':
    graph = {}
    graph["you"] = ["alice", "bob", "claire"]
    graph["bob"] = ["anuj", "peggy"]
    graph["alice"] = ["peggy"]
    graph["claire"] = ["thom", "johnny"]
    graph["anuj"] = []
    graph["peggy"] = []
    graph["thom"] = []
    graph["johnny"] = []
    bfs("you", graph)
