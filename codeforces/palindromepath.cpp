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
typedef pair<int,char> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e2 + 5;
const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n,m,x,y, ok[N][N],d[N][N];
char c;
ll minn = mod;
struct Data
{
    int x,y,s;
};
vector<ii>edge[N];
void solve()
{
   queue<Data>st;
   st.push({1,2,0});
    while(!st.empty())
    {
        Data x = st.front();
        st.pop();
        ok[x.x][x.y] = 1;
        if(x.x == x.y)
        {
            cout << x.s;
            return;
        }
        if(d[x.x][x.y])
        {
            cout << x.s + 1;
            return;
        }
        for(ii i : edge[x.x])
            for(ii j : edge[x.y])
                if(i.se == j.se && !ok[i.fi][j.fi])
                {
                    st.push({i.fi,j.fi,x.s+2});
                }
    }
    cout << -1 << endl;
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
        cin >> x >> y >> c;
        edge[x].pb(ii(y,c));
        edge[y].pb(ii(x,c));
        d[x][y] = 1;
    }
    solve();
}

