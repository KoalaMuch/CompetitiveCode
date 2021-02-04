#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b; cin >> a >> b;
    printf(a==b ? "-1\n" : "%d\n",max(a.size(),b.size()));
    return 0;
}
