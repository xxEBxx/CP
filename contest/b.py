t = int(input())

def ppalindrom(d):
    sum=0
    for i in d:
        sum+=d[i]
    if sum%2==0:
        for i in d:
            if d[i]%2==1:
                return 0
        return 1
    return 0
def ipalindrom(d):
    imp=0
    sum=0
    for i in d:
        sum+=d[i]
    if sum%2==1:
        for i in d:
            if d[i] % 2 != 0:
                if imp == 0:
                    imp = 1
                else:
                    return 0
        return 1
    return 0

def palindrom(d):
    return ppalindrom(d) or ipalindrom(d)

def pal(d, k):
    while not palindrom(d) and k>0:
        for i in d:
            if d[i]%2==1:
                d[i]-=1
                k-=1
                break
    
    if ipalindrom(d) and k>=0:
            return 1
    elif ppalindrom(d) and k>=0 and k%2==0:
        return 1
    return 0

for i in range(t):
    n, k = map(int, input().split())  # Read both n and k in the same line
    dic = {}
    s = input()
    for c in s:
        if c not in dic.keys():
            dic[c] = 1
        else:
            dic[c] += 1
    if pal(dic, k):
        print("Yes")
    else:
        print("No")
