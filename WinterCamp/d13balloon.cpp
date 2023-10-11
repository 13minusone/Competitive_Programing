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

const int N = 2e2 + 5;
const int MOD =1e6;
//const ll base = 311;
//const int BLOCK = 488;

int n, S, T, m[N];
double min_dist[N][N];
ii Point[N][N];
ll dist(ii a, ii b)
{
    ll f = 1LL * (a.fi - b.fi) * (a.fi - b.fi);
    ll g = 1LL * (a.se - b.se) * (a.se - b.se);
    return (f + g);
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> S >> T;
        FOR(i,1,n)
        {
            cin >> m[i];
            FOR(j,1,m[i])
                cin >> Point[i][j].fi >> Point[i][j].se;
        }
        FOR(i,1,n)
            FOR(j,1,n)
                min_dist[i][j] = 100000000;
       FOR(i,1,n)
            min_dist[i][i] = 0;
        FOR(i,1,n)
            FOR(j,1,i-1)
            {
                FOR(k,1,m[i])
                {
                    int ans = -1;
                    FOR(mid,1,m[j])
                        if(ans == -1 || dist(Point[i][k],Point[j][mid]) < dist(Point[i][k],Point[j][ans]))
                        {
                            ans = mid;
                        }
                    minimize(min_dist[i][j],(double)sqrt(dist(Point[i][k],Point[j][ans])));
                    minimize(min_dist[j][i],(double)sqrt(dist(Point[i][k],Point[j][ans])));
                    //cout <<i << " " << j << " " << k << " " <<ans << " " << min_dist[i][j] << endl;
                }
               // cout << i << " " << j << " " << min_dist[i][j] << endl;
            }
        FOR(k,1,n)
            FOR(i,1,n)
                FOR(j,1,n)
                    minimize(min_dist[i][j],(double)min_dist[i][k] + min_dist[k][j]);
        cout << (ll)(min_dist[S][T] * MOD) << endl;

    }

}

