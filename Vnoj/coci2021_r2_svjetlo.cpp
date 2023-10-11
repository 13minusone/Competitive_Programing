// Cao Quang Hung
#include<bits/stdc++.h>
using namespace std;
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
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 1e9 , mod = 1e9 + 7;

template <class T1, class T2>
inline T1 mul(T1& x, const T2 &k){ return x = (1LL * x * k) % mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, const T &y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, const T &y){ if (x < y){x = y; return 1;} return 0; }

template <class T>
inline void add(T &x , const T &y){ if ((x += y) >= mod) x -= mod; }

template <class T>
inline T product (const T &x , const T &y) { return 1LL * x * y % mod; }
#define PROB "a"
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
const int N = 5e5 + 5;

int n , a[N];
char s[N];
vi adj[N];
int cnt = 0;
void readip(){
    cin >> n;
    REP(i, 1, n) cin >> s[i], a[i] = s[i] - '0';
    REP(i, 1, n) cnt += a[i] ^ 1;
    REP(i, 2, n){
        int u , v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
}

int dp[N][3][2], g[3][2], sz[N];
void dfs_tree(int u = 1, int p = -1){
    sz[u] = a[u] ^ 1;
    FOR(i, 3) dp[u][i][a[u] ^ 1] = 1;

    for (int &v : adj[u]) if (v != p){
        dfs_tree(v, u);
        if (!sz[v]) continue;
        sz[u] += sz[v];

        FOR(i, 3) FOR(j, 2) g[i][j] = INF;

        REP(p, 0, 2) REP(q, 0, 2 - p) FOR(i, 2) FOR(j, 2)
        if (dp[u][p][i] < INF && dp[v][q][j] < INF)
        {
            int sum = dp[u][p][i] + dp[v][q][j];
            /// the path end at u
            if (q == 0){
                if (j == 0) minimize(g[p + q][i] , sum + 3);
                else minimize(g[p + q][i ^ 1] , sum + 1);
            }
            /// q == 1 && q == 2 , the path will end at v
            else if (q == 1){
                if (j == 0) minimize(g[p + q][i ^ 1], sum + 2);
                else minimize(g[p + q][i], sum);
            }
            else if (q == 2){
                if (j == 0) minimize(g[p + q][i], sum + 1);
                else minimize(g[p + q][i ^ 1], sum + 3);
            }
        }
        FOR(i, 3) FOR(j, 2) dp[u][i][j] = g[i][j];
    }
    if (sz[u] == cnt){
        cout << dp[u][2][1] << ln;
        exit(0);
    }
}

void solve(){
    REP(i, 1, n) REP(j, 0, 2) REP(k, 0, 1) dp[i][j][k] = INF;
    dfs_tree();
    cout << dp[1][2][1];
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
