from sys import stdout, stdin
special_numbers = [4, 8, 15, 16, 23, 42]
a = []
query_answers = []
answer_factors = []

def find_factors(a):
    if (a == 64):
        return [4, 16]
    elif (a == 32):
        return [4, 8]
    elif (a == 60):
        return [4, 15]
    elif (a == 92):
        return [4, 23]
    elif (a == 168):
        return [4, 42]
    elif (a == 120):
        return [8, 15]
    elif (a == 128):
        return [8, 16]
    elif (a == 184):
        return [8, 23]
    elif (a == 336):
        return [8, 42]
    elif (a == 240):
        return [15, 16]
    elif (a == 345):
        return [15, 23]
    elif (a == 630):
        return [15, 42]
    elif (a == 368):
        return [16, 23]
    elif (a == 672):
        return [16, 42]
    elif (a == 966):
        return [23, 42]
    else:
        quit()

def query(a, b):
    print("? {} {}\n".format(a, b))
    stdout.flush()
    ans = int(input())
    return ans

def compare(a, b, c):
    first = query(a, b)
    second = query(b, c)
    f_list = find_factors(first)
    s_list = find_factors(second)
    outs = [0, 0, 0]

    for i in f_list:
        for j in s_list:
            if i == j:
                outs[1] = i
    
    for i in f_list:
        if i != outs[1]:
            outs[0] = i
    
    for i in s_list:
        if i != outs[1]:
            outs[2] = i
    
    return outs
       
first_three = compare(1, 2, 3)
last_three = compare(4, 5, 6)

print("! {} {} {} {} {} {}\n".format(first_three[0], first_three[1], first_three[2], last_three[0], last_three[1], last_three[2]))