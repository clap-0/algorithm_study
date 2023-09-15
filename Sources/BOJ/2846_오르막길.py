N = int(input())
heights = list(map(int, input().split()))

max_height = 0;

start_height = heights[0]
prev_height = start_height

for i in range(N):

  if heights[i] <= prev_height:
    max_height = max(max_height, prev_height - start_height)
    start_height = heights[i]

  prev_height = heights[i]

max_height = max(max_height, prev_height - start_height)
print(max_height)
