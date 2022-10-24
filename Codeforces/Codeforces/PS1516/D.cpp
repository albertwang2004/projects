/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010
#define pp 10000
#define LH 17
using namespace std;
typedef long long int LL;

int N,Q;
int A[H];
vector<int> PP[H];
vector<int> P;
int P2[17] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
bool temp[pp] = {false};
int LIFT[LH][H];

int main() {
    // t = 0.0;
    // this is unironically the dumbest prime sieve
    // but i do not care
    P.pb(2);
    for (int i = 3; i < H; i++) {
        bool flag = true;
        for (int j : P) {
            if (j*j > i) break;
            if (i%j == 0) flag = false;
        }
        if (flag) P.pb(i);
    }
    for (int j = 0; j < P.size(); j++) {
        for (int i = P[j]; i < H; i+=P[j]) {
            PP[i].pb(j);
        }
    }

    // t = 0.4
    scanf("%d%d",&N,&Q);
    for (int i = 0; i < N; i++) {
        int x; scanf("%d",&x);
        A[i] = x;
    }

    int Suck = 0;
    for (int i = 0; i < N; i++) {
        while (Suck < N) {
            bool flag = false;
            for (int p : PP[A[Suck]]) {
                if (temp[p]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            for (int p : PP[A[Suck]]) {
                temp[p] = true;
            }
            Suck++;
        }
        LIFT[0][i] = Suck;
        for (int q : PP[A[i]]) {
            temp[q] = false;
        }
    }

    LIFT[0][N] = N;

    for (int j = 1; j < LH; j++) {
        for (int i = 0; i < N; i++) {
            LIFT[j][i]=LIFT[j-1][LIFT[j-1][i]];
        }
        LIFT[j][N] = N;
    }

    while (Q--) {
        int L,R,ret=0;
        scanf("%d%d",&L,&R);
        L--; R--;
        for (int e = LH-1; e>=0; e--) {
            if (LIFT[e][L]<=R){
                L=LIFT[e][L];
                ret+=P2[e];
            }
        }
        cout << ret+1 << endl;
    }
}
*/
