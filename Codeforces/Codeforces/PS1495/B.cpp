/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 100100
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;


int T,N;
vector<int> A;
int main() {
    //scanf("%d",&T);
    T=1;
    while (T--) {
        scanf("%d",&N);
        vector<int> extrema;
        vector<bool> extype;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            A.pb(x);
        }
        extrema.pb(0);
        extype.pb(A[0]>A[1]);
        for (int i = 1; i < N-1; i++) {
            if ((A[i] > A[i-1]) && (A[i] > A[i+1])) {
                extrema.pb(i);
                extype.pb(1);
            } else if ((A[i] < A[i-1]) && (A[i] < A[i+1])) {
                extrema.pb(i);
                extype.pb(0);
            }
        }
        extrema.pb(N-1);
        extype.pb(A[N-1]>A[N-2]);
        int longest = 0;
        vector<int> places;
        for (int i = 1; i < N; i++) {
            int d = (extrema[i]-extrema[i-1]);
            if (d==longest) places.pb(i);
            else if (d>longest) {
                longest = d;
                places.clear();
                places.pb(i);
            }
        }
        if (places.size()==2) {
            if ((places[0]+1==places[1]) && (extype[places[0]]==1) && (longest%2==0)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
}
*/
