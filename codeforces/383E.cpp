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

const int N = 2e7 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n ;
string s;
int a[(1LL << 24) + 5], f[(1<<24) + 5];
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
    FOR(i,1,n)
    {
        cin >> s;
        FOR(j,0,2)a[i] |= (1 << int(s[j]-'a'));
        //cout << a[i] << endl;
        f[a[i]]++;
    }
    FOR(i,0,23)
    {
        FOR(j,0,(1<<24)-1)
        {
            if(j & (1<< i))f[j] += f[j ^ (1<<i)];
        }
    }
    ll ans = 0;
    FOR(i,0,(1 << 24)-1)
    {
        ll res = n-f[(1 << 24) - 1 - i];
        ans ^= (1LL* res * res);
    }
    cout << ans;
}

