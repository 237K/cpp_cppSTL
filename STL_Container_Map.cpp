//
//  STL_Container_Map.cpp
//  cpp_study
//
//  Created by 형성모 on 11/01/2019.
//
//  STL 컨테이너를 공부하고 있습니다.
//  map
//  * key와 value의 쌍(pair객체)을 저장
//  * []연산자 사용 가능

#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<int, int> m;
    
    m.insert(pair<int, int>(1, 30));
    m.insert(pair<int, int>(5, 70));
    m.insert(pair<int, int>(3, 40));
    m.insert(pair<int, int>(7, 80));
    
    pair<int, int> pair1(9, 50);
    m.insert(pair1);
    
    map<int, int>::iterator iter;
    
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        cout<<"("<<(*iter).first<<", "<<(*iter).second<<") ";
    }
    cout<<endl<<endl;
    
    pair<map<int, int>::iterator, bool> insert_pair;
    insert_pair = m.insert(pair<int, int>(11, 1122));
    if(insert_pair.second == true) cout<<"("<<(*insert_pair.first).first<<", "<<insert_pair.first->second<<") 삽입 완료"<<endl;
    else cout<<"해당 map에 이미 "<<insert_pair.first->first<<"가 존재합니다."<<endl;
    
    insert_pair = m.insert(pair<int, int>(11, 1201));
    if(insert_pair.second == true) cout<<"("<<(*insert_pair.first).first<<", "<<insert_pair.first->second<<") 삽입 완료"<<endl;
    else cout<<"해당 map에 이미 "<<insert_pair.first->first<<"가 존재합니다."<<endl;
    
    cout<<endl;
    
    m[22] = 2222;
    cout<<"m[22] = 2222, m[22] 값 추가"<<endl;
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        cout<<"("<<(*iter).first<<", "<<(*iter).second<<") ";
    }
    cout<<endl<<endl;
    
    m[22] = 3333;
    cout<<"m[22] = 3333, m[22] 값 갱신"<<endl;
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        cout<<"("<<(*iter).first<<", "<<(*iter).second<<") ";
    }
    cout<<endl<<endl;
    
    map<int, int>::iterator find_iter;
    find_iter = m.find(5);
    cout<<"find(5)"<<endl;
    cout<<"key : "<<find_iter->first<<", value : "<<find_iter->second<<endl;
    cout<<endl;
    
    map<int, int>::iterator lower_iter;
    map<int, int>::iterator upper_iter;
    pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
    
    lower_iter = m.lower_bound(7);
    upper_iter = m.upper_bound(7);
    iter_pair = m.equal_range(7);
    
    cout<<"[lower_bound] key : "<<lower_iter->first<<" value : "<<(*lower_iter).second<<endl;
    cout<<"[upper_bound] key : "<<(*upper_iter).first<<" value : "<<upper_iter->second<<endl;
    cout<<"[equal_range]"<<endl;
    cout<<"lower_bound key : "<<iter_pair.first->first<<" value : "<<(*iter_pair.first).second<<endl;
    cout<<"upper_bound key : "<<(*iter_pair.second).first<<" value : "<<iter_pair.second->second<<endl;
    
    return 0;
}
