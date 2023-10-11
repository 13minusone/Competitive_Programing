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
#define endl '\n'
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
const ll mod = 1e9+7;
//const ll base = 311;
//const int bl = 488;

int n;
void add(int &y,int x)
{
    y+=x;
    if(y >= mod)y -= mod;
}
struct IT
{
    ii st[4*N];
    void upd(int pos, ii val, int id, int l, int r)
    {
        if(l > r)return;
        if(l == r)
        {
            if(st[id].fi == val.fi)add(st[id].se,val.se);
            else maximize(st[id],val);
            return;
        }
        int m = (l+r) >> 1;
        if(pos <= m)upd(pos, val, id << 1, l, m);
        else upd(pos, val, id << 1|1, m+1, r);
        if(st[id << 1].fi == st[id << 1|1].fi)st[id] = ii(st[id<<1].fi, (st[id << 1].se + st[id << 1|1].se)%mod);
        else st[id] = max(st[id <<1],st[id << 1|1]);
    }
    ii get(int u,int pos, int id, int l, int r)
    {
        if(l > pos || l > r  || r < u)return ii(0,0);
        if(r <= pos && l >= u)return st[id];
        int m = (l+r) >> 1;
        ii lef = get(u, pos, id << 1, l, m);
        ii rig = get(u, pos, id << 1|1, m+1, r);
        if(lef.fi == rig.fi)return ii(lef.fi, (rig.se + lef.se) %mod);
        else return max(lef,rig);
    }
}am,duong;
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
    ii res = ii(0,0);
    FOR(i,1,n)
    {
        int x;
        cin >> x;
        if(x == 0)continue;
        if(x < 0)
        {
            ii ans = duong.get(1,abs(x)-1,1,1,N-5);
            ans.fi++;
            if(ans.se == 0)ans.se++;
            am.upd(abs(x),ans,1,1,N-5);
            if(res.fi == ans.fi)add(res.se , ans.se);
            else maximize(res,ans);
            //cout << ans.fi << " " << ans.se << endl;
        }
        else
        {
            ii ans = am.get(1,x-1,1,1,N-5);
            ans.fi++;
            if(ans.se == 0)ans.se++;
            duong.upd(x,ans,1,1,N-5);
            if(res.fi == ans.fi)add(res.se, ans.se);
            else maximize(res,ans);
            //cout << ans.fi << " " << ans.se << endl;
        }
        //cout << res.fi <<  " " << res.se << endl;
    }
    cout << res.fi <<  " " << res.se << endl;

}

