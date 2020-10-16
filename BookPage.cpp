#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>

/*
       ДОМАШНЕЕ ЗАДАНИЕ:
       - Реализуйте класс Page (номер страницы, содержимое страницы)
       - Реализуйте класс Book (название, автор, год издания, массив Page)
       - При запуске программы пользователь должен заполнить данные книги
       - Страницы должны быть заполнены до тех пор пока пользователь не
       пожелает прекратить добавлять новые страницы
       - Всего должно быть добавлено 2 книги
       - В методах запрещено использовать cin, cout
       - Распечатайте все данные двух книг
   */

class Page
{
public:

    Page()
    {

    }
    Page& operator=(const Page& other)
    {
        m_length = strlen(other.m_content);
        m_content = new char[m_length + 1];
        strcpy(m_content, other.m_content);
        return *this;
    }
    /*Page&operator=(Page&& other)
    {
        m_content = other.m_content;
        m_length = other.m_length;
        other.m_content = nullptr;
        return *this;
    }*/

    Page(const Page& other)
    {
        m_numberPage = other.m_numberPage;
        m_length = other.m_length;
        m_content = new char[m_length + 1];
        strcpy(m_content, other.m_content);
    }

    /*Page(Page&& other)
    {
        m_numberPage = other.m_numberPage;
        m_length = other.m_length;
        m_content=other.m_content;
        other.m_content = nullptr;
    }*/


    Page(const int number, const char* source)
    {
        cpy(number, source);
    }

    const char* data()const
    {
        return m_content;
    }

    ~Page()
    {
        delete[] m_content;
    }

    void cpy(int number, const char* source)
    {
        int sourceLen = strlen(source);
        if (sourceLen <= allSize)
        {
            m_length = sourceLen;
            m_numberPage = number;
            m_content = new char[m_length + 1];
            strcpy(m_content, source);
        }
    }

    int getNumber()const
    {
        return m_numberPage;
    }

    void setNumber(const int number)
    {
        m_numberPage = number;
    }
private:
    size_t m_numberPage = 0;
    char* m_content = nullptr;
    size_t m_length = 0;
    const size_t allSize = 250;
};

class Book
{
public:

    Book() :m_numberPage(++count) {}

    Book(const char* name, const char* autor, const int year, const int countPage) :
        m_numberPage(++count),
        m_year(year),
        m_sizePage(countPage)
    {
        strcpy_s(m_name, name);
        strcpy_s(m_autor, autor);
        m_page = new Page[m_sizePage];
    }

    void addPage(Page& page)
    {
        Page* tmp = new Page[m_sizePage + 1];
        for (int i = 0; i < m_sizePage; i++)
        {
            tmp[i] = m_page[i];
        }
        tmp[m_sizePage++] = page;
        delete[] m_page;
        m_page = tmp;
    }

    void setName(const char* name)
    {
        strcpy_s(m_name, name);
    }

    const char* getName()const
    {
        return m_name;
    }

    Book(const Book& other)
    {
        m_sizePage = other.m_sizePage;
        m_year = other.m_year;
        strcpy(m_autor, other.m_autor);
        strcpy(m_name, other.m_name);
        m_numberPage = other.m_numberPage;
        m_page = new Page[m_sizePage];
        for (int i = 0; i < m_sizePage; i++)
        {
            m_page[i] = other.m_page[i];
        }
    }

    /*Book(Book&& other)
    {
        m_sizePage = other.m_sizePage;
        m_year = other.m_year;
        strcpy(m_autor, other.m_autor);
        strcpy(m_name, other.m_name);
        m_numberPage = other.m_numberPage;
        m_page = new Page[m_sizePage];
        for (int i = 0; i < m_sizePage; i++)
        {
            m_page[i] = other.m_page[i];
        }
        other.m_page = nullptr;
    }*/

    /*Book& operator=(Book&& other)
    {
        m_sizePage = other.m_sizePage;
        m_year = other.m_year;
        strcpy(m_autor, other.m_autor);
        strcpy(m_name, other.m_name);
        m_numberPage = other.m_numberPage;
        m_page = new Page[m_sizePage];
        for(int i = 0 ; i <m_sizePage ; i++ )
        {
            m_page[i] = other.m_page[i];
        }
        other.m_page = nullptr;
        return  *this;
    }*/

    const char* getAutor()const
    {
        return m_autor;
    }

    int getYear()const
    {
        return m_year;
    }

    int getSizePage()const
    {
        return m_sizePage;
    }

    void setAutor(const char* autor)
    {
        strcpy_s(m_autor, autor);
    }

    void setYear(const int year)
    {
        m_year = year;
    }

    void setPageNum(const int sizeNum)
    {
        m_sizePage = sizeNum;
        m_page = new Page[m_sizePage];
    }

    Page& getPage(const int index)const
    {
        return m_page[index];
    }

    ~Book()
    {
        count--;
        delete[]m_page;
    }

    size_t getNumber()const
    {
        return m_numberPage;
    }

    static size_t getCount()
    {
        return count;
    }

    void addPage(const Book& page) {



    }

private:
    Page* m_page = nullptr;
    char m_name[20] = "NoName";
    char m_autor[20] = "NoAutor";
    int m_year = 0;
    int m_sizePage = 0;
    size_t m_numberPage;
    static size_t count;
};

size_t Book::count = 0;

int main()
{
    const int quantityBook = 2;
    char text[100];
    char textInformation[20];
    int number;


    Book arr[quantityBook];


    for (int i = 0; i < quantityBook; i++)
    {
        std::cout << "Enter information\n";
        std::cout << "\nBook name   =  ";
        std::cin >> textInformation;
        arr[i].setName(textInformation);

        std::cout << "Autor name  =  ";
        std::cin >> textInformation;
        arr[i].setAutor(textInformation);

        std::cout << "Year        =  ";
        std::cin >> number;
        arr[i].setYear(number);

        std::cout << "\nQuantity page     =  ";
        std::cin >> number;
        arr[i].setPageNum(number);

        for (int j = 0; j < arr[i].getSizePage(); j++)
        {
            std::cin >> text;
            arr[i].getPage(j).cpy((j + 1), text);

        }
        std::cout << "\n\n=====================================================================\n\n";
    }


    for (int i = 0; i < quantityBook; i++)
    {
        std::cout << "Book #  " << arr[i].getNumber() << '\n';
        std::cout << "\nBook name        =  ";
        std::cout << arr[i].getName();

        std::cout << "\nAutor name       =  ";
        std::cout << arr[i].getAutor();

        std::cout << "\nYear             =  ";
        std::cout << arr[i].getYear();

        std::cout << "\nQuantity page    =  ";
        std::cout << arr[i].getSizePage();


        std::cout << "\n\nContent of page : \n\n";
        for (int j = 0; j < arr[i].getSizePage(); j++)
        {
            std::cout << arr[i].getPage(j).getNumber() << "\t:\t" << arr[i].getPage(j).data() << '\n';
        }
        std::cout << "\n\n=====================================================================\n\n";
    }

}
