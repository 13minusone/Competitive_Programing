#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long , long long>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

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
ll up[N] , down[N] , p[N];
void readip(){
    cin >> n >> s;
    s = ' ' + s;

    p[0] = 1;
    REP(i, 1, n) p[i] = (p[i - 1] * base) % mod;

    up[0] = down[n + 1] = 0;
    REP(i, 1, n) up[i] = (up[i - 1] * base + s[i] - 'a') % mod;
    REPD(i, n, 1) down[i] = (down[i + 1] * base + s[i] - 'a') % mod;
}

ll get_up(int l , int r){
    return (up[r] - 1LL * p[r - l + 1] * up[l - 1] + 1LL * mod * mod) % mod;
}

ll get_down(int l, int r){
    return (down[l] - 1LL * p[r - l + 1] * down[r + 1] + 1LL * mod * mod) % mod;
}

bool check(int l , int r){
    return get_up(l, r) == get_down(l , r);
}

ll res = 0;

void solve(){
    REP(i, 1, n){
        REP(len, 1, i){
            if (i + len > n) break;
            if (check(i - len + 1, i) && check(i + 1, i + len))
                ++res;
        }
    }
    cout << res;
}

int main(){
    sinh_();
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readip();
        solve();
    }
}
