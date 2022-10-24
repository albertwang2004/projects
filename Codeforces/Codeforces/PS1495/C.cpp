/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 501
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;


int T,N,M;
bool A[H][H];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&M);
        for (int i = 0; i < N; i++) {
            char buf[M]; scanf("%s",buf);
            for (int j = 0; j < M; j++) {
                A[i][j]=(buf[j]=='X');
            }
        }
        if ((N >= 2) && (M >= 2)) {
            if (N%3==0) {
                for (int i = 1; i < N; i+=3)
                    for (int j = 0; j < M; j++) A[i][j]=1;
                for (int i = 1; i < N-3; i+=3) {
                    if (A[i+1][1] || A[i+2][1]) {
                        A[i+1][1]=1;
                        A[i+2][1]=1;
                    } else {
                        A[i+1][0]=1;
                        A[i+2][0]=1;
                    }
                }
            } else {
                for (int i = 0; i < N; i+=3)
                    for (int j = 0; j < M; j++) A[i][j]=1;
                for (int i = 0; i < N-3; i+=3) {
                    if (A[i+1][1] || A[i+2][1]) {
                        A[i+1][1]=1;
                        A[i+2][1]=1;
                    } else {
                        A[i+1][0]=1;
                        A[i+2][0]=1;
                    }
                }
            }
        } else {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) A[i][j]=1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << (A[i][j]?'X':'.');
            }
            cout << endl;
        }
    }
}*/
