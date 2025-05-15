n=int (input())
l= list(map(int, input().split()))
curr=1
count=0
for i in range(-1,len(l)-1) :
    if l[i+1]%curr==0:
        curr=l[i+1]
        count+=1
print(count)