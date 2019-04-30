#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,inf=1e9+7;
int rt[maxn],sum[maxn*40],ls[maxn*40],rs[maxn*40],n,cnt;
vector<int>G[maxn],dis[maxn];
int deep[maxn],f[maxn][20];
void up(int pre,int& o,int l,int r,int k)
{
	o=++cnt;
	ls[o]=ls[pre],rs[o]=rs[pre];
	sum[o]=sum[pre]+1;
	if(l==r)return;
	int m=(1ll*l+r)/2;
	if(k<=m)up(ls[pre],ls[o],l,m,k);
	else up(rs[pre],rs[o],m+1,r,k);
}
int qu(int o,int l,int r,int k)
{
	if(l==r)return sum[o];
	int m=(1ll*l+r)/2;
	if(k<=m)return qu(ls[o],l,m,k);
	else return sum[ls[o]]+qu(rs[o],m+1,r,k);
}
void dfs(int u,int fa,int dep)
{
	deep[u]=dep;
	f[u][0]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)continue;
		up(rt[u],rt[v],0,inf,dis[u][i]);
		dfs(v,u,dep+1);
	}
}
void init()
{
	for(int i=1;i<20;i++)
	for(int j=1;j<=n;j++)
	f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int p,int q)
{
	if(deep[p]<deep[q])swap(p,q);
	for(int i=19;i>=0;i--)
	if(deep[f[p][i]]>=deep[q])
	p=f[p][i];
	if(p==q)return p;
	
	for(int i=19;i>=0;i--)
	if(f[p][i]!=f[q][i])
	p=f[p][i],q=f[q][i];
	return f[p][0];
}
int main()
{
	int m,u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u].push_back(w);
		dis[v].push_back(w); 
	}
	dfs(1,0,1);
	init();
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		int ans=0;
		ans=qu(rt[u],0,inf,w)+qu(rt[v],0,inf,w);
        printf("%d\n",ans);
		int fu=lca(u,v);
        printf("%d\n",fu);
		ans-=qu(rt[fu],0,inf,w)*2;
		printf("%d\n",ans);
	}
}