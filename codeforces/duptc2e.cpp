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

const int N = 2e5 + 5;
//const ll mod =1e9+9;
//const ll base = 311;
//const int bl = 488;
static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }

  inline void tie(int) {}

  inline explicit operator bool() {
    return cur != -1;
  }

  inline static bool is_blank(char c) {
    return c <= ' ';
  }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }

  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }

  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }

  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }

#if !defined(_WIN32) |defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define cin fast_input

static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;

  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }

  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }

  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }

  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }

  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }

  template <typename T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }

  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }

  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define cout fast_output
int n, m;
ll res = 0;
vector<int>val;
ll st[4*N];
struct Data
{
    int a, b, c, d;
}a[N];
vector<Data>edge;
bool cmp1(Data a,Data b)
{
    return a.a < b.a;
}
bool cmp2(Data a, Data b)
{
    return a.b < b.b;
}
bool cmp3(Data a, Data b)
{
    if(a.a != b.a)return a.a > b.a;
    else return a.d < b.d;
}
void upd(int pos,int id = 1, int l = 1, int r = m)
{
    if(l > pos || r <pos|| l > r)return;
    if(l == r)
    {
        st[id]++;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid)upd(pos, id << 1, l, mid);
    else upd(pos, id << 1|1, mid+1, r);
    st[id] =  st[id << 1] + st[id << 1|1];
}
ll get(int u,int v,int id = 1 ,int l = 1, int r = m)
{
    if(l > v || r < u || l > r)return 0;
    if(l >= u && r <= v)return st[id];
    int mid = (l+r) >> 1;
    return get(u, v, id << 1, l, mid)+ get(u, v, id << 1|1, mid+1, r);
}
void find1()
{
      sort(a+1,a+1+n,cmp1);
        FOR(i,1,n)
        {
            int ans = n+1,l = 1, r = n;
            while(l <= r)
            {
                int mid = (l+r) >> 1;
                if(a[mid].a > a[i].c)
                {
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            res += (n-ans+1);
        }
}
void find2()
{
      sort(a+1, a+1+n, cmp2);
        FOR(i,1,n)
        {
            int ans = n+1,l = 1, r = n;
            while(l <= r)
            {
                int mid = (l+r) >> 1;
                if(a[mid].b > a[i].d)
                {
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
        res += (n-ans+1);
        }
}
signed main()
{

    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t = 0;
    cin >> t;
    while(t--)
    {
        edge.clear();
        val.clear();
        memset(st,0,sizeof st);
        res= 0 ;
        cin >> n;
        FOR(i,1,n)
        {
            cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
            edge.push_back({a[i].b,a[i].a,a[i].c,1});
            edge.push_back({a[i].d,a[i].a,a[i].c,-1});
            val.pb(a[i].c);
            val.pb(a[i].a);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        m = SZ(val)+1;
        find1();
        find2();
        //cout << res << endl;
        //upd(3);
        //cout << get(1,5) << endl;
        sort(all(edge), cmp3);
        REP(i,0,2*n)
        {
            Data query = edge[i];
            if(query.d == -1)
            {
                int k = lower_bound(all(val),query.c) - val.begin()+1;
                res -= get(k+1,m+1);
            }
            else{
                int k = lower_bound(all(val),query.b) - val.begin()+1;
                upd(k);
            }
        }
//        sort(all(edge),cmp4);
        memset(st,0,sizeof st);
        FD(i,2*n-1,0)
        {
            Data query = edge[i];
            if(query.d == -1)
            {
                int k = lower_bound(all(val),query.b) - val.begin()+1;
                upd(k);
            }
            else{
                int k = lower_bound(all(val),query.c) - val.begin()+1;
                res -= get(k+1,m+1);
            }
        }
        cout << (1LL * n *(n-1)/2) - res << endl;
    }
}
