// Author : 13minusone
#include<bits/stdc++.h>
using namespace std;
#define task "DICHUYEN"
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
int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,1,-1};
char dc[5] = {'D','U','R','L'};
int SubTask, n, m, trace[180][180];
char a[180][180];
bool vis[180][180];
ii sta, en;
string s;
void init(void)
{
    cin >> SubTask;
    cin >> n >> m;
    FOR(i,1,n)
    {
        cin >> s;
        s = " " + s;
        FOR(j,1,m){
            a[i][j] = s[j];
            if(s[j] == 'S')
                sta = ii(i, j);
            if(s[j] == 'E')
                en = ii(i, j);
        }
    }
    cin >> s;
}
void sub1()
{
    FOR(i,min(sta.se, en.se), max(sta.se,en.se))
        if(s[i] == '#'){
            cout << -1;
            return;
        }
    int x = sta.se, ans = abs(st.se - en.se), id = 0, l = 0;
    int add = SZ(s);
    FOR(i, 0, SZ(s) - 1){
        char c = s[i];
        if(c == 'L' && x > 1)x--;
        if(c == 'R' && x < m)x++;
        if(minimize(ans, abs(x - en.se))){
            id = x;
            l = i + 2;
        }
       // cout << c << " "<< x << endl;
    }
    //cout << x << " " << ans << endl;
    if(ans < abs(x - en.se)){
        x = id;
        id = -1;
    }
    else id = 0;
    char c;
    int Po;
    if(id == -1)Po++;
    cout << Po << endl;
    FOR(i,1,Po + id)
    {
        cout << "INS" <<" " << add << " "<<c << endl;
        add++;
    }
    if(id == -1)
        cout << "DEL " << l << " " << SZ(s) << endl;
}
bool CanGo(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
void sub2(ii u)
{
    memset(vis, 0, sizeof vis);
    vis[u.fi][u.se] = 1;
    queue<ii>qu;
    qu.push(u);
    string tr = "-1";
    while(!qu.empty())
    {
        ii x = qu.front();
        qu.pop();
        if(x == en){
            tr = "";
            while(x != sta)
            {
                int id = trace[x.fi][x.se];
                tr = tr + dc[trace[x.fi][x.se]];
                x.fi -= dx[id];
                x.se -= dy[id];
            }
            break;
        }
        FOR(i,0,3){
            int nx = x.fi + dx[i];
            int ny = x.se + dy[i];
            if(CanGo(nx,ny) && !vis[nx][ny] && a[nx][ny] != '#')
            {
                trace[nx][ny] = i;
                vis[nx][ny] = 1;
                qu.push(ii(nx, ny));
            }
        }
    }
    if(tr == "-1")cout << -1 << endl;
    else{
        cout << SZ(tr) << endl;
        int add = SZ(s);
        reverse(all(tr));
        for(char c : tr){
            cout << "INS" <<" " << add << " "<<c << endl;
            add++;
        }
    }
}
void process(void)
{
    if(SubTask == 1)sub1();
    else if(SubTask == 2)sub2(sta);
    else{
        sub1();
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

