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
int n, m, k;
char c;
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
    while(t--)
    {
        cin >> n >> m >> k;
        vector<ii>vec[60002];
        FOR(i,1,m+1)vec[0].pb(ii(0,0));
        FOR(i,1,n+1)vec[i].pb(ii(0,0));
        int ans = 0;
        FOR(i,1,n)
        {
            FOR(j,1,m)
            {
                cin >> c;
                vec[i].pb(ii(0,0));
                vec[i][j].fi = vec[i-1][j].fi + vec[i][j-1].fi - vec[i-1][j-1].fi;
                vec[i][j].se = vec[i-1][j].se + vec[i][j-1].se - vec[i-1][j-1].se;
                if(c == 'A')vec[i][j].fi++;
                else vec[i][j].se++;
                //cout << cntb << " " ;
                //cout << vec[i][j].se << " ";
                FOR(x,1,i)
                {
                    if((i-x+1)*j<= ans)continue;
                    FOR(y,1,j)
                    {
                        int res = abs((vec[i][j].fi - vec[x-1][j].fi - vec[i][y-1].fi + vec[x-1][y-1].fi)
                                      - (vec[i][j].se - vec[x-1][j].se - vec[i][y-1].se + vec[x-1][y-1].se));
                        //if(i == 2 && j == 4)cout <<x <<" "<< y << " "<<vec[i-1][y].fi<< endl;
                        if(res <= k)
                        {
                            maximize(ans,(i-x+1)*(j-y+1));
                           //cout << i << " " << j << " " << x << " "<< y<< endl;
                        }
                    }
                }
            }
            //cout << endl;

        }
        cout << ans << endl;
    }

}

