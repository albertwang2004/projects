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
vector<int> A;
int main() {
    scanf("%d",&T);
    while (T--) {
        A.clear();
        scanf("%d",&N);
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            A.pb(x);
        }
        sort(A.begin(),A.end());
        int m = MOD;
        int s = 0;
        for (int i = 0; i < N-1; i++) {
            int d= A[i+1]-A[i];
            if (d<m) {
                s=i+1;
                m=d;
            }
        }
        if (N==2) {
            cout << A[0] << " " << A[1] << endl;
        } else {
            for (int i = s; i < s+N; i++) {
                cout << A[i%N] << " " ;
            }
            cout << endl;
        }
    }
}
*/
