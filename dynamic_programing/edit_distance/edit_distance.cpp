#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
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

int main(){
    char src[] = "SNOWY";
    char des[] = "SUNNY";
    std::cout<<EditDistance_Rec(src,des)<<std::endl;
    return 0;
}