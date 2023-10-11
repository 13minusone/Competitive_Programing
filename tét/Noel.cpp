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
int n, a[N], ans1[N], ans2[N];
bool mark[N];
void init(void)
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
}
bool check(int i, int j)
{
    int p = 0, o = 0, id = j, res = -1;
    FOR(x,1,n)
        mark[x] = 0;
    mark[i] = mark[j] = 1;
    FOR(x,j + 1, n)
        if(a[x] - a[id] == a[j] - a[i]){
            mark[x] = 1;
            id = x;
        }
    FOR(i,1,n)
        if(mark[i] == 1)ans1[++p] = a[i];
        else if(res == -1 || a[i] - ans2[o] == res){
            if(o != 0)
                res = a[i] - ans2[o];
            ans2[++o] = a[i];
        }
    if(p + o == n){
        if(p == 0)ans1[++p] = ans2[o], o--;
        else if(o == 0){
            ans2[++o] = ans1[p], p--;
        }
        if(ans1[1] < ans2[1]){
        cout << p << endl;
        FOR(k,1,p)cout << ans1[k] <<" ";
        cout << endl;
        cout << o << endl;
        FOR(k,1,o)cout << ans2[k] << " " ;
        }
        else{
            cout << o << endl;
            FOR(k,1,o)cout << ans2[k] <<" ";
            cout << endl;
            cout << p << endl;
            FOR(k,1,p)cout << ans1[k] << " " ;
        }
        return true;
    }
    else return false;
}
void sub2()
{
    FOR(i,1,n)
        FOR(j,i + 1,n)if(check(i, j))return;
    cout << -1;
}
bool Case1()
{
    int p = 0, o = 0;
    ans1[++p] = a[n];
    ans1[++p] = a[n - 1];
    FOR(i,1,n)
        mark[i] = 0;
    FD(i,n - 2, 1)
        if(ans1[p] - a[i] == ans1[1] - ans1[2]){
            ans1[++p] = a[i];
            mark[i] = 1;
        }
    FOR(i,n-2,1)
        if(!mark[i]){
            if(o >= 2 && ans2[1] - ans2[2] == ans2[2] - a[i])
                ans2[++o] = a[i];
            else ans2[++o] = a[i];
        }
        else if(o >= 2 && ans1[p])
    if(o + p == n)
    {
        if(p == 0)ans1[++p] = ans2[o], o--;
        else if(o == 0){
            ans2[++o] = ans1[p], p--;
        }
        cout << p << endl;
        FD(i,p,1)
            cout << ans1[p] << " ";
        cout << o << endl;
        FD(i,o,1)
            cout << ans2[p] << " " ;
        return true;
    }
    else return false;
}
void process(void)
{
    sort(a + 1, a + n + 1);
    if(n <= 300)sub2();
    else{
        if(Case1())return;
        else{
            int o = 0, p = 0;
            ans1[++o] = a[n];
            ans2[++o] = a[n - 1];
            cout << -1;
        }
    }
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


