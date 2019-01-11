//
//  STL_Container_Multimap.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//  
//  STL 컨테이너를 공부하고 있습니다.
//  multimap

#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    multimap<int, int> mm;
    
    mm.insert(pair<int, int>(1, 11));
    mm.insert(pair<int ,int>(7, 77));
    mm.insert(pair<int, int>(3, 33));
    mm.insert(pair<int, int>(5, 55));
    mm.insert(pair<int, int>(2, 22));
    mm.insert(pair<int, int>(4, 44));
    mm.insert(pair<int, int>(4, 444));
    mm.insert(pair<int, int>(4, 4444));
    
    multimap<int, int>::iterator iter;
    for(iter = mm.begin(); iter != mm.end(); ++iter)
    {
        cout<<"("<<iter->first<<", "<<iter->second<<") ";
    }
    cout<<endl<<endl;
    
    cout<<"key 4인 원소의 개수는 "<<mm.count(4)<<" 개 입니다."<<endl;
    
    multimap<int, int>::iterator find_iter;
    find_iter = mm.find(4);
    
    cout<<"첫 번째 key가 "<<find_iter->first<<"인 원소의 value는 "<<find_iter->second<<endl;
    
    multimap<int, int>::iterator lower_iter;
    multimap<int, int>::iterator upper_iter;
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> equal_iter;
    
    lower_iter = mm.lower_bound(4);
    upper_iter = mm.upper_bound(4);
    cout<<"[lower_bound] key : "<<lower_iter->first<<" value : "<<lower_iter->second<<endl;
    cout<<"[upper_bound] key : "<<upper_iter->first<<" value : "<<upper_iter->second<<endl;
    
    equal_iter = mm.equal_range(4);
    for(iter = equal_iter.first; iter != equal_iter.second; ++iter)
    {
        cout<<"("<<iter->first<<", "<<iter->second<<") ";
    }
    cout<<endl<<endl;
    
    return 0;
}
