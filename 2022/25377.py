from sys import stdin

N = int(stdin.readline().strip())

ans = int(1e9)

for _ in range(N):
    A, B = map(int, stdin.readline().split())
    if A <= B:
        ans = min(ans, B)

if ans == int(1e9):
    print('-1')
else:
    print(ans)
