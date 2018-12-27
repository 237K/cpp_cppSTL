//
//  CopyCon_TemporaryObj.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 26..
//
//  복사생성자와 복사생성자의 호출시점에 대해 공부하였습니다.
//  임시객체가 만들어지는 경우와 임시객체의 소멸시점에 대해 공부하였습니다.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Example
{
private:
    int num;
public:
    Example(int n) : num(n)
    {
        cout<<"생성자가 호출되었습니다!."<<endl;
        cout<<"this를 출력해보겠습니다 : "<<this<<endl<<endl;
    }
    
    Example(const Example& copy) : num(copy.num)
    {
        cout<<"복사생성자가 호출되었습니다!."<<endl;
        cout<<"this를 출력해보겠습니다 : "<<this<<endl<<endl;
    }
    
    ~Example()
    {
        cout<<"소멸자가 호출되었습니다!"<<endl;
        cout<<"this를 출력해보겠습니다 : "<<this<<endl<<endl;
    }
};

Example ExampleFunction(Example ob)
{
    cout<<"이 함수는 복사생성자를 호출할텐데요. 매개변수의 주소값을 출력해서 복사생성자로 생성된 객체의 주소와 같은지 보겠습니다."<<endl;
    cout<<&ob<<endl;
    return ob;
}

int main(void)
{
    Example ex(2);
    ExampleFunction(ex);
    
    cout<<endl;
    Example tempRef = ExampleFunction(ex);
    cout<<"Return ex "<<&tempRef<<endl;
    return 0;
}
