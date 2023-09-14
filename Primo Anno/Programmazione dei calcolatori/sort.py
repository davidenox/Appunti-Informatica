#In[] Liste
list = [ 6, 2, 8, 4, 5 ]
#In[] slicing
a = list[::]
#In[] sorted
print(list)
print(sorted(list))

strs = ['aa', 'BB', 'zz', 'CC']
print(sorted(strs))
print(sorted(strs, reverse = True))

str = ['ccc', 'aaaa', 'd', 'bb']
print(sorted(str, key = len))

#In[] sort
a = [3, 7, 2, 9, 12, 1]
a.sort()
print(a)

#In[] Tuple
tuple =(1, 2, 'hi')
print(len(tuple))
print(tuple[2])

#In[] bubbleSort
def bubbleSort(array):
    for j in range(0, len(array)-1):
        for i in range(0, len(array)-1):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]

array_num = [54, 26, 93, 17, 77, 31, 44, 55, 20] 
bubbleSort(array_num)

print(array_num)

#In[] mergeSort

def merge_sort(elements):
    if len(elements) > 1:
        # fase 1: splitting
        mid = len(elements) // 2
        left = elements[:mid]
        right = elements[mid:]
        merge_sort(left)
        merge_sort(right)

        # fase 2: merging
        a = b = c = 0
        while a < len(left) and b < len(right):
            if left[a] < right[b]:
                elements[c] = left[a]
                a += 1
            else:
                elements[c] = right[b]
                b += 1
            c += 1

        while a < len(left):
            elements[c] = left[a]
            a += 1
            c += 1

        while b < len(right):
            elements[c] = right[b]
            b += 1
            c += 1

    return elements
list_to_sort=[8,4,23,42,16,15]
merge_sort(list_to_sort)
print("Sorted list:", list_to_sort)
