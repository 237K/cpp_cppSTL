//
//  STL_Algorithm_Numeric.cpp
//  cpp_study
//
//  Created by 형성모 on 17/01/2019.
//
//  STL 알고리즘 #include <numeric>
//      7. 수치 알고리즘
//          1) accumulate(b, e, x, (f)) : x를 초깃값으로 [b, e) 구간의 합(또는 f)을 반환
//          2) inner_product(v1.begin, v1.end, v2.begin, x, (f1), (f2)) : x를 초깃값으로 두 순차열의 내적 반환
//          3) adjacent_difference(v1.begin, v1.end, v2.begin, (f)) : v1 인접한 두 원소의 차이값을 v2에 저장. 마지막 원소 반복자를 반환
//          4) partial_sum(v1.begin, v1.end, v2.begin, (f)) : 현재 원소까지의 합을 v2순차열에 저장. 마지막 원소 반복자 반환

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class PrintV
{
public:
    void operator()(const vector<int>& v)
    {
        for(vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<' ';
        }
        cout<<endl;
    }
};

class Accumulate10
{
private:
    int data;
public:
    Accumulate10(int init=0) : data(init) {}
    void operator()(int& n)
    {
        data+=10;
        n+=data;
    }
};

class Integer1
{
private:
    int data;
public:
    Integer1(int init=0) : data(init) {}
    int operator()()
    {
        return data+=1;
    }
};

int main(void)
{
    vector<int> v1(5);
    vector<int>::iterator iter;
    for_each(v1.begin(), v1.end(), Accumulate10());
    
    //accumulate
    cout<<"1) accumulate"<<endl;
    cout<<"v1 : "; PrintV()(v1);
    cout<<"accumulate(init = 0) : "<<accumulate(v1.begin(), v1.end(), 0)<<endl;
    cout<<"accumulate(init = 100) : "<<accumulate(v1.begin(), v1.end(), 100)<<endl;
    cout<<"accumulate(1, multiplies) : "<<accumulate(v1.begin(), v1.end(), 1, multiplies<int>())<<endl;
    cout<<"accumulate(10, multiplies) : "<<accumulate(v1.begin(), v1.end(), 10, multiplies<int>())<<endl;
    cout<<endl;
    
    //inner_product
    cout<<"2) inner_product"<<endl;
    vector<int> v2(10);
    generate(v2.begin(), v2.end(), Integer1());
    cout<<"v1 : "; PrintV()(v1);
    cout<<"v2 : "; PrintV()(v2);
    cout<<"inner_product(init = 0) : "<<inner_product(v1.begin(), v1.end(), v2.begin(), 0)<<endl;
    cout<<"inner_product(init = 100) : "<<inner_product(v1.begin(), v1.end(), v2.begin(), 100)<<endl;
    cout<<endl;
    cout<<"*inner_product(function1, function2)를 이용하면 다양한 연산을 수행할 수 있음"<<endl;
    cout<<"inner_product(init=0, plus, minus) : (v1[1] - v2[1]) + (v1[2] - v2[2]) + ... + (v1[5] - v2[5]) = "<<inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(), minus<int>())<<endl;
    cout<<endl;
    
    //adjacent_difference
    cout<<"3) adjacent_difference"<<endl;
    vector<int> v3(10);
    vector<int>::iterator iter1;
    cout<<"v1 : "; PrintV()(v1);
    iter1 = adjacent_difference(v1.begin(), v1.end(), v3.begin());
    cout<<"v3 : "; PrintV()(v3);
    cout<<"v3[begin, iter) : ";
    for(iter = v3.begin(); iter != iter1; ++iter) cout<<*iter<<' ';
    cout<<endl<<endl;
    
    //partial_sum
    cout<<"4) partial_sum"<<endl;
    vector<int> v4(10);
    cout<<"v1 : "; PrintV()(v1);
    iter1 = partial_sum(v1.begin(), v1.end(), v4.begin());
    cout<<"partial_sum : "; PrintV()(v4);
    cout<<"partial_sum[begin, iter) : ";
    for(iter = v4.begin(); iter != iter1; ++iter) cout<<*iter<<' ';
    cout<<endl<<endl;
    iter1 = partial_sum(v1.begin(), v1.end(), v4.begin(), multiplies<int>());
    cout<<"partial_sum(multiplies) : ";
    for(iter = v4.begin(); iter != iter1; ++iter) cout<<*iter<<' ';
    cout<<endl<<endl;
    
}
