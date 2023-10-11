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

const int N = 1e3 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, q, a[N][N];
ii r[N][N], d[N][N];
ii trace(int a, int b)
{
    ii y = ii(0, b);
    while(a--)
        y = d[y.fi][y.se];
    return y;
}
void init(void)
{
    cin >> n >> m >> q;
    FOR(i,1,n)
        FOR(j,1,m)
            cin >> a[i][j];
    FOR(i,0,n)
        FOR(j,0,m){
            r[i][j] = ii(i,j + 1);
            d[i][j] = ii(i + 1,j);
        }
}
void process(void)
{
    while(q--)
    {
        register int a, b, c, de, h, w;
        cin >> a >> b >> c >> de >> h >> w;
        //swap left right
        ii x = trace(a,b-1), y = trace(c,de-1), x1 = trace(a,b + w - 1), y1 = trace(c,de + w - 1);
        FOR(i,1,h)
        {
            swap(r[x.fi][x.se], r[y.fi][y.se]);
            swap(r[x1.fi][x1.se], r[y1.fi][y1.se]);
            x = d[x.fi][x.se];
            y = d[y.fi][y.se];
            x1 = d[x1.fi][x1.se];
            y1 = d[y1.fi][y1.se];
        }
//        swap top bottom
        x = trace(a-1,b), y = trace(c-1,de), x1 = trace(a + h -1, b), y1 = trace(c + h - 1, de);
        FOR(i,1,w)
        {
            swap(d[x.fi][x.se], d[y.fi][y.se]);
            swap(d[x1.fi][x1.se], d[y1.fi][y1.se]);
            x = r[x.fi][x.se];
            y = r[y.fi][y.se];
            x1 = r[x1.fi][x1.se];
            y1 = r[y1.fi][y1.se];
        }
    }
    FOR(i,1,n)
    {
        ii y = ii(i, 0);
        int x = m;
        while(x--){
            y = r[y.fi][y.se];
            cout <<a[y.fi][y.se] << " " ;
        }
        cout << endl;
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


