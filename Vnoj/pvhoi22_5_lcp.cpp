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

const int N = 4e6 + 5;
//const int MOD =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
//const int INF = 1e9 + 7;
int n, k, Size[N], op = 0, ID[N];
ll dp[2 * 5005][5005], tmp[5005];
string s;
vector<ii>adj[N];
int getID(int x)
{
    if(ID[x] == 0){
        ID[x] = ++op;
    }
    return ID[x];
}
struct TRIE
{
    struct Data
    {
        int End, Depth;
        int child[26];
    };
    Data trie[N];
    int cnt = 0;
    int Newnode(){
        cnt++;
        trie[cnt].End = 0;
        FOR(i,0,25)
            trie[cnt].child[i] = 0;
        return cnt;
    }
    void add(string &s)
    {
        int sz = SZ(s), cur = 0;
        s = " " + s;
        FOR(i,1,sz)
        {
            int word = s[i] - 'a';
            if(trie[cur].child[word] == 0)
                trie[cur].child[word] = Newnode();
            cur = trie[cur].child[word];
        }
        trie[cur].End++;
        return;
    }
    void dfs(int u, int pre, int depth)
    {
        trie[u].Depth = depth;
        int numchild = 0;
        FOR(i,0,25)
            if(trie[u].child[i] > 0)numchild++;
        if(trie[u].End > 0 || numchild > 1){
            if(u != pre){
                adj[getID(pre)].pb(ii(getID(u), depth - trie[pre].Depth));
            }
            pre = u;
        }
        if(trie[u].End > 0)
            Size[getID(u)] = trie[u].End;
        FOR(i,0,25)
            if(trie[u].child[i] > 0)
                dfs(trie[u].child[i], pre, depth + 1);
    }
}tree;
void solve(int u)
{
    for(ii &v : adj[u])
    {
        solve(v.fi);
        FOR(i,0,min(k,Size[u]))
            FOR(j,0,min(k - i,Size[v.fi]))
                tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v.fi][j] + 1LL * (1LL * j * (j - 1) / 2) * v.se);
        Size[u] += Size[v.fi];
        FOR(i,0,min(k, Size[u])){
            dp[u][i] = tmp[i];
            tmp[i] = 0;
        }
    }
}
void init(void)
{
    cin >> n >> k;
    FOR(i,1,n){
        cin >> s;
        tree.add(s);
    }
}
void process(void)
{
    tree.dfs(0,0,0);
    solve(1);
    cout << dp[1][k];
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


