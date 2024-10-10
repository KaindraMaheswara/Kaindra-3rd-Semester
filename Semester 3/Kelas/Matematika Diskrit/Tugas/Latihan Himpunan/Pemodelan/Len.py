n = int(input())
arr = []
for i in range (1, n+1):
    if "8" in str(i) or i % 3 == 0:
        arr.append(i)
print(arr)
print(len(arr))
print(n - len(arr))