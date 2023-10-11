// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 1e6 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, res = 0, hi[N], k;
vector<int>node[N];
vector<int>edge[N];
int dfs(int u, int pre)
{
    for(int v : edge[u]) if(v != pre)
    {
        hi[v] = hi[u]+1;
        node[u].pb(dfs(v,u));
    }
    if(node[u].empty())return hi[u];
    else
    {
        sort(all(node[u]));
        int nz = SZ(node[u]);
        FD(i,nz-2, 0)
        {
            if(node[u][i] + node[u][i+1] - 2 * hi[u] <= k){
                //cout << u << " " << res << endl;
                    return node[u][i+1];
            }
            else res++;
        }
        //cout << u << " " << res << endl;
        return node[u][0];
    }
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
    cin >> n >> k;
    FOR(i,1,n-1)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    FOR(i,1,n)if(SZ(edge[i]) != 1){
        hi[i] = 1;
        dfs(i,-1);
        break;
    }
    cout << res + 1;
}
