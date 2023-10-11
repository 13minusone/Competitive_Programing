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

const int N = 2e5 + 5;
const ll mod =2e9+9;
//const ll base = 311;
//const int bl = 488;
int n, q, a[N];
struct IT
{
    ll st[4 * N];
    int nt;
    void start(int _n = 0)
    {
        nt = _n;
        memset(st,mod,sizeof st);
    }
    void upd(int pos,int val,int id,int l,int r)
    {
        if(l == r)
        {
            st[id] = val;
            return;
        }
        int m= (l+r) >> 1;
        if(pos <= m)upd(pos,val, id << 1, l, m);
        else upd(pos, val, id << 1|1, m+1, r);
        st[id] = min(st[id << 1],st[id << 1|1]);
    }
    void upd(int pos,int val)
    {
        upd(pos,val,1,1,nt);
    }
    ll get(int u,int v,int id ,int l ,int r)
    {
        if(l > v || r < u || l > r)return mod;
        if(l >= u && r <= v)return st[id];
        int m =(l+r)>>1;
        return min(get(u, v, id << 1, l, m), get(u, v, id << 1|1, m+1, r));
    }
    ll get(int u, int v)
    {
        return get(u, v, 1, 1, nt);
    }
}tree[2];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    tree[0].start(n);
    tree[1].start(n);
    FOR(i,1,n)
    {
        cin >> a[i];
        tree[0].upd(i,a[i] - i);
        tree[1].upd(i,a[i]+i);
    }
    while(q--)
    {
        int type,x,y;
        cin >> type >> x;
        if(type == 1)
        {
            cin >> y ;
            tree[0].upd(x,y-x);
            tree[1].upd(x,y+x);
            a[x] = y;
        }
        else cout << min(tree[0].get(1,x) + x,tree[1].get(x+1,n) - x) << endl;
    }
}

