import sys

N = int(sys.stdin.readline())

dp = [0, 1, 1]

for i in range(3, N+1):
  dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3]

print(dp[N%3])
