// Onegai no bug
// Author : nyanpasuuuuu
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
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

ll n, st[4*N], a[N],ans[N];
void build(int id = 1,int l = 1,int r = n)
{
    if(l == r)
    {
        st[id] = l;
        return;
    }
    int mid = (l+r) >> 1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id] = st[id << 1] + st[id << 1|1];
}
void upd(int x,int id = 1,int l = 1,int r = n)
{
    if(l == r)
    {
        st[id] = 0;
        return;
    }
    int m = (l+r) >> 1;
    if(m >= x)upd(x,id<<1,l,m);
    else upd(x,id<<1|1,m+1,r);
    st[id] = st[id << 1] + st[id << 1|1];
}
int get(ll sum, int id = 1,int l = 1,int r = n)
{
    if(l == r)return l;
    int m = (l+r) >> 1;
    if(st[id << 1] > sum)return get(sum, id << 1, l, m);
    else return get(sum - st[id << 1],id <<1|1, m+1, r);
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
    cin >> n;
    FOR(i,1,n)cin >> a[i];
    build();
    FD(i,n,1)
    {
        int x = get(a[i]);
        ans[i] = x;
        upd(x);
    }
    FOR(i,1,n)cout << ans[i] << " ";
}

