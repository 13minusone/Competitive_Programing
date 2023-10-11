// Author : Nyanpasuuuuu
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
//const int MOD = 1e9+7;
//const int base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, p[N], q[N];
ll ans = 0, Sum[N];
ii idp[N], idq[N], Np, Nq;
void init(void)
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> p[i];
        idp[i] = ii(p[i], i);
    }
    FOR(i,1,n)
    {
        cin >> q[i];
        idq[i] = ii(q[i], i);
    }
}
ii calLeft(int x, ii a)
{
    if(a.fi > x)
    {
        return ii(min(x + 1, a.fi), a.fi);
    }
    else if(a.se < x)
    {
        return ii(1, a.fi);
    }
}
ii calRight(int x, ii a)
{
    if(a.fi > x)
    {
        return ii(a.se, n);
    }
    else if(a.se < x)
    {
        return ii(a.se , max( x - 1, a.se));
    }
}
void process(void)
{
    FOR(i,1,n)
        Sum[i] = Sum[i - 1]  + i;
    sort(idp + 1, idp + n + 1);
    sort(idq + 1, idq + n + 1);
    int xP = idp[1].se, xQ = idq[1].se;
    ans += Sum[min(xP - 1, xQ - 1)];
    ans += Sum[n - max(xP, xQ)];
    ans += Sum[max(xP, xQ) - min(xP, xQ) - 1];
    Np = ii(xP,xP);
    Nq = ii(xQ,xQ);
    FOR(i,2,n)
    {
        xP = idp[i].se, xQ = idq[i].se;
        ii lP, lQ, rP, rQ;
        lP = calLeft(xP, Np);
        lQ = calLeft(xQ, Nq);
        rP = calRight(xP, Np);
        rQ = calRight(xQ, Nq);

        if(xP >= Np.fi && xP <= Np.se){
                if(!minimize(Nq.fi, xQ))
                    maximize(Nq.se, xQ);
                continue;
        }
        if(xQ >= Nq.fi && xQ <= Nq.se){
            if(!minimize(Np.fi, xP))
                    maximize(Np.se, xP);
                continue;
        }
        ii l , r;
        l.fi = max(lP.fi, lQ.fi);
        l.se = min(lP.se, lQ.se);
        r.fi = max(rP.fi, rQ.fi);
        r.se = min(rP.se, rQ.se);
        ans += 1LL * max(0, l.se - l.fi + 1) * max(0, r.se - r.fi + 1);
//        cout << rP.fi << " " << rP.se << " " << rQ.fi << " " << rQ.se << endl;
//        cout << l.fi << " "<< l.se << " " << r.fi << " " << r.se << endl;
//        cout <<i << " " <<  ans << endl;
        if(!minimize(Np.fi, xP))
            maximize(Np.se, xP);
        if(!minimize(Nq.fi, xQ))
            maximize(Nq.se, xQ);

    }
    cout << ans + 1 << endl;
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
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }

}
