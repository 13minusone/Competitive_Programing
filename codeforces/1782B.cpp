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

const int N = 2e5 + 5;
//const ll MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, a[N], cnt[N], pre[N];
void init(void)
{
    memset(cnt,0,sizeof cnt);
    memset(pre,0x3f,sizeof pre);
    cin >> n;
    pre[n + 1] = n + 1;
    FOR(i,1,n){
        cin >> a[i];
        cnt[a[i]]++;
        pre[a[i]] = a[i];
    }
    FD(i,n,1)
        pre[i] = min(pre[i + 1], pre[i]);
}
void process(void)
{
    sort(a + 1, a + 1 + n);
    int s = 0, ans = 0;
    FOR(i,0,n)
    {
        s += cnt[i];
        if(i == 0 && s <= i)ans++;
        if(s > i && cnt[i] > 0 && s < pre[i + 1])ans++;
       // cout << i << " " << s << " " << ans << endl;
    }
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
    int t = 1;
    cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
