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

const int N = 4e2 + 5;
const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
int n, m, k;
ll x, y, w;
ll d[N][N];
ll dist[N][N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> k;
    memset(dist,0x3f, sizeof dist);
    FOR(i,1,m)
    {
        cin >> x >> y >> w;
        minimize(dist[x][y], w);
    }
    FOR(i,1,n)
        dist[i][i] = 0;
    FOR(i,1,n)
        FOR(j,1,n)
            FOR(k,1,n)
                if(i != j)minimize(dist[i][j], dist[i][k] + dist[k][j]);
    FOR(i,1,k)
    {
        register int h;
        ll s = 0;
        cin >> h;
        FOR(i,n + 1, n + 3)
        {
            FOR(j,1,n+3){
                dist[j][i] = MOD;
                dist[i][j] = MOD;
            }
            dist[i][i]=0;
        }
        FOR(i,1,h)
        {
            cin >> x >> y >> w;
            minimize(dist[x][y], w);
        }
        FOR(i,n +1, n+3)
        {
            FOR(j,1,n+3)
                FOR(k,1,n+3)
                    if(i != j)
                        minimize(dist[i][j], dist[i][k] + dist[k][j]);
        }
        FOR(i,1,n+3)
            FOR(j,n + 1, n + 3)
                FOR(k,1,n+3)
                    minimize(dist[i][j], dist[i][k] + dist[k][j]);
        FOR(i,1,n+3)
            FOR(j,1, n + 3)
                d[i][j] = dist[i][j];
        FOR(i,1,n+3)
            FOR(j,1, n + 3)
                FOR(node,n+1,n+3)
                    if(i != j)minimize(d[i][j],d[i][node] + d[node][j]);
        FOR(i,1,n+3)
        FOR(j,1,n+3) if(i != j)s += d[i][j];
        //cout << s << endl;
        cout << s << endl;
    }
}
