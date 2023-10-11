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
const int N = 1e5 + 5;

struct new_graph{
    int n;
    new_graph(int _n = 0){n = _n;}

    struct edge{
        int u, v; ll w;
        edge(int _u = 0, int _v = 0, ll _w = 0){
            u = _u, v = _v , w = _w;
        }
        bool operator < (const edge &other) const{
            return w < other.w;
        }
    };

    struct Dsu{
        int par[N];
        Dsu(int _n = 0){
            REP(i, 1, _n) par[i] = i;
        }

        int root(int x){
            if (x == par[x]) return x;
            return par[x] = root(par[x]);
        }

        bool unite(int u , int v){
            u = root(u) , v = root(v);
            if (u == v) return 0;
            par[v] = u;
            return 1;
        }
    };

    vector< edge > E;
    void add_edge(int u , int v, ll w){
        E.eb(u, v, w);
    }

    ll process(){
        Dsu dsu(n);
        sort(ALL(E));
        ll res = 0;
        for (auto [x,y,w] : E)
            if (dsu.unite(x, y))
                res += w;
        return res;
    }
} G;

int n , m , k , p[N] , id[N];
int add_one = INF + 1;
vpii adj[N];

void readip(){
    cin >> n >> m;
    REP(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    cin >> k;
    REP(i, 1, k){
        cin >> p[i];
        id[p[i]] = i;
        if (p[i] == 1) add_one = 0;
        else{
            for (auto x : adj[p[i]]) if (x.fi == 1)
                minimize(add_one, x.se);
        }
    }
}

typedef pair<ll, int> state;

ll dist[N];

void solve(){
    G = new_graph(k);

    if (k == n)
    {
        REP(i, 1, n){
            for (auto it : adj[i])
                if (it.fi > i)
                    G.add_edge(i, it.fi, it.se);
        }
        cout << G.process() << ln;
        return;
    }

    REP(i, 1, k)
    {
        REP(ii, 1, n) dist[ii] = 1e18;
        priority_queue< state , vector< state > , greater < state > > q;
        q.push(mp(0 , p[i]));
        dist[p[i]] = 0;

        while(!q.empty()){
            auto [w, u] = q.top(); q.pop();
            if (w > dist[u]) continue;
            for (auto [v , d] : adj[u]){
                if (minimize(dist[v] , w + d))
                    q.push(mp(w + d, v));
            }
        }

        REP(j, i + 1, k){
            G.add_edge(i , j , dist[p[j]]);
        }
    }

    cout << G.process() + add_one;
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
