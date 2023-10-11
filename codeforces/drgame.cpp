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

const int N = 1e4 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
vector<int>edge[N];
int n, m, cnt[N], s = 0;
int a[N][N];
vector<int>ans[N];
void dfs(int i)
{
        for(int v : edge[i])
        {
            if(a[i][v] != 0 && a[i][v]&1 == 1)
            {
                a[i][v]^= 1;
                a[v][i]^= 1;
                dfs(v);
                ans[s].pb(v);
            }
        }
        for(int v : edge[i])
        {
            if(a[i][v] != 0 && a[i][v]&2 == 2)
            {
                a[i][v]^= 2;
                a[v][i]^= 2;
                s++;
                dfs(v);
                ans[s].pb(v);
            }
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
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
        cnt[x]++;
        cnt[y]++;
        a[x][y] = 1, a[y][x] = 1;
    }
    short le = 0;
    FOR(i,1,n)
    {
        if(cnt[i]&1)
            FOR(j,1,n)
            if(i != j && cnt[j]&1)le = j,a[i][j] += 2, a[j][i] += 2;
    }
    if(le == 0)cout << 1 << endl;
    else
    {
        dfs(le);
        cout << s << endl;
    }
}
