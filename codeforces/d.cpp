/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "akarui"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define mp make_pair
#define MASK(x, i) (((x) >> (i))&1)

typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e6) + 1;
const ll INF = 1e18;
const int mod = int(1e9) + 19972207;
void add(int &a, const int &b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
int n, dp[N][3];
string a, b;
int getState(int x, int y)
{
    if(x > y)
        return 0;
    if(x < y)
        return 1;
    return 2;
}
int notState(int x, int y)
{
    if(x > y)
        return 1;
    if(x < y)
        return 0;
    return 2;
}
void init()
{
    cin >> a >> b;
    n = (int)a.size();
    a = " " + a;
    b = " " + b;
}
void process(const int &tc)
{
    int res = 0;
    dp[0][2] = 1;
    for(int i = 1; i <= n; i++)
    {
        if((a[i] == '?')&&(b[i] == '?'))
        {
            for(int x = 0; x <= 9; x++)
                for(int y = 0; y <= 9; y++)
                {
                    if(x == y)
                    {
                        add(dp[i][0], dp[i - 1][0]);
                        add(dp[i][1], dp[i - 1][1]);
                        add(dp[i][2], dp[i - 1][2]);
                    }
                    if(x > y)
                    {
                        add(dp[i][0], dp[i - 1][2]);
                        add(dp[i][0], dp[i - 1][1]);
                        add(res, dp[i - 1][1]);
                    }
                    if(x < y)
                    {
                        add(dp[i][1], dp[i - 1][2]);
                        add(dp[i][1], dp[i - 1][0]);
                        add(res, dp[i - 1][0]);
                    }
                }
        }
        else if(b[i] == '?')
        {
            int x = a[i] - '0';
            for(int y = 0; y <= 9; y++)
            {
                if(x == y)
                {
                    add(dp[i][0], dp[i - 1][0]);
                    add(dp[i][1], dp[i - 1][1]);
                    add(dp[i][2], dp[i - 1][2]);
                }
                if(x > y)
                {
                    add(dp[i][0], dp[i - 1][2]);
                    add(dp[i][0], dp[i - 1][1]);
                    add(res, dp[i - 1][1]);
                }
                if(x < y)
                {
                    add(dp[i][1], dp[i - 1][2]);
                    add(dp[i][1], dp[i - 1][0]);
                    add(res, dp[i - 1][0]);
                }
            }
        }
        else if(a[i] == '?')
        {
            int y = b[i] - '0';
            for(int x = 0; x <= 9; x++)
            {
                if(x == y)
                {
                    add(dp[i][0], dp[i - 1][0]);
                    add(dp[i][1], dp[i - 1][1]);
                    add(dp[i][2], dp[i - 1][2]);
                }
                if(x > y)
                {
                    add(dp[i][0], dp[i - 1][2]);
                    add(dp[i][0], dp[i - 1][1]);
                    add(res, dp[i - 1][1]);
                }
                if(x < y)
                {
                    add(dp[i][1], dp[i - 1][2]);
                    add(dp[i][1], dp[i - 1][0]);
                    add(res, dp[i - 1][0]);
                }
            }
        }
        else
        {
            int x = a[i] - '0';
            int y = b[i] - '0';
            if(x == y)
            {
                add(dp[i][0], dp[i - 1][0]);
                add(dp[i][1], dp[i - 1][1]);
                add(dp[i][2], dp[i - 1][2]);
            }
            if(x > y)
            {
                add(dp[i][0], dp[i - 1][2]);
                add(dp[i][0], dp[i - 1][1]);
                add(res, dp[i - 1][1]);
            }
            if(x < y)
            {
                add(dp[i][1], dp[i - 1][2]);
                add(dp[i][1], dp[i - 1][0]);
                add(res, dp[i - 1][0]);
            }
        }
    }
    cout << res;
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
