/*
    由字符组成的等式：WWWDOT-GOOGLE=DOTCOM
*/
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <string>

const int max_char_count = 10;
const int max_search_count = 9;
long long  total_count = 0;

struct CharItem{
    explicit CharItem(char _c,bool _b):c(_c),bLeading(_b){

    }
    char c;
    int value=-1;
    bool bLeading = false;
};



void CheckCharList(std::vector<CharItem>& char_vec){
    std::string p0 = "WWWDOT";
    std::string p1 = "GOOGLE";
    std::string p2 = "DOTCOM";
    auto make_int_value = [char_vec](std::string& p)->int{
        int ret = 0;
        for (std::size_t i = 0; i < p.size(); ++i)
        {
            char c = p[i];
            auto itr = std::find_if(char_vec.begin(),char_vec.end(),[c](const CharItem& rhd){
                return rhd.c == c;
            });
            int value = 0;
            if(itr!=char_vec.end()){
                 value = (*itr).value;
            }
            else{
                std::cout<<"cant find char "<<c<<std::endl;
            }
            ret = ret * 10 + value;
        }
        return ret;
    };
    int m = make_int_value(p0);
    int n = make_int_value(p1);
    int s = make_int_value(p2);
    if(m-n==s){
        std::cout<<m<<" - "<<n<<" = "<<s<<std::endl;
    }
    total_count+=1;
}

void SearchingResult(std::set<int>& num_set,std::vector<CharItem>& char_vec,int count){
    if(count == max_search_count){
        CheckCharList(char_vec);
        return;
    }
    for(std::size_t i = 0;i<max_char_count;++i){
        if( i == 0 && char_vec[count].bLeading){
            continue;
        }
        if(num_set.find(i)!=num_set.end()){
            continue;
        }
        num_set.insert(i);
        char_vec[count].value = i;
        SearchingResult(num_set,char_vec,count+1);
        num_set.erase(i);
    }
}



int main(){ 
    std::set<int> num_map;//number where been used
    std::vector<CharItem> char_map;
    char_map.push_back(CharItem('W',true));
    char_map.push_back(CharItem('D',true));
    char_map.push_back(CharItem('O',false));
    char_map.push_back(CharItem('T',false));
    char_map.push_back(CharItem('G',true));
    char_map.push_back(CharItem('L',false));
    char_map.push_back(CharItem('E',false));
    char_map.push_back(CharItem('C',false));
    char_map.push_back(CharItem('M',false));
                            

    SearchingResult(num_map,char_map,0);

    std::cout<<"total searched count = "<<total_count<<std::endl;
    return 0;
}