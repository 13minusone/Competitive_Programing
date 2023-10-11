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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

int n, a[N], cnt[N], f[N], q;
set<ii>s;
void init(void)
{
    cin >> n;
    FOR(i,1,n){
        cin >> a[i];
        if(a[i] > n)f[i] = 3 * n;
        else{
        if(a[i] < i)
            f[i] = n - i + a[i];
        else
            f[i] = a[i] - i;
        }
        if(f[i] <= 2 * n)cnt[f[i]]++;
        //cout << i << " "<< f[i] << endl;
    }
}
void process(void)
{
    s.insert(ii(n,0));
    FOR(i,0,2 * n)
        if(cnt[i] != 0)
            s.insert(ii(i + n - cnt[i], i));
    cin >> q;
    FOR(i,1,q)
    {
        int x, b;
        cin >> x >> b;
        if(f[x] <= 2 * n)
        {
            s.erase(ii(f[x] + n - cnt[f[x]], f[x]));
            cnt[f[x]]--;
            if(cnt[f[x]])s.insert(ii(f[x] + n - cnt[f[x]],f[x]));
        }
        if(b > n) f[x] = 3 * n;
        else {
            if(b < x)
            f[x] = n - x + b;
            else
            f[x] = b - x;
        }
        if(f[x] <= 2 * n)
        {
            s.erase(ii(f[x] + n - cnt[f[x]], f[x]));
            cnt[f[x]]++;
            s.insert(ii(f[x] + n - cnt[f[x]], f[x]));
        }
           // cout << x << " " << f[x] << endl;
        ii ans = *s.begin();
        cout << ans.fi << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    cerr << "TIME : " << TIME << "s\n";
}

