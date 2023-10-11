// Onegai no bug
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
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,ll> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 1e6 + 5;
const ll INF = 6e9 + 5;
//const ll base = 311;
//const int BLOCK = 488;

ll mod,a, b;
struct Matrix {
    int a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator *(const Matrix& other) const {
        Matrix product;
        for(int i : {0, 1}) {
            for(int j : {0, 1}) {
                for(int k : {0, 1}) {
                    product.a[i][k] = (product.a[i][k]
                            + (long long) a[i][j] * other.a[j][k]) % mod;
                }
            }
        }
        return product;
    }
};
Matrix expo_power(Matrix a, long long n) {
    Matrix res;
    res.a[0][0] = res.a[1][1] = 1;
    while(n) {
        if(n % 2) {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}
Matrix cal(int n){
    Matrix single;
    single.a[0][0] = 0;
    single.a[0][1] = 1;
    single.a[1][0] = 1;
    single.a[1][1] = 1;
    return expo_power(single, n);
}
map<ii, ll>mp;
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
    cin >> t;
    while(t--)
    {
        cin >> mod >> a >> b;
        int Jump = sqrt(1LL * 6 * mod);
        Matrix PowUp  = cal(Jump);
        //cout <<Jump << " " <<  PowUp.a[0][0] << " " <<PowUp.a[0][1] << endl;
        Matrix cur = PowUp;
        mp.clear();
        mp[{0,1}] = 0;
        for(ll i = Jump;i <= 6 * mod;i += Jump)
        {
           // cout << cur.a[0][1] << " " << cur.a[1][1] << endl;
            if(mp.find(ii(cur.a[0][1], cur.a[1][1])) == mp.end())
            {
                mp[ii(cur.a[0][1], cur.a[1][1])] = i;
            }
            cur =   cur *  PowUp;
        }
        ll Big = b, Small = a;
        ll ans = INF;
        for(ll i = 0; i <= Jump; i++)
        {
            //cout << mp[ii(Small, Big)] << endl;
            if(mp.find(ii(Small, Big)) != mp.end())
            {
                minimize(ans,mp[ii(Small, Big)] + i);
            }
            swap(Big, Small);
            Small = (Small - Big + mod)%mod;
            //cout <<i << " "<<  Small << " " << Big << " " << ans << endl;
        }
        if(ans != INF)cout << ans << endl;
        else cout << -1 << endl;
    }

}
