// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "KHONG"
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
int SubTask, n, q;
struct Data
{
    int num2, num5;
}a[N];
struct ST
{
    vector<ll>vec, lz;
    int n;
    void init(int _n = 0)
    {
        n = _n;
        vec.resize(4 * n);
        lz.resize(4 * n);
    }
    void Down(int id, int l, int r)
    {
        int mid = (l+r) >> 1;
        vec[id << 1] += 1LL * (mid - l + 1) *lz[id];
        vec[id << 1|1] += 1LL * (r - mid) *lz[id];
        lz[id << 1] += lz[id];
        lz[id << 1|1] += lz[id];
        lz[id] = 0;
    }
    void upd(int u, int v, int val, int id, int l, int r)
    {
        if(l > v || r < u || l > r || u > v)return;
        if(l >= u && r <= v)
        {
            vec[id] += (r - l + 1) * val;
            lz[id] += val;
            return;
        }
        int mid = (l+r) >> 1;
        Down(id,l, r);
        upd(u, v, val, id << 1, l, mid);
        upd(u, v, val, id << 1|1, mid + 1, r);
        vec[id] = vec[id << 1] + vec[id << 1|1];
    }
    ll getSum(int u, int v, int id, int l, int r)
    {
        if(l > v || r < u || l > r || u > v)return 0;
        if(l >= u && r <= v)return vec[id];
        Down(id, l, r);
        int mid = (l+r) >> 1;
        return getSum(u, v, id << 1, l, mid) + getSum(u, v, id << 1|1, mid + 1, r);
    }
    void Build(int id, int l,int r, int T)
    {
        if(l == r)
        {
            if(T)vec[id] = a[l].num5;
            else vec[id] = a[l].num2;
            return;
        }
        int mid = (l+r) >> 1;
        Build(id << 1, l, mid, T);
        Build(id << 1|1, mid + 1, r, T);
        vec[id] = vec[id << 1] + vec[id << 1|1];
    }
}Tree2, Tree5;
void init(void)
{
    cin >> SubTask;
    cin >> n >> q;
    FOR(i,1,n){
        register int x;
        cin >> x;
        while(x > 0 && x % 2 == 0)
        {
            a[i].num2++;
            x /= 2;
        }
        while(x > 0 && x % 5 == 0)
        {
            a[i].num5++;
            x /= 5;
        }
    }
    Tree2.init(n);
    Tree5.init(n);
    Tree2.Build(1,1,n,0);
    Tree5.Build(1,1,n,1);
}
int cal2(ll x)
{
    int num2 = 0;
   while(x > 0 && x % 2 == 0)
        {
            num2++;
            x /= 2;
        }
    return num2;
}
int cal5(ll x)
{
    int num5 = 0;
    while(x > 0 && x % 5 == 0)
    {
        num5++;
        x /= 5;
    }
    return num5;
}
char Type;
void sub1()
{
    while(q--)
    {
        register int l, r, x, y;
        cin >> Type >> l >> r;
        if(Type != 'C')
        {
            cin >> x >> y;
            if(Type == 'A'){
                FOR(i,l,r)
                {
                    ll p = x + 1LL * (i - l) * y;
                    a[i].num2 += cal2(p);
                    a[i].num5 += cal5(p);
                }
            }
            else
            {
                int Cou2 = cal2(x), Cou2y = cal2(y);
                int Cou5 = cal5(x), Cou5y = cal5(y);
                ll num2 = Cou2;
                ll num5 = Cou5;
                FOR(i,l,r)
                {
                    a[i].num2 += num2;
                    a[i].num5 += num5;
                    num2 += Cou2y;
                    num5 += Cou5y;
                }
            }
        }
        else{
            ll num2 = 0, num5 = 0;
            FOR(i,l,r)
            {
                num2 += a[i].num2;
                num5 += a[i].num5;
            }
            cout << min(num2,num5) << " ";
        }
    }
}
void sub2()
{
    while(q--)
    {
        register int l, r, x, y;
        cin >> Type >> l >> r;
        if(Type != 'C')
        {
            cin >> x >> y;
            int Cou2 = cal2(x), Cou2y = cal2(y);
            int Cou5 = cal5(x), Cou5y = cal5(y);
            Tree2.upd(l, r, Cou2,1,1,n);
            Tree5.upd(l, r, Cou5,1,1,n);
        }
        else{
            ll num2 = Tree2.getSum(l, r,1,1,n), num5 = Tree5.getSum(l, r,1,1,n);
            cout << min(num2,num5) << " ";
        }
    }
}
void process(void)
{
    if(SubTask == 1)sub1();
    else if(SubTask == 2)sub2();
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


