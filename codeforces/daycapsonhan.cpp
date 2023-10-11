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

const int N = 1e5 + 1;
const ll mod = 1e9+7;
//const ll base = 311;
//const int bl = 488;
int n, q, x, cnt, a[N], Log, d[N];
ll  s[N], dp[N][31];
vector<int>vec;
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
    FOR(i,1,n){
        cin >> a[i];
        vec.pb(a[i]);
    }
    sort(all(vec));
    vec.resize(unique(all(vec))- vec.begin());
    FOR(i,1,n)
    {
        x = lower_bound(all(vec), a[i]) - vec.begin();
        dp[x][1]++;
        if(a[i]%q == 0)
        {
            int k = lower_bound(all(vec), a[i]/q) - vec.begin();
            //cout << x << " "<< k << endl;
            if(vec[k] == a[i]/q)
            {
                FOR(j,2,30)
                {
                    if(dp[k][j-1] == 0)break;
                    dp[x][j] += dp[k][j-1];
                    s[j] += dp[k][j-1];
                    dp[x][j] %= mod;
                    s[j] %= mod;
                    //cout << i << " " << j << " " << dp[k][j-1] << endl;

                }
            }
            //cout << dp[x][2] << endl;

        }

    }
    FOR(j,2,n)cout << s[j] << " ";
}

