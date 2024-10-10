n = int(input())
d = int(input())
arr = []
for i in range (1, (n + 1)):
    if (str(d) in str(i)):
        arr.append(i)
print(arr)
print(len(arr))