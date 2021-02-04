#include "grader.h"
#include "cluedo.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
void Solve(){
   int m=1,l=1,w=1;
   while(1)
   {
       int r = Theory(m,l,w);
       if(!r)   return ;
       if(r==1) ++m;
       if(r==2) ++l;
       if(r==3) ++w;
   }
}
