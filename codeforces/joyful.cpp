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

const int N = 4e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m;
struct Data
{
    ll a, b, c, d;
    Data(ll _a = 0, ll _b = 0, ll _c = 0, ll _d = 0)
    {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};
vector<Data>edge;
vector<ll>val;
ll st[4*N];
bool cmp(Data a, Data b)
{
    if(a.a != b.a)return a.a < b.a;
    return a.d > b.d;
}
void upd(int pos, int val, int id = 1, int l = 1, int r = m)
{
    if(l == r){
        st[id]+= val;
    return ;
    }
    int m = (l+r) >> 1;
    if(pos <= m)upd(pos, val, id << 1, l, m);
    else upd(pos, val, id << 1|1, m+1, r);
    st[id] = st[id << 1] + st[id << 1|1];
}
ll get(int u, int v, int id = 1, int l = 1, int r = m)
{
    if(l > v || r < u || l > r)return 0;
    if(l >= u && r <= v)return st[id];
    int m = (l+r) >> 1;
    return get(u, v, id << 1, l, m) + get(u, v, id << 1|1, m+1, r);
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
    FOR(i,1,n)
    {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 - x2 == 0)edge.pb(Data(x1,min(y1,y2),max(y1,y2),1));
        if(y1 - y2 == 0){
                edge.pb(Data(min(x1,x2),y1,y2,2));
                edge.pb(Data(max(x1,x2),y1,y2,-1));
        }
        val.pb(y1);
        val.pb(y2);
    }
    sort(all(edge),cmp);
    sort(all(val));
    val.resize(unique(all(val))-val.begin());
     m = SZ(val)+1;
     ll ans = 0;
    for(Data i : edge)
    {
        int k = lower_bound(all(val), i.b) - val.begin()+1;
        if(i.d == 1){
            int j = lower_bound(all(val), i.c)-val.begin()+1;
            ans+= get(k, j);
        }
        else if(i.d == 2)upd(k,1);
        else upd(k,-1);
    }
    cout << ans;
}

