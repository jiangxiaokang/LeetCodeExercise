#include<iostream>
#include<vector>

template <typename T>
void BubbleSort(std::vector<T>& array){
    std::size_t num = array.size();
    for(std::size_t i = 0 ; i < num - 1; ++i){
        for(std::size_t j = 0; j < num - 1 - i;++j){
            if(array[j] > array[j+1]){
                //std::swap(array[j],array[j+1]);
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    std::vector<int> vec = {4,5,2,3,1,9,7};
    BubbleSort<int>(vec);
    for(auto&& i : vec){
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}