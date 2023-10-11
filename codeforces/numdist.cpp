/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "numdist"
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
const int N = int(1e6) + 1;
const ll INF = 998244353;
int n, a[N], maxx = 0,cnt[N];
int powe(ll a, ll b)
{
    if(b == 1)return a;
    if(b == 0)return 1;
    int t = powe(a, b/2);
    if(b&1)return (((t* t) % INF)*a)%INF;
    else return (t*t)%INF;
}
void init()
{
    cin >> n;
    FOR(i,1,n){
        cin >> a[i];
        maximize(maxx,a[i]);
    }
    if(maxx <= 1e6)
    {
        FOR(i,1,n)cnt[a[i]]++;
    }
}
void process()
{
    int ans = 1;
    if(n <= 1000)
    {
        FOR(i,1,n)
        {
            FOR(j,1,i-1)
            {
                int ai = a[i], bj = a[j], res =0;
                FOR(k,1,7)
                {
                    if(ai % 10 != bj % 10)res++;
                    ai/=10;
                    bj/=10;
                }
                ans *= res;
                ans %=INF;
            }
        }
    }
    else{
        if(n > maxx){
                cout << 0;
        return;
        }
        if(maxx == n && maxx <= 1e6)
        {
            FOR(i,1,n)if(cnt[i] == 0 || cnt[i] > 1 )
            {
                cout << 0;
                return;
            }
        }
        FOR(i,1,maxx)
        {
            if(cnt[i] == 0)continue;
            FOR(j,1,i-1)
            {
                if(cnt[i] * cnt[j] > 0)
                {
                    int ai = i, bj = j, res =0;
                    FOR(k,1,4)
                    {
                        if(ai % 10 != bj % 10)res++;
                        ai/=10;
                        bj/=10;
                    }
                    ans =(1LL*ans* powe(res,1LL*cnt[i] * cnt[j]))%INF;
                }
            }
        }
    }
    cout << ans;
}
int main()
{
    fastio();
    init();
    process();
    return 0;
}
