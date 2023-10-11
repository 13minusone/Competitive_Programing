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
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 1e9 , mod = 1e9 + 7;

template <class T1, class T2>
inline T1 mul(T1& x, const T2 &k){ return x = (1LL * x * k) % mod; }

template <class T>
inline void add(T &x, const T &y){ if ((x += y) >= mod) x -= mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, const T &y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, const T &y){ if (x < y){x = y; return 1;} return 0; }

template<typename T>
void read(T &x){
    char ch;
    for(ch = getchar(); !isdigit(ch); ch = getchar());
    x = ch - '0';
    for(ch = getchar(); isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
}

template<typename T>
void write(T x){
    if (x < 10){
        putchar(x + '0');
    } else {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}

#define PROB "test"
void file(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".ans","w",stdout);
    }
}
void sinh_(){
//    srand(time(0));
//    freopen(PROB".inp" , "w" , stdout);
//    int n;
}
typedef long long ll;
const int N = 5e5 + 5;

int n , dp[N], color[N] , root;
vi adj[N];
set<int> unvis;

void readip(){
    cin >> n;
    REP(i, 2, n){
        int u , v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    REP(i, 1, n) color[i] = 0 , unvis.insert(i);
}

void dfs_tree(int u , int p){
    dp[u] = u;
    for (int &v : adj[u]) if (v != p && !color[v]){
        dfs_tree(v , u);
        dp[u] = min(dp[u] , dp[v]);
    }
}

void dfs_color(int u, int p, int c){
    color[u] = c , unvis.erase(u);

    int min1 = -1, min2 = -1, val1 = INF , val2 = INF;
    for (int &v : adj[u]) if (v != p && !color[v]) {
        if (dp[v] < val1){
            min2 = min1;
            val2 = val1;

            min1 = v;
            val1 = dp[v];
        }
        else if (dp[v] < val2){
            min2 = v;
            val2 = dp[v];
        }
    }

    if (min1 != -1) dfs_color(min1, u, c);
    if (u == root) if (min2 != -1) dfs_color(min2, u, c);
}

void solve(){
    int cnt = 0;
    while(!unvis.empty()){
        int u = *unvis.begin();
        root = u;
        dfs_tree(u , -1);
        dfs_color(u, -1, ++cnt);
    }
    REP(i, 1, n) cout << color[i] << ' ';
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
