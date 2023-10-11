/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "camera"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define FOR(i,a,b) for(int i = a; i <= b;i++)
#define FD(i,a,b) for(int i = a; i >= b; i--)

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
const int N = int(1e6) + 1;
const ll INF = 1e18;
int n, r, k, t, d[N], cnt[N];
void init()
{
    cin >> n >> k >> r >> t;
    FOR(i,1,k){
        register int x;
        cin >> x;
        d[x]=1;
    }
    int res = 0, ans = 0;
    FOR(i,1,r-1)
    {
        if(d[i] == 0)res++;
    }
    FOR(i,1,n-r+1)
    {
        if(d[i+r-1] == 0)res++;
        if(res > r- t)cnt[i+r-1] = res -r+t;
        while(res > r-t)res--,ans++;
        if(d[i] == 0 && res - (d[i+r-1] == 0 ? 1 : 0)> 0)res--;
    }
    res = 0;
    vector<int>vec;
    FD(i,n,1)
    {
        res += cnt[i];
        //cout << i << " "<< cnt[i] << endl;
        if(d[i] == 0 && res >  0)vec.pb(i), res--;
    }
    cout << ans << endl;
    FD(i,ans-1,0)cout << vec[i] << " " ;
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

