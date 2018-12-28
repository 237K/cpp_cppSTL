//
//  IS_A_inheritance.cpp
//  cpp_study
//
//  Created by 형성모 on 28/12/2018.
//
//  상속과 관련된 5번째 예시문제 입니다.
//  어떤 문법을 사용하는 것이 좋을지.. 가령 매개변수의 이름을 어떻게 정하는게 좋을지.. this를 사용하는게 좋을지 고민하며,
//  다양한 코드들을 참고하여 작성해보고 있습니다.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Book
{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book() {}
    Book(char *title, char *isbn, int price) :price(price)
    {
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
        this->isbn = new char[strlen(isbn)+1];
        strcpy(this->isbn, isbn);
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
    void ShowBook() const
    {
        cout<<"제목 : "<<title<<endl;
        cout<<"ISBN : "<<isbn<<endl;
        cout<<"가격 : "<<price<<"원"<<endl;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;
public:
    EBook() {};
    EBook(char *title, char *isbn, int price, char *DRMKey) :Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey)+1];
        strcpy(this->DRMKey, DRMKey);
    }
    ~EBook()
    {
        delete []DRMKey;
    }
    void ShowEBook() const
    {
        ShowBook();
        cout<<"DRM Key : "<<DRMKey<<endl<<endl;
    }
};

int main(void)
{
    char book_name[50] = {'C','+','+'};
    char ebook_name[50] = {'E','-','C','+','+'};
    char book_isbn[50] = {'5','5','5','-','1','2','3','4','-','8','9','0','-','0'};
    char ebook_drm[50] = {'f','d','k','x','9','w','0','i','8','k'};
    
    char *pbn = book_name;
    char *pebn = ebook_name;
    char *pbi = book_isbn;
    char *pdrm = ebook_drm;
    
    int book_price = 20000;
    int ebook_price = 10000;
    
    Book book1(pbn, pbi, book_price);
    book1.ShowBook();
    
    cout<<endl;
    
    EBook ebook1(pebn, pbi, ebook_price, pdrm);
    ebook1.ShowEBook();
    
    return 0;
}
