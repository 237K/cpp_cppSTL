//  Linux
//  Vector.cpp
//  Created by Seongmo Hyeong on 08/01/2019.
//
//  Studying STL.. STL Container, Iterator, Algorithm, Functor, Adaptor, Allocator..
//  I start using Linux. It's still unfamiliar, but I hope to use it frequently and expect to be close.
//  
//  Last two days, I have been looking at the outline of STL and now I look deeply into it.
//  First, STL container. <vector>

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;

    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    v.push_back(44);
    v.push_back(55);

    for(vector<int>::size_type i=0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;

    cout<<"v.size() : "<<v.size()<<endl;
    cout<<"v.capacity() : "<<v.capacity()<<endl;
    cout<<"v.max_size() : "<<v.max_size()<<endl;

    return 0;
}
