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

const int N = 1e7 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

vector<int>vec;
bool vis[N];
ll n;
int k;
void pre()
{
    for(int i = 2; i <= N-5;i++)
    {
        if(!vis[i])
        {
            vec.pb(i);
            for(ll j = 1LL *i * i; j <= N-5; j += i)
                vis[j] = 1;
        }
    }
}
bool check(ll val)
{
    int s = 0;
    if(val == 1)return 0;
    for(int i = 2; i <= sqrt(val);i++)
    {
        if(val % i == 0)return 0;
    }
    return 1;
}
bool checkk(ll val)
{
    ll s = 1;
    if(val == 1)return 1;
    int Svec = SZ(vec) - 1;
    for(int i = 0; i < k; i++)
    {
        s *= vec[i];
    }
    if(s == val)return 1;
    if(s > val)return 0;
    for(int i = k;i <= Svec;i++)
    {
        s =1LL * s/vec[i-k];
        s =1LL * s* vec[i];
        if(s > val)return 0;
        if(s == val)return 1;
    }
    return 0;
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
    int t = 1;
    pre();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k == 1)
            cout << (check(n)? "Yes" : "No") << endl;
        else
            cout << (checkk(n)? "Yes" : "No") << endl;
    }

}

