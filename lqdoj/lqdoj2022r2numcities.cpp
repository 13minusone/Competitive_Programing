// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "NUMCITIES"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;

int n;
ll ans = 0, pre[N];
ll powe(int a, int b)
{
    if(b == 0)return 1;
    ll t = powe(a,b/2) % MOD;
    if(b&1)return 1LL * ((1LL * t * t)%MOD) * a %MOD;
    else return (1LL * t * t %MOD);
}
void add(ll &a, ll b)
{
    a += b;
    while(a >= MOD)
        a-=MOD;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    pre[0] = 0;
    FOR(i,1,10)
    {
        pre[i] = pre[i-1];
        add(pre[i], powe(i,MOD-2));
       // cout << pre[i] << endl;
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        if(n > int(1e4))
        {
            FOR(i,0,n)
            {
                add(ans, 1LL *(n - i +MOD)%MOD*(( pre[n] + pre[0] + MOD)%MOD)%MOD);
                add(ans,1);
            }
        }
        else
        {
            FOR(i,0,n)
            {
                add(ans,1);
                    FOR(j,1,n-i)
                    add(ans, int((n - i)/j));
            }
        }
        cout << ans << endl;
    }

}
