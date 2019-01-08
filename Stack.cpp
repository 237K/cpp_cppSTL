//
//  Stack.cpp
//  cpp_study
//
//  Created by 형성모 on 08/01/2019.
//
//  최소한의 기능을 가진 Stack 클래스를 구현해보았습니다.
//

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T* data;
    int size;
    int index;
public:
    Stack(int size=100) : size(size), index(0)
    {
        data = new T[size];
    }
    ~Stack() { delete []data; }
    void Push(const T& dt)
    {
        data[index++] = dt;
    }
    const T& Pop()
    {
        return data[--index];
    }
    bool Empty() const
    {
        return index == 0 ? true : false;
    }
};

int main(void)
{
    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    
    if(!st.Empty()) cout<<"Not Empty"<<st.Pop()<<endl;
    if(!st.Empty()) cout<<"Not Empty"<<st.Pop()<<endl;
    if(!st.Empty()) cout<<"Not Empty"<<st.Pop()<<endl;
    if(!st.Empty()) cout<<"Not Empty"<<st.Pop()<<endl;
    else cout<<"Empty"<<endl;
    
    return 0;
}
