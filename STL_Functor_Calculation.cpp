//
//  STL_Functor_Calculation.cpp
//  cpp_study
//
//  Created by 형성모 on 18/01/2019.
//
//  STL 함수객체(Functor) #include <functional>
//      1. 산술연산 함수객체
//          1) plus<T>
//          2) minus<T>
//          3) multiplies<T>
//          4) divides<T> : /
//          5) modulus<T> : %
//          6) negate<T> : 단항 연산 -
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class PrintV
{
public:
    void operator()(const vector<int>& v) const
    {
        for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
            cout<<v[i]<<' ';
        cout<<endl;
    }
};

class Integer10
{
private:
    int data;
public:
    Integer10(int n=0) : data(n) {}
    int operator()()
    {
        return data+=10;
    }
};

class Integer1
{
private:
    int data;
public:
    Integer1(int n=0) : data(n) {}
    int operator()()
    {
        return data+=1;
    }
};

int main(void)
{
    vector<int> v1(5);
    vector<int> v2(5);
    vector<int> v3(5);
    
    generate(v1.begin(), v1.end(), Integer10());
    generate(v2.begin(), v2.end(), Integer1());
    
    cout<<"v1 : "; PrintV()(v1);
    cout<<"v2 : "; PrintV()(v2);
    cout<<"=========STL 산술연산 함수객체 사용========="<<endl;
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
    cout<<"v1 + v2 : "; PrintV()(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), minus<int>());
    cout<<"v1 - v2 : "; PrintV()(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
    cout<<"v1 * v2 : "; PrintV()(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), divides<int>());
    cout<<"v1 / v2 : "; PrintV()(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), modulus<int>());
    cout<<"v1 % v2 : "; PrintV()(v3);
    transform(v1.begin(), v1.end(), v3.begin(), negate<int>());
    cout<<"(-)v1 : "; PrintV()(v3);
    cout<<endl;
}

