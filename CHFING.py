t=int(input())
while t>0:
    mod=1000000007
    n,k=[int(i) for i in input().split()]
    num_terms=(n+k-2)//(n-1)
    sum=(num_terms* ((2*(k-1))-((n-1)*(num_terms-1))))//2
    print(sum%mod)
    t-=1