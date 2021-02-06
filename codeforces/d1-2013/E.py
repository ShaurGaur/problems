import pprint as pp
import queue

grid = []
t = int(input())

for q in range(t):
    pq = queue.PriorityQueue()
    k, w, h = map(int, input().split(" "))
    classes = {}
    grid = [[] for i in range(h)]

    for i in range(k):
        line = input()
        classes[line[0]] = int(line[2:])
    
    ei, ej = -1, -1
    for i in range(h):
        line = input().strip('\r')
        for j in range(len(line)):
            if (line[j] == 'E'):
                ei, ej = i, j
                grid[i].append(0)
            else:
                grid[i].append(classes[line[j]])
    
    pq.put((0, ei, ej))
    c = -1
    while not pq.empty():
        (c, i, j) = pq.get()
        if i == 0 or j == 0 or i == h-1 or j == w-1:
            break
        
        neighbors = [(i+1, j), (i, j+1), (i-1, j), (i, j-1)]
        for ni, nj in neighbors:
            if not (ni < 0 or nj < 0 or ni >= h or nj >= w):
                pq.put((c + grid[ni][nj], ni, nj))

    pq.queue.clear()
    print(c)
    


