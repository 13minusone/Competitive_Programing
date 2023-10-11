#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int INF = 1e9;
const int mod = 1e9 + 7;
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
bool vis[MAX];
char a[5];
signed main()
{
    srand(time(nullptr));
    a[1] = 'A';
    a[2] = 'G';
    a[3] = 'T';
    a[4] = 'X';
    FU(t, 1, 500)
    {
        ofstream inp("ADN.inp");
        int n = 5000, m = 2, cnt = 500;
        FU(i,1,n)vis[i]  = 0;
        while(cnt > 0)
        {
            int x = rand() % n + 1;
            if(!vis[x])
            {
                vis[x]  = 1;
                cnt--;
            }
        }
        for(int i = 1; i <= n;i++)
        {
            if(vis[i])inp << '?';
            else inp << a[rand()%4 + 1];
        }
        inp << endl;
        inp.close();
        system("test.exe");
        system("c.exe");
        if (system("fc ADN.out ADN.ans") != 0)
        {
            cout << "Test " << t << " : WRONG\n";
            return 0;
        }
        cout << "Test " << t << " : CORRECT\n";
    }
}
