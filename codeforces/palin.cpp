// Onegai no bug
// Author : 13minusone
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

const int INF = 1e9 , mod = 1e9 + 19972207;

template <class T1, class T2>
inline T1 mul(T1& x, const T2 &k){ return x = (1LL * x * k) % mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, const T &y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, const T &y){ if (x < y){x = y; return 1;} return 0; }

template<typename T>
void read(T &x){
    char ch;
    for(ch = getchar(); !isdigit(ch); ch = getchar());
    x = ch - '0';
    for(ch = getchar(); isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
}

template<typename T>
void write(T x){
    if (x < 10){
        putchar(x + '0');
    } else {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}

#define PROB "a"
void file(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".out","w",stdout);
    }
}
void sinh_(){
//    srand(time(0));
//    freopen(PROB".inp" , "w" , stdout);
//    int n;
}
typedef long long ll;
const ll base = 331 , N = 5e5 + 5;
string s;
int n;
ll len[N] , xuong[N] , p[N];
void readip(){
    cin >> n >> s;
    s = ' ' + s;

    p[0] = 1;
    FOR(i, 1, n) p[i] = (p[i - 1] * base) % mod;

    len[0] = xuong[n + 1] = 0;
    FOR(i, 1, n) len[i] = (len[i - 1] * base + s[i] - 'a') % mod;
    FD(i, n, 1) xuong[i] = (xuong[i + 1] * base + s[i] - 'a') % mod;
}

ll get_len(int l , int r){
    return (len[r] - 1LL * p[r - l + 1] * len[l - 1] + 1LL * mod * mod) % mod;
}

ll get_xuong(int l, int r){
    return (xuong[l] - 1LL * p[r - l + 1] * xuong[r + 1] + 1LL * mod * mod) % mod;
}

bool check(int l , int r){
    return get_len(l, r) == get_xuong(l , r);
}

ll res = 0;

void solve(){
    FOR(i, 1, n){
        FOR(lon, 1, i){
            if (i + lon > n) break;
            if (check(i - lon + 1, i) && check(i + 1, i + lon))
                ++res;
        }
    }
    cout << res;
}
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    sinh_();
    io_faster;
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readip();
        solve();
    }
}
