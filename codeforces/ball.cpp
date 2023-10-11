/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "ball"
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
        freopen(task ".ans", "w", stdout);
    }
}
const int N = int(1e3) + 505;
const ll INF = 1e18;
ll n, sum[N];
ii point[N];
ii calVec (const ii &x, const ii &y)
{
    ii res;
    res.fi = y.fi - x.fi;
    res.se = y.se - x.se;
    int g = __gcd(abs(res.fi), abs(res.se));
   // if (y.se==2) cout << g << " " << x.fi << " " << x.se << " " << y.fi << " " << y.se << " " << res.fi << " " << res.se << endl;
    //return res;
    if (g!=0) res.fi /= g;
    if (g!=0) res.se /= g;
    swap(res.fi, res.se);
    res.fi = - res.fi;
    if(res.fi < 0)res.fi *= (-1), res.se *= (-1);
    return res;
}
void init()
{
    cin >> n;
    bool te = true;
    FOR(i,1,n){
        int x, y;
        cin >> x >> y;
        point[i] =  ii(x+20000,y+20000);
        sum[i] = sum[i-1] + i;
    }
    sort(point+1, point+1+n);
    FOR(i,1,n)
     if(i > 2)
            if(calVec(point[i], point[1]) != calVec(point[i], point[2]))te = false;
    set<tuple<ll,int,int>>se;
    ll ans = 0;
    if(te)
    {
        FOR(i,1,n)
            ans += sum[n-i];
        cout << ans*2;
        return;
    }
    else {
    FOR(i,1,n)
    {
        //cout << point[i].fi << " " << point[i].se << endl;
        se.clear();
        FOR(j,i+1,n)
        {
            ii res = calVec(point[i], point[j]);
            ll c = res.fi * point[i].fi + res.se * point[i].se;
            c *= -1;
            if(se.count({c,res.fi,res.se}) != 0){
                   // cout << i << " " << j << endl;
                    ans += 2;
            }
            else ans += 1;
            se.insert({c,res.fi,res.se});
       // cout <<i << " " << j << " " <<  res.fi << " " << res.se << " " << c << endl;
        }
    }
    cout << ans*2;
}
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
