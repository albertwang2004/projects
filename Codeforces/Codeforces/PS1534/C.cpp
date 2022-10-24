/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define t top
#define fr front
#define H 400100
#define MOD 1000000007
using namespace std;
typedef long long int LL;

int T,N;
int A[H];
int P[H];
int S[H];

int pp(int x) {
	if (P[x]==x) return x;
    return (P[x] = pp(P[x]));
}

void un(int a, int b) {
	a = pp(a);
	b = pp(b);
	if (a == b) return;
	if (S[a] > S[b]) swap(a,b);
	S[b] += S[a];
	P[a] = b;
}
bool done[H];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        for (int i = 1; i <= N; i++) {
            scanf("%d",A+i);
            S[i]=1;P[i]=i;done[i]=false;
        }
        for (int i = 1; i <= N; i++) {
            int x; scanf("%d",&x);
            un(x,*(A+i));
        }
        LL ret = 1;
        for (int i = 1; i <= N; i++) {
            if (!done[pp(i)]) {
                ret=(ret*2)%MOD;
                done[pp(i)]=true;
            }
        }
        cout << ret << endl;
    }
}
*/
