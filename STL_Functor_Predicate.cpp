//
//  STL_Functor_Predicate.cpp
//  cpp_study
//
//  Created by 형성모 on 18/01/2019.
//
//  STL 함수객체(Functor) #include <functional>
//      2. 비교연산 조건자
//          1) equal_to<T>
//          2) not_equal_to<T>
//          3) less<T> : < 연산
//          4) less_equal<T> : <= 연산
//          5) greater<T> : > 연산
//          6) greater_equal : >= 연산
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class Less : public binary_function<T, T, bool>
{
public:
    bool operator()(const T& left, const T& right) const
    {
        return left < right ? true : false;
    }
};

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

int main(void)
{
    vector<int> v1(5);
    
    generate(v1.begin(), v1.end(), Integer10());
    
    cout<<"v1 : "; PrintV()(v1);
    cout<<endl;
    //count_if(v1.begin(), v1.end(), bind2nd<less<int> > (less<int>(), 30));
    //count_if(v1.begin(), v1.end(), bind2nd<Less<int> > (Less<int>(), 30));
    //count_if(v1.begin(), v1.end(), Less<int>());
    cout<<"v1에 30미만 원소의 개수 (사용자 함수객체 Less 사용) :"<<count_if(v1.begin(), v1.end(), bind2nd<Less<int> > (Less<int>(), 30))<<endl;
    cout<<"v1에 30이하 원소의 개수 : "<<count_if(v1.begin(), v1.end(), bind2nd<less_equal<int> > (less_equal<int>(), 30));
    cout<<endl;
    cout<<"v1에 30과 같은 원소의 개수 (count 사용) : "<<count(v1.begin(), v1.end(), 30)<<endl;
    cout<<"v1에 30과 같은 원소의 개수 (count_if사용) : "<<count_if(v1.begin(), v1.end(), bind2nd<equal_to<int> > (equal_to<int>(), 30))<<endl;
    cout<<"v1에 30과 다른 원소의 개수 : "<<count_if(v1.begin(), v1.end(), bind2nd<not_equal_to<int> > (not_equal_to<int>(), 30));
    cout<<endl;
    cout<<"v1에 30초과 원소의 개수 : "<<count_if(v1.begin(), v1.end(), bind2nd<greater<int> > (greater<int>(), 30))<<endl;
    cout<<"v1에 30이상 원소의 개수 : "<<count_if(v1.begin(), v1.end(), bind2nd<greater_equal<int> > (greater_equal<int>(), 30));
    cout<<endl;
    cout<<endl;
}
