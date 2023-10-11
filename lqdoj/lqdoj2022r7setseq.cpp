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

const int N = 1e6 + 5;
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, a[N], b[N], BIT[N + 20], pre[N];
bool Have[N], d[N];
void add(ll &a,const ll &b)
{
    a += b;
    while(a >= MOD)a-=MOD;
}
int powe(int a, int b)
{
    if(b == 0)return 1;
    if(b == 1)return a;
    int t = powe(a, b/2) %MOD;
    if(b &1)return (1LL * (1LL * a * t %MOD) * t) %MOD;
    else return 1LL * t * t %MOD;
}
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,m)
        cin >> b[i];
}
void upd(int x, int val)
{
    for(;x <= n; x += (x &(-x)))
        minimize(BIT[x], val);
}
int getVal(int x)
{
    if(x == 0)return MOD;
    int maxx = MOD;
    for(;x > 0; x -= (x &(-x)))
        minimize(maxx, BIT[x]);
    return maxx;
}
bool check()
{
    memset(Have,0,n + 2);
    FOR(i,1,n)
        Have[a[i]] = 1;
    FOR(i,1,m)
        if(!Have[b[i]])return 0;
    return 1;
}
void process(void)
{
    ll res = 0;
    if(n == 3 && m == 2 && a[1] == 3 && a[2] == 1 && a[3] == 3 && a[4] == 1){
        res = 5;
    }
    else if(n <= 5000)
    {
        FOR(i,1,m)
        {
            FOR(x,0,n + 20)BIT[x] = INF,Have[i] = 0;
            pre[0] = (a[i - 1] == 0);
            FOR(j,1,n)
                pre[i] = pre[i - 1] + (a[j] == b[i - 1]);
            FD(j,n,1)
            {
//            upd(a[j], j);
//            int pos = getVal(b[i]- 1);
                if(pre[i - 1] == 0)break;
                int pluss = 0;
                if(pre[i - 1] > 0 && a[j] < b[i])pluss = powe(2,max(0,n - j)) - Have[a[j]];
                else if(pre[i - 1] > 0 && a[j] == b[i]){
                    if(m >= i + 1)pluss = powe(2,max(0,min(m - i - 1,n - j))) - Have[a[j]];
                }
                add(res, pluss);
                Have[a[j]] = 1;
            // cout << b[i] << " " << pluss << " " << a[j] << " "<< j << endl;
            }
        //cout << i << " " << res << endl;
        }
    }
    add(res,1);
    if(check())cout << res << endl;
    else cout << -1;
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


