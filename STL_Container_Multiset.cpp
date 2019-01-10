//
//  STL_Container_Multiset.cpp
//  cpp_study
//
//  Created by 형성모 on 10/01/2019.
//
//  STL 컨테이너를 공부하고 있습니다.
//  연관컨테이너 multiset
//

#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    multiset<int> ms;
    ms.insert(30);
    ms.insert(40);
    ms.insert(80);
    ms.insert(50);
    ms.insert(70);
    ms.insert(50);
    ms.insert(40);
    ms.insert(40);
    
    multiset<int>::iterator iter;
    for(iter=ms.begin(); iter != ms.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<endl;
    
    cout<<"40원소 개수 : "<<ms.count(40)<<endl;
    
    iter = ms.find(40);
    cout<<"첫 번째 40원소 반복자 : "<<*iter<<endl;
    
    multiset<int>::iterator upper_iter;
    multiset<int>::iterator lower_iter;
    
    lower_iter = ms.lower_bound(40);
    upper_iter = ms.upper_bound(40);
    cout<<"lower_bound : "<<*lower_iter<<endl;
    cout<<"upper_bound : "<<*upper_iter<<endl;
    cout<<"[lower_bound, upper_bound) 순차열"<<endl;
    for(iter = lower_iter; iter != upper_iter; ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<endl;
    
    pair<multiset<int>::iterator, multiset<int>::iterator> multiset_pair;

    multiset_pair = ms.equal_range(40);
    cout<<"equal_range(40)"<<endl;
    cout<<"pair.first : "<<*multiset_pair.first<<endl;
    cout<<"pair.second : "<<*multiset_pair.second<<endl;
    for(iter = multiset_pair.first; iter != multiset_pair.second; ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<endl;
    
    return 0;
}
    
    
    
