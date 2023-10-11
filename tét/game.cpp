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

const int N = 5e3 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n;
ll T, F[N][N], a[N], val[N];
void init(void)
{
    cin >> n >> T;
    FOR(i,1,n) cin >> a[i];
}
void process(void)
{
    memset(F, -0x3f, sizeof(F));
    memset(val,-0x3f, sizeof(val));
    F[1][1] = a[1];
    maximize(val[1], F[1][1] + T);
    REP(i,1,n) FOR(j,1,i)
    {
        //cout << i << " " << j << " " << F[i][j] << '\n';
        if(val[j] >= 1LL * i * T)
        F[i][j] = max(F[i][j], val[j] - 1LL * i * T);
        maximize(val[j], F[i][j] + 1LL * i * T);
        if(F[i][j] + a[i + 1] >= 0)
            F[i + 1][j + 1] = max(F[i + 1][j + 1], F[i][j] + a[i + 1]);
    }
    FOR(i,1,n) if(F[n][i] >= 0)
    {
        cout << i;
        return;
    }
    cout << -1;
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

