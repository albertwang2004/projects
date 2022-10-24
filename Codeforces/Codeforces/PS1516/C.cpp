/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 205000

using namespace std;
typedef long long int LL;

int N,S=0;
vector<int> A;
bool DP[H];
int main() {
    cin >> N;
    int b = 9999999;
    int x=0;
    for (int i = 1; i <= N; i++) {
        int y; cin >> y;
        S+=y;
        A.pb(y);
        int r = 0;
        while (y%2==0) {
            y/=2;
            r++;
        }
        if (b>r) {
            b=r;
            x=i;
        }
    }
    if (S % 2 == 0) {
        for (int i = 1; i < H; i++) DP[i] = false;
        DP[0] = 1;
        for (int i = 0; i < N; i++) {
            int y = A[i];
            for (int j = H-69; j >= y; j--) {
                DP[j] |= DP[j-y];
            }
        }
        if (DP[S/2]) {
            cout << 1 << endl << x << endl;
            return 0;
        }
    }
     cout << 0 << endl;
    return 0;
}
*/
