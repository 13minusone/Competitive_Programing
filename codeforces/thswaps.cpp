// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
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
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
int bl ;

int n,a[N],maxx[505];
ll res = 0;
struct BIT
{
    ll st[50100];
    void upd(int x, int val)
    {
        for(;x <= 50000; x += (x & (-x)))st[x]+= val;
    }
    ll get(int x)
    {
        if(x <= 0)return 0;
        ll ans = 0 ;
        for(;x > 0 ; x -= (x & (-x)))ans += st[x];
        return ans;
    }
}Block[505],st;
void change(int pos, int val)
{
    int l = pos/bl - 1;
    int r = pos/bl + 1;
    FOR(i,r,(n-1)/bl)
    {
        res -= Block[i].get(a[pos]-1);
        res += Block[i].get(val-1);
    }
    FOR(i,0,l)
    {
        res += (Block[i].get(maxx[i]) - Block[i].get(val));
        res -= (Block[i].get(maxx[i]) - Block[i].get(a[pos]));
    }
    FOR(i,(pos/bl)* bl,min((pos/bl+1) * bl -1,n-1))
    {
        if(i < pos){
            if(a[i] > val)res++;
            if(a[i] > a[pos])res--;
        }
        if(i > pos){
            if(a[i] < val)res++;
            if(a[i] < a[pos])res--;
        }
    }
    Block[pos/bl].upd(a[pos],-1);
    a[pos] = val;
    Block[pos/bl].upd(a[pos],1);
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
    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> a[i];
        res += i - st.get(a[i]);
        st.upd(a[i],1);
    }
    //cout << res << endl;
    bl = sqrt(n);
    FOR(i,0,n-1)
    {
        maxx[i/bl] = max(maxx[i/bl],a[i]);
        Block[i / bl].upd(a[i],1);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int pos, val;
        cin >> pos >> val;
        change(pos-1,val);
        cout << res << endl;
    }
}

