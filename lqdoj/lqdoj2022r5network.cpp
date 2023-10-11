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

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, k, m, c[N], x[N],minn[N];
vector<int>edge[N];
bool check(int sum)
{

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
        cin >> n >> k >> m;
        FOR(i,1,n)
            cin >> c[i];
        FOR(i,1,k)
        {
            cin >> x[i];
            FOR(j,1,x[i]){
                cin >> u;
                node[i].pb(u);
                minimize(minn[i], c[u]);
            }
            s += minn[i];
        }
        FOR(i,1,m)
        {
            register int u, v;
            cin >> u >> v;
            edge[u].pb(v);
            edge[v].pb(u);
        }
        FOR(i,1,n)
            qu.pb(ii(minn[i], i))

        cout << ans;
    }

}

