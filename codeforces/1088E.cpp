     // Onegai no bug
    // Author : Nyanpasuuuuu
    #include<bits/stdc++.h>
    using namespace std;
    #define task "akarui"
    #define SZ(c) (c).size()
    #define getbit(x,i) (((x) >> (i)) & 1)
    #define turnoff(x,i) (x)&(~(1<<(i)))
    #define __builtin_popcount __builtin_popcountll
    #define all(x) (x).begin(),(x).end()
    #define pb(x) push_back(x)
    #define eb(x) emplace_back(x)
    #define endl '\n'
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

    const int N = 3e6 + 5;
    const ll mod =1e9+9;
    //const ll base = 311;
    //const int bl = 488;

    int n, x, y;
    ll dp[N], ans = -mod, d[N], k;
    vector<int>edge[N];
    void dfs(int u, int pre, bool state)
    {
        dp[u] = d[u];
        for(int v : edge[u]) if(v != pre)
        {
            dfs(v,u,state);
            dp[u] += max(dp[v], 0LL);
        }
        if(state)maximize(ans, dp[u]);
        else if(dp[u] == ans)
        {
            dp[u] = 0;
            k++;
        }
    }
    signed main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        if(fopen(task".inp","r"))
        {
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);
        }
        cin >> n;
        FOR(i,1,n)cin >> d[i];
        FOR(i,1,n-1)
        {
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        dfs(1,-1,1);
        dfs(1,-1,0);
        cout << (1LL * ans * k) << " " << k;
    }
