//
//  STL_Functor_Logical.cpp
//  cpp_study
//
//  Created by 형성모 on 19/01/2019.
//
//  STL 함수객체(Functor) #include <functional>
//      3. 논리연산 조건자
//          1) logical_and<T>
//          2) logical_or<T>
//          3) logical_not<T>
//

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class Logical_And : public binary_function<T, T, bool>
{
public:
    bool operator() (const T& left, const T& right) const
    {
        return left && right;
    }
};

template <typename T>
class Logical_Or : public binary_function<T, T, bool>
{
public:
    bool operator() (const T& left, const T& right) const
    {
        return left || right;
    }
};

template <typename T>
class Logical_Not : public unary_function<T, bool>
{
public:
    bool operator() (const T& t) const
    {
        return !t;
    }
};

int main(void)
{
    int n = 30;
    cout<<"30 > 10 && 30 < 50 ?"<<endl;
    cout<<"사용자 정의 함수 : "<<Logical_And<bool>()(greater<int>()(n, 10), less<int>()(n, 50))<<endl;
    cout<<"STL logical_and : "<<logical_and<bool>()(greater<int>()(n, 10), less<int>()(n, 50))<<endl<<endl;
    cout<<"30 > 10 || 30 < 10 ?"<<endl;
    cout<<"사용자 정의 함수 : "<<Logical_Or<bool>()(greater<int>()(n, 10), less<int>()(n, 10))<<endl;
    cout<<"STL logical_or : "<<logical_or<bool>()(greater<int>()(n, 10), less<int>()(n, 10))<<endl<<endl;
    cout<<"!(30 > 10) ? "<<endl;
    cout<<"사용자 정의 함수 : "<<Logical_Not<bool>()(greater<int>()(n, 10))<<endl;
    cout<<"!(30 < 10) ? "<<endl;
    cout<<"STL logical_not : "<<logical_not<bool>()(less<int>()(n, 10))<<endl<<endl;
}
