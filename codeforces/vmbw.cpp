// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define endl '\n'
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

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
int Bl = 488;

ll n, q, m;
ll cnt[N][2], deg[N], light[N],res[2][2];
vector<int>Big[N],Small[N];
vector<ii>edge;
void prepare()
{
    for(ii i : edge)
    {
        int u = i.fi, v = i.se;
        if(deg[v] > Bl)Big[u].pb(v);
        else if(deg[u] <= Bl)Small[u].pb(v);
        if(deg[u] > Bl)Big[v].pb(u);
        else if(deg[v] <= Bl)Small[v].pb(u);
        if(deg[u] > Bl)cnt[u][light[v]]++;
        if(deg[v] > Bl)cnt[v][light[u]]++;
        int ri = light[v], le = light[u];
        if(ri < le)swap(le,ri);
        res[le][ri]++;
    }
}
void ChangeBig(int u)
{
    for(int v : Big[u])
    {
        cnt[v][light[u]]--;
        cnt[v][1-light[u]]++;
    }
    if(light[u])
    {
        res[0][1] -= cnt[u][0];
        res[0][0] += cnt[u][0];
        res[1][1] -= cnt[u][1];
        res[0][1] += cnt[u][1];
    }
    else
    {
        res[0][0] -= cnt[u][0];
        res[0][1] += cnt[u][0];
        res[1][1] += cnt[u][1];
        res[0][1] -= cnt[u][1];
    }
    light[u] = 1-light[u];
}
void ChangeSmall(int u)
{
    for(int v : Big[u])
    {
        cnt[v][light[u]]--;
        cnt[v][1-light[u]]++;
        int le = light[u], ri = light[v];
        if(le)
        {
            res[ri][le]--;
            res[1-le][ri]++;
        }
        else
        {
            res[le][ri]--;
            res[ri][1-le]++;
        }
    }
    for(int v : Small[u])
    {
        int le = light[u], ri = light[v];
        if(le)
        {
            res[ri][le]--;
            res[1-le][ri]++;
        }
        else
        {
            res[le][ri]--;
            res[ri][1-le]++;
        }
    }
    light[u] = 1 - light[u];
}
string query;
int x,y;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    FOR(i,1,m)
    {
        cin >> x >> y;
        edge.pb(ii(x,y));
        deg[x]++,deg[y]++;
    }
    FOR(i,1,n)cin >> light[i];
    Bl = 488;
    prepare();
    cin >> q;
    while(q--)
    {
        cin >> query >> x;
        if(query == "print")
        {
            cin >> y;
            if(y < x)swap(x,y);
            cout << res[x][y] << endl ;
        }
        else
        {
            if(deg[x] > Bl)ChangeBig(x);
            else ChangeSmall(x);
        }
    }
}

