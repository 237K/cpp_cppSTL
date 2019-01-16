//
//  STL_Algorithm_Sorting.cpp
//  cpp_study
//
//  Created by 형성모 on 16/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      5. 정렬 알고리즘
//          1) heap
//              a) make_heap(b, e, (f)) : 벡터와 힙구조를 항상 상상하자 벡터의 각 원소가 힙의 어디에 위치하는지
//              b) push_heap(b, e, (f)) : vector에 push_back 한 다음 사용
//              c) pop_heap(b, e, (f)) : 루트노드(가장 큰 원소) 제거. 루트노드와 마지막노드를 교환한 후 힙정렬 실행됨
//              d) sort_heap(b, e, (f)) : 힙정렬
//          2) nth_element(b, middle_iter, e) : middle_iter-b 만큼의 원소를 선별(사전순)하여 [b, middle_iter)에 저장
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

void Func_Rand(int& i) { i = rand()%1000; }

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
    
    //pop_heap
    cout<<"1-c) pop_heap"<<endl;
    cout<<"v1(heap) : "; PrintV()(v1);
    cout<<"pop_heap!"<<endl;
    pop_heap(v1.begin(), v1.end());
    cout<<"v1(heap) : "; PrintV()(v1);
    cout<<endl;
    
    //sort_heap
    cout<<"1-d) sort_heap"<<endl;
    vector<int> v2(6);
    vector<int> v3(6);
    generate(v2.begin(), v2.end(), Integer10<int>());
    generate(v3.begin(), v3.end(), Integer10<int>());
    cout<<"v2 : "; PrintV()(v2);
    cout<<"v3 : "; PrintV()(v3);
    cout<<endl;
    
    make_heap(v2.begin(), v2.end());
    make_heap(v3.begin(), v3.end(), greater<int>());
    cout<<"make_heap(default) : "; PrintV()(v2);
    cout<<"make_heap(greater) : "; PrintV()(v3);
    cout<<endl;
    
    v2.push_back(35);
    v3.push_back(35);
    push_heap(v2.begin(), v2.end());
    push_heap(v3.begin(), v3.end(), greater<int>());
    cout<<"push_heap(default) : "; PrintV()(v2);
    cout<<"push_heap(greater) : "; PrintV()(v3);
    cout<<endl;
    
    sort_heap(v2.begin(), v2.end());
    sort_heap(v3.begin(), v3.end(), greater<int>());
    cout<<"sort_heap(default) : "; PrintV()(v2);
    cout<<"sort_heap(greater) : "; PrintV()(v3);
    cout<<endl;
    sort_heap(v2.begin(), v2.end(), greater<int>());
    cout<<"make랑 push를 디폴트로 한 경우에 sort를 greater로 하면 : "; PrintV()(v2);
    cout<<endl;
    
    //nth_element
    cout<<"2) nth_element"<<endl;
    vector<int> v4(100);
    for_each(v4.begin(), v4.end(), Func_Rand);
    cout<<"v4 : "; PrintV()(v4);
    vector<int>::iterator middle_iter = v4.begin()+20;
    vector<int>::iterator iter;
    cout<<"middle_iter : "<<*middle_iter<<endl;
    cout<<endl;
    nth_element(v4.begin(), middle_iter, v4.end());
    cout<<"nth_element!"<<endl;
    cout<<"v4 : "; PrintV()(v4);
    cout<<"[v4.begin, middle_iter) : ";
    for(iter = v4.begin(); iter != middle_iter; ++iter) cout<<*iter<<' ';
    cout<<endl;
    cout<<"[middle_iter, v4.end) : ";
    for(iter = middle_iter; iter != v4.end(); ++iter) cout<<*iter<<' ';
    cout<<endl<<endl;
}
