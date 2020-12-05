'''
quick sort
快速排序
'''


def quickSort(arr):
    if len(arr) < 2:
        return arr
    else:
        pivot = arr[0]
        smaller = [i for i in arr[1:] if i <= pivot]
        bigger = [i for i in arr[1:] if i > pivot]
        return quickSort(smaller) + [pivot] + quickSort(bigger)


if __name__ == '__main__':
    print(quickSort([3, 7, 1, 2, 9]))
