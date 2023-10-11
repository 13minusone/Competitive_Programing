// Author : Nyanpasuuuuu
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
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int, char> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
const int INF =1e9+7;
//const ll base = 311;
//const int BLOCK = 488;
int n, cnt[30], num[N];
ii occ[30];
string s;
void init(void)
{
    cin >> n;
    cin >> s;
    s = " " + s;
}
bool cmp(pair<int,int> u, pair<int,int> v)
{
     if(u.fi != v.fi)return u.fi < v.fi;
    else return u.se > v.se;
}
void trace(int sameCnt) {
    int targetCount = n / sameCnt;
    vector<int> targetCnt(30, 0);
    REP(i,0,sameCnt)
        targetCnt[occ[i].se -'a'] = targetCount;
    FOR(j,1,n) {
        char ch = s[j];
        if (cnt[ch-'a'] > targetCnt[ch-'a']) {
            REP(i,0,sameCnt){
            if (cnt[occ[i].second-'a'] < targetCnt[occ[i].se-'a']) {
                cnt[occ[i].second-'a']++;
                cout << occ[i].se;
                break;
                }
            }
        cnt[ch-'a']--;
    }else cout << ch;
    }
    cout << endl;
    return ;
}
void process(void)
{
    memset(cnt,0,sizeof cnt);
    FOR(i,1,n)
        cnt[s[i] - 'a']++;
    REP(i,0,26) {
      occ[i] = {cnt[i], 'a'+i};
    }
    sort(occ, occ + 26, greater<pair<int, char>>());
    int ans = INF,h = -1;
    FOR(i,1,26)if(n%i == 0){
        int targetCount = n / i;
        int sum = 0;
        REP(j,0,i) {
            sum += min(targetCount, occ[j].first);
        }
        if(minimize(ans, n - sum))h = i;
    }
    //cout << h << endl;
    cout << ans << endl;
    trace(h);
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
    int t = 1;
    cin >> t;
    while(t--)
    {
       // cout << t << endl;
        init();
        process();
    }

}

