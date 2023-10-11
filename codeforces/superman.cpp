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

int n, m, k,d[N];
int cal(int x,int y,int pa,int pb)
{
    memset(d,0,sizeof d);
    int node = 0, s=0, dif = (x == y);
    x%= n;
    y%= n;
    d[x] = 1,d[y] = 1;
    FOR(i,1,n){
        x = x + pa;
        if(x > 0)x%=n;
        y = y + pb;
        if(y > 0)y %=n;
        if(x < 0)x+=n;
        if(y < 0)y+=n;
        if(node >= n-2 + dif)return s;
        if(!d[x])
        {
            d[x] = 1;
            node++;
        }
        else{
            pa*= (-1), x += 2*pa;
            if(x > 0)x%= n;
            if(x < 0)x+=n;
            if(!d[x])
            {
                d[x] = 1;
                node++;
            }
        }
         if(!d[y])
        {
            d[y] = 1;
            node++;
        }
        else{
            pb*= (-1), y+= 2*pb;
            if(y > 0)y%=n;
            if(y < 0)y+=n;
            //cout << pb << endl;
            if(!d[y])
            {
                d[y] = 1;
                node++;
            }
        }
        s++;
       // cout <<x << " " << y  <<" " << node << endl;
    }
    return s;
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
    cin >> n >> m >> k;
    if(m == 1)
    {
        int x, y;
        cin >>x >> y;
        //cout << cal(x,y,1,-1) << endl;
        cout << min({cal(x,y,1,1),cal(x,y,-1,-1),cal(x,y,1,-1),cal(x,y,-1,1)});
    }
}

