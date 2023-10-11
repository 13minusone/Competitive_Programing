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
int n, k, m, a[N], pos[N];
vector<int>val;
ll st[4 * N];
int BIT[N + 10];
void updBIT(int x)
{
    for(; x <= m; x += (x &(-x)))BIT[x]++;
    return;
}
int getBIT(int x)
{
    if(x == 0)return 0;
    int ans = 0;
    for(;x > 0; x -= (x & (-x)))ans += BIT[x];
    return ans;
}
void updIT(int pos, int val, int id = 1, int l = 1, int r = m)
{
    if(l == r)
    {
        st[id] += val;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)updIT(pos, val, id << 1, l, mid);
    else updIT(pos, val, id << 1|1, mid  + 1, r);
    st[id] = st[id << 1] + st[id << 1|1];
}
ll getIT(int pos, int id = 1, int l = 1, int r  = m)
{
    if(l > pos || l > r || u > v)return 0;
    if(r <= pos)return st[id];
    int mid = (l+r) >> 1;
   return (getIT(pos, id << 1, l, mid) +  getIT(pos, id << 1|1, mid + 1, r));
}
int findd(int val)
{
    int ans = 0, l = 1, r = m;
    while(l <= r)
    {
        int mid = (l+r) >> 1;
        if(val <= getBIT(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
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
        m = SZ(val);
        FOR(i,1,n){
            f[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
            pre[i] = pre[i-1] + a[i];
        }
        FOR(i,1,k-1)upd(f[i],ii(a[i], 1));
        FOR(i,k,n)
        {
            updIT(f[i], a[i]);
            updBIT(f[i], 1);
            FD(j,k, 2 *k)
            {
                int pos = i - j +1;
                updBIT(f[pos], 1);
                updIT(f[pos], a[pos]);
                int x = findd((j+1)/2);
                ll res = getIT(x-1);
                int y = getBIT(x-1);
                cost[i][j] = (f[x] * y- res) + pre[(j - y)
            }
        }
    }

}


