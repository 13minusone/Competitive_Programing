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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;

const int MAX = 1111 * 1111 + 1;
int n;
int p[MAX];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    int t = 1;
    vector<int> primes;
    for(int i = 2; i <= MAX; i++)
        if(!p[i])
        {
            primes.pb(i);
            for(int j = i; j <= MAX; j += i) if(!p[j]) p[j] = i;
        }
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll s = n * n + 1;
        for(auto &p : primes) if(s % p == 0)
        {
            cout << p << " " << s/p << '\n';
            break;
        }
    }

}

