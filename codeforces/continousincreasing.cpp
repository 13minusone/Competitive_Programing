#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
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

  #if !defined(_WIN32) | defined(_WIN64)
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

namespace segmentTree
{
	LL input[MAX];
	struct data
	{
		LL ans,Lis,Ris,L,R,Lm,Rm;
	};
	data tree[3*MAX];
	data combine_data(data left,data right)
	{
		data res;
		res.ans = max(left.ans,right.ans);
		if(left.Rm < right.Lm)
			res.ans = max(res.ans,left.Ris + right.Lis);

		res.L = left.L; res.R = right.R;
		res.Lm = left.Lm; res.Rm = right.Rm;
		res.Lis = left.Lis; res.Ris = right.Ris;

		if(left.Lis == (left.R - left.L +1) && left.Rm < right.Lm)
			res.Lis += right.Lis;
		if(right.Ris == (right.R - right.L +1) && left.Rm < right.Lm)
			res.Ris += left.Ris;

		return res;
	}
	data make_data(int val,int b)
	{
		data res;
		res.ans = res.Lis = res.Ris = 1;
		res.Lm = res.Rm = val;
		res.L = res.R = b;
		return res;
	}
	void init_tree(int node,int b,int e)
	{
		if(b==e) // leaf node
		{
			tree[node] = make_data(input[b],b);
			return ;
		}
		int mid = (b+e)/2;
		init_tree(2*node,b,mid);
		init_tree(2*node+1,mid+1,e);
		tree[node] = combine_data(tree[2*node],tree[2*node+1]);
	}
	void update(int node,int b,int e,int index,int newval)
	{
		if(b==e)
		{
			tree[node].Lm += newval;
			tree[node].Rm += newval;
			return;
		}

		int mid = (b+e)/2;

		if(index<=mid)
			update(2*node,b,mid,index,newval);
		else
			update(2*node+1,mid+1,e,index,newval);

		tree[node] = combine_data(tree[2*node],tree[2*node+1]);
	}
	data query(int node,int b,int e,int i,int j)
	{
		if(b >= i && e <= j)//in range
			return tree[node];

		int mid = (b+e)/2;
		if(j<=mid)
			return query(2*node,b,mid,i,j);
		else if(i>mid)
			return query(2*node+1,mid+1,e,i,j);

		data p1 = query(2*node,b,mid,i,j);
		data p2 = query(2*node+1,mid+1,e,i,j);

		return combine_data(p1,p2);
	}


}
using namespace segmentTree;
int main()
{
    freopen("akarui.inp","r",stdin);
    freopen("akarui.out","w",stdout);
	int t,n,q,a,b,type;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
			cin>>input[i];

		init_tree(1,1,n);

		while(q--){
			cin>>type>>a>>b;
			if(type == 0){
				data ret = query(1,1,n,a,b);
				cout<<ret.ans<<endl;
			}
			else
				update(1,1,n,a,b);
		}
	}
	return 0;
}

