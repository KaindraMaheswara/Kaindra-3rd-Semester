n = int(input())
b = int(input())
arr = []
for i in range (1, (n + 1)):
    if i % b == 0:
        arr.append(i)
print(arr)
print(len(arr))