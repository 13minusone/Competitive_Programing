/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "akarui"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define FOR(i,a,b) for(int i = a; i <= b;i++)

typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
int n;
const int N = int(1e6) + 1;
const ll INF = 1e18;
ii dp[26][10];
ii solve(int pos, int sum, )
void init()
{
    cin >> n;

}
void process()
{
}
int main()
{
    fastio();
    init();
    process();
    return 0;
}

