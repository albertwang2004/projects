/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100100
#define INF 5000000000000000

using namespace std;
typedef pair<int,int> pii;


int MC,MA,T,M,K;
bool dumbass(int a, int b) {
    a = (a!=MC)?a:(a-999999);
    b = (b!=MC)?b:(b-999999);
    return (a<b);
}

vector<int> A;
int C[H];
int ANS[1000][1000];
int main() {
    scanf("%d",&T);
    while (T--) {
        A = vector<int>();
        MC=0;
        MA=0;
        scanf("%d%d",&M,&K);
        for (int i = 1; i <= K; i++) {
            scanf("%d",C+i);
            if (MA<C[i]) {
                MA = C[i];
                MC = i;
            }
            for (int j = 0; j < C[i]; j++) A.pb(i);
        }
        sort(A.begin(),A.end(),dumbass);
        int L = 1;
        int R = 1001;
        int best = 99990;
        while (L<R) {
            int MM = (R+L)/2;
            bool c1 = (M <= MM*MM-(MM/2)*(MM/2));
            bool c2 = (MA <= MM*((MM+1+2)/2 - 1));
            if (c1 && c2) {
                best=min(best,MM);
                R=MM;
            } else {
                L=++MM;
            }
        }
        cout << best << endl;
        vector<pii> loc;
        for (int i = 0; i < best; i++) {
            for (int j = 0; j < best; j++) {
                if (!(i%2)) if (j%2) loc.pb(mp(i,j));
            }
        }
        for (int i = 0; i < best; i++) {
            for (int j = 0; j < best; j++) {
                if (!(i%2)) if (!(j%2)) loc.pb(mp(i,j));
            }
        }
        for (int i = 0; i < best; i++) {
            for (int j = 0; j < best; j++) {
                if (i%2) if (!(j%2)) loc.pb(mp(i,j));
            }
        }
        for (int i = 0; i < M; i++) {
            ANS[loc[i].f][loc[i].s]=A[i];
        }
        for (int i = 0; i < best; i++) {
            for (int j = 0; j < best; j++) {
                cout << ANS[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < M; i++) {
            ANS[loc[i].f][loc[i].s]=0;
        }
    }
}
*/
