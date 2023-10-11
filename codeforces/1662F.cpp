// Author : Nyanpasuuuuu
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
const int INF = 1e9 + 7;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
/*
if(p[i] <= p[j])
    abs(i - j) <= p[i]
    if(i > j)
        => i - p[i] <= j
    if(i < j)
        => j <= p[i] + i
same with p[i] > p[j]
    abs(i - j) <= p[j]
    if(i > j)
        => i <= j + p[j]
    if(i < j)
        => j - p[j] <= i
*/
int n, a, b, p[N], d[N];
struct SegmentTree
{
    vector<ii>st[2];
    int n;
    void init(int _n = 0)
    {
        n = _n;
        st[0].assign(4 * n + 10, ii(-INF,0));
        st[1].assign(4 * n + 10, ii(INF,0));
    }
    void build(int id, int l, int r)
    {
        if(l == r){
            st[0][id] = ii(p[l] + l, l);
            st[1][id] = ii(l - p[l], l);
            return;
        }
        int mid = (l+r) >> 1;
        build(id << 1, l, mid);
        build(id << 1|1, mid + 1, r);
        st[0][id] = max(st[0][id << 1], st[0][id << 1|1]);
        st[1][id] = min(st[1][id << 1], st[1][id << 1|1]);
    }
    void upd(int pos, int id, int l, int r)
    {
        if(l == r)
        {
            st[0][id].fi = -INF;
            st[1][id].fi = INF;
            return;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid)upd(pos, id << 1, l, mid);
        else upd(pos, id << 1|1, mid + 1, r);
        st[0][id] = max(st[0][id << 1], st[0][id << 1|1]);
        st[1][id] = min(st[1][id << 1], st[1][id << 1|1]);
    }
    ii getMax(int u, int v, int id, int l, int r)
    {
        if(l > r || u > v || l > v || r < u)return ii(-INF,0);
        if(l >= u && r <= v)return st[0][id];
        int mid = (l+r) >> 1;
        return max(getMax(u, v, id << 1, l, mid), getMax(u, v, id << 1|1, mid + 1, r));
    }
    ii getMin(int u, int v, int id, int l, int r)
    {
        if(l > r || u > v || l > v || r < u)return ii(INF,0);
        if(l >= u && r <= v)return st[1][id];
        int mid = (l+r) >> 1;
        return min(getMin(u, v, id << 1, l, mid), getMin(u, v, id << 1|1, mid + 1, r));
    }
    void build()
    {
        build(1,1,n);
    }
    void upd(int pos)
    {
        upd(pos, 1, 1, n);
    }
    ii getMax(int u, int v)
    {
        return getMax(u, v, 1, 1, n);
    }
    ii getMin(int u, int v)
    {
        return getMin(u, v, 1, 1, n);
    }
}tree;
void init(void)
{
    cin >> n >> a >> b;
    FOR(i,1,n)
        cin >>p[i];
}
void process(void)
{
    tree.init(n);
    tree.build();
    queue<int>qu;
    memset(d, 0x3f,sizeof d);
    d[a] = 0;
    tree.upd(a);
    qu.push(a);
    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        if(x == b){
            cout << d[x] << endl;
            break;
        }
        while(1)
        {
           ii Mx = tree.getMax(max(1,x - p[x]), min(n,x + p[x]));
           ii Mx1 = tree.getMax(max(1,x - p[x]),x);
           ii Mn = tree.getMin(x, min(n,x + p[x]));
           //break;
           bool ok = false;
           if(Mx.fi - Mx.se >= p[x]){
                d[Mx.se] = d[x] + 1;
                qu.push(Mx.se);
                tree.upd(Mx.se);
                ok = 1;
           }
           if(Mx1.fi >= x)
            {
                d[Mx1.se] = d[x] + 1;
                qu.push(Mx1.se);
                tree.upd(Mx1.se);
                ok = 1;
            }
           if(Mn.fi <= x){
                d[Mn.se] = d[x] + 1;
                qu.push(Mn.se);
                tree.upd(Mn.se);
                ok = 1;
           }
            if(!ok)break;
      //  cout << x << " " << Mn.se<< " " << d[Mn.se] << " " << Mx.se<< " " << d[Mx.se] <<  endl;
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
    int t = 1;
    cin >> t;
    while(t--)
    {
        init();
        process();
    }

}

