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
typedef pair<int,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int n, d[N], p[N];
priority_queue<int, vector<int>, greater<int>>q[N];
struct IT_lz
{
    ii st[4 * N];
    int sum[4*N], lz[4*N];
    void build(int id = 1, int l = 1, int r = N-5)
    {
        if(l == r)
        {
            st[id] = ii(1e9, l);
            sum[id] = -l;
            return;
        }
        int mid = (l+r) >> 1;
        build(id << 1, l, mid);
        build(id << 1|1, mid + 1, r);
        st[id] = min(st[id << 1], st[id << 1|1]);
        sum[id] = max(sum[id << 1], sum[id << 1|1]);
        return;
    }
    void push(int id)
    {
        int &t = lz[id];
        if(t)
        {
            sum[id << 1] += t;
            sum[id << 1|1] += t;
            lz[id << 1] += t;
            lz[id << 1|1] += t;
            t = 0;
        }
        return;
    }
    int findd(int id = 1, int l = 1, int r = N-5)
    {
        if(sum[id] <= 0)return -1;
        if(l == r)return l;
        push(id);
        int mid = (l+r) >> 1;
        if(sum[id << 1] > 0)return findd(id << 1, l, mid);
        return  findd(id << 1|1, mid + 1, r);
    }
    ii getmin(int u, int v, int id = 1, int l = 1 , int r = N-5)
    {
        if(l > v || r < u) return ii(N,N);
        if(l >= u && r <= v)return st[id];
        int mid = (l + r) >> 1;
        return min(getmin(u, v, id << 1, l, mid), getmin(u , v, id << 1 |1, mid + 1, r));
    }
    void upd(int pos, int id = 1, int l = 1, int r = N- 5)
    {
        if(l == r)
        {
            st[id].fi = (q[pos].empty()? 1e9: q[pos].top());
            return;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid)upd(pos, id << 1, l, mid);
        else upd(pos, id << 1|1, mid+1, r);
         st[id] = min(st[id << 1], st[id << 1|1]);
    }
    void upd_range(int u, int v, int val, int id = 1, int l =1 ,int r=  N- 5)
    {
        if(l > v || r < u || l > r)return;
        if(l >= u && r <= v)
        {
            sum[id] += val;
            lz[id] += val;
            return;
        }
        push(id);
        int mid = (l+r) >> 1;
        upd_range(u ,v, val, id << 1, l, mid);
        upd_range(u ,v, val, id << 1|1, mid + 1, r);
        sum[id] = max(sum[id << 1], sum[id << 1|1]);
    }
}tree;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n ;
    FOR(i,1,n)cin >> d[i] >> p[i];
   // cout << findd(1,4,20);
   tree.build();
   ll res = 0;
    FOR(i,1,n)
    {
        q[d[i]].push(p[i]);
        tree.upd_range(d[i],N-5, 1);
        tree.upd(d[i]);
        res += p[i];
        int pos = tree.findd();
        if(pos != -1)
        {
            ii x = tree.getmin(1,pos);
           // cout << pos << " " << x.fi << endl;
            res-=x.fi;
            q[x.se].pop();
            tree.upd(x.se);
            tree.upd_range(x.se, N-5, -1);
        }
        cout << res <<endl;
    }
}
