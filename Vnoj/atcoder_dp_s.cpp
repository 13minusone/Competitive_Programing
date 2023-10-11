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
//const int INF = 1e9 + 7;
string s;
int d;
int dp[10002][101][2];
void add(int &a, const int &b)
{
    a += b;
    while(a >= MOD)a -= MOD;
}
vector<int>c;
int solve(int pos, int du, bool tight)
{
    if(pos == SZ(c))
    {
        if(du == 0)
            return 1;
        else return 0;
    }
    if(dp[pos][du][tight] != -1)return dp[pos][du][tight];
    int &res = dp[pos][du][tight], limit = (tight ? c[pos] : 9);
    res = 0;
    for(int i = 0; i <= limit; i++)
        add(res, solve(pos + 1, (du + i) % d, tight * (i == limit)));
   // cout << pos << " " << du << " " << tight << " " << res << endl;
    return res;
}
void init(void)
{
    cin >> s;
    cin >> d;
    for(char ch : s)
        c.push_back(int(ch - '0'));
}
void process(void)
{
    memset(dp,-1,sizeof dp);
    cout << (solve(0,0,1) - 1 + MOD)%MOD << endl;
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


