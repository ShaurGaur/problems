n, k = map(int, input().split(" "))
arr = [int(input()) for i in range(n)]

freq = dict([(i, 0) for i in range(1, k+1)])
for i in range(n): freq[arr[i]] += 1

ans = []
nxt = k+1
nid = -1
fnd = set()

for i in range(n):
    x = arr[i]
    freq[x] -= 1
    if x not in fnd:
        if x < nxt:
            nxt, nid = x, i

    if x not in fnd and freq[x] <= 0:
        for j in range(nid, i+1):
            if j == i or arr[j] < arr[i]:
                ans.append(arr[j])
                fnd.add(arr[j])
        nxt = k+1
        nid = -1

for i in ans: print(i, end=" ")
print()