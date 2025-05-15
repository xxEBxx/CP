o=int(input())

for i in range(o):
    l= list(map(int, input().split()))
    n,k=l[0],l[1]
    asci=ord('a')
    s=""
    final=""
    for i in range(k):
        s+=chr(asci)
        asci+=1
    final=s*n
    print(final)


