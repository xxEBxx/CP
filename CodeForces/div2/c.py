t, c = map(int, input().split())

sums = []

for _ in range(t):
    sum_ = 0
    n = int(input())
    gain = list(map(float, input().split()))
    proba = list(map(float, input().split()))

    for i in range(n):
        sum_ += gain[i] * proba[i]

    sums.append(sum_)

max_sum = max(sums)
print(c * max_sum)
