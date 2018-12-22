//
//  swap_pointer.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 22..
//
// 포인터 스왑 함수

#include <iostream>

using namespace std;

void SwapPointer(int *(&ptr1), int *(&ptr2));

int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;
    
    cout<<"num1 = *ptr1 = "<<*ptr1<<endl;
    cout<<"num2 = *ptr2 = "<<*ptr2<<endl;
    
    SwapPointer(ptr1, ptr2);
    
    cout<<"-------swap--------"<<endl;
    cout<<"ptr1 = "<<*ptr1<<endl;
    cout<<"ptr2 = "<<*ptr2<<endl;

    return 0;
}

void SwapPointer(int *(&ptr1), int *(&ptr2))
{
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
