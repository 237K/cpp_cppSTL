//
//  STL_Algorithm_Modifying.cpp
//  cpp_study
//
//  Created by 형성모 on 13/01/2019.
//
//  STL 알고리즘 #include <algorithm>
//      2. 원소를 수정하는 알고리즘
//          1) copy(v1.begin(), v1.end(), v2.begin()) : v1 순차열을 v2에 복사
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(const vector<int>& v)
{
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int main(void)
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    vector<int> v2;
    v2.resize(5);
    
    vector<int>::iterator copy_end_iter;
    
    copy_end_iter = copy(v1.begin(), v1.end(), v2.begin());
    
    cout<<"v1 : "; Print(v1);
    cout<<"copy_end_iter : "<<*(copy_end_iter-1)<<endl;
    cout<<"v2 : "; Print(v2);
    
    return 0;
}
