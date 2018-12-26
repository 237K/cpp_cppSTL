//
//  name_card.cpp
//  cpp_study
//
//  Created by 형성모 on 2018. 12. 25..
//
//  동적할당을 이용하여 명함 관리 프로그램을 개발하였습니다.
//  ver2. 복사생성자와 얕은복사, 깊은복사에 대해 배웠으며, 얕은복사로 인한 에러 상황을 이해하였습니다.
//  ver2. 복사생성자를 정의함으로써 깊은복사를 가능하도록 하여 소스의 안정성을 높였습니다.

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
 
namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPosition(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout<<"사원";
                break;
            case SENIOR:
                cout<<"주임";
                break;
            case ASSIST:
                cout<<"대리";
                break;
            case MANAGER:
                cout<<"과장";
                break;
        }
    }
};

class NameCard
{
private:
    char *name, *company, *mobile;
    int position;
public:
    NameCard(char *name1, char *company1, char *mobile1, int position);
    ~NameCard();
    NameCard(const NameCard &copy);
    void ShowNameCard() const;
};

NameCard::NameCard(char *name1, char *company1, char *mobile1, int position1)
{
    name = new char[strlen(name1)+1];
    strcpy(name, name1);

    company = new char[strlen(company1)+1];
    strcpy(company, company1);
    
    mobile = new char[strlen(mobile1)+1];
    strcpy(mobile, mobile1);
    
    position = position1;
}

NameCard::NameCard(const NameCard &copy) :position(copy.position)
{
    name = new char[strlen(copy.name)+1];
    strcpy(name, copy.name);
    company = new char[strlen(copy.company)+1];
    strcpy(company, copy.company);
    mobile = new char[strlen(copy.mobile)+1];
    strcpy(mobile, copy.mobile);
}

NameCard::~NameCard()
{
    delete []name;
    delete []company;
    delete []mobile;
}

void NameCard::ShowNameCard() const
{
    cout<<"-----------------------"<<endl;
    cout<<"이   름 : "<<name<<endl;
    cout<<"회   사 : "<<company<<endl;
    cout<<"전화번호 : "<<mobile<<endl;
    cout<<"직   급 : "; COMP_POS::ShowPosition(position);
    cout<<endl;
    cout<<"-----------------------"<<endl<<endl;
}

int main(void)
{
    NameCard manCLERK("Lee", "ABC", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "BCD", "010-2222-3333", COMP_POS::SENIOR);
    NameCard manASSIST("Kim", "CDF", "010-3333-4444", COMP_POS::ASSIST);
    
    manCLERK.ShowNameCard();
    manSENIOR.ShowNameCard();
    manASSIST.ShowNameCard();
    
    NameCard copy1 = manCLERK; //NameCard copy1(manCLERK) 의 형태로 묵시적 형변환이 발생합니다.
    NameCard copy2 = manSENIOR;
    
    copy1.ShowNameCard();
    copy2.ShowNameCard();
    
    cout<<"깊은복사가 제대로 이루어졌는지 확인합니다."<<endl;
    
    return 0;
}
