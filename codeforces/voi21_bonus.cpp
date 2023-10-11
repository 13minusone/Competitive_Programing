// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) (int)(c).size()
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
//const ll mod =1e9+9;
//const ll base = 311;
 int bl = 488;

string query[N];
vector<ii>edge;
int n, m, deg[N], a[N],trie[N][27],x,y;
ll cnt = 0;
ll maxx[N],self[N];
vector<int>big[N], small[N];
ll snode[N];
void prepare()
{
    for(ii i : edge)
    {
        if(deg[i.fi] > bl)big[i.se].pb(i.fi);
        else small[i.fi].pb(i.se);
        if(deg[i.se] > bl)big[i.fi].pb(i.se);
        else small[i.se].pb(i.fi);
    }
}
ll add(string s,int x)
{
    int res = 0;
    ll sum = 0;
    int sz = SZ(s);
    REP(i,0,sz)
    {
        if(!trie[res][s[i] - 'A'])trie[res][s[i] - 'A'] = ++cnt;
        maximize(sum,snode[res]);
        res = trie[res][s[i] - 'A'];
    }
    sum+= x;
    maximize(snode[res], sum);
    if(deg[x] > bl)snode[res] = max(snode[res],maxx[x]);
    else for(int i : small[x])maximize(snode[res], self[i] + x);
    maximize(self[x],snode[res]);
    for(int v : big[x])maximize(maxx[v],snode[res]+v);
    return snode[res];
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
    FOR(i,1,n)
        cin >> query[i] >> a[i];
    FOR(i,1,m)
    {
        cin >> x >> y;
        edge.pb(ii(x,y));
        deg[x]++;
        deg[y]++;
    }
    bl = sqrt(n);
    prepare();
    ll ans = 0;
    FD(i,n,1){
        ll opt= add(query[i],a[i]);
        maximize(ans,opt);
        //cout << ans << " " << opt << endl;
    }
    cout << ans;

}

