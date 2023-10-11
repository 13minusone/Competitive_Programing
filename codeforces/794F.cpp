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

const int N = 1e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int block = 488;

struct node
{
    int change[10];
    ll sum[10];
};
node st[4 * N];
int n;
ll  mu10[10], a[N];
node Megre(node u, node v)
{
    node re;
    FOR(i,0,9)
    {
        re.sum[i] = u.sum[i] + v.sum[i];
        re.change[i] = i;
    }
    return re;
}
ll sum1[10],sum2[10], m;
void push(int id)
{
    FOR(i,0,9)sum1[i] = sum2[i] = 0;
    FOR(i,0,9)
    {
        st[id << 1].change[i] = st[id].change[st[id << 1].change[i]];
        st[id << 1|1].change[i] = st[id].change[st[id << 1|1].change[i]];

    }
    FOR(i,0,9)
    {
        sum1[st[id].change[i]] += st[id << 1].sum[i];
        sum2[st[id].change[i]] += st[id << 1|1].sum[i];
    }
    FOR(i,0,9){
        st[id << 1].sum[i] = sum1[i];
        st[id << 1|1].sum[i] =  sum2[i];
        st[id].change[i] = i;
    }
}
void build(int id = 1,int l = 1,int r = n)
{
    if(l == r)
    {
        ll val = a[l], j = 0;
        while(val)
        {
            st[id].sum[val%10] += mu10[j];
            val /= 10;
            j++;
        }
        FOR(i,0,9)st[id].change[i] = i;
        return;
    }
    int m = (l+r) >> 1;
    build(id << 1, l, m);
    build(id << 1|1, m+1, r);
    st[id] = Megre(st[id << 1], st[id << 1|1]);
}
void upd(int u, int v, int old, int neww, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return;
    if(l >= u && r <= v)
    {   ll ss = st[id].sum[old];
        st[id].sum[old] = 0;
        st[id].sum[neww] += ss;
        FOR(i,0,9)if(st[id].change[i] == old)st[id].change[i] = neww;
        return;
    }
    push(id);
    int m = (l+r) >> 1;
    upd(u, v, old, neww, id << 1, l, m);
    upd(u, v, old, neww, id << 1|1, m+1, r);
    st[id] = Megre(st[id << 1], st[id << 1|1]);
}
ll get(int u, int v, int id = 1, int l = 1, int r = n)
{
    if(l > v || r < u || l > r)return 0;
    if(l >= u && r <= v)
    {
        ll s = 0;
        FOR(i,0,9)s += (1LL * i * st[id].sum[i]);
        return s;
    }
    int m = (l+r) >> 1;
    push(id);
    return get(u, v, id << 1, l, m) + get(u , v, id << 1|1, m+1, r);
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
    cin >> n >> m;
    mu10[0]= 1;
    FOR(i,1,9)mu10[i] = mu10[i-1]*10;
    FOR(i,1,n)
        cin >> a[i];
    build();
    while(m--)
    {
        int type, l, r, old, neww;
        cin >> type >> l >> r;
        if(type == 1)
        {
            cin >> old >> neww;
            upd(l, r, old, neww);
        }
        else cout << get(l, r) << endl;
    }
}
