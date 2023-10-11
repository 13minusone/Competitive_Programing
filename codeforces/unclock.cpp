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

const int N = 1e5 + 5;
const ll mod =1e18+9;
//const ll base = 311;
//const int bl = 488;

ll ans =  0, b, n, m, a[N], pre[N];
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
    FOR(i,1,n)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    FOR(i,1,n)pre[i] = pre[i-1] + a[i];
    ans = mod;
    ll res = 0;
    FOR(i,1,n)
    {
        res = 0;
        int l = 1, r= i-1, pos = 0, x = a[i];
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(2 * a[mid]  <= 2*a[i] - m)pos = mid,l = mid+1;
            else r = mid-1;
        }
        if(pos>=1 )
            res += 1LL*pos * (m - x) + pre[pos];
            res += 1LL*(i - pos - 1) * x - (pre[i-1] - pre[pos]);

        l = i+1, r = n;
        //cout <<pos << " "<< res << " " << i << endl;
        pos = n+1;
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(2 * a[mid]  >= 2*a[i] + m)pos = mid,r = mid-1;
            else l = mid+1;
        }
        if(pos <= n )
            res += 1LL*(n - pos + 1) * (m +x) -( pre[n] - pre[pos-1]);
            res += (pre[pos-1] - pre[i])-1LL*(pos- i-1) * x ;

        //cout << pos<< " " << res << " " << i << endl;
        minimize(ans,res);
        //cout << endl;
    }
    cout << ans;
}

