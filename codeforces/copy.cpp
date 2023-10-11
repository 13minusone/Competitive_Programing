// LUOGU_RID: 91816922
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N=1e6+100;
struct dsu{
	int fa[N*2],sz[N*2];
	stack<int> s;
	void init(int n){
		while(!s.empty()) s.pop();
		for(int i=0;i<=n*2;i++) fa[i]=i,sz[i]=1;
	}
	int get(int x){
		return x==fa[x]?x:get(fa[x]);
	}
	void add(int x,int y){
		x=get(x),y=get(y);
		if(x==y) s.push(-1);
		else{
			if(sz[x]>sz[y]) sz[x]+=sz[y],fa[y]=x,s.push(y);
			else sz[y]+=sz[x],fa[x]=y,s.push(x);
		}
	}
	void undo(){
		int x=s.top();s.pop();
		if(x==-1) return ;
		sz[fa[x]]-=sz[x],fa[x]=x;
	}
};
dsu D;
vector<pair<int,int> > oper[N<<2];
void insert(int id,int l,int r,int x,int y,pair<int,int> e){
	if(x>y) return ;
	if(x<=l&&r<=y){
		oper[id].push_back(e);return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) insert(id<<1,l,mid,x,y,e);
	if(y>mid) insert(id<<1|1,mid+1,r,x,y,e);
}
int n,m;

pair<int,int> E[N];
bool hvput;
void putYES(int id){
	if(hvput) return ;
	hvput=true;
	static bool vis[N*2];
	for(int i=1;i<=n*2;i++) vis[i]=false;
	cout << id << endl;
	printf("YES\n");
	if(id){
		vis[D.get(E[id].X)]=vis[D.get(E[id].Y)]=true;
	}
	for(int i=1;i<=n;i++){
		int yx=D.get(i),nx=D.get(i+n);
		assert(vis[yx]+vis[nx]<2);
		if(vis[yx]) putchar('1');
		else{
			if(vis[nx]) putchar('0');
			else putchar('1'),vis[yx]=true;
		}
	}
	printf("\n");
}
void solve(int id,int l,int r,bool ok);
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&E[i].X,&E[i].Y);
			insert(1,1,m,1,i-1,E[i]),insert(1,1,m,i+1,m,E[i]);
		}
		D.init(n);
		bool ok=true;
		for(int i=1;i<=m;i++){
			if(D.get(E[i].X)==D.get(E[i].Y)) ok=false;
			D.add(E[i].X,E[i].Y+n),D.add(E[i].X+n,E[i].Y);
		}
		if(ok) putYES(0);
		else{
			D.init(n);
			solve(1,1,m,1);
			assert(!D.s.size());
			if(!hvput) printf("NO\n");
		}
		for(int i=0;i<4*m;i++) oper[i].clear();
		hvput=false;
	}
	return 0;
}
void solve(int id,int l,int r,bool ok){
	for(auto E:oper[id]){
		if(D.get(E.X)==D.get(E.Y)) ok=false;
		D.add(E.X,E.Y+n),D.add(E.X+n,E.Y);
	}
	if(l==r){
		if(ok) putYES(l);
	}else{
		int mid=(l+r)>>1;
		solve(id<<1,l,mid,ok);
		if(!hvput) solve(id<<1|1,mid+1,r,ok);
	}
	for(auto E:oper[id]) D.undo(),D.undo();
	oper[id].clear();
}
