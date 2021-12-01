def recurse(a, b):
    if a <= b: return b - a
    step = 1 + (a % 2)
    a = a + (a % 2)
    return step + recurse(a // 2, b)

a, b = map(int, input().split(" "))
print(recurse(a, b))