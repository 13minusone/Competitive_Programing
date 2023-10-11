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
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 3e6 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
string s, res;
int n, ns;
vector<string>full, miss;
vector<pair<string, short>> misnotfound;
bool cmp(pair<string, short> a, pair<string, short> b)
{
    return a.se > b.se;
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
    cin >> n;
    FOR(i,1,n)
    {
        cin >>s;
        ns = SZ(s);
        bool te = false;
        for(char c : s)if(c == '*'){
                te=true;
            break;
        }
        if(!te)full.pb(s);
        else miss.pb(s);
    }
    sort(all(full));
    full.resize(unique(all(full))  - full.begin());
    int t = SZ(full), nmiss = SZ(miss);
    REP(i,0,nmiss)
    {
        bool te = false;
        res = miss[i];
        for(string k : full)
        {
            FOR(j,0,ns-1)
                if( res[j] ==  k[j] || res[j] == '*')
                    te = true;
                else{
                    te = false;
                    break;
                }
            if(te)
                break;
        }
        if(!te)
            if(SZ(misnotfound) != 0)
            {
                bool fe = false;
                for(pair<string,short> &k : misnotfound)
                {
                    FOR(j,0,ns-1)
                        if(res[j] == k.fi[j])
                            fe = true;
                        else{
                            fe = false;
                            break;
                        }
                    if(fe){
                        k.se++;
                        break;
                    }
                }
                if(!fe)misnotfound.pb(make_pair(res,1));
            }
            else misnotfound.pb(make_pair(res,1));
    }
    sort(all(misnotfound), cmp);
    int nsmf = SZ(misnotfound);
//    for(pair<string,short> i : misnotfound)cout << i.fi << " " << i.se << endl;
//    cout << endl;
    FOR(i,0,nsmf-1)
    {
        bool te = false;
        pair<string, short> &x = misnotfound[i];
                short maxx = 0;
                ll bit = 0;
                string &o = x.fi;
                for(ll k = 0; k < (1 << (nsmf-i-1)); k++)
                {
                    short sum = 0;
                    string now = x.fi;
                    bool te = false;
                    FOR(ibit,0,nsmf-i-2)
                    if(getbit(k,ibit)){
                        short cur = i+1 + ibit;
                        te = false;
                        pair<string, short> op = misnotfound[cur];
                        FOR(pos,0,ns-1)
                        {
                            if(now[pos] != op.fi[pos] && now[pos] != '*' && op.fi[pos] != '*')
                            {
                                te = false;
                                break;
                            }
                            else if(now[pos] =='*' && op.fi[pos] != '*')now[pos] = op.fi[pos];
                            else te = true;
                        }
                        if(te)sum += op.se;
                        else break;
                    }
                    if(te)
                        if(maximize(maxx,sum))
                            bit = k;
                }
                //cout << i << " " << bit << " " << maxx << endl;
//                cout << i << " "<< bit << endl;
                    FOR(ibit,0,nsmf-i-2)
                    if(getbit(bit,ibit)){
                        short cur = i+1 + ibit;
                        te = false;
                        pair<string, short> &op = misnotfound[cur];
                        FOR(pos,0,ns-1)
                        {
                            if(x.fi[pos] != op.fi[pos] && x.fi[pos] != '*' && op.fi[pos] != '*')
                            {
                                te = false;
                                break;
                            }
                            else if(x.fi[pos] =='*' && op.fi[pos] != '*')x.fi[pos] = op.fi[pos];
                            else if(op.fi[pos] == '*' && x.fi[pos] !='*')op.fi[pos] = x.fi[pos];
                            else te = true;
                        }
                        x.se += op.se;
                        op.se = 0;
                    }
    }
    short ans = 0;
   // cout << endl;
    for(pair<string, short> i : misnotfound){
          // cout << i.fi  << " " << i.se<< endl;
            if(i.se != 0)ans++;
    }
    cout << SZ(full) + ans << endl;

}

