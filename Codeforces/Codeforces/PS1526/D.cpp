/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100000

using namespace std;
typedef long long int LL;

int T;
char buf[H];
char A[H];
char B[H];
map<char,int> comp;
string P[24] = {
    "ANOT",
    "ANTO",
    "AONT",
    "AOTN",
    "ATNO",
    "ATON",
    "NAOT",
    "NATO",
    "NOAT",
    "NOTA",
    "NTAO",
    "NTOA",
    "OANT",
    "OATN",
    "ONAT",
    "ONTA",
    "OTAN",
    "OTNA",
    "TANO",
    "TAON",
    "TNAO",
    "TNOA",
    "TOAN",
    "TONA"
};
//LL mergeInv(int L, int M, int R) {
//    int i=L,j=M;
//    LL ret = 0;
//    for (int idx = L; idx < R; idx++) {
//        if (idx<=M) B[idx]=A[idx];
//        else B[idx]=A[idx];
//    }
//    while ((i < M) && (j < R)) {
//        if (B[i] <= B[j]) {
//            A[i+j] = B[i];
//            i++;
//        } else {
//            A[i+j] = B[j];
//            j++;
//            ret+=M-i;
//        }
//    }
//    for (;i<M;i++) A[i] = B[i];
//    for (;j<R;j++) A[j] = B[j];
//    return ret;
//}
//LL mergeSort(int L, int R) {
//    if (R-L>1) {
//        int M = (L+R)/2;
//        return mergeSort(L, M) + mergeSort(M, R) + mergeInv(L,M,R);
//    } else {
//        return 0;
//    }
//}

//void paste() {
//    for (int i = 0; i < H; i++) A[i]=buf[i];
//}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%s",buf);
        int N = strlen(buf);

        string best = P[0];
        LL least = 0;
        map<char,int> C;

        string nnn = "ANOT";
        map<char,int> norm;
        norm['A']=0;
        norm['N']=1;
        norm['O']=2;
        norm['T']=3;

        LL adj[4][4]; // adj[i][j] is number of times character i occurred after j
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) adj[i][j]=0;

        LL c[4] = {0,0,0,0};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < norm[buf[i]]; j++) {
                adj[norm[buf[i]]][j]+=c[j];
            }
            c[norm[buf[i]]]++;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = i+1; j < 4; j++) {
                adj[i][j] = c[i]*c[j]-adj[j][i];
            }
        }
       // for (int i = 0; i < 4; i++) {
        //    for (int j = 0; j < 4; j++) {
         //       //cout << i << " " << j << " " << adj[i][j] << endl;
        //    }
       // }
        for (string p : P) {
            for (int i = 0; i < 4; i++) {
                C[p.at(i)]=i;
            }
            LL k = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = i+1; j < 4; j++) {
                    k+=adj[norm[p.at(i)]][norm[p.at(j)]];
                    //cout << i << " " << j << " " << adj[norm[p.at(i)]][norm[p.at(j)]] << endl;
                }
            }
            //cout << p << " " << k << endl;
            if (k>least) {
                least=k;
                best=p;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < c[norm[best.at(i)]]; j++) {
                cout << best.at(i);
            }
        }
        cout << endl;
    }
}
*/
