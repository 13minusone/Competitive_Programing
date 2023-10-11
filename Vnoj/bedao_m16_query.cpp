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

const int N = 5e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, m, a[N];
int st[4 * N], lz[4 * N], lz_and[4 * N];
void down(int id)
{
    if(lz[id] != -1){
        st[id << 1] = lz[id];
        st[id << 1 | 1] = lz[id];
        lz[id << 1] = lz[id << 1|1] = lz[id];
        lz_and[id << 1] = lz_and[id << 1|1] = lz_and[id];
        lz[id] = -1;
    }
    if(lz_and[id] != -1)
    {
        st[id << 1] &= lz_and[id];
        st[id << 1|1] &= lz_and[id];
        lz_and[id << 1] &= lz_and[id];
        lz_and[id << 1|1] &= lz_and[id];
        lz_and[id] = -1;
    }
}
void upd1(int u, int v, int val, int id = 1, int l = 1, int r = n)
{
    if(l > v || u > r || u > v || l > r)return;
    if(l >= u & r <= v){

        if(lz[id] == -1){
            st[id] &= val;
            if(lz_and[id] == -1)lz_and[id] = val;
            else lz_and[id] &= val;
        }
        else{
            lz[id] &= val;
            st[id] &= val;
        }
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    upd1(u, v, val, id << 1, l, mid);
    upd1(u, v, val, id << 1|1, mid + 1, r);
    st[id] = st[id << 1] | st[id << 1|1];
}
void build(int id = 1,int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    st[id] = st[id << 1] | st[id << 1|1];
}
void upd2(int u, int v, int  val, int id = 1, int l = 1, int r = n)
{
    if(l > v || u > r || u > v || l > r)return;
    if(l >= u && r <= v)
    {
        lz[id] = val;
        st[id] = val;
        lz_and[id] = -1;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    upd2(u, v, val, id << 1, l, mid);
    upd2(u, v, val, id << 1|1, mid + 1, r);
    st[id] = st[id << 1] | st[id << 1|1];
}
int getVal(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || u > r || u > v || l > r)return 0;
    if(l >= u && r <= v)return st[id];
    down(id);
    int mid = (l + r) >> 1;
    return (getVal(u, v, id << 1, l, mid) |
    getVal(u, v, id << 1|1, mid + 1, r));
}
void init(void)
{
    cin >> n >> m;
    fill(lz,lz + 4 * n + 1, -1);
    fill(lz_and,lz_and + 4 * n + 1, -1);
    FOR(i,1,n)
        cin >> a[i];

}
void process(void)
{
    build();
    while(m--)
    {
        register int type, l, r, x;
        cin >> type >> l >> r;
        if(type == 3)
        {
            cout << getVal(l, r) << endl;
        }
        else
        {
            cin >> x;
            if(type == 2)
                upd2(l, r, x);
            else
                upd1(l, r, x);
        }
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


