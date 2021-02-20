import pprint

n = int(input())
t = [int(i) for i in input().split(" ")]
d = [[1e9 for i in range(n)] for i in range(n)]
w = [[0 for i in range(n)] for i in range(n)]

for i in range(n):
    d[i][i] = 0
    for j in range(n):
        w[i][j] = w[j][i] = 0 if i == j else (t[i] + t[j])

for i in range(n-1):
    u, v, x = map(int, input().split(" "))
    u -= 1
    v -= 1
    d[u][v] = d[v][u] = x

totalEdges = sum(range(1, n))
edgeCount = n-1

while edgeCount < totalEdges:
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i != k and i != j and d[i][k] > d[i][j] + d[j][k]:
                    d[k][i] = d[i][k] = d[i][j] + d[j][k]
                    edgeCount += 1

ans = [sum([d[i][j]*w[i][j] for j in range(n)]) for i in range(n)]
for i in ans: print(i)