/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "ball"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

struct Points
{
    ll x, y;
    void read()
    {
        cin >> x >> y;
    }
    Points(ll _x = 0, ll _y = 0)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const Points &b) const
    {
        return (make_pair(x, y) < make_pair(b.x, b.y));
    }
    Points operator-(const Points &b) const
    {
        return Points(x - b.x, y - b.y);
    }
    ll operator*(const Points &b) const
    {
        return x * b.y - y * b.x;
    }
    ll triangle(const Points &b, const Points &c) const
    {
        return (*this - b) * (*this - c);
    }
    ll dist(const Points &other)
    {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
};
const int N = 1505;
const ll INF = 1e18;
int n, d[N];
Points points[N];
vec<vec<int>> adj(N);
void init()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        points[i].read();
}
void process(const int &tc)
{
    for(int i = 1; i <= n; i++)
    {
        vec<pair<ll, int>> p;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            p.pb(mp(points[i].dist(points[j]), j));
        }
        //cout << points[i].x << " " << points[j].y << '\n';
        sort(SZ(p));
        set<ii> vis;
        for(auto &tmp : p)
        {
            Points tPoint = points[tmp.se];
            tPoint.x -= points[i].x;
            tPoint.y -= points[i].y;
            int g = __gcd(tPoint.x, tPoint.y);
            tPoint.x /= g;
            tPoint.y /= g;
            if(vis.find(ii(tPoint.x, tPoint.y)) == vis.end())
            {
                vis.insert(ii(tPoint.x, tPoint.y));
                adj[i].pb(tmp.se);
                adj[tmp.se].pb(i);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(d, -1, sizeof(d));
        queue<int> q;
        d[i] = 0;
        q.push(i);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(d[u] == 2)
                continue;
            for(int v : adj[u])
                if(d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
                }
        for(int j = 1; j <= n; j++)
            res += d[j];
    }
    cout << res;
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
