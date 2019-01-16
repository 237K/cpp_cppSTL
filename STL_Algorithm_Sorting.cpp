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
//          3) sort(b, e) : 퀵소트
//          4) stable_sort(b, e) : 머지정렬
//          5) partial_sort(b, e) : 힙정렬
//          6) partial_sort_copy(v1.begin, v1.end, v2.begin, v2.end) : v2크기만큼 v1원소를 정렬한 후 v2에 복사
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
int Func_Rand_Gen(){ return rand()%1000; }

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
    
    //quick sort
    cout<<"3) sort (quick sort)"<<endl;
    vector<int> v5(100);
    generate(v5.begin(), v5.end(), Func_Rand_Gen);
    cout<<"v5 : "; PrintV()(v5);
    cout<<endl;
    sort(v5.begin(), v5.end());
    cout<<"quick sort(v5) : "; PrintV()(v5);
    cout<<endl;
    
    //stable_sort (merge sort)
    cout<<"4) stable_sort (merge sort)"<<endl;
    vector<int> v6;
    v6.push_back(30);
    v6.push_back(50);
    v6.push_back(30);
    v6.push_back(20);
    v6.push_back(40);
    v6.push_back(10);
    v6.push_back(40);
    
    cout<<"v6 : "; PrintV()(v6);
    cout<<endl;
    stable_sort(v6.begin(), v6.end(), greater<int>());
    cout<<"stable_sort(greater) : "; PrintV()(v6);
    cout<<endl;
    
    //partial_sort (heap sort)
    cout<<"5) partial_sort (heap sort)"<<endl;
    vector<int> v7;
    for(int i = 0; i < 100; ++i)
    {
        v7.push_back(rand()%1000);
    }
    cout<<"v7 : "; PrintV()(v7);
    cout<<endl;
    partial_sort(v7.begin(), v7.begin()+20, v7.end());
    cout<<"정렬된 상위 20개 원소 : ";
    for(vector<int>::size_type i = 0; i < 20; ++i) cout<<v7[i]<<' ';
    cout<<endl;
    cout<<"정렬되지 않은 하위 80개 원소 : ";
    for(vector<int>::size_type i = 20; i < v7.size(); ++i) cout<<v7[i]<<' ';
    cout<<endl<<endl;
    
    //partial_sort_copy
    cout<<"6) partial_sort_copy"<<endl;
    vector<int> v8(100);
    vector<int> v9(20);
    generate(v8.begin(), v8.end(), Func_Rand_Gen);
    partial_sort_copy(v8.begin(), v8.end(), v9.begin(), v9.end());
    cout<<"v8 : "; PrintV()(v8);
    cout<<endl;
    cout<<"v9 : "; PrintV()(v9);
    cout<<endl;
}
