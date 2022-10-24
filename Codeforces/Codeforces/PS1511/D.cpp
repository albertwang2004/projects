/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 1000000069

using namespace std;
typedef long long int LL;

int N,K;
vector<int> ret;
string alpha = "`abcdefghijklmnopqrstuvwxyz";

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= K; i++) {
        ret.pb(i);
        for (int j = i+1; j <= K; j++) {
            ret.pb(i);
            ret.pb(j);
        }
    }
    while (N--)
        cout << alpha[ret[N % (K*K)]];
    cout << endl;
}*/
