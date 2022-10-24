/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 800010
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int T,N;
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        int M=N;
        int p = 0;
        while (M%2==0) { M/=2; p++; }
        if (M==1)
            if (p==0 || (p%2==1))
            cout << "Bob\n";
            else cout << "Alice" << endl;
        else
            if (N%2)
                cout << "Bob\n";
            else cout << "Alice" << endl;
    }
}
*/
