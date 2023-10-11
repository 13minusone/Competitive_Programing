#include<bits/stdc++.h>
using namespace std;
#define task "long"
#define pb push_back
//#define int long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define MASK(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 20
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)
const int MAX = 5e5 + 5;
const int INF = 1e9;
const int base = 998244353;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
template<class X, class Y> bool maximize(X &x, Y y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y> bool minimize(X &x, Y y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    return false;
}
bool used[105];
int a[105][105], Col[105], Row[105];
signed main()
{
    srand(time(nullptr));
    FOR(t, 1, 100)
    {
        ofstream inp("test.inp");
        int n = 20;
        inp << n << endl;
        for(int i = 1; i <= n;i++)
        {
            FOR(j,1,n){
                a[i][j] = rand() %3 - 1;
                inp << a[i][j]<< " ";
            }
            inp << endl;
        }
        FOR(i,1,n){
            Row[i] = rand() % 2;
            Col[i] = rand() % 2;
            if(Row[i] == 0)Row[i]--;
            if(Col[i] == 0)Col[i]--;
        }
        for(int i = 1; i <= n;i++)
        {
            FOR(j,1,n)
                inp << a[i][j] * Row[i] * Col[j] << " ";
            inp << endl;
        }
        inp.close();
        system("CTAB.exe");
        system("c.exe");
        if (system("fc test.out test.ans") != 0)
        {
            cout << "Test " << t << " : WRONG\n";
            return 0;
        }
        cout << "Test " << t << " : CORRECT\n";
    }
}


