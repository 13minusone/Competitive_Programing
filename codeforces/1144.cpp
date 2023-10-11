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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

ll n, q, a[N], x[N], y[N],bit[2*N+5];
char c[N];
vector<ll>s;
void upd(int x,int val)
{
    for(;x <= n; x += (x & (-x)))bit[x]+=val;
}
ll get(int x)
{
    ll ans = 0;
    if(x == 0)return 0;
    for(;x > 0; x -= (x & (-x)))ans+= bit[x];
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
    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> a[i];
        s.pb(a[i]);
    }
    FOR(i,1,q)
    {
        cin >> c[i] >> x[i] >> y[i];
        if(c[i] == '!')s.pb(y[i]);
    }
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    int pre = n;
    n = SZ(s);
    FOR(i,1,pre)
    {
        a[i] =lower_bound(all(s),a[i])- s.begin()+1;
        upd(a[i],1);
    }
    FOR(i,1,q)
    {

        if(c[i] == '!')
        {
            y[i] = lower_bound(all(s),y[i]) - s.begin()+1;
            upd(a[x[i]],-1);
            a[x[i]] = y[i];
            upd(y[i],1);
        }
        else
        {
            x[i] = lower_bound(all(s),x[i]) - s.begin()+1;
            y[i] = upper_bound(all(s),y[i]) - s.begin();
            cout << get(y[i]) - get(x[i]-1) << endl;
        }
    }
}
