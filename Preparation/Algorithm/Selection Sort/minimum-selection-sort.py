# PROGRAM MinimumSelectionSort
# Sort an array using the minimum selection sort algorithm.

# DECLARATION
# array : array of integers
# n: integer

# FUNCTION
def finding_minimum():
    temporary = array[0]
    for i in range (n-1):
        j = i + 1
        if temporary > array[j]:
            temporary = array[j]
    return temporary

# INPUT
n = int(input("Enter the number of elements in the array: "))
array = []
final_array = []

for i in range(n):
    array.append(int(input("Enter the element: ")))

# PROCESS
for i in range(n):
    minimum = finding_minimum()
    final_array.append(minimum)
    array.remove(minimum)
    n = n - 1

# OUTPUT
print(final_array)



