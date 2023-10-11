// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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

int n, m, k;
bool  d[605][605];
int clique[605], deg[605];
bool check(int l)
{
    FOR(i,1,l)
        FOR(j,i+1,l)
            if(!d[clique[i]][clique[j]])return false;
    return true;
}
bool findd(int start, int l, int s)
{
    FOR(i,start+1,n-s+l + 1)
    {
        if(deg[i] >= s-1)
        {
            clique[l] = i;
            if(check(l))
                if(l < s){
                    if(findd(i,l+1,s))return true;
                }
                else{
                    FOR(j,1,l)printf("%d ",clique[j]);
                    cout << endl;
                    return true;
                }
        }
    }
    return false;
}
signed main()
{

    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(d,0,sizeof d);
        FOR(i,1,m)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            d[x][y] = 1, d[y][x] = 1;
            deg[x]++;
            deg[y]++;
        }
        short cnt = 0;
        FOR(i,1,n)if(deg[i] >= k-1)cnt++;
        if(!findd(0,1,k))
            cout << -1 << endl;

    }
}

