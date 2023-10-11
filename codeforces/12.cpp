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

const int N = 1e4 + 2;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, dp[N][N], a[N], s;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> s;
    FOR(i,1,n){
        cin >> a[i];
        a[i] += (n-i) * s;
    }
    priority_queue<int, vector<int>>qu;
    ll ans = 0;
    FD(i, n, 1)
    {
        if(!qu.empty() && qu.top() > a[i])
        {
            ans += qu.top() - a[i];
            qu.pop();
            qu.push(a[i]);
        }
        qu.push(a[i]);
    }
    cout << ans ;
}
