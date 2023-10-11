#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long , long long>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//template <class T>
//inline void read(T& x){
//    bool Neg = false;
//    char c;
//    for (c = getchar(); c < '0'  c > '9'; c = getchar())
//        if (c == '-') Neg = !Neg;
//    x = c - '0';
//    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
//        x = x * 10 + c - '0';
//    if (Neg) x = -x;
//}
//
//template <class T>
//inline void write(T x)
//{
//    if (x < 0)
//    {
//        putchar('-'); x = -x;
//    }
//    T p = 1;
//    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
//    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
//}

const int INF = 1e9 , mod = 1e9 + 7;

template <class T1, class T2>
inline void mul(T1& x, T2 k){ x = (1LL * x * k) % mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, T y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, T y){ if (x < y){x = y; return 1;} return 0; }

#define PROB "akarui"
void file(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".out","w",stdout);
    }
}
void sinh_(){
//    srand(time(0));
//    freopen(PROB".inp" , "w" , stdout);
//    int n;
}
typedef long long ll;
const int N = 1e5 + 5;
int n, k, dp[N] , h[N] , diameter[N] , x[N];
vi adj[N];
void readip(){
    cin >> n >> k;
    REP(i, 2, n){
        int u , v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
}
/*
    x[u] : 2 paths , 1 not end at (maybe go through) u and 1 end at u
    diameter[u] : diameter of subtree u
    dp[u] : 2 paths in subtree u
    x[u]:
            x[v] + 1;
            depth[v'] + 1 + diameter[v]
            depth[v1] + depth[v2] + depth[v3] + 3
    dp[u]:
            depth[v 1 2 3 4] + 4;
            diameter[v1] + diameter[v2]
            x[v'] + 1 + depth[v] + 1
*/
void dfs_1(int u = 1, int p = -1){

    pii res2 = mp(0, 0);
    pair<pii , pii> res4 = mp(mp(0, 0), mp(0, 0));

    for (int v : adj[u]) if (v != p){
        dfs_1(v, u);

        REMAX(dp[u] , x[v] + h[u] + 1);
        REMAX(dp[u] , x[u] + h[v] + 1);

        REMAX(x[u] , x[v] + 1);
        REMAX(x[u] , h[u] + diameter[v]);
        REMAX(x[u] , h[v] + diameter[u] + 1);
        REMAX(x[u] , res4.fi.fi + res4.fi.se + res4.se.fi);

        REMAX(h[u] , h[v] + 1);
        REMAX(diameter[u] , diameter[v]);
        REMAX(diameter[u] , res4.fi.fi + res4.fi.se);

        res2 = max({res2 , mp(diameter[v] , res2.fi) , mp(res2.fi, diameter[v])});

        res4 = max({res4,
                    mp(mp(h[v] + 1, res4.fi.fi) , mp(res4.fi.se, res4.se.fi)),
                    mp(mp(res4.fi.fi, h[v] + 1) , mp(res4.fi.se, res4.se.fi)),
                    mp(mp(res4.fi.fi, res4.fi.se) , mp(h[v] + 1, res4.se.fi)),
                    mp(mp(res4.fi.fi, res4.fi.se) , mp(res4.se.fi, h[v] + 1))
                   });
        REMAX(dp[u], dp[v]);

    }
    REMAX(diameter[u] , res4.fi.fi + res4.fi.se);
    REMAX(x[u] , res4.fi.fi + res4.fi.se + res4.se.fi);

    REMAX(dp[u] , res2.fi + res2.se);
    REMAX(dp[u] , res4.fi.fi + res4.fi.se + res4.se.fi + res4.se.se);
    REMAX(dp[u] , x[u]);
}

void solve(){
    dfs_1();
    if (k == 1){
        cout << 2*(n - 1) + 1 - diameter[1];
        return;
    }
//    REP(i ,1 , n) cout << diameter[i] << ' ' << dp[i] << ln;
    cout << 2*(n - 1) + 2 - dp[1];
}

int main(){
    sinh_();
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readip();
        solve();
    }
}

