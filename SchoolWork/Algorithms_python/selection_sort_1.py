'''
selection sort
选择排序
'''


def findSmallest(arr):
    smallest = arr[0]
    smallestIndex = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallestIndex = i
    return smallestIndex


def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        smallestIndex = findSmallest(arr)
        newArr.append(arr.pop(smallestIndex))
    return newArr


if __name__ == '__main__':
    print(selectionSort([3, 2, 6, 4, 7]))
