//
//  STL_Functor_Binder.cpp
//  cpp_study
//
//  Created by 형성모 on 19/01/2019.
//
//  STL 함수객체(Functor) #include <functional>
//      4. 바인더 : 이항 함수객체를 단항 함수객체로 변환
//          1) bind1st : first argument 고정. 실제 단항함수자 클래스는 binder1st, bind1st는 함수
//          2) bind2nd : second argument 고정. 실제 단항함수자 클래스는 binder2nd, bind2nd는 함수
//

#include <iostream>
#include <functional>
using namespace std;

int main(void)
{
    binder1st<less<int> > binder1 = bind1st(less<int>(), 10);
    binder2nd<less<int> > binder2 = bind2nd(less<int>(), 10);
    
    cout<<"1. first argument 고정"<<endl;
    cout<<"binder1st<less<int>> binder1 = bind1st(less<int>(), 10) 와 less<int>()(10, 5) 비교"<<endl;
    cout<<"binder1(5) : "<<binder1(5)<<endl;
    cout<<"less<int>()(10, 5) : "<<less<int>()(10, 5)<<endl<<endl;
    
    cout<<"binder1st<less<int>> binder1 = bind1st(less<int>(), 10) 와 less<int>()(10, 10) 비교"<<endl;
    cout<<"binder1(10) : "<<binder1(10)<<endl;
    cout<<"less<int>()(10, 10) : "<<less<int>()(10, 10)<<endl<<endl;
    
    cout<<"binder1st<less<int>> binder1 = bind1st(less<int>(), 10) 와 less<int>()(10, 15) 비교"<<endl;
    cout<<"binder1(15) : "<<binder1(15)<<endl;
    cout<<"less<int>()(10, 15) : "<<less<int>()(10, 15)<<endl<<endl;
    
    cout<<"2. second argument 고정"<<endl;
    cout<<"binder2nd<less<int>> binder2 = bind2nd(less<int>, 10) 와 less<int>()(5, 10) 비교"<<endl;
    cout<<"binder2(5) : "<<binder2(5)<<endl;
    cout<<"less<int>()(5, 10) : "<<less<int>()(5, 10)<<endl<<endl;
    
    cout<<"binder2nd<less<int>> binder2 = bind2nd(less<int>, 10) 와 less<int>()(10, 10) 비교"<<endl;
    cout<<"binder2(10) : "<<binder2(10)<<endl;
    cout<<"less<int>()(10, 10) : "<<less<int>()(10, 10)<<endl<<endl;
    
    cout<<"binder2nd<less<int>> binder2 = bind2nd(less<int>, 10) 와 less<int>()(15, 10) 비교"<<endl;
    cout<<"binder2(15) : "<<binder2(15)<<endl;
    cout<<"less<int>()(15, 10) : "<<less<int>()(15, 10)<<endl<<endl;
    
}
