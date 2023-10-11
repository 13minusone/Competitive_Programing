// Onegai no bug
// Author : 13minusone
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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, a[N], d[N], cnt = 0;
int c[5] = {2,0,2,3};
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> d[i];
}
void process(void)
{
    int id = 0;
    cnt = 0;
    FOR(i,1,n)
    {
        a[++id] = d[i];
        if(id >= 4)
        {
            bool check = 1;
            FOR(j,1,4)
            {
                if(a[id - 4 + j] != c[j - 1]){
                        check = 0;
                    break;
                }
               // cout << id << " " << id - 4 + j << " " << j + 1 << endl;
            }
            if(check){
                cnt++;
                id -= 4;
            }
        }
        //cout << i << " " << id << endl;
    }
    if(cnt == 0)cout << " :( " << endl;
    else if(cnt&1)cout  << "Bedao" << endl;
    else cout << "Bemai" << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 1;
    cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


