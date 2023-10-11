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

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
int n, k, m, a[N], pos[N], midnum = 0;
vector<int>val;
ii st[4 * N];
ii Merge(ii a, ii b)
{
    return ii(a.fi + b.fi, a.se + b.se);
}
void upd(int pos, ii val, int id = 1, int l = 1, int r = m)
{
    if(l == r)
    {
        st[id] = Merge(st[id], val);
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, val, id << 1, l, mid);
    else upd(pos, val, id << 1|1, mid  + 1, r);
    st[id] = Merge(st[id << 1], st[id << 1|1]);
}
ii get(int val, int id = 1, int l = 1, int r  = m)
{
    if(l > v || r < u || l > r || u > v)return ii(0,0);
    if(val == 0){
        midnum = l;
        return ii(0,0);
    }
    int mid = (l+r) >> 1;
    ii res = ii(0,0);
    if(st[id << 1].se < val){
        Merge(res, st[id << 1]);
        Merge(res, get(val - st[id << 1].se, id << 1|1, mid + 1, r));
    }
    else {
        Merge(res, get(val, id << 1, l, mid));
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n){
            cin >> a[i];
            val.pb(a[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        FOR(i,1,n)f[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
        FOR(i,2,k-1)upd(f[i],ii(a[i], 1));
        FOR(i,k,n)
        {
            upd(f[i], ii(a[i],1));
            FD(j,k, 2 * k)
            {
                if(j > i)break;
                int pos = i - j + 1;
                upd(f[pos], ii(a[pos], 1));
                int mid =
                ii res = get(mid);
                cost[i][j] = ()
            }
        }
    }

}

