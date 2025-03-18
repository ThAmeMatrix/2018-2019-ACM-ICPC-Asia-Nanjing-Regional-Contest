#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 1e5 + 9;

int main(){
    int n, k; scanf("%d%d", &n, &k);
    if (k == 1) puts(n & 1 ? "Adrien" : "Austin");
    else if (!n) puts("Austin");
    else puts("Adrien");
    return 0;
}