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
#define mp make_pair
#define FOR(i,a,b) for(int i = a; i <= b; i++)

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
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e6) + 1;
const ll mod = int(1e9) + 19972207;
ll dp[N][2][2],sum[N][N][N], snum[10];
int ns, nt;
string s, t;
void add(ll &a, const ll &b)
{
    a += b;
    while(a >= mod)
        a-=mod;
}
void init()
{
    cin >> s >> t;
    ns = int(s.size());
    nt = int(t.size());
    if(ns > nt){
        swap(s,t);
        swap(ns,nt);
    }
    FOR(i,ns,nt-1)
        s = '0' + s;
    ns = nt;
     s = " " + s;
     t = " "+ t;
}
void process(const int &tc)
{
    int chamhoi = 0,schamhoi = 0;
    FOR(i,0,8){
       chamhoi += (9-i);
       FOR(j,i+1,9)
        add(schamhoi, i + j);
    }
    FOR(i,1,n)
        add(snum[i],snum[i-1] + i);
    dp[0][0][0] =  1;
    FOR(i,1,ns)
    {
        int bigger = 0, sbig = 0, smaller = 0, ssmall = 0, balance  = 0, sbalance = 0;
        int Si, Ti;
        Si = int(s[i] - '0'), Ti = int(t[i] - '0');
        if(s[i] != '?'){
            if(t[i] != '?')
                bigger = (s[i] > t[i] ? 1 : 0),sbig = (Si + Ti)*bigger;
            else
                bigger = max(Si, 0), sbig = (snum[max(Si-1,0)] + bigger * Si)*bigger;
        }
        else
        {
            if(t[i] != '?')
                bigger = max(0, 9 - Ti), sbig = (snum[9] - snum[Ti] + bigger * Ti)*bigger;
            else
                bigger = chamhoi, sbig = schamhoi;
        }
        if(t[i] != '?'){
            if(s[i] != '?')
                smaller = (s[i] < t[i] ? 1 : 0), ssmall = (Si + Ti)*smaller;
            else
                smaller = max(Ti, 0),ssmall = (snum[max(Ti-1,0)] + smaller * Ti)*smaller;
        }
        else
        {
            if(s[i] != '?')
                smaller = max(0, 9 - Si),sbig = (snum[9] - snum[Ti] + bigger * Ti)*bigger;
            else
                smaller = chamhoi;
        }
        if(t[i] != '?' && s[i] != '?')
            balance = (t[i] == s[i] ? 1 : 0);
        else if(t[i] == '?' && s[i] == '?')
            balance = 10;
        else balance = 1;
        add(dp[i][1][1], 1LL * bigger * ((dp[i-1][0][1] + dp[i-1][1][1])%mod)%mod);
        add(dp[i][1][0], 1LL * bigger * ((dp[i-1][0][0] + dp[i-1][1][0])%mod)%mod);
        add(dp[i][1][1], 1LL * smaller * ((dp[i-1][1][0] + dp[i-1][1][1])%mod)%mod);
        add(dp[i][0][1], 1LL * smaller * ((dp[i-1][0][0] + dp[i-1][0][1])%mod)%mod);
        add(dp[i][1][1], 1LL * balance * dp[i-1][1][1]%mod);
        add(dp[i][0][1], 1LL * balance * dp[i-1][0][1]%mod);
        add(dp[i][1][0], 1LL * balance * dp[i-1][1][0]%mod);
        add(dp[i][0][0], 1LL * balance * dp[i-1][0][0]%mod);
        //cout << bigger << " " << smaller << " " << balance << endl;
    }
    cout << dp[ns][1][1];
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}

