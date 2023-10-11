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

const int N = 1e2 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;

int n, m;
char a[N][N];
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
       FOR(i,1,m)cout << ".";
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
       FOR(i,1,n)cout << "." << endl;
       return;
    }
    else if(n >= 2 && m >= 2){
        cout <<"Possible" << endl;
        FOR(i,1,n)
        {
            FOR(j,1,m)cout << "^";
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

