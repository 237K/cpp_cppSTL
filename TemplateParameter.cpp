//
//  TemplateParameter.cpp
//  cpp_study
//
//  Created by 형성모 on 05/01/2019.
//
//  템플릿 매개변수에 값을 전달받을 수 있는 변수를 선언하면, 변수에 전달되는 상수를 통해 서로 다른 형의 클래스가 생성되게 할 수 있습니다.
//  이렇게 하면 서로 다른 형의 객체간 대입연산이나 복사생성자를 방지할 수 있으므로, 별도의 추가적인 코드를 삽입하지 않아도 됩니다.
//  또한 템플릿 매개변수는 디폴트값 지정 역시 가능합니다.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T=int, int len=5>
class Array
{
private:
    T array[len];
public:
    T& operator[](int index)
    {
        if(index < 0 || index >= len) { exit(1); }
        return array[index];
    }
    Array<T, len>& operator=(const Array<T, len>& arr)
    {
        for(int i = 0; i < len; i++)
        {
            array[i] = arr.array[i];
        }
        return *this;
    }
    void ShowArray() const
    {
        for(int i = 0; i < len; i++)
        {
            cout<<array[i]<<' ';
        }
        cout<<endl;
    }
};

int main(void)
{
    cout<<"디폴트값 지정이 가능한지 확인합니다."<<endl;
    Array<> arr1;
    for(int i = 0; i < 5; i++)
    {
        arr1[i] = i+3;
    }
    arr1.ShowArray();
    
    cout<<"Array<int, 5>"<<endl;
    Array<int, 5> i5arr1;
    for(int i = 0; i < 5; i++)
    {
        i5arr1[i] = i*5;
    }
    i5arr1.ShowArray();
    
    cout<<"Array<int, 5>를 새로 만들어 대입해보겠습니다."<<endl;
    Array<int, 5> i5arr2;
    i5arr2 = i5arr1;
    i5arr2.ShowArray();
    
    cout<<"Array<int, 7>"<<endl;
    Array<int, 7> i7arr1;
    
    //i7arr1 = i5arr1;
    
    for(int i = 0; i < 7; i++)
    {
        i7arr1[i] = i*7;
    }
    i7arr1.ShowArray();
    
    Array<int, 7> i7arr2;
    i7arr2 = i7arr1;
    i7arr2.ShowArray();
    
    return 0;
}
