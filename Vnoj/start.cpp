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
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int sum = 0;
int n;
void init(void)
{
    cin >> n;
    FOR(i,1,2006)
    {
        int x = i;
        cout << x << endl;
        while(x > 0)
        {
            if((x % 10)%2 == 0)
            {
                sum += (x %10);
            }
            x/=10;
        }
    }
    cout << sum;
}
void process(void)
{
}
signed main()
{
    int t = 1;
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


