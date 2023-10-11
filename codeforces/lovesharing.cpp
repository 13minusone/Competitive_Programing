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

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, q, x[N], r[N], t[N];
struct BIT
{
    int n;
    vector<int>vec;
    BIT(int _n = 0)
    {
        n = _n;
        vec.assign(n+10, 0);
    }

    void upd(int x int val)
    {
        if(x <= 0)return;
        for(; x <= n; x += (x & (-x)))vec[x] += val;
        return;
    }
    ll get(int x)
    {
        if(x <= 0)return 0;
        ll ans = 0;
        for(; x > 0; x -= (x & (-x)))ans += vec[x];
        return ans;
    }
}ans[55];
void preCal(){
    FOR(dif,0,50)
    {
        ans[dif] = BIT(n);
        int l = 0;
        for(int val : Valt)
        {
            while(Valt[l] < )
            if(val - Valt[l] != dif)continue;
        }
    }
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
    cin >> n >> n >> q;
    FOR(i, 1, n)
    {
        cin >> x[i] >> r[i]  >> t[i];
        Valx.pb(x[i]);
        Valt.pb(t[i]);
    }
    sort(all(Valx));
    vec.resize(unique(all(Valx)) - Valx.begin());
    sort(all(Valt));
    vec.resize(unique(all(Valt)) - Valt.begin());
    preCal();
}
