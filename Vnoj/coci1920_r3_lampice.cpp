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

const int N = 5e4+ 5;
//const ll MOD =1e17+9;
const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
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

int n, sz[N], cnt = 0, par[N][17],h[N],ans = 1, LOG = 16, id[N], sta[N], fin[N];
int HashD[N], HashU[N], Powe[N], val[N];
string s;
char c[N];
vector<int>edge[N];
bool vis[N];
void getSZ(int u, int pre)
{
    if(vis[u]){
        sz[u] = 0;
        return;
    }
    sz[u] = 1;
    for(int &v : edge[u])if(v != pre && !vis[v])
    {
        getSZ(v, u);
        sz[u] +=sz[v];
    }
}
int getCentroid(int u, int Sizetree, int p)
{
    for(int &v : edge[u])
        if(v != p && !vis[v] && sz[v] * 2 > Sizetree)
            return getCentroid(v,Sizetree, u);
    return u;
}
void CreateCentroid(int u, int pre)
{
    getSZ(u, -1);
    u = getCentroid(u,sz[u] , -1);
    vis[u] = 1;
    id[++cnt] = u;
    sta[u] = cnt;
    for(int &v : edge[u])if(v!= pre && !vis[v])
        CreateCentroid(v, u);
    fin[u] = cnt;
}
void DfsH(int u, int pre)
{
    FOR(i,1,LOG)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for(int &v : edge[u])if(v != pre && !vis[u])
    {
        h[v] = h[u] + 1;
        par[v][0] = u;
        HashU[v] = HashU[u] * base + c[v];
        HashD[v] = HashD[u] + c[v] * Powe[h[v]];
        DfsH(v, u);
    }
}
int findPar(int u, int d)
{
    FD(i,LOG,0)
    {
        if(d >= (1 << i))
        {
            d -= (1 << i);
            u = par[u][i];
        }
    }
    return u;
}
bool Cost(int u,int len,int &res)
{
    if(h[u] >= len)
        return 0;
    int Dist = min(h[u], len - 1 - h[u]);
    int x = findPar(u,Dist);
    if(HashU[x] != HashD[x])
        return 0;
    res = HashU[u] - HashU[x] * Powe[Dist];
    return 1;
}
bool check(int len)
{
    set<ii>S;
    memset(vis,0, n + 1);
    FOR(i,1,cnt)
    {
        int root = id[i];
        HashU[root] = HashD[root] = c[root];
        par[root][0] = root;
        h[root] = 0;
        DfsH(root, -1);
        S.clear();
        S.insert(ii(0,0));
        int u;
        FOR(l,sta[root] + 1, fin[root])
        {
            int r = fin[id[l]];

            FOR(j,l,r)
            {
                u = id[j];
                val[u] = -1;
                if(!Cost(u,len, val[u]))
                    continue;
                if(S.find(ii(len - h[u] - 1, val[u])) != S.end())
                    return 1;
            }
            FOR(j,l,r)
            {
                u = id[j];
                if(val[u] == -1)
                    continue;
                S.insert(ii(h[u], val[u]));
            }
            l = r;
        }
        vis[root] = 1;
    }

    return 0;
}
void init(void)
{
    read(n);
    cin >> s;
    REP(i,0,SZ(s))
        c[i + 1] = s[i];
    FOR(i,1,n-1)
    {
        int u, v;
        read(u);
        read(v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
}
void process(void)
{
    Powe[0] = 1;
    FOR(i,1,n)Powe[i] = Powe[i - 1] * base;
    CreateCentroid(1,-1);
    int l = 1, r = n/2;
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        //cout << mid << endl;
        if(check(2 * mid + 1))
        {
            maximize(ans, 2 * mid + 1);
            l = mid  + 1;
        }
        else r = mid - 1;
    }
    l = 1, r = n/2;
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        //cout << mid << endl;
        if(2 * r <= ans)break;
        if(check(2 * mid))
        {
            maximize(ans, 2 * mid);
            l = mid  + 1;
        }
        else r = mid - 1;
    }
   write(ans);
}
signed main()
{
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
