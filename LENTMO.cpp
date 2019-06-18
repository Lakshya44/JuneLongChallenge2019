#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define show(x) cout<<x<<'\n'
#define showh(x) cout<<x<<' '
#define go(i,a,n) for(ll i=a;i<n;i++)
#define gor(i,a,n) for(ll i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
bool prime[100001];

bool ispoweroftwo(ll x)
{
    return x && !(x & (x-1));
}
ll xorcal(ll n)
{
    if(n%4==0)
        return n;
    if(n%4==1)
        return 1;
    if(n%4==2)
        return n+1;
    if(n%4==3)
        return 0;
}
void sieve(ll n)
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    show(prime[89]);
}
bool isprime(ll n)
{
    if (n<=1) return false;
    if (n<=3) return true;

    if(n%2==0 or n%3==0) return false;

    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0 or n%(i+2)==0) return false;
    }
    return true;
}

ll modinverse(ll a,ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;

        m = a % m; a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
       x += m0;

    return x;
}

ll gcd(ll a,ll b)
{
    if(a==0)
    {
        return b;
    }
    return(b%a,a);
}

ll power(ll A, ll B)
{
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    ll y;
    if (B % 2 == 0) {
        y = power(A, B / 2);
        y = (y * y) % mod;
    }

    else {
        y = A % mod;
        y = (y * power(A, B - 1) % mod) % mod;
    }

    return (ll)((y + mod) % mod);
}
ll max_sum(vector<ll>v)
{
    ll sum=0;
    go(i,0,(ll)v.size())
    {
        sum+=v[i];
    }
    return sum;
}
bool cmp(const pair<ll,ll> &a , const pair<ll,ll> &b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,init_sum=0,count0=0,count1=0,sum=0,k,x;
        cin>>n;
        ll a[n];
        go(i,0,n)
        {
            cin>>a[i];
            init_sum+=a[i];
        }
        cin>>k>>x;
        vector<ll>gre,sma;
        go(i,0,n)
        {
            if((a[i] ^ x) > a[i])
            {
                count0++;
                gre.pb((a[i] ^ x));
            }
            else
            {
                count1++;
                sma.pb(a[i]);
            }
        }
        if(x==0 or count1==n)
        {
            show(init_sum);
            continue;
        }
        if(n==k)
        {
            go(i,0,n)
            {
                sum+=(a[i]^x);
            }
            show(max(sum,init_sum));
            continue;
        }
        if(count0%k==0 or (k & 1))
        {
            show(max_sum(gre)+max_sum(sma));
            continue;
        }
        if(k%2==0)
        {
            if(count0%2==0)
            {
                show(max_sum(gre)+max_sum(sma));
            }
            else
            {
                vector<pair<ll,ll>>v;
                go(i,0,n)
                {
                    ll j=abs( ( a[i] ^ x) - a[i] );
                    v.pb(make_pair(j,a[i]));
                }
                sort(v.begin(),v.end(),cmp);
                go(i,0,(ll)gre.size())
                {
                    if((gre[i] ^ x)==v[0].second)
                    {
                        sum += (gre[i] ^ x);
                        v[0].second=-1;
                    }
                    else
                    {
                        sum += gre[i];
                    }
                }
                go(i,0,(ll)sma.size())
                {
                    if(sma[i]==v[0].second)
                    {
                        sum += (sma[i] ^ x);
                        v[0].second=-1;
                    }
                    else
                    {
                        sum += sma[i];
                    }
                }
                show(sum);
            }
            continue;
        }
    }
    return 0;

}
