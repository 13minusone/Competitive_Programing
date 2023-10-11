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
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1501;
const ll mod =1e9+7;
//const ll base = 311;
//const int block = 488;
int n, m,x[5001],y[5001],w[5001];
ll cnt[N][N],d[N][N];
bool check[N];
void add(ll &ans, ll b)
{
    ans += b;
    if(ans >= mod)ans-=mod;
}
ll dist[N][N];
vector<ii>edge[N],bac[N];
void tv(int u,int i)
{
    check[u]= true;
    for(ii v : edge[u])
    {
        if(dist[i][u] + v.fi == dist[i][v.se]  && !check[v.se])tv(v.se,i),add(d[i][u] ,(d[i][v.se]+1)%mod);
        else if(dist[i][u] + v.fi == dist[i][v.se])add(d[i][u] ,d[i][v.se]+1);
    }
}
void dijkstra(int x)
{
    FOR(i,1,n)dist[x][i] = mod;
    dist[x][x] = 0;
    priority_queue<ii, vector<ii>,greater<ii>>qu;
    qu.push(ii(0,x));
    while(!qu.empty())
    {
        ii u = qu.top();
        qu.pop();
        if(dist[x][u.se] < u.fi)continue;
        for(ii v : edge[u.se])
        {
            if(dist[x][u.se] + v.fi < dist[x][v.se])
            {
                cnt[x][v.se] = cnt[x][u.se];
                dist[x][v.se] = dist[x][u.se] + v.fi;
                qu.push(ii(dist[x][v.se],v.se));
            }
            else if(dist[x][u.se] + v.fi == dist[x][v.se]){
                add(cnt[x][v.se],cnt[x][u.se]);
            }
        }
    }
    memset(check,false,sizeof check);
    tv(x,x);
    d[x][x] = 0;
}
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
        cin >> x[i] >> y[i] >> w[i];
        edge[x[i]].pb(ii(w[i],y[i]));
        bac[y[i]].pb(ii(w[i],x[i]));
    }
    FOR(i,1,n)
    {
        cnt[i][i] =1;
        dijkstra(i);
//        FOR(j,1,n)cout << dist[i][j] << " " ;
//        cout << endl;
    }
    FOR(i,1,m)
    {
        ll ans = 0;
        FOR(j,1,n)
        {
            if(dist[j][x[i]] + w[i] == dist[j][y[i]])
            {
                //cout << i << " " << j << " " << cnt[j][x[i]] << " "<< d[j][y[i]] << endl;
                add(ans, ((cnt[j][x[i]]%mod) * ((d[j][y[i]]+1)%mod))%mod);
            }
        }
        cout << ans << endl;
    }
}



