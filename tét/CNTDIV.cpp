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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

const int N = 1e6 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, Prime[N];
void sang()
{
    FOR(i,2,N - 2)
        if(!Prime[i])
            for(int j = i; j <= N - 2; j+= i)
                Prime[j] = i;
}
void init(void)
{
    cin >> n;
}
map<int,int>mp;
void calPrime(int x)
{
    while(x > 1)
    {
        mp[Prime[x]]++;
        x /= Prime[x];
    }
}
void process(void)
{
    mp.clear();
    calPrime(n);
    calPrime(n + 1);
    calPrime(n + 2);
    ll sub = 1, ans = 1;
    for(ii v : mp)
    {
        sub *= (v.se + 1);
        ans *= (2 * v.se + 1);
    }
    cout << ans/2  - sub + 1 << endl;
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
    sang();
    cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}

