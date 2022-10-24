/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 1010
#define MOD 1000000007
#define INF 9999999999

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int T, N, M;
vector<LL> A;
// gcd

LL gcd(LL a, LL b) {
   return b?gcd(b, a % b):a;
}

int main() {
    //scanf("%d",&T);
    T=1;
    while (T--) {
        scanf("%d%d",&N,&M);
        for (int i = 0; i < N; i++) {
            LL X; scanf("%lld", &X);
            A.pb(X);
        }
        sort(A.begin(),A.end());
        LL ret = 0;
        for (int i = 1; i < N; i++) {
            A[i] -= A[0];
            ret = gcd(ret,A[i]);
        }
        for (int i = 0; i < M; i++) {
            LL X; scanf("%lld", &X);
            LL ans = gcd(ret, A[0]+X);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}

*/
