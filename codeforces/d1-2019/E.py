import pprint

s = input()
bits = {}
count = {}
mod = 11092019
n = len(s)

for i in range(n):
    count[s[i]] = 0
    bits[s[i]] = 2**n - 1

for i in range(n):
    count[s[i]] += 1
    bits[s[i]] = bits[s[i]] ^ (2 ** (n-1-i))

ans = 2 ** n
ans2 = 0

pprint.pprint(bits)
pprint.pprint(count)

for c in bits:
    if count[c] > 1:
        ans -= bits[c]
    else:
        ans2 += bits[c]

print(ans, ans2)
