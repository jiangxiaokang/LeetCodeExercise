#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
//recursive
int EditDistance_Rec(char *src, char *des)
{
    int len_src = strlen(src);
    int len_des = strlen(des);
    if (len_src == 0 || len_des == 0){
        return abs(len_src - len_des);
    }
    if (src[0] == des[0]){
        return EditDistance_Rec(src + 1, des + 1);
    }
    int edIns = EditDistance_Rec(src, des + 1) + 1;
    int edDel = EditDistance_Rec(src + 1, des) + 1;
    int edRep = EditDistance_Rec(src + 1, des + 1) + 1;
    
    return std::min(std::min(edIns, edDel), edRep);
}

struct RecordData{
    int distance = 0;
    bool bRecorded = false;
};
#define MAX_STRING_LEN 1024
RecordData table[MAX_STRING_LEN][MAX_STRING_LEN];
int EditDistance_Table(char* src,char* dest,int i ,int j){
   if(table[i][j].bRecorded){
       return table[i][j].distance;
   }
   int dist = 0;
   if(strlen(src+i) == 0){
       dist = strlen(dest+j);
   }
   else if(strlen(dest+j) == 0){
       dist = strlen(src+i);
   }
   else{
       if(src[i] == dest[j]){
           dist = EditDistance_Table(src,dest,i+1,j+1);
       }
       else{
           int edIns = EditDistance_Table(src,dest,i,j+1) + 1;
           int edDel = EditDistance_Table(src,dest,i+1,j) + 1;
           int edRep = EditDistance_Table(src,dest,i+1,j+1) + 1;
           dist = std::min(std::min(edIns,edDel),edRep);
       }
   }
    table[i][j].bRecorded = true;
    table[i][j].distance = dist;
    //std::cout<<" record i|j|distance "<<i<<"|"<<j<<"|"<<dist<<std::endl;
    return dist;
}

int EditDistance(const char* src,const char* dest){
    int len_src = strlen(src);
    int len_dest = strlen(dest);
    int d[MAX_STRING_LEN][MAX_STRING_LEN] = {0xffff} ;
    int i ,j;
    for(i = 0;i<=len_src;++i){ 
        d[i][0]= i;
    }
    for(i=0;i<=len_dest;++i){
        d[0][i] = i;
    }
    for(i=1;i<=len_src;++i) {
        for (j = 1; j <= len_dest; ++j) {
            if (src[i - 1] == dest[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                int edIns = d[i][j - 1] + 1;
                int edDel = d[i - 1][j] + 1;
                int edRep = d[i - 1][j - 1] + 1;
                d[i][j] = std::min(std::min(edIns, edDel), edRep);
            }
        }
    }
    return d[len_src][len_dest];
}

int main(){
    char src[] = "SNOWY";
    char des[] = "SUNNY";
   // std::cout<<EditDistance_Rec(src,des)<<std::endl;
   // std::cout<<EditDistance_Table(src,des,0,0)<<std::endl;
    std::cout<<EditDistance(src,des)<<std::endl;
    return 0;
}