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

const int N = 2e6 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, a[N], cnt[N];
vector<int>val;
void init(void)
{
    cin >> n;
    n = 2 * n;
    REP(i,0,n){
        cin >> a[i];
        val.pb(a[i]);
    }
    sort(all(val));
}
void process(void)
{
    if(n <= 2000)
    {
        int ans = 0;

        FOR(i,0,n-2)
        {
            FOR(i,0,n-1)
                cnt[i] = 1;
            int diff = val[n - 1] - val[i], s = n;
            FOR(i,0,n-1)
                if(cnt[i])
                {
                    int k = lower_bound(all(val), val[i] + diff) - val.begin();
                    if(k  < SZ(val) && val[k] == val[i] + diff){
                        s -= 2;
                        cnt[i] = 0;
                        cnt[k] = 0;
                    }
                  //  cout << i << " " << k << " " <<val[i] << " " <<  val[i] + diff << endl;
                }
            //cout <<"COUT"<< diff << " " << s << " " << val[n - 1]<< endl;
            if(s == 0)ans++;
        }
        cout << ans << endl;
    }
    else
    {
        n/=2;
        int s = 0;
        FOR(i,1,n)
            if(n % i == 0)s++;
        cout << s;
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


