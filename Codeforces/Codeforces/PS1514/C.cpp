/*#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010

using namespace std;
typedef long long int LL;

int N;
vector<int> ret;
int gcd(int a, int b) {
   return b?gcd(b, a % b):a;
}
int main() {
    cin >> N;
    LL P = 1;
    for (int i = 1; i < N-1; i++) {
        if (gcd(i,N)==1) {
            ret.pb(i);
            P = (P * i) % N;
        }
    }
    if (P==N-1) ret.pb(N-1);
    cout << ret.size() << endl;
    for (int i : ret) cout << i << " ";
    cout << endl;
}
*/
