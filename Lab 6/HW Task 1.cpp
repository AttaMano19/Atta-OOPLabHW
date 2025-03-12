#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string category;
public:
    Publication(string cat) : category(cat) {}
    virtual void showDetails()
    {
        cout << "Category: " << category << endl;
    }
};

class Thriller : public Publication
{
private:
    string bookTitle;
    string writer;
public:
    Thriller(string t, string a) : Publication("Thriller"), bookTitle(t), writer(a) {}
    void showDetails() override
    {
        Publication::showDetails();
        cout << "Book Title: " << bookTitle << endl;
        cout << "Writer: " << writer << endl;
    }
};

class Fiction : public Publication
{
private:
    string bookTitle;
    string writer;
public:
    Fiction(string t, string a) : Publication("Fiction"), bookTitle(t), writer(a) {}
    void showDetails() override
    {
        Publication::showDetails();
        cout << "Book Title: " << bookTitle << endl;
        cout << "Writer: " << writer << endl;
    }
};

int main()
{
    Fiction fictionBook("Wuthering Heights", "Emily Bronte");
    Thriller thrillerBook("The Woman in White", "Wilkie Collins");
    
    fictionBook.showDetails();
    cout << endl;
    thrillerBook.showDetails();
    
    return 0;
}