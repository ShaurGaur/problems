import pprint
n = int(input())
people = {}
keys = {}

for i in range(n):
    name, clas = input().split(": ")
    classes = clas.split(" ")
    classes.pop()
    people[name] = classes

m = max([len(s) for s in people.values()])
for name in people.keys():
    keys[name] = ""

for name in people:
    i = 0
    while i < m:
        if i >= len(people[name]):
            keys[name] += 'b'
        elif people[name][len(people[name]) - 1 - i] == "upper":
            keys[name] += 'a'
        elif people[name][len(people[name]) - 1 - i] == "lower":
            keys[name] += 'c'
        else:
            keys[name] += 'b'
        i += 1
    
    keys[name] += name

def getkey(s): return keys[s]
names = [s for s in people.keys()]
names.sort(key=getkey)

for s in names:
    print(s)
