from sys import stdin

w, h = map(int, stdin.readline().split())
p, q = map(int, stdin.readline().split())
t = int(stdin.readline())

t1 = t
if t1 < w - p:
    p += t1
else:
    t1 -= w - p
    N = t1 // w
    r = t1 % w
    if N % 2 == 0:
        p = w - r
    else:
        p = r

t2 = t
if t2 < h - q:
    q += t2
else:
    t2 -= h - q
    N = t2 // h
    r = t2 % h
    if N % 2 == 0:
        q = h - r
    else:
        q = r

print(p, q)
