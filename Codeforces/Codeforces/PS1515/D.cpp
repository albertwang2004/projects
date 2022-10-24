/*#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010

using namespace std;

int T,N,L,R;
int LS[200010];
int RS[200010];
int main() {
    cin >> T;
    while (T--) {
        cin >> N >> L >> R;
        for (int i = 1; i <= N; i++) {
            LS[i] = 0;
            RS[i] = 0;
        }
        for (int i = 0; i < L; i++) {
            int x;
            cin >> x;
            LS[x]++;
        }
        for (int i = 0; i < R; i++) {
            int x;
            cin >> x;
            RS[x]++;
        }
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            int d = min(LS[i],RS[i]);
            LS[i]-=d;
            RS[i]-=d;
            L-=d;
            R-=d;
            if (LS[i]!=0 && (L>R)) {
                int a = min(L-R,LS[i])>>1;
                ret += a;
                LS[i] -= a<<1;
                L -= a<<1;
            } else if (RS[i]!=0 && (R>L)) {
                int a = min(R-L,RS[i])>>1;
                ret += a;
                RS[i] -= a<<1;
                R -= a<<1;
            }
        }
        ret+=max(R,L);
        cout << ret << endl;
    }
}
*/
