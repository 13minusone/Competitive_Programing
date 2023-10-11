// Author : Nyanpasuuuuu
#include<bits/stdc++.h>
using namespace std;
#define task "test"
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, a[N];
ii f[(1 << 21)];
void add(ii &a, int b)
{
    if(a.fi < b){
        a.se = a.fi;
        a.fi = b;
    }
    else maximize(a.se, b);
}
void init(void)
{
    cin >> n;
    FOR(i,1,n){
        cin >> a[i];
        add(f[a[i]], i);
    }
}
void process(void)
{
     FOR(i,0,20)
        FOR(j,0,(1 << 21) - 1)
            if(getbit(j,i))
            {
                add(f[j ^ (1 << i)], f[j].fi);
                add(f[j ^ (1 << i)], f[j].se);
            }
    int ans = 0;
   // cout << f[4].fi << " " << f[4].se << endl;
    FOR(i,1,n)
    {
        int cur = (1 << 21) - 1 - a[i], opt = 0;
        FD(j,20,0)if(getbit(cur, j))
        {
            if(f[opt ^ (1 << j)].se > i){
                opt ^= (1 << j);
            }
        }
        if(f[opt].se > i)maximize(ans, a[i] |opt);
    }
    cout << ans << endl;
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
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
