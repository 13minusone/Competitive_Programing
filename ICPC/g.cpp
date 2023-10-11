/// Do the solution on the paper
/// Author: Lê Nguyễn Anh Khoa
/// 20TI Lương Thế Vinh
#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
#define pb push_back
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define endl '\n'
#define SZ(x) (int)((x).size())
#define dem(x) __builtin_popcount(x)
#define rep(i, n) for(int i = 0;i < n;++i)
#define fi first
#define se second
//#define int long long
typedef pair<int,int> ii;
typedef long long ll;
const ll mod = 1e9 + 7; //998244353
/// Free solution have not to pay
const int N = 1e6 + 5;
int p[N], n, m, ans, a[N], b[N];
set<int> s[N];
int root(int u){
    return p[u] < 0 ? u : p[u] = root(p[u]);
}
void join(int u, int v){
    if((u = root(u)) == (v = root(v)))return;
    if(p[u] > p[v])swap(u, v);
    p[u] += p[v]; p[v] = u;
}
struct BIT{
    int bit[N];
    void add(int i, int x){
        if(i <= 0)return;
        for(; i < N; i += i&-i)
            maxx(bit[i], x);
    }
    int get(int i){
        int res = 0;
        for(; i > 0; i ^= i&-i)
            maxx(res, bit[i]);
        return res;
    }
    int get(int l, int r){
        return get(r) - get(l-1);
    }
}bit;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("test.inp","r",stdin);
    cin >> n >> m;
    FOR(i, 1, n)cin >> a[i];
    memset(p, -1, sizeof p);
    while(m--){
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    FOR(i, 1, n)s[root(i)].insert(a[i]);
    FOR(i, 1, n){
        int pa = root(i);
        int j = *s[pa].lower_bound(b[i-1]);
        if(i < n && j > *s[root(i+1)].begin())
            j = *s[pa].rbegin();
        s[pa].erase(j);
//        cout << i << ' ' << j << endl;
        b[i] = j;
        int res = bit.get(j-1) + 1;
        bit.add(j, res);
        maxx(ans, res);
    }
    cout << ans;
}

