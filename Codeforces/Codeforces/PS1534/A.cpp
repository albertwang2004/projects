/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define t top
#define fr front

using namespace std;
typedef long long int LL;

int T,N,M;

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&M);
        int flip = -1;
        bool good = true;
        for (int i = 0; i < N; i++) {
            char k[M]; scanf("%s",k);
            for (int j = 0; j < M; j++) {
                if (k[j]=='.')continue;
                int x = (i+j)%2;
                if (flip<0) {
                    if (k[j]=='R') {
                        flip=x;
                    } else {
                        flip=1-x;
                    }
                } else {
                    if (((k[j]=='R')&&(x!=flip))
                        ||((k[j]=='W')&&(x==flip))) {
                        good = false;
                    }
                }
            }
        }
        if (good) {
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout << (char)('R'+5*(flip?(1-(i+j)%2):((i+j)%2)));
                }
                cout << endl;
            }
        } else {
            cout << "NO\n";
        }
    }
}
*/
