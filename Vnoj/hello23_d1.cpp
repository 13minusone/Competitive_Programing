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

const int N = 5e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, k,d1[N], dn[N], cntn[N], pren[N];
vector<int>edge[N];
vector<ii>vec;
void init(void)
{
    cin >> n >> m >> k;
    FOR(i,1,m)
    {
        register int x, y;
        cin >> x >> y;
        vec.pb(ii(x, y));
        edge[x].pb(y);
        edge[y].pb(x);
    }
}
void process(void)
{
    queue<ii>qu;
    memset(d1,0x3f,sizeof d1);
    d1[1] = 0;
    qu.push(ii(-0,1));
    while(!qu.empty())
    {
        ii x = qu.front();
        qu.pop();
        for(int v : edge[x.se])
            if(minimize(d1[v], x.fi + 1)){
                qu.push(ii(d1[v], v));
            }
    }
    memset(dn,0x3f,sizeof dn);
    dn[n] = 0;
    qu.push(ii(0,n));
    while(!qu.empty())
    {
        ii x = qu.front();
        qu.pop();
        for(int v : edge[x.se])
             if(minimize(dn[v], x.fi + 1)){
                qu.push(ii(dn[v], v));
            }
    }
   // cout << dn[1] << endl;
   FOR(i,1,n)
        cntn[dn[i]]++;
    FOR(i,0,m)
    {
        pren[i] = cntn[i];
        pren[i] += pren[i - 1];
    }
    if(dn[1] < k)cout << 0;
    else if(dn[1] == k){
        ll ans = 0;
        FOR(i,1,n)
        {
            int dist1 = d1[i];
            if(k >= 2 + dist1)ans += max(0,pren[k - 2 -dist1]);
        }
        cout << 1LL * n  * (n - 1) / 2 - m - ans << endl;
    }
    else
    {
        ll ans = 0;
        FOR(i,1,n)
        {
            int dist1 = d1[i];
            if(k >= 1 + dist1)ans += max(0,cntn[k - 1 -dist1]);
        }
        cout << ans << endl;
    }
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


