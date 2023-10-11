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

const int N = 1e3 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, m, d[N];
bool inQ[N];
string s;
vector<int>edge[N];
ll ans[300];
void init(void)
{
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    FOR(i,1,m)
    {
        register int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}
void cal(int u)
{
    memset(d, 0x3f, sizeof d);
    memset(inQ, 0, sizeof inQ);
    d[u] = 0;
    inQ[u] = 1;
    deque<ii>qu, tmp;
    qu.push_front(ii(0,u));
   // cout << u << endl;
    while(!qu.empty() || !tmp.empty())
    {
        if(qu.empty() || (qu.front().fi >= tmp.front().fi)){
            int z = INF;
            if(!qu.empty())z = qu.front().fi;
            while(!tmp.empty() && tmp.front().fi <= z)
            {
                if(d[tmp.front().se] > tmp.front().fi){
                    d[tmp.front().se] = tmp.front().fi;
                    qu.push_front(tmp.front());
                }
               // inQ[tmp.front().se] = 0;
                tmp.pop_front();
            }
        }
        ii x = qu.front();
        //cout << x.fi << " " << x.se << endl;
        qu.pop_front();
        if(x.fi != d[x.se])continue;
        for(int v : edge[x.se])
            if(d[v] > d[x.se] + 1 + (s[v] != s[u] ? 3 : 0)){
                if(s[v] == s[u]){
                    d[v] = d[x.se] + 1;
                    //cout << u << " " << v << endl;
                    qu.push_front(ii(d[v], v));
                }
                else{
                        tmp.push_back(ii(d[x.se] + 4, v));
                }
            }
    }
    FOR(i,u + 1,n)
        if(s[i] == s[u])ans[s[u]]+= d[i];
   // cout << u << "  " << ans[s[u]] << endl;
    return;
}
void process(void)
{
    FOR(i,1,n)
        cal(i);
    cout << ans['G'] << " " << ans['Y'];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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


