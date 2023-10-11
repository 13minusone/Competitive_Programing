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
//const int MOD =1e9+7;
//const ll base = 311;
const int BLOCK = 488;
//const int INF = 1e9 + 7;
struct Data
{
    int l, r, id;
    Data(int _l = 0, int _r = 0, int _id = 0)
    {
        l = _l;
        r = _r;
        id = _id;
    }
    bool operator < (const Data &other)const{
        if(l / BLOCK != other.l / BLOCK)return (l/BLOCK) < (other.l / BLOCK);
        else return r < other.r;
    }
};
int n, a[N], cnt[N], ans[N], res = 0, q;
vector<Data>query;
void add(int &id)
{
    if(cnt[a[id]] == 0)res++;
    cnt[a[id]]++;
}
void del(int &id)
{
    if(cnt[a[id]] == 1)res--;
    cnt[a[id]]--;
}
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    cin >> q;
    FOR(i,1,q)
    {
        int l, r;
        cin >> l >> r;
        query.pb(Data(l, r, i));
    }
}
void process(void)
{
    sort(all(query));
    int l = 1, r = 0;
    for(Data i : query)
    {
        while(l < i.l)del(l), l++;
        while(l > i.l)add(--l);
        while(r > i.r)del(r), r--;
        while(r < i.r)add(++r);
        ans[i.id] = res;
    }
    FOR(i,1,q)
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

