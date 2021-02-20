def recurse(a, b):
    if a <= b:
        return b - a
    
    if a % 2 == 0:
        return 1 + recurse(a // 2, b)
    else:
        return 1 + recurse(a + 1, b)

a, b = map(int, input().split(" "))
print(recurse(a, b))