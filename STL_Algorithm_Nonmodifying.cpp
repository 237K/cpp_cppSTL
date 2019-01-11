//
//  STL_Algorithm_Nonmodifying.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      1. 원소를 수정하지 않는 알고리즘
//          1) adjacent_find(v.begin(), v.end(), (func)) : begin부터 end까지의 순차열에서 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자 반환
//          2) count(v.begin(), v.end(), num) : begin부터 end까지 num의 개수를 반환
//          2-2) count_if(v.begin(), v.end(), func) : func를 만족하는 원소 개수 반환
//          3) equal(v1.begin(), v1.end(), v2.begin(), (func)) : v1 [begin, end)구간을 v2의 해당 구간과 (같은지/func)비교, bool반환

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Pred(int n)
{
    return n > 30 ? true : false;
}

bool Pred2(int left, int right)
{
    return abs(right - left) < 15;
}

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
    
    //adjacent_find
    vector<int>::iterator adjacent_iter;
    adjacent_iter = adjacent_find(v.begin(), v.end());
    
    if(adjacent_iter != v.end()) cout<<"adjacent_iter : "<<*adjacent_iter<<endl;
    
    for( ; adjacent_iter != v.end(); ++adjacent_iter)
    {
        cout<<*adjacent_iter<<" ";
    }
    cout<<endl<<endl;
    
    //count
    cout<<"40의 개수 : "<<count(v.begin(), v.end(), 40)<<endl;
    
    cout<<"30보다 큰 원소 개수 : "<<count_if(v.begin(), v.end(), Pred)<<endl;
    
    //equal
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    
    bool bl = equal(v2.begin(), v2.end(), v.begin());
    cout<<"v2 [begin, end) 구간과 v 비교 : "<<bl<<endl;
    cout<<"v2, v 각 원소의 차이가 15보다 작은지 비교 : "<<equal(v2.begin(), v2.end(), v.begin(), Pred2)<<endl;
    
    
    return 0;
}
