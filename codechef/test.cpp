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

const int N = 5e5 + 5;
//const ll MOD =1e17+9;
//const ll base = 311;
//const int BLOCK = 488;
const int INF = 1e9 + 7;
int n, ans = INF, k;
string s, x;
void init(void)
{
    cin >> n >> k;
    cin >> s;
    s = " " + s;
}
void process(void)
{
    ans = INF;
    queue<int>q;
    FOR(i,1,n)
    {
        if(s[i] == '0')
                if(s[i - 1] != '0')
                    q.push(i);
        //cout << s[i] << endl;
        if(i >= k)
        {
            int x = q.size() - 1;
            if(x < 0){
                minimize(ans, 0);
            }
            else{
                if(q.front() == i - k + 1)
                    minimize(ans, x * 2 + 1);
                else
                    minimize(ans,(x + 1) * 2);
            }
            if(i - k + 2 <= n && s[i - k + 2] == '1' && q.front() == i - k + 1)
                q.pop();
            else if(q.front() == i - k + 1 && i - k + 2 <= n)
                q.front() = i - k + 2;
            //cout << q.front() << endl;
        }

    }
    cout << ans << endl;
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


