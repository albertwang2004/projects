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
//int gcd(int a, int b) {
//   if (b == 0) return a;
//   return gcd(b, a % b);
//}
int T,N;
vector<int> A;
bool B[201];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        A=vector<int>();
        for (int i = 0; i < 201; i++) {
            B[i] = false;
        }
        bool negs = true;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            A.pb(x);
            B[x+100] = true;
            negs &= (x>=0);
        }

        if (!negs) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << 200 << endl;
            for (int i = 0; i < 200; i++) cout << i << " ";
            cout << endl;
        }
    }
}*/
