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
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
const int MOD = (int)1e9 + 19972207;
int cur = seed;
int getRandom(int n) {
    cur = (1LL * mul * cur + add) % MOD;
    return 1 + cur % n;
}
int gspvhcute(void) {
 int res = 0;
    for (int i = 1; i <= q; i++) {
    int e1 = getRandom(n – 1);
    int u1 = getRandom(n); int v1 = getRandom(n);
    int e2 = getRandom(n – 1);
    int u2 = getRandom(n); int v2 = getRandom(n);
    int tmp = e1 == e2 || u1 == v1 || u2 == v2
    ? MOD – 1 : query(e1, u1, v1, e2, u2, v2);
    res = (227LL * res + tmp) % MOD;
 }
 return res;
}
void init(void)
{
}
void process(void)
{
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


