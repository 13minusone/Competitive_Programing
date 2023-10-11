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
const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;

vector<int>val;
int a[N], f[N], n;
ii L[N + 10], R[N + 10];
void add(int &a,const int &b)
{
    a += b;
    if(a >= MOD)a -= MOD;
}
void updL(int x, ii res)
{
    for(;x >= 1; x -= (x &(-x)))
        if(L[x].fi == res.fi)
            add(L[x].se, res.se);
        else if(L[x].fi < res.fi)
            L[x] = res;
   return;
}
ii getL(int x)
{
    ii res = ii(0,0);
    if(x != 0)
   {
       for(; x <= val.size(); x += (x &(-x)))
        if(res.fi < L[x].fi)
            res = L[x];
        else if(L[x].fi == res.fi)
                add(res.se, L[x].se);
   }
    res.fi += 1;
    if(res.se == 0)return ii(res.fi, 1);
    return res;
}
void updR(int x, ii res)
{
    if(x == 0)return;
     for(;x <= val.size(); x += (x &(-x)))
        if(R[x].fi == res.fi)
            add(R[x].se, res.se);
        else if(R[x].fi < res.fi)
            R[x] = res;
   return;
}
ii getR(int x)
{
    ii res = ii(0,0);
    for(; x > 0; x -= (x &(-x)))
        if(res.fi < R[x].fi)
            res = R[x];
        else if(R[x].fi == res.fi)
                add(res.se,R[x].se);
    res.fi += 1;
    if(res.se == 0)return ii(res.fi, 1);
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        f[0] = 1;
        FOR(i,1,n){
            f[i] = 1LL * f[i - 1] * 2 %MOD;
            cin >> a[i];
            val.pb(a[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        FOR(i,1,n){
            a[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
        }
        ii res = ii(0,1);
        FD(i,n,1)
        {
            ii down = getL(a[i] + 1), up = getR(a[i]-  1);
            if(down.fi + up.fi - 1 == res.fi)
                add(res.se, 1LL * (1LL * down.se * up.se %MOD) * f[n - (down.fi + up.fi - 1)] %MOD);
            else if(down.fi + up.fi - 1 > res.fi){
                res.fi = down.fi + up.fi - 1;
                res.se = 1LL * (1LL * down.se * up.se %MOD) * f[n - (down.fi + up.fi - 1)] %MOD;
            }
            updL(a[i], ii(down.fi, down.se));
            updR(a[i], ii(up.fi, up.se));
            //cout << a[i] << " " << up.fi << " " << down.fi << endl;
        }
        cout <<res.fi << " " << res.se << endl;

    }

}

