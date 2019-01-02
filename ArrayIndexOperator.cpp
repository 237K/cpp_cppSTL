//
//  ArrayIndexOperator.cpp
//  cpp_study
//
//  Created by 형성모 on 02/01/2019.
//
//  배열요소에 접근하는 [] 연산자 오버로딩에 대해 공부했습니다.
//  배열의 안정성을 높일 수 있는 방법들에 대해 공부하고 이해했습니다.
//  기본 배열이 경계검사를 하지 않는다는 단점을 보완할 수 있도록 오버로딩 해보았습니다.
//  배열의 복사생성자와 대입연산자를 private으로 선언함으로써 안정성을 높일 수 있도록 하였습니다.
//  const의 선언유무도 함수오버로딩 조건에 해당한다는 것을 이용하여 배열을 참조하지 않고 단순히 반환하는 경우에는 값 변경을 허용하지 않도록 하였습니다.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class BoundCheckArray
{
private:
    int *array;
    int arr_len;
private:
    BoundCheckArray(const BoundCheckArray &copy) {}
    BoundCheckArray& operator=(const BoundCheckArray &assign) {return *this;}
public:
    BoundCheckArray(int len) :arr_len(len)
    {
        array = new int[len];
    }
    int& operator[](int index)
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array Index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    int& operator[](int index) const
    {
        if(index < 0 || index >= arr_len)
        {
            cout<<"Array Index out of bound exception"<<endl;
            exit(1);
        }
        return array[index];
    }
    int GetLen() const { return arr_len; }
    ~BoundCheckArray()
    {
        delete []array;
    }
};

void ShowArray(const BoundCheckArray& array)
{
    int length = array.GetLen();
    for(int i = 0; i < length; i++)
    {
        cout<<array[i]<<endl;
    }
}

int main(void)
{
    BoundCheckArray arr(5);
    for(int i = 0; i < 5; i++)
    {
        arr[i] = (i+1)*11;
    }
    
    ShowArray(arr);
    /*
    for(int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    */
    /*
    BoundCheckArray copy(5);
    copy = arr;
    BoundCheckArray copy2 = arr;
     */
    return 0;
}
