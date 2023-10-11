// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "haircut"
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

const int N = 1e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

ll BIT[N + 20], cnt[N];
int n;
void upd(int x){
    for(;x <= N; x += (x & (-x)))
        BIT[x]++;
}
ll get(int x)
{
    ll ans = 0;
    for(;x > 0; x -= (x & (-x)))
        ans += BIT[x];
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".in","r"))
    {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n)
        {
            int a;
            cin >> a;
            a++;
            upd(a);
            cnt[a] += i - get(a);
        }
        ll ans = 0;
        FOR(i,1,n)
        {
            cout << ans << endl;
            ans += cnt[i];
            //cout << i << " " << cnt[i] <<endl;
        }
    }

}

