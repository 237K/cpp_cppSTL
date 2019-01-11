//
//  STL_Algorithm_Nonmodifying.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      1. 원소를 수정하지 않는 알고리즘
//          1) adjacent_find(v.begin(), v.end()) : begin부터 end까지의 순차열에서 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자 반환
//          2) count(v.begin(), v.end(), num) : begin부터 end까지 num의 개수를 반환

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<endl;
    
    vector<int>::iterator adjacent_iter;
    adjacent_iter = adjacent_find(v.begin(), v.end());
    
    if(adjacent_iter != v.end()) cout<<"adjacent_iter : "<<*adjacent_iter<<endl;
    
    for( ; adjacent_iter != v.end(); ++adjacent_iter)
    {
        cout<<*adjacent_iter<<" ";
    }
    cout<<endl<<endl;
    
    cout<<"40의 개수 : "<<count(v.begin(), v.end(), 40)<<endl;
    
    return 0;
}
