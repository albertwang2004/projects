/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 500010
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int N,K;
char buf[H];
int main() {
    scanf("%d%d",&N,&K);
    scanf("%s",&buf);
    int l = 0;
    int i;
    for (i=1; i<N; i++) {
        if (buf[i]==buf[l]) {
            l++;
        } else if (buf[i] > buf[l]) {
            break;
        } else {
            l=0;
        }
    }
    i-=l;
    for (int j = 0; j < K; j++) {
        cout << buf[j%i];
    }
    cout << endl;
}
*/
