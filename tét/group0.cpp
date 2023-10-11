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
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

int n,a[N],k ,R;
vector<ii> bit;
vector<int>val;
void upd(int x, int val)
{
    if(x == 0)return;
    for(; x <= n; x += (x &(-x))){
            bit[x].fi+=val;
            bit[x].se++;
    }
}
ii get(int x)
{
    ii ans = ii(0,0);
    if(x == 0)return ii(0,0);
    for(;x > 0; x -=(x &(-x))){
            ans.fi += bit[x].fi;
            ans.se += bit[x].se;
    }
    return ans;
}
bool check(ll res, int id)
{
    int pos = upper_bound(all(val),res) -val.begin();

    ii ans = get(pos);
    ll s = 0;
    s = ans.fi + (id - ans.se)*res;
    if(s >= res * k)
        return true;
    else
        return false;
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
        bit.clear();
        cin >> n >> k;
        R = n - 1;
        bit.resize(n + 10);
        val.clear();
        FOR(i,1,n){
            cin >> a[i];
            val.pb(a[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        FOR(i,1,R)
        {
            int pos = lower_bound(all(val),a[i]) - val.begin() + 1;
            upd(pos,a[i]);
        }
        FOR(i,R + 1, n)
        {
            int pos = lower_bound(all(val),a[i]) - val.begin() + 1;
            upd(pos,a[i]);
            ll l = 0, r = 1e15,ans = 0;
            while(l <= r)
            {
                ll mid = (l+r) >> 1;
                if(check(mid, i))
                {
                    l = mid + 1;
                    ans = mid;
                }
                else r = mid-1;
            }
            //if(check(8,i))cout << 1 << endl;
            cout << ans << " " ;
        }
       cout << endl;
    }

}
