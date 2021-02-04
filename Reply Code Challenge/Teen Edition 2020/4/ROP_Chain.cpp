/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[1010],b[1010];
unordered_map<string ,int > mapp;
int dp[1010];
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("in5.txt","r",stdin);
	freopen("out5.txt","w",stdout);
	int q,n,m;
	scanf("%d",&q);
	for(int z=1;z<=q;z++){
		scanf("%d %s",&n,a+1);
		for(int i=1;i<=n;i++){
			scanf(" %s",b+1);
			m = strlen(b+1);
			for(int i=1;i<=m;i++){
				mapp[b+i] = 1;
			}
		}
		m = strlen(a+1);
		for(int i=1;i<=m;i++)
			dp[i] = 1e9;
		for(int i=1;i<=m;i++){
            char tmp = a[i+1];
            a[i+1] = '\0';
			for(int j=i;j>=1;j--){
				// cout << str << '\n';
				if(!mapp[a+j])			break;
				if(dp[j-1] == 1e9)	continue;
				dp[i] = min(dp[i],dp[j-1]+1);
				// printf("%d %d\n",i,j,mark[i]);
			}
			a[i+1] = tmp;
		}
		if(dp[m] == 1e9)	printf("Case #%d: -1\n",z);
		else				printf("Case #%d: %d\n",z,dp[m]);
		mapp.clear();
	}
	return 0;
}
/*
3
2
mississippi
missi
lippi
2
sisi
missi
lippi
2
lissi
missi
lippi
*/
