#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1000007;
int Pri[MAX], np;
vector<int> Pre[MAX];
bool dp[MAX];
int n;
void get_prime(int MAX) {
	np=0;
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i < MAX; ++ i) {
        if(!dp[i]) {
        	Pre[i].push_back(np);
        	Pri[np ++] = i;
		}
        for(int it = 0; it < np; ++ it) {
        	int t = Pri[it] * i;
            if (t >= MAX)
				break;
            dp[t] = 1;
            Pre[t] = Pre[i];
            if (i % Pri[it] == 0)
				break;
            Pre[t].push_back(it);
        }
    }
}


vector<int> v[MAX];
void getPre(int x, int id) {
	for (int i = 0; i < Pre[x].size(); ++ i) {
		v[Pre[x][i]].push_back(id);
	}
}

int main(){
	get_prime(MAX);
	while (~scanf("%d", &n)) {
		for (int i = 0; i < np; ++ i) v[i].clear();
		for (int i = 1; i <= n; ++ i) {
			int x;
			scanf("%d", &x);
			getPre(x, i);
		}
		ll ans = 0;
		for (int i = 0; i < np; ++ i) {
			for (int j = 0; j < v[i].size(); ++ j) {
				if (j == 0) {
					if(v[i].size() == 1)
						ans = ans + 1LL * v[i][j] * (n + 1 - v[i][j]);
					else
						ans = ans + 1LL * v[i][j] * (v[i][j + 1] - v[i][j]);
				}
				else if (j == v[i].size() - 1)
					ans = ans + 1LL * v[i][j] * (n + 1 - v[i][j]);
				else
					ans = ans + 1LL * v[i][j] * (v[i][j + 1] - v[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
}
