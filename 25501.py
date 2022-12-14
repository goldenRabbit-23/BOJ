from sys import stdin

T = int(stdin.readline())


def run_case():
    S = stdin.readline().strip()
    flag = True
    left = 0
    right = len(S) - 1
    ans = 0

    while left <= right:
        ans += 1

        if S[left] != S[right]:
            flag = False
            break

        left += 1
        right -= 1

    print(1 if flag else 0, ans + 1 if flag and len(S) % 2 == 0 else ans)


for _ in range(T):
    run_case()
