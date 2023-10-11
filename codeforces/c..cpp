#include<bits/stdc++.h>
#define LL long long
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b - 1); ++i)
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define X first
#define Y second

#define pb push_back
#define ef else if
using namespace std;
const int mxn = 1e5 + 5;
const int INF = 1e9 + 7;
const int mxC = 1e7 + 5;
const int mxN = 1e6;
vector<int> a;
int sz[mxn];
bool cnt[mxC];

int findd(int u)
{
    if (sz[u] < 0) return u;
    return (sz[u] = findd(sz[u]));
}

void uni(const int &u, const int &v)
{
    if (sz[u] > sz[v])
    {
        sz[v] += sz[u];
        sz[u] = v;
    }
    else
    {
        sz[u] += sz[v];
        sz[v] = u;
    }
}

map<int, int> pos;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n; REP(i, 1, n) {int x; scanf("%d", &x); a.pb(x);}
    sort(a.begin(), a.end());
    vector<int>::iterator ip = unique(a.begin(), a.end());

    n = distance(a.begin(), ip);
    FOR(i, 0, n) {cnt[a[i]] = 1; pos[a[i]] = i;}

    FOR(i, 0, n) sz[i] = -1;
    int n_ed = n - 1, x = 0, res = 0, mx = a[n - 1];
    while(n_ed)
    {
        FOR(i, 0, n)
        {
            int t = a[i] + x;
            while(t <= mx)
            {
                if (t == a[i] || !cnt[t]) {t += a[i]; continue;}
                int u = findd(pos[t]), v = findd(i);
                if (u != v)
                {
                    res += x;
                    uni(u, v);
                    if (--n_ed == 0) break;
                }
                t += a[i];
            }
            if (n_ed == 0) break;
        }
        ++x;
    }

    cout << res << endl;
}
