//
//  STL_MemFuncPtrAdapter.cpp
//  cpp_study
//
//  Created by 형성모 on 20/01/2019.
//
//  STL 함수객체(Functor)
//      6. 멤버함수포인터 어댑터
//          - mem_fun_ref() : 객체로 멤버함수 호출
//          - mem_fun() : 객체의 주소로 멤버함수 호출
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//Mem_fun_ref 클래스 정의
template <typename RType, typename CType>
class Mem_fun_ref_class : public unary_function<CType, RType>
{
private:
    RType (CType::*pf)() const;
public:
    Mem_fun_ref_class(RType (CType::*_pf)() const) : pf(_pf){}
    RType operator() (const CType& o) const
    {
        return (o.*pf) ();
    }
};

//Mem_fun_ref 어댑터 함수 정의
template <typename RType, typename CType>
Mem_fun_ref_class<RType, CType> Mem_fun_ref(RType (CType::*pf)() const)
{
    return Mem_fun_ref_class<RType, CType>(pf);
}

class Point
{
private:
    int xpos, ypos;
public:
    explicit Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    int GetX() const { return xpos; }
    int GetY() const { return ypos; }
    void Print() const { cout<<"("<<xpos<<", "<<ypos<<")"<<endl; }
    friend ostream& operator<< (ostream& os, const Point& pnt);
};

ostream& operator<< (ostream& os, const Point& pnt)
{
    os<<"("<<pnt.xpos<<", "<<pnt.ypos<<")"<<endl;
    return os;
}

int main(void)
{
    //멤버함수포인터 어댑터
    cout<<"멤버함수포인터 어댑터"<<endl;
    vector<Point> vp1;
    vp1.push_back(Point(1, 1));
    vp1.push_back(Point(2, 2));
    vp1.push_back(Point(3, 3));
    vp1.push_back(Point(4, 4));
    vp1.push_back(Point(5, 5));
    cout<<endl;
    cout<<"Mem_fun_ref(Point.Print형태, 객체로 멤버함수 호출"<<endl;
    for_each(vp1.begin(), vp1.end(), Mem_fun_ref(&Point::Print));
}
