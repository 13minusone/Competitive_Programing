// Onegai no bug
// Author : Nyanpasuuuuu
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

const int N = 1e5+5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int trie[N*40][2], cnt = 0, n;
ll a[N], suf[N];
void add(ll x)
{
    int cur = 0;
    FD(i,40,0)
    {
        int k = getbit(x,i);
        if(!trie[cur][k])trie[cur][k] = ++cnt;
        cur = trie[cur][k];
    }
}
ll findmax(ll x)
{
    int cur = 0;
    ll  ans = 0;
    FD(i,40,0)
    {
        int k = getbit(x,i);
        if(trie[cur][1-k])cur = trie[cur][1-k], ans += (1LL << i);
        else cur = trie[cur][k];
    }
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
    cin >> n;
    FOR(i,1,n)cin >> a[i];
    FD(i,n,1)
        suf[i] = suf[i+1] ^ a[i];
    ll ans = 0,pre = 0;
    FOR(i,1,n)
    {
        add(pre);
        maximize(ans,findmax(suf[i]));
        pre ^= a[i];
    }
    add(pre);
    maximize(ans,findmax(0));
    cout << ans;
}

