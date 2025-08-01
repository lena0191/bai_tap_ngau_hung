import math
from collections import defaultdict

n, m = map(int, input().split())
a = list(map(int, input().split()))

dem = defaultdict(int)
for x in a:
    dem[math.gcd(x, m)] += 1

b = []
for i in range(1, int(m ** 0.5) + 1):
    if m % i == 0:
        b.append(i)
        if i * i != m:
            b.append(m // i)

tong = 0
b.sort()
for i in range(len(b)):
    for j in range(i, len(b)):
        if (b[i] % m) * (b[j] % m) % m == 0:
            if i == j:
                tong += dem[b[i]] * (dem[b[i]] + 1) // 2
            else:
                tong += dem[b[i]] * dem[b[j]]

print(tong)
