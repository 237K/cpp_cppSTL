//
//  InheritAssignOperator2.cpp
//  cpp_study
//
//  Created by 형성모 on 1/1/2019.
//
//  상속 구조에서의 대입 연산자 호출에 대해 공부했습니다.
//  derived class에서 대입연산자를 정의해야할 경우, base class의 대입연산자를 명시하지 않으면 bass class 대입연산자가 호출되지 않는다는
//  것을 이해했습니다.
//
//  상속 구조에서 대입연산자 호출을 통해 깊은복사가 일어나도록 하는 예시문제 2
//

#include <iostream>
#include <cstring>

using namespace std;

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
    Book(const Book &book)
    {
        title = new char[strlen(book.title)+1];
        strcpy(title, book.title);
        isbn = new char[strlen(book.isbn)+1];
        strcpy(isbn, book.isbn);
        price = book.price;
    }
    Book& operator=(const Book & temp)
    {
        delete []title;
        delete []isbn;
        title = new char[strlen(temp.title)+1];
        strcpy(title, temp.title);
        isbn = new char[strlen(temp.isbn)+1];
        strcpy(isbn, temp.isbn);
        price = temp.price;
        return *this;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
        cout<<"Book 소멸자가 호출되었습니다."<<endl;
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
    EBook(const EBook &ebook) : Book(ebook)
    {
        DRMKey = new char[strlen(ebook.DRMKey)+1];
        strcpy(DRMKey, ebook.DRMKey);
    }
    EBook& operator=(const EBook &temp)
    {
        Book::operator=(temp);
        delete []DRMKey;
        DRMKey = new char[strlen(temp.DRMKey)+1];
        strcpy(DRMKey, temp.DRMKey);
        return *this;
    }
    ~EBook()
    {
        delete []DRMKey;
        cout<<"EBook 소멸자가 호출되었습니다."<<endl;
    }
    void ShowEBook() const
    {
        ShowBook();
        cout<<"DRM Key : "<<DRMKey<<endl<<endl;
    }
};

int main(void)
{
    //char book_name[50] = {'C','+','+'};
    char ebook_name[50] = {'E','-','C','+','+'};
    char book_isbn[50] = {'5','5','5','-','1','2','3','4','-','8','9','0','-','0'};
    char ebook_drm[50] = {'f','d','k','x','9','w','0','i','8','k'};
    
    //char *pbn = book_name;
    char *pebn = ebook_name;
    char *pbi = book_isbn;
    char *pdrm = ebook_drm;
    
    //int book_price = 20000;
    int ebook_price = 10000;
    
    //Book book1(pbn, pbi, book_price);
    //book1.ShowBook();
    
    //cout<<endl;
    
    EBook ebook1(pebn, pbi, ebook_price, pdrm);
    ebook1.ShowEBook();
    
    EBook ebook2 = ebook1;
    ebook2.ShowEBook();
    
    return 0;
}
