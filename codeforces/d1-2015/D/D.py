import pprint

tri1, tri2 = [int(i) for i in input().split(" ")], [int(i) for i in input().split(" ")]
tri1.sort()
tri2.sort()

if tri1 != tri2: 
    print("NO")
else:
    a, b, c = tri1
    print("YES" if (a**2 + b**2 - c**2) == 0 else "NO")