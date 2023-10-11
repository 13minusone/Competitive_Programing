// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "ddd"
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
int n;
void init(void)
{
    cin >> n;
}
void process(void)
{
    vector<int>a, tmp;
    FOR(i,1,n)
        a.pb(i);
    ii ans = ii(-1,-1);
    int sum = 0;
    while(SZ(a) != 0)
    {
        if(sum + 1000 > 90000)break;
        int x = (SZ(a) - 1)/2;
        sum += 1000;
        tmp.clear();
        char c;
        cout << "compare_k" << " "<< a[x] << endl;
        cin >> c;
        if(c == '<')
        {
            ans.fi = a[x];
            for(int i : a)if(i != a[x])
            {
                cout << "compare" << " " << a[x] << " " << i<< endl;
                cin >> c;
                sum++;
                if(c == '<')tmp.pb(i);
            }
        }
        else
        {
            ans.se = a[x];
            for(int i : a)if(i != a[x])
            {
                cout << "compare" << " " << a[x] << " " << i << endl;
                cin >> c;
                sum++;
                if(c == '>')tmp.pb(i);
            }
        }
        a = tmp;
    }
    if(ans.fi != -1 && ans.se != -1)cout <<"answer"<< " " <<  ans.fi << "  "<< ans.se << endl;
    else cout <<"no_answer" << endl;
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
    //cin >> t;
    while(t--)
    {
        init();
        process();
    }
    cerr << "TIME : " << TIME << "s\n";
}


