'''
greedy algorithm
贪心算法（贪婪算法）
每步都选择局部最优解，不考虑整体，目光短浅
是一种近似算法，不一定能得到最优解，但很接近

下面这个是一个集合覆盖问题
'''


def greedy(statesNeeded, stations):
    finalStations = set()  # 存储最终选择的广播台
    while statesNeeded:
        bestStation = None  # 存储当前覆盖最多的未覆盖州的广播台
        statesCovered = set()
        for station, statesForStation in stations.items():  # 分别获得每个键和对应的值
            covered = statesNeeded & statesForStation
            if len(covered) > len(statesCovered):
                bestStation = station
                statesCovered = covered
        finalStations.add(bestStation)
        statesNeeded -= statesCovered
    print(finalStations)  # 每次运行结果可能不同


if __name__ == "__main__":
    statesNeeded = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"}  # 即使这里面有重复的它也会自动消除啦
    stations = {}  # 存储每个广播台覆盖的州
    stations["kone"] = {"id", "nv", "ut"}
    stations["ktwo"] = {"wa", "id", "mt"}
    stations["kthree"] = {"or", "nv", "ca"}
    stations["kfour"] = {"nv", "ut"}
    stations["kfive"] = {"ca", "az"}
    greedy(statesNeeded, stations)
    # 顺便说一下，如果要得到最优解，则：
    # 广播台的所有子集一共2^n个，挨个看这2^n个子集中，哪个子集是覆盖了所有州并且广播台最少
