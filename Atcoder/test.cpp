// Onegai no bug
// Author : 13minusone
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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e3 + 5;
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll d[N];
int a[N][205], mx[N][205][16], n, m;
void preCal()
{
    FOR(i,1,n)
        FOR(j,1,m)
            mx[i][j][0] = a[i][j];
    FOR(k,1,14)
        FOR(j,1,m)
            FOR(i,1,n - (1 << k) + 1)
                mx[i][j][k] = max(mx[i][j][k-1], mx[i + (1 << (k - 1))][j][k-1]);
}
ll getmax(int i, int j, int t)
{
    int lg = log2(j - i + 1);
    return max(mx[i][t][lg], mx[j - (1 << lg) + 1][t][lg]);
}
ll Cost(int i, int j)
{
    ll ans = -(d[j] - d[i]);
    FOR(k,1,m)
        ans += getmax(i,j,k);
    return ans;
}
ll ans = -INF;
void DnC(int l, int r, int optl, int optr)
{
    if(l > r)return ;
    int mid = (l+r) >> 1, opt = -1;
    ll best = -INF;
    FOR(i,optl,min(mid, optr))
        if(maximize(best, Cost(i,mid)))
            opt = i;
    maximize(ans, best);
    DnC(l, mid - 1, optl, opt);
    DnC(mid + 1, r, opt, optr);
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
        cin >> n >> m;
        FOR(i,2,n){
            int x;
            cin >> x;
            d[i] = d[i-1] + x;
        }
        FOR(i,1,n)
            FOR(j,1,m)
                cin >> a[i][j];
        memset(mx,-1,sizeof mx);
        preCal();
        DnC(1,n,1,n);
        cout << ans;
    }

}

