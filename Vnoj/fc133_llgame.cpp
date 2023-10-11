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

const int N = 1e3 + 5;
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, a[N];
int Fact[N], IFact[N], sum = 0;
int F[N][N/2];
int powe(int a, int b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    int t = powe(a, b/2) %MOD;
    if(b&1)return 1LL * (1LL * t * t)%MOD * a %MOD;
    else return (1LL * t * t)%MOD;
}
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n){
        cin >> a[i];
        a[i] = abs(a[i]);
        sum += a[i];
    }
}
int C(int k, int n)
{
    if(k > n)return 0;
    return 1LL * Fact[n] * (1LL * IFact[n - k] * IFact[k] % MOD) %MOD;
}
void add(int &a, const int &b)
{
    a += b;
    while(a >= MOD)
        a -= MOD;
}
void process(void)
{
    Fact[0] = 1;
    FOR(i,1,1000)Fact[i] = 1LL * Fact[i - 1] * i %MOD;
    IFact[1000] = powe(Fact[1000], MOD - 2);
    FD(i,999,0)IFact[i] = 1LL *IFact[i + 1] * (i + 1)%MOD;

    int res;;
    if(n == 1){
        int x = k - a[1];
        res = 0;
        if(x &1)
            x--;
       // cout << C(3,8) << endl;
        for(int i = 0; i <= x; i += 2){
            add(res,1LL * C(a[1] + i / 2,a[1] +  i)* C(a[1] + i, k) %MOD);
        }
    }
    else{
        F[0][0] = 1;
        FOR(i,1,n)
        {
            FOR(j, 0, k/2)
                FOR(o,0,j)
                {
                    int op = 1LL * F[i - 1][j  - o] * C(a[i] + o, a[i] + 2  * o) % MOD;
                    op = 1LL * op * IFact[a[i] + 2 * o] % MOD;
                    add(F[i][j], op);
                }
        }
        res = 0;
       // cout << C(3,8) << endl;
        for(int i = sum; i <= k; i += 2){
            int o = 1LL * C(i, k) * F[n][(i - sum) / 2] %MOD;
            o = 1LL * o * Fact[i] % MOD;
            add(res, o);
        }
    }
    cout << res;
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

