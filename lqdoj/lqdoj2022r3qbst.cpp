// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "qbst"
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
const ll INF =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n, c[N], pos[N], w[N], root = 0, adj[N][2], num[N];
ll ans = INF, res = 0;
ii st[4 * N];
ii MINI(ii a, ii b)
{
    if(a.fi == b.fi){
        if(a.se < b.se)return b;
        return a;
    }
    else {
        if(a.fi < b.fi)return a;
        return b;
    }
}
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] = ii(c[pos[l]], pos[l]);
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    st[id] = MINI(st[id << 1], st[id << 1|1]);
}
ii getMin(int u, int v, int id = 1,int l = 1, int r = n)
{
    if(l > v || r < u || l > r || u > v)return ii(INF,INF);
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return MINI(getMin(u, v, id << 1, l, mid), getMin(u, v, id << 1|1, mid + 1, r));
}
void upd(int pos, int id = 1, int l = 1, int r = n)
{
    if(l > pos || r < pos)return;
    if(l == r)
    {
        st[id] = ii(INF,INF);
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, id << 1, l, mid);
    else upd(pos, id << 1|1, mid + 1, r);
    st[id] = MINI(st[id << 1], st[id << 1|1]);
}
ll dfs(int u)
{
    if(u == -1)return 0;
    ll s = 0;
    FOR(i,0,1)
        if(adj[u][i] != -1)
        {
            s += dfs(adj[u][i]);
        }
    maximize(res, s + c[u]);
    return s + w[u];
}
void dfs_trace(int u)
{
    cout << u <<" ";
    FOR(i,0,1)
        if(adj[u][i] != -1)
            dfs_trace(adj[u][i]);
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
        cin >> n;
        FOR(i,1,n){
            cin >> c[i];
            pos[i] = i;
        }
        FOR(i,1,n)
            cin >> w[i];
        sort(pos + 1, pos + 1 + n,[&](const int &u, const int &v){
             return w[u] < w[v];});
        FOR(i,1,n)
            num[pos[i]] = i;
        queue<int>qu;
        FOR(i,1,n)
        {
            FOR(j,1,n)adj[j][1] = adj[j][0] = -1;
            build();
            qu.push(i);
            upd(num[i]);
            while(!qu.empty())
            {
                int x = qu.front();
                qu.pop();
                if(x == INF)continue;
                //cout << x << " " ;
                ii Lef= getMin(1,pos[x] - 1);
                if(Lef.fi != INF)
                {
                    adj[x][0] = Lef.se;
                    upd(num[Lef.se]);
                    qu.push(Lef.se);
                  //  cout << Lef.se << " " ;
                }
                ii Rig = getMin(pos[x] + 1, n);
                if(Rig.fi != INF)
                {
                    adj[x][1] = Rig.se;
                    upd(num[Rig.se]);
                    qu.push(Rig.se);
                    //cout << Rig.se << "  ";
                }
                //cout << endl;
            }
//            FOR(j,1,n)
//                cout << j << " " << adj[j][0] << " " << adj[j][1] << endl;
            res = 0;
            dfs(i);
            if(minimize(ans,res))root = i;
           // cout << i << endl;
        }
        cout << ans << endl;
        int i = root;
        FOR(j,1,n)adj[j][1] = adj[j][0] = -1;
        build();
        qu.push(root);
        upd(num[root]);
        while(!qu.empty())
        {
            int x = qu.front();
            qu.pop();
            if(x == INF)continue;
            //cout << x << " " ;
            ii Lef= getMin(1,pos[x] - 1);
            if(Lef.fi != INF)
            {
                adj[x][0] = Lef.se;
                upd(num[Lef.se]);
                qu.push(Lef.se);
                //cout << Lef.se << " " ;
            }
            ii Rig = getMin(pos[x] + 1, n);
            if(Rig.fi != INF)
            {
                adj[x][1] = Rig.se;
                upd(num[Rig.se]);
                qu.push(Rig.se);
                //cout << Rig.se << "  ";
            }
            //cout << endl;
        }
        dfs_trace(root);
    }

}

