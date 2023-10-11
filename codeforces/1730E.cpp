// Author : Nyanpasuuuuu
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
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int a[N], n, cnt[N];
ll ans = 0;
vector<int>divisible[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
}
void DnC(int l = 1, int r = n)
{
    if(l == r){
        ans++;
        return;
    }
    int mid = (l+r) >> 1;
    int minn = INF, maxx = 0, lmin = mid, lmax = mid, minn1 = INF, minn2 = INF;
    FOR(i, mid + 1, r)
    {
        minimize(minn, a[i]);
        maximize(maxx, a[i]);
        while(lmin >= l && a[lmin] >= minn)
        {
            minimize(minn1, a[lmin]);
            cnt[minn1]--;
            lmin--;
        }
        while(lmax >= l && a[lmax] <= maxx)
        {
            minimize(minn2, a[lmax]);
            cnt[minn2]++;
            lmax--;
        }
        if(maxx % minn == 0)ans += max(0, mid - max(lmin, lmax));
        if(lmax <=lmin)
        {
            for(int v : divisible[maxx])
                ans += cnt[v];
        }
    }
    FOR(i,l,mid)cnt[a[i]] = 0;
    minn = INF, maxx = 0, lmin = mid + 1, lmax = mid + 1, minn1 = INF, minn2 = INF;
    FD(i, mid, l)
    {
        minimize(minn, a[i]);
        maximize(maxx, a[i]);
        while(lmin <= r && a[lmin] > minn)
        {
            minimize(minn1, a[lmin]);
            cnt[minn1]--;
            lmin++;
        }
        while(lmax <= r && a[lmax] < maxx)
        {
            minimize(minn2, a[lmax]);
            cnt[minn2]++;
            lmax++;
        }
        if(maxx % minn == 0)ans += max(0,min(lmin, lmax) - mid - 1);
        if(lmax >= lmin)
        {
            for(int v : divisible[maxx])
                ans += cnt[v];
        }
    }
    FOR(i,mid + 1,r)cnt[a[i]] = 0;
    DnC(l, mid);
    DnC(mid + 1, r);
}
void process(void)
{
    ans = 0;
    DnC();
    FOR(i,1,n)cnt[a[i]] = 0;
    cout << ans << endl;
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
     FOR(i,1,N - 5)
        for(int j = 2 * i; j <= N - 5; j += i)
            divisible[j].pb(i);
    int t = 1;
    cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
