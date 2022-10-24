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

int H(string s) {
    if (s.size()==1) return int(s.at(0)-'`');
    if (s.size()==2) return 27*int(s.at(0)-'`')+int(s.at(1)-'`');
    if (s.size()==3) return 729*int(s.at(0)-'`')+27*int(s.at(1)-'`')+int(s.at(2)-'`');
}

string S(int h) {
    stack<char> ret;
    while (h>0) {
        ret.p(char((h%27)+int('`')));
        h/=27;
    }
    string retu = "";
    while (ret.size()>0) {
        char x = ret.top();
        ret.pop();
        retu+=x;
    }
    return retu;
}
int T,N;
bool exists[20000];
int main() {
    scanf("%d",&T);
    while (T--) {
        char str[1000];
        scanf("%d",&N);
        scanf("%s",str);
        string STR = str;
        for (int i = 0; i < 20000; i++) {
            exists[i]=false;
        }
        exists[0]=true;
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j <= N-i; j++) {
               // cout << i << " " << j << " " << STR.substr(j,i) << H(STR.substr(j,i)) << endl;
                exists[H(STR.substr(j,i))]=true;
            }
        }
        int ret = 0;
        string curr = S(ret);
        while (exists[ret]||(curr.find('`')!=-1)) {
            ret++;
        curr = S(ret);
        }
        cout << S(ret) << endl;
    }
}*/
