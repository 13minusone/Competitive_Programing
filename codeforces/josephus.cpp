// Onegai no bug
// Author : 13minusone
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
tree < int ,  null_type , less<int>,  rb_tree_tag ,  tree_order_statistics_node_update > o;
typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
int binpow(int a, int b){
	if(b==0) return 1;
	if(b%2==1) return binpow(a,b-1)*a;
	int r=binpow(a,b/2);
	return r*r;
}
void solve(){
	int n,k; cin>>n>>k;
	for(int i=0;i<n;i++) o.insert(i+1);
	int x=k;
	while(o.size()){
		x%=o.size();
		auto it=o.find_by_order(x);
		cout<<*it<<" ";
		o.erase(it);
		x+=k;
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
    	int t=1;
	while(t--) { solve();}
}
