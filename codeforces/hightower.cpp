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

const int N = 3e6 + 5;
const int mod =2e9+9;
//const ll base = 311;
//const int block = 488;
int n, m, a, b, x, y, z, d,c[5005][5005],f[5005][5005];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m >> a >> b >> x >> y >> z;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            d = (1LL*d*x%z + y%z)%z;
            c[i][j] = d;
        }
    FOR(i,1,n)
    {
        deque<ii>qu;
        FOR(j,1,b)
        {
            while(!qu.empty() && qu.back().fi < c[i][j])qu.pop_back();
            qu.push_back(ii(c[i][j],j));
        }
        f[i][1] = qu.front().fi;
//        cout << f[i][1] << " ";
        FOR(j,2,m-b+1)
        {
            while(!qu.empty() && qu.front().se < j)qu.pop_front();
            while(!qu.empty() && (qu.back().fi < c[i][j+b-1]||qu.back().se < j))qu.pop_back();
            qu.push_back(ii(c[i][j+b-1],j+b-1));
            f[i][j] = qu.front().fi;
            //cout << f[i][j] << " \n"[j == m - b+1];
        }
    }
    int minn = mod;
    FOR(j,1,m-b+1)
    {
        deque<ii>qu;
        FOR(i,1,a)
        {
            while(!qu.empty() && qu.back().fi < f[i][j])qu.pop_back();
            qu.push_back(ii(f[i][j],i));
        }
        minimize(minn,qu.front().fi);
        FOR(i,2,n-a+1)
        {
            while(!qu.empty() && qu.front().se < i)qu.pop_front();
            while(!qu.empty() && (qu.back().fi < f[i+a-1][j]||qu.back().se < i))qu.pop_back();
            qu.push_back(ii(f[i+a-1][j],i+a-1));
            minimize(minn,qu.front().fi);
            //cout << qu.front().fi << " \n"[i == n - a+1];
        }
    }
    cout << minn << endl;
}

