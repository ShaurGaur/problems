line_count = int(input())

char_counts = []
numbers = []

for i in range(line_count):
    char_counts.append(int(input()))
    numbers.append(input())

# for i in range(len(char_counts)):
#     if (char_counts[i] < 11):
#         print("NO")
#     elif (char_counts[i] == 11):
#         if (int(numbers[i][0]) != 8):
#             print("NO")
#     else:
#         for j in range(char_counts[i] - 10):
#             invalid = True
#             if (int(numbers[i][j]) == 8):
#                 invalid = False
#                 break
#         if (invalid):
#             print("NO")
#         else:
#             print("YES")

for i in range(len(char_counts)):
    valid = False
    for j in range(len(numbers[i])):
        if (int(numbers[i][j]) == 8):
            if (len(numbers[i]) - j >= 11):
                valid = True
    if (valid):
        print("YES")
    else:
        print("NO")


        
                    
    