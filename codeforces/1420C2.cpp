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
#define fi first
#define se second
#define endl '\n'
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

struct node
{
    ll pp,ps,ss,sp;
};
int n, a[N],q;
node st[4 * N];
node Merge(node u, node v)
{
    node re;
    re.pp = max({u.pp,v.pp,u.pp + v.sp,u.ps + v.pp});
    re.ps = max({u.ps,v.ps,u.ps + v.ps,u.pp + v.ss});
    re.ss = max({u.ss,v.ss,u.ss + v.ps,u.sp + v.ss});
    re.sp = max({u.sp,v.sp,u.sp + v.sp,u.ss + v.pp});
    return re;
}
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] = {a[l],0,-a[l],0};
        return;
    }
    int m = (l+r) >> 1;
    build(id << 1, l, m);
    build(id << 1|1, m+1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
void upd(int u,int id = 1, int l = 1, int  r = n)
{
    if(l > u || r < u )return;
    if(l == r)
    {
        st[id] = {a[l],0,-a[l],0};
        return;
    }
    int m = (l + r) >> 1;
    if(u <= m)upd( u,id << 1, l, m);
    else upd( u,id << 1|1, m+1, r);
    st[id] = Merge(st[id << 1],st[id << 1|1]);
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
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        FOR(i,1,n)cin >> a[i];
        build();
        cout << max(st[1].pp,st[1].ps) << endl;
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            swap(a[l],a[r]);
            upd(l);
            upd(r);
            cout << max(st[1].pp,st[1].ps) << endl;
        }
    }
}
