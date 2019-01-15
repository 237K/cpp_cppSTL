//
//  STL_Algorithm_Sorting.cpp
//  cpp_study
//
//  Created by 형성모 on 16/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      5. 정렬 알고리즘
//          1) heap
//              a) make_heap(b, e) : 벡터와 힙구조를 항상 상상하자 벡터의 각 원소가 힙의 어디에 위치하는지
//              b) push_heap(b, e) : vector에 push_back 한 다음 사용
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PrintV
{
private:
    int count;
public:
    PrintV() : count(0) {}
    void operator()(const vector<int>& v)
    {
        for(vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<' ';
        }
        cout<<endl;
    }
};

template <typename T>
class Integer10
{
private:
    T data;
public:
    Integer10(T init=0) :data(init) {}
    int operator()()
    {
        return data+=10;
    }
};

int main(void)
{
    vector<int> v1(5);
    generate(v1.begin(), v1.end(), Integer10<int>());
    cout<<"v1 : "; PrintV()(v1);
    cout<<endl;
    
    //make_heap
    cout<<"1-a) make_heap"<<endl;
    make_heap(v1.begin(), v1.end());
    cout<<"v1(heap) : "; PrintV()(v1);
    cout<<endl;
    
    //push_heap
    cout<<"1-b) push_heap"<<endl;
    cout<<"v1(heap) : "; PrintV()(v1);
    v1.push_back(35);
    cout<<"=====push_back(35)====="<<endl;
    cout<<"v1(heap) : "; PrintV()(v1);
    cout<<"=====push_heap====="<<endl;
    push_heap(v1.begin(), v1.end());
    cout<<"v1(heap) : "; PrintV()(v1);
    cout<<endl;
}
