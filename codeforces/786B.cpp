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

const int N = 1e5 + 5;
//const ll mod =1e17+9;
//const ll base = 311;
//const int block = 488;

int n, m, s, pos[N], v, l, r, w, t;
ll d[8 * N];
vector<ii>adj[8 * N];
void build(int id = 1, int l = 1, int r = n)
{
    d[id] = d[id + 4 * n] = 1e18;
    if(l == r){
        pos[l] = id;
        adj[id].pb(ii(id + 4 * n, 0));
        adj[id + 4 * n].pb(ii(id, 0));
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    adj[id].pb(ii(id << 1|1, 0));
    adj[id].pb(ii(id << 1, 0));
    adj[(id<< 1|1) + 4 * n].pb(ii(id + 4 * n, 0));
    adj[(id<<1) + 4 * n].pb(ii(id + 4 * n, 0));
    return;
}
void add(int k, int u, int v, int t, int val, int id = 1, int l = 1, int r = n)
{
    if(l > v || r  < u || l > r || u > v)return;
    if(l >= u && r <= v){
        if(t == 2)adj[k ].pb(ii(id , val));
        else adj[id + 4 * n].pb(ii(k + 4 * n,val));
        return;
    }
    int mid = (l+r) >> 1;
    add(k, u, v, t, val, id << 1, l, mid);
    add(k, u, v, t, val, id << 1|1, mid + 1, r);
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
    int tese = 1;
    //cin >> t;
    while(tese--)
    {
        cin >> n >> m >> s;
        build();
        while(m--){
            cin >> t;
            if(t == 1){
                cin >> l >> r >> w;
                adj[pos[l]].pb(ii(pos[r], w));
            }
            else{
                cin >> v >> l >> r >> w;
                add(pos[v], l, r, t, w);
            }
        }
        d[pos[s]]  = 0;
        priority_queue<ii,vector<ii>, greater<ii>>qu;
        qu.push(ii(0,pos[s]));
        while(!qu.empty())
        {
            ii x = qu.top();
            qu.pop();
            if(d[x.se] != x.fi)continue;
            for(ii v : adj[x.se])
                if(minimize(d[v.fi], x.fi + v.se))
                qu.push(ii(d[v.fi], v.fi));
        }
        FOR(i,1,n)
            cout << (d[pos[i]] == 1e18 ? -1 : d[pos[i]]) <<  " ";

    }

}
