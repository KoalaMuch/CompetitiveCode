#include "grader.h"
#include "memory.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
vector< int > v[26];
void play() {
   for(int i=1;i<=50;i++)
   {
       char a = faceup(i);
       v[a-'A'].push_back(i);
   }
   for(int i=0;i<25;i++)    faceup(v[i][0]),faceup(v[i][1]);
}
