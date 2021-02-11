n = int(input())
nums = [int(input()) for i in range(n)]
nums.sort()
print(min([nums[i] + nums[n-1-i] for i in range(n // 2)]))