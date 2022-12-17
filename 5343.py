from sys import stdin

n = int(stdin.readline().strip())

for _ in range(n):
    ans = 0
    data = stdin.readline().strip()
    parts = [data[i*8:i*8+8] for i in range(len(data) // 8)]
    for part in parts:
        ones = part[:-1].count('1')
        if (ones % 2 == 0 and part[-1] == '1') or (ones % 2 == 1 and part[-1] == '0'):
            ans += 1

    print(ans)
