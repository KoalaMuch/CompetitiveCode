#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1e9+7;
int main()
{
    long long T,a,b,c;
    cin >> T;
    while(T--){
    cin >> a >> b >>c;
    long long G = __gcd(a,__gcd(b,c));
    a/=G;
    b/=G;
    c/=G;
    printf("%lld %lld\n",G,(a*b%mod)*c%mod);
    }
}
/*
4
G: I want to go on 19
M: No that is now pos lets go on 21
G: No 19 is 21

4
G: I want to go on 19
M: No that is now pos lets go on 21
G: No 19 is 21


4
G: I want to go on 19
M: No that is not possible lets go on 21
G: No 19 is final and 21 is not
M: OKAY as you wish
*/
