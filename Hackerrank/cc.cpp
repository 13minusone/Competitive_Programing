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

const int N = 2e5 + 5;
//const ll mod =1e17+9;
//const ll base = 311;
//const int block = 488;

ll a[N], b[N], n, m;
ll pre[N];
vector<ll>val;
ii st[4 * N];
/*
  fi : sum của các từ l , r
  se : số thằng có từ l, r

*/
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
ii get(int u, int v, int id = 1, int l = 1, int r  = m)
{
    if(l > v || r < u || l > r || u > v)return ii(0,0);
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return Merge(get(u, v, id << 1, l, mid), get(u, v, id << 1|1, mid + 1, r));
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
        FOR(i,1, 2*n)
        {
            if(i <= n)cin >> a[i];
            else a[i] = a[i - n];
            b[i] = a[i] - i;
            pre[i] = pre[i-1] + b[i];
            val.pb(b[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        m = val.size();
        FOR(i,1,n){
            int k = lower_bound(all(val), b[i]) - val.begin() + 1;
            upd(k, ii(b[i], 1));
        }
        /*
           a : 6 2  3  1 6  2  3 1
           b : 5 0 -1 -3 1 -4 -4 -7
            sum b from 2 to 5 : -3
            get  : (-1, 1)
            ans : abs(get.fi + get.se * (i - 1)) + -3 - (-1) + 3 * (i-1)

        */
        int pluss = 0 ;
        ll ans = 0;
        FOR(i,1,n)
        {
            int k = upper_bound(all(val), -pluss) - val.begin();
            // k : min pos that a[k] > -pluss, plus =i-1= > -plus = -i + 1
            ii sub  = get(1,k);
            ll s = pre[i + n - 1] - pre[i-1];
            maximize(ans, abs(sub.fi + 1LL * sub.se * pluss) + s - sub.fi + 1LL *(n-sub.se) * pluss);
            //cout << i << " " << sub.fi << " " << sub.se << " " << abs(sub.fi + 1LL * sub.se * pluss) + s - sub.fi + 1LL *(n-sub.se) * pluss << endl;
            k = lower_bound(all(val), b[i]) - val.begin() + 1;
            upd(k,ii(-b[i],-1));
            k = lower_bound(all(val), b[i + n]) - val.begin() + 1;
            upd(k,ii(b[i+n],1));
            pluss++;
        }
        cout << ans;
    }

}
