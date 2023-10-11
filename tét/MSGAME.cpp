#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MASK(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 14
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FU(i, a, b) for(int i=a; i<=b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, x) for(int i=0; i<x; i++)
#define REPD(i, x) for(int i=x-1; i>=0; i--)
const int MAX = 1e4 + 5;
const int mod = 1e9 + 7;
const int base = 31;
const ll INF = 1e18 + 7;
typedef pair<int, int> ii;

#define task "test"
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    else if (fopen(task".in", "r"))
    {
       freopen(task".in", "r", stdin);
       freopen(task".out", "w", stdout);
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
int mul(int x, int y) {return 1LL * x * y % mod;}
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
int n, k;
int a[MAX], f[MAX][LOG+2], g[MAX][LOG+2], pos[MAX];
void read()
{
   cin >> n >> k;
   FU(i, 1, n) cin >> a[i];
}
int getMax(int l, int r)
{
   int d = log2(r - l + 1);
   return max(f[l][d], f[r-MASK(d)+1][d]);
}
int getMin(int l, int r)
{
   int d = log2(r - l + 1);
   return min(g[l][d], g[r-MASK(d)+1][d]);
}
void sub1()
{
   ll ans = INF;
   REP(mask, MASK(n)) if (CNTBIT(mask) == k)
   {
      ll res = 0;
      vector<int> trace;
      FU(i, 1, n) if (GETBIT(mask, i-1)) trace.pb(i);
      FU(i, 0, k-1) FU(j, i, k-1) res += getMax(trace[i], trace[j]);
      ans = min(ans, res);
   }
   cout << ans;
}
int findPos(int l, int r, int val)
{
   int p = l, ans = l;
   while(l <= r)
   {
      int mid = (l + r) >> 1;
      if (getMin(p, mid) <= val)
      {
         ans = mid;
         r = mid - 1;
      }
      else l = mid + 1;
   }
   return ans;
}
void sub2()
{
   deque<int> dq;
   FD(i, n, 1)
   {
      while(SZ(dq) && a[dq.back()] <= a[i]) dq.pop_back();
      if (SZ(dq)) pos[i] = dq.front() - 1;
      else pos[i] = n;
      dq.pb(i);
   }
   //FU(i, 1, n) cout << pos[i] << " "; EL;
   ll ans = INF;
   FU(i, 1, n-2)
   {
      int mx = a[i], p = i;
      FU(j, i+1, n-1)
      {
         if (maximize(mx, a[j])) p = j;
         ll res = a[i] + a[j] + mx;
         if (pos[p] > j)
         {
            int mn = getMin(j+1, pos[p]);
            int pos_mn = findPos(j+1, pos[p], mn);
            res += mn + mx + getMax(j, pos_mn);
         }
         else
         {
            int mn = getMin(j+1, pos[j+1]);
            int pos_mn = findPos(j+1, pos[j+1], mn);
            res += mn + getMax(j+1, pos_mn) + getMax(i, pos_mn);
         }
         ans = min(ans, res);
      }
   }
   cout << ans;
}
void sol()
{
   FU(i, 1, n) f[i][0] = g[i][0] = a[i];
   for(int j = 1; MASK(j) <= n; j++)
   {
      for(int i = 1; i <= n; i++)
      {
         f[i][j] = max(f[i][j-1], f[i + MASK(j-1)][j-1]);
         g[i][j] = min(g[i][j-1], g[i + MASK(j-1)][j-1]);
      }
   }
   if (n <= 20) {sub1(); return;}
   if (k == 3) {sub2(); return;}
}
signed main()
{
    fastio();
    init();
    int TEST = 1;
    //cin >> TEST;
    while(TEST--)
    {
        read();
        sol();
    }
}
