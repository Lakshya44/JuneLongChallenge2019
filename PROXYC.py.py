import math
m=int(input())
while m>0:
    n=int(input())
    s=input()
    if (100*s.count('P'))//n >= 75:
        print("0")
        m-=1
        continue
    required = math.ceil(((3*n)-(4*s.count('P')))/4)
    require=required
    for i in range(2,n-2):
        if s[i]=='A':
            if required!=0:
                if (s[i+1]=='P' or s[i+2]=='P') and (s[i-1]=='P' or s[i-2]=='P'):
                    required-=1
    if required!=0:
        print("-1")
    else:
        print(require)
    m-=1