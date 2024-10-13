n = int(input())
arr = []
for i in range(1, n + 1):
    if i >= 10 and i % 6 != 3:
        arr.append(i)
print(arr)
print(len(arr))