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
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int a[N], maxx[N], minn[N], cnt[2 * N], n;
ll solve(int l, int r)
{
    if(l == r)
        return 1;
    int mid = (l+r) >> 1;
    ll ans = solve(l, mid) + solve(mid + 1, r);
    minn[mid] = maxx[mid] = a[mid];
    minn[mid + 1] = maxx[mid + 1] = a[mid + 1];
    FD(i,mid-1,l){
        minn[i] = min(minn[i + 1], a[i]);
        maxx[i] = max(maxx[i + 1], a[i]);
    }
    FOR(i,mid + 2, r){
        minn[i] = min(minn[i - 1], a[i]);
        maxx[i] = max(maxx[i - 1], a[i]);
    }
    // maxx , minn in l
    FD(i,mid, l)
    {
        int x = i + maxx[i] - minn[i];
        if(x > mid && x <= r && maxx[x] < maxx[i] && minn[x] > minn[i])
            ans++;
    }
    // maxx , minn in e
    FOR(i,mid + 1, r)
    {
        int x = i - maxx[i] + minn[i];
        if(x >= l && x <= mid && maxx[x] < maxx[i] && minn[x] > minn[i])
            ans++;
    }
    // maxx in r, minn in l && maxx in l,minn in r
    int i1 = mid + 1, i2 = mid + 1;
    FD(i,mid,l)
    {
        while(i1 <= r && minn[i1] > minn[i])
        {
            cnt[maxx[i1] - i1 + n]++;
            i1++;
        }
        while(i2 < i1 && maxx[i2] < maxx[i])
        {
            cnt[maxx[i2] - i2 + n]--;
            i2++;
        }
        ans += cnt[minn[i] - i + n];
    }
    while(i2 < i1)
    {
        cnt[maxx[i2] - i2 + n]--;
        i2++;
    }
    i1 = mid, i2 = mid;
    FOR(i,mid + 1, r)
    {
        while(i1 >= l && minn[i1] > minn[i])
        {
            cnt[maxx[i1] + i1]++;
            i1--;
        }
        while(i2 > i1 && maxx[i2] < maxx[i])
        {
            cnt[maxx[i2] + i2]--;
            i2--;
        }
        ans += cnt[minn[i] + i];
    }
    while(i2 > i1)
    {
        cnt[maxx[i2] + i2]--;
        i2--;
    }
    return ans;
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
    {
        register int x, y;
        cin >> x >> y;
        a[x] = y;
    }
}
void process(void)
{
    cout << solve(1,n);
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
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}

