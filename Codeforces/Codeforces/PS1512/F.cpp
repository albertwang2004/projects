/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 200010

using namespace std;
typedef long long int LL;

int N,T;
LL C;
LL A[H];
LL B[H];

LL upDiv(LL x, LL y) {
    LL adj = 0;
    if (x<=1) adj=999LL;
    x+=adj*y;
    //cout << "DIVIDING " << x << " " << y << endl;
    //cout << "work " << (x-1LL) << " " << (x-1LL)/y << endl;
    //cout << (1LL+(x-1LL)/y) << " " << ((x+y-1LL)/y) << endl;
    //assert((1LL+(x-1LL)/y)==((x+y-1LL)/y));
    return 1LL+(x-1LL)/y - adj; // this one doesn't work
    //return (x+y-1LL)/y; // this one does
    // hello what the fuck
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            A[i]=a;
            //cout << "Read A " << i << " " << a << endl;
        }
        for (int i = 0; i < N-1; i++) {
            int b; cin >> b;
            B[i]=b;
            //cout << "Read B " << i << " " << b << endl;
        }
        B[N-1] = 0;

        LL ret = 1000000000000000LL;
        LL currmoney = 0;
        LL time = 0;
        for (int i = 0; i < N; i++) {
            LL k = max(upDiv(C-currmoney,A[i]),0LL);
            ret=min(time+k,ret);
            LL z = max(upDiv(B[i]-currmoney,A[i]),0LL);
            if (z<0) z=0LL;
            currmoney += z*A[i]-B[i];
            time+=z+1;
        }
        cout << ret << endl;
    }
}*/

