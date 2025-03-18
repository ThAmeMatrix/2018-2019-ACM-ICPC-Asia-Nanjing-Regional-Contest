#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1e5 + 9;

char str[5] = "LRUD", s[25];

int main(){
	srand(time(NULL));
	int n, m;
	for (; ~scanf("%d%d", &n, &m);){
		for (int i = 0; i < n; i ++) scanf("%s", s);
		for (int i = 0; i < 50000; i ++){
			printf("%c", str[rand() % 4]);
		}
	}
	return 0;
}