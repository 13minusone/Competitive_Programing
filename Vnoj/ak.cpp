#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define PB push_back

using namespace std;

int n, k, a[N], pointer[11];
ll s[N], sum[N], dp[N][11];
vector<ll> U[11], V[11];
bool check(int id, int l1, int l2, int l3)
{
    return (V[id][l3] - V[id][l1]) * (U[id][l1] - U[id][l2]) < (V[id][l2] - V[id][l1]) * (U[id][l1] - U[id][l3]);
}
void add(int id, ll u, ll v)
{
    U[id].PB(u);
    V[id].PB(v);
    while (U[id].size() >= 3 && check(id, U[id].size()-3, U[id].size()-2, U[id].size()-1))
    {
        U[id].erase(U[id].end()-2);
        V[id].erase(V[id].end()-2);
    }
}
ll get(int id, int x)
{
    if (pointer[id] >= U[id].size()) pointer[id] = U[id].size()-1;
    while (pointer[id] < U[id].size() - 1 && U[id][pointer[id]]*x + V[id][pointer[id]] > U[id][pointer[id]+1]*x + V[id][pointer[id]+1])
        pointer[id]++;
    return U[id][pointer[id]]*x + V[id][pointer[id]];
}
int main()
{
    freopen("akarui.inp", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    reverse(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
        s[i] = s[i-1] + sum[i];
    }
    add(0, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j > i) break;
            dp[i][j] = s[i-1] + get(j-1, i);
            add(j, -sum[i], dp[i][j] - s[i] + sum[i]*(i+1));
            cout <<i << " " << j << " "<< dp[i][j]  << endl;
        }
    }
    cout <<dp[n][k];
}

