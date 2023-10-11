// i'm wutan
#include <bits/stdc++.h>
#define EL cout<<endl
#define pli pair<ll,ll>
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ll(a.size())
#define FU(x,a,b) for(ll x=ll(a);x<=ll(b);x++)
#define FD(x,a,b) for(ll x=ll(a);x>=ll(b);x--)
#define PROB "xorsequence"

using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// ordered_set name_of_set;
// ll pos = *name_of_set.find_by_order(ll(value));
*/
typedef long long ll;
typedef double db;

/*
template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
*/

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}
const bool love = true;
const ll N = 2e4 + 2;
const ll BC = 200;
ll n, m, t, a[N];
ll f[BC + 1][N], XOR[N], F[101][N];
vector < ll > dp[2];
/*
    XOR[i]= (a[1] ^ a[2] ^ a[3] ^ .... ^ a[i])
    f[len][i] : tổng xor lớn nhất của đoạn con thuôc [i, i + len - 1]

    chia N số thành N / BC đoạn
    mỗi đoạn có BC phần tử, riêng đoạn cuối có N % BC phần tử
    F[j][i] : tổng xor lớn nhất của đoạn con thuộc 'j' đoạn liên tiếp tính từ vị trí i

*/
void readinp(){
    cin >> n >> m >> t;

    FU(i, 1, n) cin >> a[i];
}

void init(){
    XOR[0] = 0; FU(i, 1, n) XOR[i] = XOR[i-1] ^ a[i];
    FU(i, 1, n) f[1][i] = a[i];
    FU(len, 2, BC){
        FU(i, 1, n - len + 1)
            f[len][i] = max({f[len-1][i], f[len-1][i+1],
                             XOR[i + len - 1] ^ XOR[i-1]});
    }


    dp[0].resize(n + 1, 0); dp[1].resize(n + 1, 0);
    FU(i, 1, n) F[1][i] = dp[0][i] = f[BC][i];
    FU(j, 2, 100){
        FU(p, 1, BC){
            FU(i, 1, n){
                if (i + p + BC * (j - 1) - 1 > n) break;
                dp[1][i] = max({dp[0][i], dp[0][i+1],
                                XOR[i + p + BC * (j - 1) - 1] ^ XOR[i-1]});
            }
            swap(dp[0], dp[1]);
        }
        FU(i, 1, n) F[j][i] = dp[0][i];
    }
}

void cal(ll l, ll r){
    ll res = 0;
    FU(i, l, r){
        FU(j, i, r){
            res = max(res, XOR[j] ^ XOR[i-1]);
        }
    }
    cout << res,EL;
}

void solve(){
    init();
    ll ans = 0;
    while (m--){
        ll x, y;
        cin >> x >> y;
        x = ((x + ans * 1LL * t) % n) + 1;
        y = ((y + ans * 1LL * t) % n) + 1;
        ll l = min(x, y), r = max(x, y);
//        ll l, r; cin >> l >> r;
        ll len = r - l + 1;
        if (len <= BC){
            ans = f[r - l + 1][l];
            goto here;
        }
        else{
            if (len % BC == 0){
                ans = F[len / BC][l];
                goto here;
            }
            else{
                ll rem = len % BC;
                ll tbc = (len / BC) * BC;

                FU(i, 0, rem) dp[0][i] = F[len / BC][l +  i];
                FU(s, 1, rem){
                    FU(i, 0, rem - s){
                        dp[1][i] = max({dp[0][i], dp[0][i+1],
                                       XOR[l + i + tbc + s - 1] ^ XOR[l + i - 1]});
                    }
                    swap(dp[0], dp[1]);
                }

                ans = dp[0][0];
                goto here;
            }
        }
        cout << "hello";
        here:;
        cout << ans;EL;
    }
}

int main(){
    setIO();
    ll t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}
