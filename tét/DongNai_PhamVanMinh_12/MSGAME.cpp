// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "MSGAME"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e4 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e14 + 7;
int n, k, a[N], b[N], d[25][25], LOG  = 13, p[N][15];
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];
}
ii f[N][4];
int getMax(int l, int r)
{
    int o = log2(r - l + 1);
    return max(p[l][o], p[r - (1 << o) + 1][o]);
}
void process(void)
{
    if(n <= 20)
    {
        FOR(i,1,n)
            FOR(j,i,n)
                d[i][j] = max(d[i][j - 1], a[j]);
            //cout << i << " " << j << " " << d[i][j] << endl;
        ll ans = INF;
        FOR(i,0,(1 << n) - 1)
        {
            int cnt = 0;
            FOR(j,1,n){
                if(getbit(i, j - 1)){
                    b[++cnt] = j;
                }
            }
            if(cnt != k)continue;
            ll res = 0;
            FOR(o,1,cnt)
                FOR(p,o,cnt)
                    res += d[b[o]][b[p]];
            minimize(ans, res);
        }
        cout << ans;
    }
    else
    {
        LOG = log2(n + 1);
        FOR(i,1,n)
            p[i][0] = a[i];
        FOR(j,1,LOG)
            FOR(i,1,n - (1 << j) + 1)
                p[i][j] = max(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
        FOR(i, 1, n)
        {
            f[i][1] = ii(a[i], -i);
            f[i][2] = f[i][3] = ii(INF, INF);
        }
        FOR(i,2,n)
        {
           FOR(j,1,i-1)
            {
                if(f[j][1].fi != INF)
                    minimize(f[i][2], ii(f[j][1].fi + getMax(j, i) + a[i], -j));
                if(f[j][2].fi != INF)
                    minimize(f[i][3], ii(getMax(j, i) + getMax(-f[j][2].se, i)+ getMax(-f[j][2].se, j) + a[i] + a[j] + a[-f[j][2].se], -j));
            }
        }
        ll ans = INF;
        FOR(i,3,n)
            minimize(ans, f[i][3].fi);
        cout << ans;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    cerr << "TIME : " << TIME << "s\n";
}


