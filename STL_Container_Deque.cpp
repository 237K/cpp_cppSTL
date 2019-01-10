
//
//  STL_Container_Deque.cpp
//  cpp_study
//
//  Created by 형성모 on 10/01/2019.
//
//  STL을 공부하고 있습니다.
//  Deque의 특징을 이해했습니다.
//

#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    deque<int> dq;
    deque<int>::iterator iter;
    
    dq.push_back(11);
    dq.push_back(22);
    dq.push_back(33);
    for(iter = dq.begin(); iter != dq.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    dq.push_front(1111);
    dq.push_front(2222);
    dq.push_front(3333);
    for(iter = dq.begin(); iter != dq.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    deque<int>::iterator iter1;
    deque<int>::iterator iter2;
    iter1 = dq.begin()+3;
    iter2 = dq.insert(iter1, 99999);
    cout<<"insert "<<*iter2<<"to dq[3]"<<endl;
    for(iter = dq.begin(); iter != dq.end(); ++iter)
    {
        cout<<*iter<<' ';
    }
    cout<<endl<<endl;
    
    return 0;
}
