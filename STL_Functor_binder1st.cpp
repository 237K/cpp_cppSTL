//
//  STL_Functor.cpp
//  cpp_study
//
//  Created by 형성모 on 18/01/2019.
//
//  STL Functor
//  binder1st<int>를 사용하여 binary_function을 unary_function처럼 기능하도록 해보았습니다.
//      1) Plus 펑터에 타입을 모두 정의함으로써 어댑터와 결합할 수 있도록 하였습니다.
//      2) binary_function을 상속하는 방법으로 이항함수객체가 어댑터변환이 가능하도록 하였습니다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Printv
{
public:
    void operator()(const vector<int>& v)
    {
        for(vector<int>::size_type i = 0; i < v.size(); ++i) cout<<v[i]<<' ';
        cout<<endl;
    }
};

template <typename T>
class Plus : public binary_function<T, T, T>
{
public:
    //typedef T first_argument_type;
    //typedef T second_argument_type;
    //typedef T result_type;
public:
    T operator()(const T& left, const T& right) const { return left+right; }
};

int main(void)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3(5);
    vector<int> v4(5);
    
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    
    cout<<"v1 : "; Printv()(v1);
    cout<<"v2 : "; Printv()(v2);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus<int>());
    cout<<"v3(user's Plus) : "; Printv()(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v4.begin(), plus<int>());
    cout<<"v4(STL plus) : "; Printv()(v4);
    cout<<endl;
    
    //binder1st<int>를 사용하여 한 항을 100으로 고정
    cout<<"binder1st<int>를 사용하여 transform을 단항연산처럼 기능하도록 해보았습니다."<<endl;
    transform(v1.begin(), v1.end(), v3.begin(), binder1st<Plus<int> > (Plus<int>(), 100));
    cout<<"v1 : "; Printv()(v1);
    cout<<"v3(user's Plus) : "; Printv()(v3);
    cout<<endl;
    transform(v1.begin(), v1.end(), v4.begin(), binder1st<plus<int> > (plus<int>(), 100));
    cout<<"v1 : "; Printv()(v1);
    cout<<"v4(STL plus) : "; Printv()(v4);
    
}
