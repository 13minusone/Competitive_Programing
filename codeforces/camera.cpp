/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define FOR(i,a,b) for(int i = a; i <= b;i++)

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
}
const int N = int(1e6) + 1;
const ll INF = 1e18;
int n, r, k, t, st[4*N], maxx[4*N];
void build(int id = 1, int l = 1, int r = n)
{
    if(l == r){
        maxx[id] = l;
        return;
    }
    int mid = (l+r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid+1, r);
    maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
}
void updd(int pos, int id = 1, int l = 1, int r = n)
{
    if(l == r)
    {
        st[id] = 1;
        maxx[id] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)updd(pos, id << 1, l, mid);
    else updd(pos, id << 1|1, mid+1, r);
    st[id] = st[id << 1] + st[id << 1|1];
    maxx[id] = max(maxx[id << 1], maxx[id << 1|1]);
}
int upd(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > r || l > v || r < u)return 0;
    if(l >= u && r <= v){

    }
    int mid =(l+r) >> 1;
    return max(upd(u, v, id <<1, l, mid),upd(u, v, id << 1|1, mid+1, r));
}
int get(int u, int v, int id = 1, int l =1, int r = n)
{
    if(l > r || l > v || r < u)return 0;
    if(l >=u && r <= v)return st[id];
    int mid =(l+r) >> 1;
    return get(u, v, id << 1, l, mid) + get(u, v, id << 1|1, mid+1, r);
}
void init()
{
    cin >> n >> k >> r >> t;
    FOR(i,1,k){
        cin >> x;
        updd(x);
    }
    build()l
    FOR(i,1,n-r+1)
    {
        int res =
        if(get(i, i + r -1) <=  t)
        {

        }
    }
}
void process()
{
}
int main()
{
    fastio();
    init();
    process();
    return 0;
}

