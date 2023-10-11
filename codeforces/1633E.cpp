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
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 505 + 5;
//const ll mod =1e17+9;
//const ll base = 311;
//const int block = 488;
struct Data
{
    int x, y, m;
    Data(int _x = 0, int _y = 0, int _m= 0)
    {
        x = _x;
        y = _y;
        m = _m;
    }
};
int w;
bool cmp(Data u, Data v)
{
     int uw = abs(u.m- w);
    int vw = abs(v.m - w);
    return ((uw < vw) || ((uw == vw) && (u.m < v.m)) || ((uw == vw) && (u.m == v.m) && (make_pair(u.x, u.y) < make_pair(v.x, v.y))));
}
int n, x[N], y[N], c[N], idl[N], idx[N], parx[N], parl[N], m;
map<int,vector<int>>sum;
vector<int>vec;
vector<Data>val;
//
int fpar(int x)
{
    return (parx[x] < 0 ? x : parx[x] = fpar(parx[x]));
}
bool join(int u, int v)
{
    if((u = fpar(u)) == (v = fpar(v)))return false;
    if(-parx[u] < -parx[v])swap(u,v);
    parx[u] += parx[v];
    parx[v] = u;
    return true;
}

// add mst
bool check(int xd)
{
    FOR(i,1,n) parx[i] =-1;
    w = xd;
    sort(all(val), cmp);
    vector<int>che;
    for(Data i : val)
    {
        if(join(i.x,i.y)){
            che.pb(i.m);
        }
    }
    sort(all(che));
    if(che != vec)return false;
    else return true;
}
void add(int l)
{
    vec.clear();
    FOR(i,1,n)parx[i] = -1;
    w = l;
    sort(all(val), cmp);
    for(Data i : val)
    {
        if(join(i.x,i.y)){
            vec.pb(i.m);
        }
    }
    sort(all(vec));
}
// check coincde mst
int findcur(int lfake, int rfake)
{
    int res = 0;
        while(lfake <= rfake)
        {
            int mid = (lfake+rfake) >> 1;
            if(check(mid))res = mid, lfake = mid+1;
            else rfake = mid-1;
        }
    return res;
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
    FOR(i,1, m)
    {
        cin >> x[i] >> y[i] >> c[i];
        val.pb(Data(x[i],y[i],c[i]));
    }
    int l = 0, r = 1e8;
    while(l <= r)
    {
        int  res = l;
        add(l);
        res = findcur(l,r);
        sum[res] =vec;
        l = res + 1;
    }
    ll p, k, a, b, c, ans = 0, x;
    cin >> p >> k >> a >> b >> c;
    FOR(i,1,k)
    {
        if(i <= p)cin >> x;
        else x = (1LL *x * a + b)%c;
        auto tmp = sum.lower_bound(x);
        ll res = 0;
        for(auto id : tmp->se)
        {
            res += abs(x-id);
        }
        ans ^= res;
    }
    cout << ans;
}
