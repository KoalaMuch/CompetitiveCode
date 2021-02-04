#include<bits/stdc++.h>
using namespace std;
struct B{
    int u;
    double w,speed;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
priority_queue<B> q;
double g[210][210];
double dis[210];
char opr[10];
int main(){
    int n,m,Q,u,v,mm,i,st,en,j,ch;
    double w,speed,c;
    scanf("%d %d %d",&n,&m,&Q);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)continue;
            g[i][j]=LLONG_MAX;
        }
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %lf",&u,&v,&w);
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(g[v][u],w);
    }
    while(Q--){
        scanf(" %s",opr);
        if(opr[0]=='a'){
            scanf("%d %d",&u,&mm);
            for(i=1;i<=mm;i++){
                scanf("%d %lf",&v,&w);
                g[u][v]=min(g[u][v],w);
                g[v][u]=min(g[v][u],w);
            }
        }
        if(opr[0]=='d'){
            scanf("%d",&u);
            for(i=1;i<=n;i++){
                if(i==u)continue;
                g[i][u]=g[u][i]=LLONG_MAX;
            }
        }
        if(opr[0]=='t'){
            scanf("%d %d %lf %lf",&st,&en,&speed,&c);
            for(i=1;i<=n;i++)dis[i]=LLONG_MAX;
            dis[st]=0;
            ch=0;
            q.push({st,0,speed});
            while(!q.empty()){
                u=q.top().u;
                w=q.top().w;
                speed=q.top().speed;
                if(u==en){printf("%.2lf\n",dis[en]);ch=1;break;}
                q.pop();
                if(speed<=0.0)continue;
                for(i=1;i<=n;i++){
                    if(u==i)continue;
                    if(g[u][i]==LLONG_MAX)continue;
                    if(dis[i]>dis[u]+g[u][i]/speed){
                        dis[i]=dis[u]+g[u][i]/speed;
                        q.push({i,dis[i],speed-c*g[u][i]});
                    }
                }
            }
            if(ch==0)printf("IMPOSSIBLE\n");
            while(!q.empty())q.pop();
        }
    }
    return 0;
}
/*
5 10 8
1 2 5.0
1 1 5.5
3 1 6.0
1 3 7.0
2 1 3.0
2 2 9.5
3 3 8.5
4 4 10.0
5 5 11.0
1 2 5.5
travel 2 3 10.0 1.0
travel 2 4 6.0
destroy 4
add 4 1
3 15.5
travel 1 4 3.5 0.1
destroy 2
add 2 3
1 1.0
3 3.0
5 5.0
travel 4 5 1.0 0.2
*/

