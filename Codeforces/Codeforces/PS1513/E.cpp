/*#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010
#define MOD 1000000007
using namespace std;
typedef long long int LL;

LL S, X = 0;
int N, NS, NT = 0;
vector<LL> A;
vector<LL> F;
LL inv(LL a){
    LL x = MOD - 2;
    if (a==1)
        return 1;
    LL r = 1;
    while (x) {
        if (x & 1)
            r = (r * a) % MOD;
        x >>= 1;
        a = (a * a) % MOD;
    }
    return r;
}
void fact() {
    F.pb(1);
    for (int i = 1; i < H; i++) {
        F.pb((F[i-1]*i)%MOD);
    }
}
void read() {
    for (int i = 0; i < N; i++) {
        cin >> X; S += X;
        A.pb(X);
    }
}
LL solve() {
    LL ret = 1;
    LL C = 0;
    int curr = A[0];
    for (int i = 0; i < N; i++) {
        if (A[i]<X) NS++;
        if (A[i]>X) NT++;
        if (A[i]==curr) {
            C++;
        } else {
            if (curr!=X) ret=(ret*F[C])%MOD;
            curr = A[i];
            C = 1;
        }
    }
    if (curr!=X) ret=(ret*F[C])%MOD;
    //cout << NS << " " << NT << " " << ret << endl;
    if ((NS <= 1) || (NT <= 1)) {
        ret = (inv(F[N-NS-NT])*((((F[N])%MOD)*inv(ret))%MOD))%MOD;
    } else {
        ret = (2*(

                    ((inv(F[N-NS-NT])*((F[N]*inv(F[NS+NT])%MOD)))%MOD)*
                    ((((F[NS]*F[NT])%MOD)*(inv(ret)))%MOD)

               %MOD))%MOD;
    }
    return ret;
}
int main() {
    fact();
    cin >> N;
    read();
    if (S%N!=0) {
        cout << 0 << endl;
        return 0;
    }
    X=S/N;
    sort(A.begin(),A.end());
    cout << solve() << endl;
}
*/
