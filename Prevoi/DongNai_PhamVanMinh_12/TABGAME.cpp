// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "TABGAME"
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e1 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, r[5], c[5], a[5], b[105], Row[105][105], Col[105][105], d[105][105];
ii id[N * N];
ll ans = 0;
void init(void)
{
    cin >> n >> m;
    FOR(i,1,5)
        cin >> r[i];
    FOR(i,1,5)
        cin >> c[i];
    FOR(i,1,n)
        FOR(j,1,n)
            id[(i - 1) * n + j] = ii(i, j);
    FOR(i,1,5){
        cin >> a[i];
        int x = a[i];
        d[id[x].fi][id[x].se] = 1;
        //cout << d[id[x].fi][id[x].se] << endl;
    }
    FOR(i,1,m)
        cin >> b[i];
}
void solve(int o, ll sum = 0)
{
    if(o == m + 1)
    {
        maximize(ans, sum);
        return;
    }
    FOR(i,1,5)
    {
        int x = a[i];
        d[id[x].fi][id[x].se] = 0;
        d[id[b[o]].fi][id[b[o]].se] = 1;
        a[i] = b[o];
        //cout << id[b[o]].fi << " " << id[b[o]].fi << endl;
        FOR(p,1,n){
            FOR(l,1,n){
                Row[p][l] = Row[p][l - 1] + d[p][l];
                Col[l][p] = Col[l][p - 1] + d[p][l];
            }
        }
        int maxRow = 0, maxCol = 0;
        FOR(j,1,n){
            maximize(maxRow, Row[j][n]);
            maximize(maxCol, Col[j][n]);
        }
        //if(o == 1 && i == 3)cout << maxRow << " " <<maxCol << endl;
        //if(o == 2 && i == 5)cout << maxRow << " " <<maxCol << endl;
        solve(o + 1, sum + r[maxRow] + c[maxCol]);
        a[i] = x;
        d[id[x].fi][id[x].se] = 1;
        d[id[b[o]].fi][id[b[o]].se] = 0;
    }
}
void process(void)
{
    solve(1,0);
    cout << ans << endl;
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


