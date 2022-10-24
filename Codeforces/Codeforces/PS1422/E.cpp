/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front

#define T1 10
#define T2 100
#define T3 1000
#define T4 10000
#define T5 100000
#define T6 1000000

#define H1 11
#define H2 105
#define H3 1010
#define H4 10010
#define H5 100010
#define H6 1000010

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;
char S[H5];
int stacc[H5];
int pt;
bool rem[H5];
stack<string> ret;

void compress() {
    string curr = to_string(pt) + " ";
    if (pt>10) {
        for (int j = pt; j > pt-5; j--) curr += S[N-stacc[j]];
        curr+="...";
        for (int j = 2; j > 0; j--) curr += S[N-stacc[j]];
    } else {
        for (int j = pt; j > 0; j--) curr += S[N-stacc[j]];
    }
    ret.p(curr);
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%s",S);
        N = strlen(S);
        for (int i = 1; i <= N; i++) {
            //cout << pt << endl;
            //for (int j = 0; j < N; j++) {
            //    cout << stacc[j] << " ";
            //}
            //cout << endl;
            bool del = 0;
            char last = S[N-stacc[pt]];
            char curr = S[N-i];
            if ((pt>0) && (curr==last)) {
                rem[i] = rem[stacc[pt]];
                del = (stacc[pt]==i-1) && rem[i];
            }
            if (pt==0) rem[i] = 1;
            if (last<curr) rem[i] = 1;
            if (del) --pt;
            else stacc[++pt]=i;
            compress();
        }
        while (ret.size()) {
            cout << ret.t() << endl;
            ret.pop();
        }
    }
}
*/
