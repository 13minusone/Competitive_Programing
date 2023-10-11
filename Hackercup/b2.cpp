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

const int N = 3e3 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m, f[N][N];
char a[N][N];
int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,1,-1};
bool cango(int x,int y)
{
    if(x >= 1 && y >= 1 && x <= n && y <= m)return true;
    else return false;
}
void sol()
{
    if(n == 1)
    {
        FOR(i,1,m)
            if(a[1][i] == '^')
            {
                cout <<"Impossible" << endl;
                return;
            }
       cout << "Possible" << endl;
       FOR(i,1,m)cout << a[1][i];
       cout << endl;
       return;
    }
    else if(m == 1){
         FOR(i,1,n)
            if(a[i][1] == '^')
            {
                cout <<"Impossible" << endl;
                return;
            }
       cout << "Possible" << endl;
       FOR(i,1,n)cout << a[i][1]<< endl;
       return;
    }
    else if(n >= 2 && m >= 2){
        memset(f,0,sizeof f);
        FOR(i,1,n)a[i][0] = a[i][m+1] = '#';
        FOR(i,1,m)a[0][i] = a[n+1][i] = '#';
        queue<ii>qu;
        FOR(i,0,n+1)  FOR(j,0,n+1)if(a[i][j] == '#'){
            f[i][j] = 5;
            qu.push(ii(i,j));
        }
        while(!qu.empty())
        {
            ii x = qu.front();
            qu.pop();
            FOR(k,0,3)
            {
                int dirx = x.fi + dx[k];
                int diry = x.se + dy[k];
                if(cango(dirx,diry)){
                    f[dirx][diry]++;
                    if(f[dirx][diry] == 3)
                    {
                        qu.push(ii(dirx, diry));
                    //cout << dirx << " " << diry << endl;
                    }
                }
            }
        }
        FOR(i,1,n)
            FOR(j,1,m)
                if(f[i][j] > 2 && a[i][j] == '^')
                {
                    cout << " Impossible" << endl;
                    return;
                }
        cout << " Possible" << endl;
        FOR(i,1,n){
            FOR(j,1,m){
                if(f[i][j] <= 2)a[i][j] = '^';
                cout << a[i][j];
            }
            cout << endl;
        }
        return;
    }
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
    int t;
    cin >> t;
    FOR(Test, 1, t)
    {
        cin >> n >> m;
        FOR(i,1,n)
        {
            FOR(j,1,m)
            {
                cin >> a[i][j];
            }
        }
        cout << "Case #" << Test << ": ";
       sol();
    }
}

