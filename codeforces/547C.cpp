// Onegai no bug
// Author : Nyanpasuuuu
#include<bits/stdc++.h>
using namespace std;
#define task "akarui"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 5e5+5;
const ll mod =1e9+9;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll prime[N+5],check[N],a[N];
void nhap()
{
    int q,type,x, n;
    ll ans=0;
    cin >>n >>  q;
    for(int i = 1; i <= n ;i++)cin >> a[i];
    while(q--)
    {
        cin >> x;
        vector<int>vec;
        if(!check[x]){
            check[x] = 1;
                type = 1;
        }
        else {
            type = 2;
            check[x] = 0;
        }
        x = a[x];
        for(int i = 2 ; i*i <= x ;i++)
        {
            if(x%i==0)
            {
                vec.emplace_back(i);
                while(x%i==0)x/=i;
            }
        }
        if(x>1)vec.emplace_back(x);
        int s=SZ(vec);
        for(int i = 0 ; i < mu2(s) ; i++)
        {
            int k=1;
            for(int j = 0 ; j < s; j++)
            {
                if(getbit(i,j))k*=vec[j];
            }
            if(type == 1)
            {
                if(__builtin_popcount(i)&1)ans-=prime[k];
                else ans+=prime[k];
                prime[k]++;
            }
            else
            {
                prime[k]--;
                if(__builtin_popcount(i)&1)ans+=prime[k];
                else ans-=prime[k];
            }
        }
        cout << ans << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}

