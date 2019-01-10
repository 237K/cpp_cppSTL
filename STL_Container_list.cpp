//
//  STL_Container_list.cpp
//  cpp_study
//
//  Created by 형성모 on 10/01/2019.
//
//  STL을 공부하고 있습니다.
//  list의 특징을 이해했습니다.
//

#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)
{
    return 10 <= n && n <= 30;
}

int main(void)
{
    list<int> lt;
    list<int>::iterator iter;

    lt.push_back(11);
    lt.push_back(22);
    lt.push_back(33);
    lt.push_back(44);
    lt.push_back(55);
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    lt.push_front(1111);
    lt.push_front(2222);
    lt.push_front(3333);
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    list<int>::iterator iter1 = lt.begin();
    list<int>::iterator iter2;
    iter1++;
    iter1++;
    iter2 = lt.erase(iter1);
    cout<<"iter1 : "<<*iter1<<endl;
    cout<<"iter2 : "<<*iter2<<endl;
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    iter1 = iter2;                                      
    iter2 = lt.insert(iter1, 999999);
    cout<<"iter2 : "<<*iter2<<endl;
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    cout<<"remove(11)"<<endl;
    lt.remove(11);
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    cout<<"remove_if(Predicate)"<<endl;
    lt.remove_if(Predicate);
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    list<int> lt2;
    list<int>::iterator iter3 = lt.begin();
    
    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    iter3++;
    iter3++;
    iter3++;
    
    cout<<"iter1 : "<<*iter1<<endl;
    cout<<"iter2 : "<<*iter2<<endl;
    cout<<"iter3 : "<<*iter3<<endl;
    cout<<"splice(iter3, lt2)"<<endl;
    lt.splice(iter3, lt2);
    cout<<"lt : ";
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    cout<<"lt2 : ";
    for(iter=lt2.begin(); iter != lt2.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;

    list<int> lt3;
    list<int>::iterator iter4;
    
    lt3.push_back(10000);
    lt3.push_back(20000);
    lt3.push_back(30000);
    iter4 = lt3.begin();
    iter4++;
    iter4++;
    
    cout<<"iter1 : "<<*iter1<<endl;
    cout<<"iter2 : "<<*iter2<<endl;
    cout<<"iter3 : "<<*iter3<<endl;
    cout<<"iter4 : "<<*iter4<<endl;
    cout<<"splice(iter3, lt3, iter4)"<<endl;
    lt.splice(iter3, lt3, iter4);
    cout<<"lt : ";
    for(iter=lt.begin(); iter != lt.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    cout<<"lt3 : ";
    for(iter=lt3.begin(); iter != lt3.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
 
    list<int> lt4;
    lt4.push_back(30);
    lt4.push_back(10);
    lt4.push_back(70);
    lt4.push_back(10);
    lt4.push_back(50);
    cout<<"lt4 : ";
    for(iter=lt4.begin(); iter != lt4.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    cout<<"sort()"<<endl;
    lt4.sort();
    cout<<"lt4 : ";
    for(iter=lt4.begin(); iter != lt4.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    cout<<"unique()"<<endl;
    lt4.unique();
    cout<<"lt4 : ";
    for(iter=lt4.begin(); iter != lt4.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    return 0;
}
