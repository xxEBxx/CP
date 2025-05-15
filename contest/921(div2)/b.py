o=int(input())
for _ in range(o):
    (x,n)= tuple(map(int, input().split()))
    d=int(x/n)
    while x%d !=0 or (x- d*n) %d != 0:
        d-=1
    print(d)