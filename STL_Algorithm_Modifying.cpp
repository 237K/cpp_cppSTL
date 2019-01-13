//
//  STL_Algorithm_Modifying.cpp
//  cpp_study
//
//  Created by 형성모 on 13/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      2. 원소를 수정하는 알고리즘
//          1) copy(v1.begin(), v1.end(), v2.begin()) : v1 순차열을 v2에 복사(덮어쓰기). v2는 v1보다 커야함
//          2) copy_backward(v1.begin(), v1.end(), v2.end()) : v1순차열을 v2 끝에서부터 복사해서 붙여넣기(덮어씀)
//          3) fill(v1.begin(), v1.end(), x) : v1을 x로 채움
//          4) fill_n(v1.begin(), n, x) : v1 [begin, begin+n)을 x로 채움
//          5) for_each(v1.begin(), v1.end(), func) : v1의 각 원소에 func(*p)를 적용함
//          6) generate(v1.begin(), v1.end(), func) : 각 원소에 func을 채움. for_each나 transform과는 달리 원소의 원값을 활용할 수 없음
//          7) generate_n(v1.begin(), n, func) : [begin, begin+3) 구간에 generate
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int>& v)
{
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

void Func_EachPlus(int& i)
{
    i += 5;
}

template <typename T>
class Accumalate
{
private:
    T total;
public:
    Accumalate(T n=0) :total(n) {}
    void operator()(T& r)
    {
        total += r;
        r = total;
    }
};

template <typename T>
class Integer
{
private:
    T data;
public:
    Integer(T init=0) : data(init) {}
    int operator()()
    {
        return data++;
    }
};

int main(void)
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    vector<int> v2;
    v2.resize(5);
    
    //copy
    cout<<"1) copy"<<endl;
    vector<int>::iterator copy_iter;
    copy_iter = copy(v1.begin(), v1.end(), v2.begin());
    
    cout<<"v1 : "; Print(v1);
    cout<<"copy_iter : "<<*(copy_iter-1)<<endl;
    cout<<"v2 : "; Print(v2);
    cout<<endl;
    
    //copy_backward
    cout<<"2) copy_backward"<<endl;
    v2.clear();
    v2.resize(10);
    copy_iter = copy_backward(v1.begin(), v1.end(), v2.end());
    
    cout<<"v1 : "; Print(v1);
    cout<<"copy_backward_iter : "<<*copy_iter<<endl;
    cout<<"v2 : "; Print(v2);
    cout<<endl;
    
    //fill
    cout<<"3) fill"<<endl;
    fill(v1.begin(), v1.end(), 0);
    cout<<"v1을 0으로 채움 : "; Print(v1);
    cout<<endl;
    
    //fill_n
    cout<<"4) fill_n"<<endl;
    fill_n(v2.begin(), 5, 55);
    cout<<"v2의 시작부터 5번째까지를 55로 채움 : "; Print(v2);
    cout<<endl;
    
    //for_each
    cout<<"5) for_each"<<endl;
    for_each(v1.begin(), v1.end(), Func_EachPlus);
    cout<<"v1 : "; Print(v1);
    cout<<endl;
    
    cout<<"5) for_each에 상태변수를 활용할 수 있는 fuctor대입"<<endl;
    for_each(v1.begin(), v1.end(), Accumalate<int>(0));
    cout<<"v1 : "; Print(v1);
    cout<<endl;
    
    //generate
    cout<<"6) generate 원소의 원값을 활용하지 않고 값을 채움"<<endl;
    generate(v1.begin(), v1.end(), Integer<int>(1));
    cout<<"v1의 각 원소를 1씩 증가시킴 : "; Print(v1);
    cout<<endl;
    
    return 0;
}
