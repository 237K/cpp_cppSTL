//
//  STL_Algorithm_Nonmodifying.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      1. 원소를 수정하지 않는 알고리즘
//          1) adjacent_find(v.begin(), v.end(), (func)) : 순차열에서 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자 반환
//          2) count(_if)(v.begin(), v.end(), num(func)) : num의 개수를 반환 (func을 만족하는 원소 개수 반환)
//          3) equal(v1.begin(), v1.end(), v2.begin(), (func)) : v1[begin, end)구간 기준 v2의 해당 구간과 비교, bool반환
//          4) find(_if)(v.begin(), v.end(), num(func)) : [begin, end)구간에서 num과 같은 첫번째 원소 반환
//          5) find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), (func)) : v1에 v2와 같은 순차열이 있는지 확인, 마지막 순차열의 첫 번째 원소반환
//          6) find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), (func)) : find_end처럼 구간 검색, 모든 원소 중 같은 원소가 하나라도 발견되면 발견된 첫 번쩨 원소의 반복자 반환
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Pred_1var(int n)
{
    return n > 30 ? true : false;
}

bool Pred_2var(int left, int right)
{
    return abs(right - left) < 15;
}

bool Pred_ffo(int left, int right)
{
    return left > right ? true : false;
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
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
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
    
    //count, count_if
    cout<<"40의 개수 : "<<count(v.begin(), v.end(), 40)<<endl;
    
    cout<<"30보다 큰 원소 개수 : "<<count_if(v.begin(), v.end(), Pred_1var)<<endl;
    cout<<endl;
    
    //equal
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    
    bool bl = equal(v2.begin(), v2.end(), v.begin());
    cout<<"v2 [begin, end) 구간과 v 비교 : "<<bl<<endl;
    cout<<"v2, v 각 원소의 차이가 15보다 작은지 비교 : "<<equal(v2.begin(), v2.end(), v.begin(), Pred_2var)<<endl;
    cout<<endl;
    
    //find, find_if
    vector<int>::iterator find_iter;
    find_iter = find(v.begin(), v.end(), 40);
    cout<<"40과 같은 원소를 찾습니다 "<<*find_iter<<endl;
    find_iter = find_if(v.begin(), v.end(), Pred_1var);
    cout<<"30보다 큰 첫 번째 원소를 찾습니다 "<<*find_iter<<endl;
    cout<<endl;
    
    //find_end
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    vector<int>::iterator find_end_iter;
    find_end_iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    if(find_end_iter != v.end())
    {
        cout<<"find_end_iter = "<<*find_end_iter<<endl;
        cout<<"find_end_iter - 1 = "<<*(find_end_iter-1)<<endl;
        cout<<"find_end_iter + 1 = "<<*(find_end_iter+1)<<endl;
    }
    cout<<endl;
    
    //find_first_of
    for(iter = v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl;
    vector<int>::iterator find_first_iter;
    find_first_iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
    if(find_first_iter == v.end()) cout<<"같은 원소가 없습니다"<<endl;
    cout<<"find_first_iter = "<<*find_first_iter<<endl;
    cout<<endl;
    
    //find_first_of(func)
    find_first_iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), Pred_ffo);
    if(find_first_iter == v.end()) cout<<"조건과 일치하는 원소가 없습니다"<<endl;
    cout<<"find_first_iter = "<<*find_first_iter<<endl;
    cout<<endl;
    
    return 0;
}
