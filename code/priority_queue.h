#pragma once

#include <queue>


 namespace TEST{
     void TestPriorityQueue(){
         std::priority_queue<int,vector<int>,std::less<int> > pq;
         pq.push(4);
         pq.push(5);
         pq.push(6);

         while(!pq.empty()){
            std::cout<<  pq.top() <<","<<std::endl;
            pq.pop();
         }
     }
 }