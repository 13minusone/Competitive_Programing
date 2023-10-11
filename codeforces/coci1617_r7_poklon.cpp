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

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n,a,b,hi[N];
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
    ii maxx = ii(0,0);
    hi[1] = 1;
    FOR(i,1,n)
    {
        cin >> a >> b;
        if(a < 0)
        {
            int res = hi[i]-maxx.se;
            ll cur = maxx.fi, cur1 = -a;
            if(res < 0)cur = (cur << abs(res));
            else cur1 = (cur1 << res);
            FD(j,30,0)
                if(getbit(cur1,j) == 1 && getbit(cur,j) == 0)
                    maxx = ii(-a,hi[i]);
                else if(getbit(cur1,j) == 0 && getbit(cur,j) == 1)
                    break;
            //cout <<'a'<<" "<< cur << endl;
        }
        else hi[a] = hi[i] + 1;
        if(b < 0)
        {
            int res = hi[i]-maxx.se;
            ll cur = maxx.fi, cur1 = -b;
            if(res < 0)cur = (cur << abs(res));
            else cur1 = (cur1 << res);
            FD(j,30,0)
                if(getbit(cur1,j) == 1 && getbit(cur,j) == 0)
                    maxx = ii(-b,hi[i]);
                else if(getbit(cur1,j) == 0 && getbit(cur,j) == 1)
                    break;
            //cout <<'b'<< " "<< cur << endl;
        }
        else hi[b] = hi[i] + 1;
        //cout << maxx.fi << " " << maxx.se << " " << hi[i] << endl;
    }
    int Log= log2(maxx.fi);
    FD(i,Log,0)cout << getbit(maxx.fi,i);
    FOR(i,1,maxx.se)cout << 0;
}

