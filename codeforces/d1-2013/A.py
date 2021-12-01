t = int(input())

for i in range(t):
    n, d = map(int, input().split(" "))
    ans = 0

    for j in range(n):
        v, f, c = map(int, input().split(" "))
        hours_to = d / v
        hours_can = f / c
        if (hours_to <= hours_can): ans += 1        

    print(ans)
