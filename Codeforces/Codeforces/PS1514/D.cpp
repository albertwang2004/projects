/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 300010
using namespace std;
typedef long long int LL;

std::mt19937 rrr(time(0));
//int randint(int m, int M) {
//    std::uniform_int_distribution<int> dist(m,M);
//    return dist(rrr);
//}


int N,Q;
int spam = 35;
vector<int> A;
vector<int> pf[H];


int main() {
    scanf("%d%d",&N,&Q);
    for (int i = 0; i < H; i++) {
        pf[i] = vector<int>();
    }
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d",&x);
        pf[x].pb(i);
        A.pb(x);
    }
    for (int q = 0; q < Q; q++) {
        int L,R; scanf("%d%d",&L,&R);
        int t = (R-L)/2+1;
        int i;
        int m = -69420;
        for (i = 0; i < spam; i++) {
            int dfjk = A[-1+uniform_int_distribution<int>(L,R)(rrr)];
            m=max(m,upper_bound(pf[dfjk].begin(),pf[dfjk].end(),R)
                    -lower_bound(pf[dfjk].begin(),pf[dfjk].end(),L));
        }
        cout << max(1,2*m-(R-L+1)) << endl;
    }
}
*/
