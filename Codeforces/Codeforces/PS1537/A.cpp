/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 800010
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int T,N;
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        int S=0;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            S+=x;
        }
        if (S==N) {
            cout << "0\n";
        } else if (S<N) {
            cout << "1\n";
        } else {
            cout << (S-N) << endl;
        }
    }
}
*/
