/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define pp 10000
#define LH 17
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
int T,N;
int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}
pii simplify(pii x) {
    return mp(x.f/gcd(x.f,x.s),x.s/gcd(x.f,x.s));
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        char str[N];
        scanf("%s",str);
        map<pii,int> trash;
        int nD=0;int nK=0;
        for (int i = 0; i < N; i++) {
            if (str[i]=='D') nD++;
            else nK++;
            trash[simplify(mp(nD,nK))]++;
            cout << trash[simplify(mp(nD,nK))] << " ";
        }
        cout << endl;
    }
}
*/
