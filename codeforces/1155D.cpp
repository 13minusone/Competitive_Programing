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

const int N = 3e5 + 5;
const ll mod =1e17+9;
//const ll base = 311;
//const int block = 488;

int n, x;
ll s[N],a[N],leftr[N];
ll ans = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> x;
    FOR(i,1,n)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    ll res = 0;
    ll  right = 0;
    FOR(i,1,n)
    {
        leftr[i] = max(leftr[i-1],s[i]-res - 1LL * s[i] * x );
        minimize(res,s[i]);
        //cout << i <<  " " << leftr[i] << endl;
    }
    s[n+1] = -mod;
    res = s[n];
    right = -mod;
    FD(i,n+1,2)
    {
        maximize(right,  res - s[i] + s[i-1] * x );
        maximize(res,s[i]);
    cout << i << " " << leftr[i-1] << " " <<right << endl;
    }
    cout <<  right;
}
