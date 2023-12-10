def partition(arr, index, low, high):
    i = (low - 1)
    pivot = arr[high]
    for j in range(low, high):
        if arr[j] < pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
            index[i], index[j] = index[j], index[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    index[i + 1], index[high] = index[high], index[i + 1]
    return i + 1

def quickSort(arr, index, low, high):
    if low < high:
        pi = partition(arr, index, low, high)
        quickSort(arr, index, low, pi - 1)
        quickSort(arr, index, pi + 1, high)

def putdata(arr, n):
    print('\n\nFollowing are the percentages of all the students...\n')
    print('**********************************')
    print('| Roll No | Percentage |')
    print('**********************************')
    for i in range(n):
        print(f'|\t{i + 1}\t|\t{arr[i]}%\t |')
    print('----------------------------------\n\n')

def putsorteddata(arr, n):
    print('\n**********************************')
    print('| Roll No | Percentage |')
    print('**********************************')
    for i in range(n):
        print(f'|\t{arr[i][0]}\t|\t{arr[i][1]}%\t |')
    print('----------------------------------\n\n')

def main():
    n = int(input('\nEnter number of students in 1st year: '))
    arr = []
    for i in range(n):
        arr.append(int(input(f'Enter percentage of roll no {i + 1}: ')))
    putdata(arr, n)
    n = len(arr)
    index = list(range(1, n + 1))
    print('Sorting all the percentages using Quick Sort:')
    quickSort(arr, index, 0, n - 1)
    putsorteddata(list(zip(index, arr)), n)

if __name__ == "__main__":
    main()