// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "to"
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
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, ans[N];
ii a[N];
vector<ii>vec;
void init(void)
{
    cin >> n >> m;
    FOR(i,1,n)
    {
        register int l, r;
        cin >> l >> r;
        vec.pb(ii(l, 1));
        vec.pb(ii(r, -1));
    }
    FOR(i,1,m){
        cin >> a[i].fi;
        a[i].se = i;
        ans[i] = -1;
    }
}
void process(void)
{
    sort(all(vec));
    sort(a + 1, a + 1 + m);
    int id = 1;
    int cnt = 0;
    FOR(i,0,SZ(vec) - 1)
    {
        //cout << vec[i].fi << " " << vec[i].se << " " << id << endl;
        cnt += vec[i].se;
        if(vec[i].se == 1)
        {
            while(id <= m && a[id].fi < vec[i].fi && cnt == 1)
            {
                //cout << vec[i].fi << " " << a[id].fi << endl;
                ans[a[id].se] = vec[i].fi - a[id].fi;
                id++;
            }
        }
        else if(vec[i].se == -1)
        {
            while(id <= m && a[id].fi < vec[i].fi)
            {
                ans[a[id].se] = 0;
                id++;
            }
        }
    }
    FOR(i,1,m)
        cout << ans[i] << endl;
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

