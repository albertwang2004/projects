/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 100100
#define INF 5000000000000000

using namespace std;
typedef long long int LL;

int T,N;
char buf[3][2*H];
int bleh[3][2*H];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        for (int i = 0; i < 3; i++) {
            scanf("%s",buf[i]);
            for (int j = 0; j < 2*N; j++) {
                bleh[i][j] = buf[i][j]-'0';
            }
        }
        int p0=0,p1=0,p2=0;
        int i = 3*N;
        while (max(p1,max(p2,p0))<2*N) {
            --i;
            if (bleh[0][p0]+bleh[1][p1]+bleh[2][p2]>1) {
                if (bleh[0][p0]) p0++;
                if (bleh[1][p1]) p1++;
                if (bleh[2][p2]) p2++;
                cout << 1;
            } else {
                if (bleh[0][p0]==0) p0++;
                if (bleh[1][p1]==0) p1++;
                if (bleh[2][p2]==0) p2++;
                cout << 0;
            }
        }
        if (p0==2*N) {
            if (p1 < p2) {
                for (;p2<2*N;p2++) {
                    --i;
                    cout << bleh[2][p2];
                }
            } else {
                for (;p1<2*N;p1++) {
                    --i;
                    cout << bleh[1][p1];
                }
            }
        } else if (p1==2*N) {
            if (p0 < p2) {
                for (;p2<2*N;p2++) {
                    --i;
                    cout << bleh[2][p2];
                }
            } else {
                for (;p0<2*N;p0++) {
                    --i;
                    cout << bleh[0][p0];
                }
            }
        } else {
            if (p1 < p0) {
                for (;p0<2*N;p0++) {
                    --i;
                    cout << bleh[0][p0];
                }
            } else {
                for (;p1<2*N;p1++) {
                    --i;
                    cout << bleh[1][p1];
                }
            }
        }
        while (i--) cout << 0;
        cout << endl;
    }
}
*/
