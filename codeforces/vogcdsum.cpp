// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e5 + 5;
const ll mod =1e9+7;
//const ll base = 311;
//const int bl = 488;

int n;
ll Gcd[N][25];
ll get(int u,int v)
{
    int LOG = __lg(v-u+1);
    return __gcd(Gcd[u][LOG],Gcd[v - (1 << (LOG))+1][LOG]);
}
int findd(ll val,int pos, int i)
{
    int r = n ,ans = pos;
    while(pos <= r)
    {
        int mid = (r+pos)/2;
        if(get(i,mid) == val){
            ans = mid;
            pos = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
void add(ll &a, ll x)
{
    a+=x;
    if(a >= mod)a-=mod;
    return ;
}
ll x;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    FOR(i,1,n)
    {
        cin >> x;
        Gcd[i][0] = x;
    }
    int Log = __lg(n)+1;
    FOR(i,1,Log)
        FOR(j,1,n - (1 << i)+1)
            Gcd[j][i] = __gcd(Gcd[j][i-1], Gcd[j +(1LL << (i-1))][i-1]);
    ll res =0;
    FOR(i,1,n)
    {
        int pos = i;
        while(pos <= n)
        {
            int old = pos;
            ll val = get(i,old);
            pos = findd(val,pos,i);
            ll cong =  (((pos-old+1)%mod) * (val%mod))%mod;
            add(res,cong);
            pos++;
        }
    }
    cout << res;
}
