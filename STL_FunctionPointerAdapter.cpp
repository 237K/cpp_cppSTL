//
//  STL_FunctionPointerAdapter.cpp
//  cpp_study
//
//  Created by 형성모 on 20/01/2019.
//
//  STL 함수객체(Functor)
//      5. 함수포인터 어댑터
//          - ptr_fun의 기능을 이해하고, 어댑터를 직접 구현해보았습니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//Ptr_fun 클래스 정의
template <typename RType, typename AType>
class Ptr_fun_class : public unary_function<AType, RType>
{
private:
    RType (*pf)(AType);
public:
    Ptr_fun_class(RType (*_pf) (AType)) : pf(_pf) {}
    RType operator() (AType n) const
    {
        return pf(n);
    }
};

//Ptr_fun 어댑터 함수 정의
template <typename RType, typename AType>
Ptr_fun_class<RType, AType> Ptr_fun(RType (*pf)(AType))
{
    return Ptr_fun_class<RType, AType>(pf);
}

class PrintV
{
public:
    void operator() (const vector<int>& v)
    {
        for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
            cout<<v[i]<<' ';
        cout<<endl;
    }
};

class Integer5
{
private:
    int data;
public:
    Integer5(int init=0) : data(init) {}
    int operator() () { return data += 5; }
};

bool Pred(int n)
{
    return (n > 30) && (n < 60) ? true : false;
}

int main(void)
{
    vector<int> v1(10);
    generate(v1.begin(), v1.end(), Integer5());
    
    //함수포인터 어댑터
    cout<<"함수포인터 어댑터"<<endl;
    cout<<"v1 : "; PrintV()(v1);
    cout<<endl<<"직접 정의한 어댑터 사용"<<endl;
    cout<<"30초과 60미만 원소 개수 : "<<count_if(v1.begin(), v1.end(), Pred)<<endl;
    cout<<"30초과 60미만이 아닌 원소 개수 : "<<count_if(v1.begin(), v1.end(), not1(Ptr_fun(Pred)))<<endl<<endl;
    
    cout<<endl<<"STL 어댑터 사용"<<endl;
    cout<<"30초과 60미만 원소 개수 : "<<count_if(v1.begin(), v1.end(), Pred)<<endl;
    cout<<"30초과 60미만이 아닌 원소 개수 : "<<count_if(v1.begin(), v1.end(), not1(ptr_fun(Pred)))<<endl<<endl;
    
    return 0;
}

