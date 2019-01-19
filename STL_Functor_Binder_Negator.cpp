//
//  STL_Functor_Binder_Negator.cpp
//  cpp_study
//
//  Created by 형성모 on 19/01/2019.
//
//  STL 함수객체(Functor) #include <functional>
//      4. 바인더 : 이항 함수객체를 단항 함수객체로 변환
//          1) bind1st : first argument 고정. 실제 단항함수자 클래스는 binder1st, bind1st는 함수
//          2) bind2nd : second argument 고정. 실제 단항함수자 클래스는 binder2nd, bind2nd는 함수
//
//      5. 부정자 : 조건자를 반대의 조건자로 변환
//          1) not1 : 단항 조건자를 반대의 조건자로 변환
//          2) not2 : 이항 조건자를 반대의 조건자로 변환
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
    
    
    binary_negate<less<int> > negator2 = not2(less<int>());
    cout<<"3. not2"<<endl;
    cout<<"negator2(5, 10) : "<<negator2(5, 10)<<endl;
    cout<<"not2(less<int>())(5, 10) : "<<not2(less<int>())(5, 10)<<endl<<endl;
    
    cout<<"negator2(10, 10) : "<<negator2(10, 10)<<endl;
    cout<<"not2(less<int>())(10, 10) : "<<not2(less<int>())(10, 10)<<endl<<endl;
    
    cout<<"negator2(15, 10) : "<<negator2(15, 10)<<endl;
    cout<<"not2(less<int>())(15, 10) : "<<not2(less<int>())(15, 10)<<endl<<endl;
    
    cout<<"4. not1"<<endl;
    binder2nd<less<int> > binder3 = bind2nd(less<int>(), 10);
    unary_negate<binder2nd<less<int> > > negator1 = not1(binder3);
    
    cout<<"negator1(5) : "<<negator1(5)<<endl;
    cout<<"not1(binder3)(5) : "<<not1(binder3)(5)<<endl<<endl;
    
    cout<<"negator1(10) : "<<negator1(10)<<endl;
    cout<<"not1(binder3)(10) : "<<not1(binder3)(10)<<endl<<endl;
    
    cout<<"negator1(15) : "<<negator1(15)<<endl;
    cout<<"not1(binder3)(15) : "<<not1(binder3)(15)<<endl<<endl;
    
}
