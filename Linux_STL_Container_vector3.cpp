//  Linux
//  Vector.cpp
//  Created by Seongmo Hyeong on 08/01/2019.
//
//  Studying STL.. STL Container, Iterator, Algorithm, Functor, Adaptor, Allocator..
//  I start using Linux. It's still unfamiliar, but I hope to use it frequently and expect to be close.
//  
//  Last two days, I have been looking at the outline of STL and now I look deeply into it.
//  First, STL container. <vector>
//  The way to make capacity 0 with swap()
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
    vector<int> v(5);

    Print(v);

    v.clear();
    cout<<"clear()"<<endl;
    Print(v);

    cout<<endl;

    vector<int>().swap(v);
    cout<<"swap with default vector"<<endl;
    Print(v);
    cout<<endl;

    return 0;
}