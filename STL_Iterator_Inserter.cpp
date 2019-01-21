//
//  STL_Iterator_Inserter.cpp
//  cpp_study
//
//  Created by 형성모 on 21/01/2019.
//
//  [STL 반복자]
//      1. iterator, const_iterator
//      2. reverse_iterator, const_reverse_iterater
//      3. const <T>::iterator/reverse_iterator, const <T>::const_iterator/const_reverse_iterator
//      4. reverse_iterator<T>, base()
//      5. insert iterator
//          1) inserter() : insert_iterator 객체 생성. insert함수 호출. 모든 컨테이너 사용 가능
//          2) back_inserter() : back_insert_iterator 객체 생성. push_back함수 호출. 시퀀스 컨테이너(vector, deque, list) 사용 가능
//          3) front_inserter() : front_insert_iterator 객체 생성. push_front함수 호출. deque, list 사용 가능
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class Integer10
{
private:
    int data;
public:
    Integer10(int init=0) : data(init) {}
    int operator() () { return data += 10; }
};

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

int main(void)
{
    vector<int> v1(5);
    generate(v1.begin(), v1.end(), Integer10());
    
    //inserter
    vector<int> v2;
    
    copy(v1.begin(), v1.end(), inserter<vector<int> >(v2, v2.begin()));
    //v2.begin()반복자를 v2의 insert()멤버함수를 호출하는 삽입반복자로 변환
    
    cout<<"v1 : "; PrintV()(v1);
    cout<<"v1 copy : "; PrintV()(v2);
    cout<<endl<<endl;;
    
    //back_inserter, front_inserter
    list<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    
    list<int> lt2;
    lt2.push_back(1);
    lt2.push_back(2);
    lt2.push_back(3);
    
    list<int>::iterator liter;
    
    cout<<"lt1 : ";
    for(liter = lt1.begin(); liter != lt1.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl;
    cout<<"lt2 : ";
    for(liter = lt2.begin(); liter != lt2.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    cout<<"vector->list copy(back_inserter)"<<endl;
    copy(v1.begin(), v1.end(), back_inserter<list<int> >(lt1));
    cout<<"lt1 : ";
    for(liter = lt1.begin(); liter != lt1.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    cout<<"vector->list copy(front_inserter)"<<endl;
    copy(v1.begin(), v1.end(), front_inserter<list<int> >(lt2));
    cout<<"lt2 : ";
    for(liter = lt2.begin(); liter != lt2.end(); ++liter)
        cout<<*liter<<' ';
    cout<<endl<<endl;
    
    return 0;
}
