#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define MASK(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 20
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FU(i, a, b) for(int i=a; i<=b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, x) for(int i=0; i<x; i++)
const int MAX = 5e2 + 5, VAL = 1e5 + 5;
const int mod = 1e9 + 7;
const int base = 31;
const int INF = 1e9 + 7;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
template<class X, class Y> bool maximize(X &x, Y y){ if (x < y) {x = y; return true;} return false;};
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y) {x = y; return true;} return false;};
void add(int &x, int y) { x += y; if (x>=mod) x-=mod;}
void sub(int &x, int y) { x -= y; if (x<0) x+=mod;}
int calPw(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if (y&1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
int n, m, q;
int a[MAX][MAX], mx[2][MAX][MAX], mn[2][MAX][MAX], dp[MAX][VAL];
// mx[0][i][j] = max(a[i][j] -> a[i + k-1][j + k-1];
// mn[0][i][j] = min(a[i][j] -> a[i + k-1][j + k-1];
// dp[i][j] = k la hcn co do dai la i co max la j va min >= k
void read()
{
   cin >> n >> m >> q;
   FU(i, 1, n) FU(j, 1, m) cin >> a[i][j];
}
void calDp()
{
   FU(i, 1, n) FU(j, 1, m)
   {
      mx[0][i][j] = mn[0][i][j] = a[i][j];
      maximize(dp[1][a[i][j]], a[i][j]);
   }
   FU(i, 1, VAL-5) maximize(dp[1][i], dp[1][i-1]);
   FU(k, 2, min(n, m))
   {
      FU(i, 1, n-k+1) FU(j, 1, m-k+1)
      {
         mx[1][i][j] = max({mx[0][i][j], mx[0][i+1][j], mx[0][i][j+1], mx[0][i+1][j+1]});
         mn[1][i][j] = min({mn[0][i][j], mn[0][i+1][j], mn[0][i][j+1], mn[0][i+1][j+1]});
         // tinh tien tu tu len
         maximize(dp[k][mx[1][i][j]], mn[1][i][j]);
      }
      FU(i, 1, n-k+1) FU(j, 1, m-k+1)
      {
         mx[0][i][j] = mx[1][i][j];
         mn[0][i][j] = mn[1][i][j];
         //day tu k len k+1
      }
      FU(i, 1, VAL-5) maximize(dp[k][i], dp[k][i-1]);
      // cap nhat dp[k][i-1] len dp[k][i];
   }
}
void sol()
{
   calDp();
   while(q--)
   {
      int l, r; cin >> l >> r;
      bool ok = false;
      FD(i, min(n, m), 1) if (dp[i][r] >= l)
      {
         cout << i * i, EL;
         ok = true;
         break;
      }
      if (!ok) cout << 0, EL;
   }
}
signed main()
{
    fastio();
    init();
    int T = 1;
    //cin >> T;
    while(T--)
    {
        read();
        sol();
    }
}
