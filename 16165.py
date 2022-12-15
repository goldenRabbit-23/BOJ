from sys import stdin

N, M = map(int, stdin.readline().split())

teams = {}

for _ in range(N):
    team_name = stdin.readline().strip()
    team_member_cnt = int(stdin.readline().strip())
    team_members = []
    for _ in range(team_member_cnt):
        member = stdin.readline().strip()
        team_members.append(member)
    teams[team_name] = sorted(team_members)

for _ in range(M):
    name = stdin.readline().strip()
    q = int(stdin.readline().strip())

    if q == 0:
        for name_ in teams[name]:
            print(name_)
    else:
        for key in teams.keys():
            if name in teams[key]:
                print(key)
                break
