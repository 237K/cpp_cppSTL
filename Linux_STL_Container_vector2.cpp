//  Linux
//  Vector.cpp
//  Created by Seongmo Hyeong on 08/01/2019.
//
//  Studying STL.. STL Container, Iterator, Algorithm, Functor, Adaptor, Allocator..
//  I start using Linux. It's still unfamiliar, but I hope to use it frequently and expect to be close.
//  
//  Last two days, I have been looking at the outline of STL and now I look deeply into it.
//  First, STL container. <vector>
//  Think about capacity() of vector
//
#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& vect)
{
    cout<<"size : "<<vect.size()<<endl;
    cout<<"capacity : "<<vect.capacity()<<endl;
    cout<<"element : ";
    for(vector<int>::size_type i=0; i < vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    cout<<"=============================="<<endl;   
}

int main(void)
{
    vector<int> v;

    Print(v);

    v.push_back(11);
    Print(v);

    v.push_back(22);
    Print(v);

    v.push_back(33);
    Print(v);

    v.push_back(44);
    Print(v);

    v.push_back(55);
    Print(v);

    return 0;
}