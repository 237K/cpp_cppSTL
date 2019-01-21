//
//  STL_ContainerAdapter.cpp
//  cpp_study
//
//  Created by 형성모 on 21/01/2019.
//
//  [STL 컨테이너 어댑터]
//      1. stack
//          - LIFO / 기본 컨테이너 deque / vector, deque, list 사용 가능
//          - 멤버함수
//              1) empty() : bool empty() const
//              2) size() : size_type size() const
//              3) push(x) : void push(const value_type& x)
//              4) pop() : void pop()
//              5) top() : value_type& top()
//              6) top() const : const value_type& top() const
//
//      2. queue
//          - FIFO / 기본 컨테이너 deque / deque, list 사용 가능
//          - 멤버함수
//              1) empty()
//              2) size()
//              3) push(x) : push_back(x)
//              4) pop() : pop_front()
//              5) front()
//              6) front() const
//              7) back()
//              8) back() const
//
//      3. priority_queue
//          - 우선순위 queue / 힙구조 / 기본 컨테이너 vector / 기본 정렬 기준 less / vector, deque 사용 가능
//          - 멤버함수
//              1) empty()
//              2) size()
//              3) push(x) : push_back, push_heap
//              4) pop() : 벡터를 사용하면 루트노드와 마지막 노드를 교환하고 pop_back 하고 pop_heap
//              5) top() : 루트노드( front() )
//              6) top() const
//

#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int main(void)
{
    //stack
    cout<<"stack"<<endl;
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;
    
    //queue
    cout<<"queue"<<endl;
    queue<int, list<int> > q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;
    
    //priority_queue
    cout<<"priority_queue"<<endl;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(20);
    
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
    return 0;
}
