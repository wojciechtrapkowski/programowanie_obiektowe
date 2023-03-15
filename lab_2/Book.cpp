#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() : author(""), title("") {
    cout << "Utworzono nowy pusty obiekt klasy Book."<<endl;
}

Book::Book(Book& other) : author(other.author), title(other.title) {
    cout << "Utworzono nowy obiekt klasy Book, na podstawie jej obiektu, korzystajac z funkcji kompilatora. "<<endl;
}

Book::Book(Book&& other) {
    author = other.author;
    title = other.title;
    other.author = nullptr;
    other.title = nullptr;
    cout << "Utworzono nowy obiekt klasy Book, na podstawie jej obiektu, korzystajac z funkcji move. "<<endl;
}

Book::Book(string& author, string& title) : author(author), title(title) {
    cout<<"Utworzony nowy obiekt z gotowym autorem i tytulem, LReference"<<endl;
}

Book::Book(string&& author, string&& title) : author(move(author)), title(move(title)) {
    cout<<"Utworzony nowy obiekt z gotowym autorem i tytulem, rReference"<<endl;
}

std::ostream& operator<<(std::ostream& os, Book& other) {
	cout<<"Author: " << other.author<<endl;
	cout<<"Title: " << other.title<<endl;
};

void Book::SetAuthor(string &newAuthor) {
    this->author = newAuthor;
}
void Book::SetTitle(string &newTitle) {
    this->title = newTitle;
}

void Book::SetAuthor(string &&newAuthor) {
    author = move(newAuthor);
}
void Book::SetTitle(string &&newTitle) {
    title = move(newTitle);
}

string Book::GetAuthor() {
    return this->author;
}

string Book::GetTitle() {
    return this->title;
}
Book& Book::operator=(Book& right) {
    Book copy = Book(right);
    swap(this->title, copy.title);
    swap(this->author, copy.author);
    return *this;
}

Book& Book::operator=(Book&& other) {
    swap(title, other.title);
    swap(author, other.author);
    return *this;
}

Book::~Book() {
    cout<<"Destruktor został wywołany"<<endl;
}