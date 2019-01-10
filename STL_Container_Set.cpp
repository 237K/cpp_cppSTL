//
//  STL_Container_Set.cpp
//  cpp_study
//
//  Created by 형성모 on 10/01/2019.
//
//  STL Container를 공부하고 있습니다.
//  연관컨테이너 set
//

#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    set<int> set1;
    pair<set<int>::iterator, bool> pair1;
    
    set1.insert(10);
    set1.insert(50);
    set1.insert(40);
    set1.insert(70);
    set1.insert(20);
    set1.insert(90);
    
    pair1 = set1.insert(20);
    cout<<"pair1.first = "<<*pair1.first<<endl;
    cout<<"pair1.second = "<<pair1.second<<endl;
    
    set<int>::iterator iter1;
    cout<<"set1 : ";
    for(iter1=set1.begin(); iter1 != set1.end(); ++iter1)
    {
        cout<<*iter1<<' ';
    }
    cout<<endl<<endl;
    
    set1.insert(pair1.first, 30);
    cout<<"insert(pair1.first, 30)"<<endl;
    cout<<"set1 : ";
    for(iter1=set1.begin(); iter1 != set1.end(); ++iter1)
    {
        cout<<*iter1<<' ';
    }
    cout<<endl<<endl;
    
    iter1 = set1.find(70);
    if(iter1 != set1.end()) cout<<*iter1<<"를 찾았습니다."<<endl;
    else cout<<"찾으시는 원소가 없습니다."<<endl;
    
    return 0;
}
