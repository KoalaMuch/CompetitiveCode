#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;  scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c); printf( (a>1&&!c)||(b>1&&!a)||(c>1&&!a) ? "NO\n" : "YES\n");
    }
    return 0;
}
