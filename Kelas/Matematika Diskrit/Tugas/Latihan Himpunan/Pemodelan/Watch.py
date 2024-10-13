n = int(input())
arr = []
for i in range (1, n + 1):
    if i % 7 == 0:
        arr.append(i)
print(arr)
print(len(arr))