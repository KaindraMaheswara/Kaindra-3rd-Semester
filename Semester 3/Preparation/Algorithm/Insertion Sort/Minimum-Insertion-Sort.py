# PROGRAM MinimumInsertionSort
# Making an array of integers and sorting it using insertion sort from the minimum to the maximum

# DECLARATION
# array, final_array: array of integers
# i,j: integers
# n: integer
# found : boolean

# INPUT
n= int(input("Enter the number of elements in the array: "))
array = [int(input("Enter the element: ")) for i in range(n)]

# PROCESS
# Elemen pertama dianggap urut
for i in range(1,n):
    found = False
    j = i - 1
    while j >= 0 and (not found):
        if array[j + 1] < array[j]:
            array[j], array[j + 1] = array[j + 1], array[j]
            j -= 1
        else:
            found = True

# OUTPUT
print(array)