/*#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010

using namespace std;
typedef long long int LL;

int T;
LL N,P;
LL A[200000];
LL r[200000];
int main() {
    cin >> T;
    while (T--) {
        cin >> N >> P;
        for (int i = 0; i < N; i++) {
            LL x; cin >> x; A[i] = x;
            r[i] = P;
        }
        LL curr = A[0];
        for (int i = 1; i < N; i++) {
            if (A[i]%curr==0) {
                r[i-1]=min(r[i-1],curr);
            } else {
                curr=A[i];
            }
        }
        curr = A[N-1];
        for (int i = N-2; i >= 0; i--) {
            if (A[i]%curr==0) {
                r[i]=min(r[i],curr);
            } else {
                curr=A[i];
            }
        }
        LL ret = 0;
        for (int i = 0; i < N-1; i++) {
            ret+=r[i];
        }
        cout << ret << endl;
    }
}
*/
