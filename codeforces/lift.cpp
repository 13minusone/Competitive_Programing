    /// KoJa
    #include <bits/stdc++.h>
    using namespace std;
    #define task "test"
    #define pb push_back
    #define SZ(a) (a).begin(), (a).end()
    #define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
    #define BIT(a) (1LL << (a))
    #define vec vector
    #define fi first
    #define se second
    #define mp make_pair
    #define FOR(i,a,b) for(int i = a; i <= b; i++)

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
    void init()
    {
        int t;
        cin >> t;
        if(t == 1)cout << "1";
        else if(t == 2)cout << "10";
        else {
            while(t--)
            cout << "1";
        }
    }
    void process(const int &tc)
    {
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

