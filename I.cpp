#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 5e2 + 9;

int n, m, k;

struct Node{
	vector<int>hero;
}M[N];

bool cmp(const Node &X, const Node &Y){
	return X.hero.size() < Y.hero.size();
}

int isHero[N];

int T;
int vis[N], Link[N];

int dex, adj[N];
struct Edge{
	int v, nxt;
}e[N << 2];

int tt;

bool Find(int u){
	int len = M[u].hero.size();
	for (int i = 0, v; i < len; i ++){
		v = M[u].hero[i];
		if (vis[v] == T) continue;
		vis[v] = T;
		if (Link[v] == -1 || Find(Link[v])){
			Link[v] = u;
			return true;
		}
	}
	return false;
}

int main(){
	for (; ~scanf("%d%d%d", &n, &m, &k);){
		for (int i = 0; i < N; i ++){
			adj[i] = -1;
			M[i].hero.clear();
		}
		dex = 0;
		for (int u = 1, v; u <= n; u ++){
			int kk; scanf("%d", &kk);
			for (; kk --;){
				scanf("%d", &v);
				M[v].hero.push_back(u);
			}
		}
		
		sort(M + 1, M + 1 + m, cmp);
		
		memset(isHero, 0, sizeof(isHero));
		memset(vis, 0, sizeof(vis));
		memset(Link, -1, sizeof(Link));
		int ans = 0;
		
		for (int i = 1; i <= m; i ++){
			if (M[i].hero.size() != 0){
				T = i;
				if (Find(i)) ans ++;
			}
		}
		for (int i = 1; i <= n; i ++){
			if (~Link[i]){
//				printf("hero %d mon %d\n", i, Link[i]);
				isHero[i] = 1;
				M[Link[i]].hero.clear();
			}
		}
		
//		for (int i = 1; i <= m; i ++){
//			int len = M[i].hero.size();
//			printf("%d", i); 
//			for (int j = 0; j < len; j ++) printf(" %d", M[i].hero[j]);
//			puts("");
//		}
		
		memset(Link, -1, sizeof(Link));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= m; i ++){
			if (M[i].hero.size() != 0){
				T = i;
				if (Find(i)) tt ++;
			}
		}
//		for (int i = 1; i <= n; i ++){
//			if (~Link[i]){
//				printf("hero %d mon %d\n", i, Link[i]);
//				isHero[i] = 1;
//				M[Link[i]].hero.clear();
//			}
//		}
		printf("%d\n", ans + min(k, tt));
	}
	
	return 0;
}
