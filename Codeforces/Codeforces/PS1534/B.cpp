/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define t top
#define fr front
#define H 400100
using namespace std;
typedef long long int LL;

int T,N;
int A[H];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        A[0]=0;
        for (int i = 1; i <= N; i++) {
            scanf("%d",A+i);
        }
        A[N+1]=0;
        LL ret = 0;
        LL sub = 0;
        for (int i = 1; i <= N; i++) {
            ret+=max(A[i]-A[i-1],0)+max(A[i]-A[i+1],0);
            sub+=max(A[i]-max(A[i-1],A[i+1]),0);
        }
        cout << ret-sub << endl;
    }
}
*/
