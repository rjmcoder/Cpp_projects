#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX_BOOKS = 1000;

struct book
{
    int id, total_quantity;
    string name;

};

struct user
{
    int id;
    string name;

};

struct library
{
    book books[MAX_BOOKS];
    book curr_book;
    int no_of_books {0};
    int id_arr[MAX_BOOKS];
    string names_arr[MAX_BOOKS];

    void add_book()
    {

        cout << "Enter book info: id & name & total quantity: " << endl;
        cin >> curr_book.id >> curr_book.name >> curr_book.total_quantity;

        books[no_of_books] = curr_book;
        id_arr[no_of_books] = curr_book.id;
        names_arr[no_of_books] = curr_book.name;
        no_of_books++;

    }


    void print(string sort_by)
    {
        if (sort_by == "id")
        {
            cout << endl;
            sort(id_arr, id_arr + no_of_books);

            for (int i=0; i<no_of_books; i++)
            {
                for (int j=0; j<no_of_books; j++)
                {
                    if (id_arr[i] == books[j].id)
                    {
                        cout << "id = " << books[j].id << " name = " << books[j].name \
                        << " total quantity = " << books[j].total_quantity << endl;
                    }
                }
            }
        }
        else
        {
            cout << endl;
            sort(names_arr, names_arr + no_of_books);

            for (int i=0; i<no_of_books; i++)
            {
                for (int j=0; j<no_of_books; j++)
                {
                    if (names_arr[i] == books[j].name)
                    {
                        cout << "id = " << books[j].id << " name = " << books[j].name \
                        << " total quantity = " << books[j].total_quantity << endl;
                    }
                }
            }
        }
    }

};


int menu()
{
    int choice;

    cout << endl;
    cout << "Library Menu: " << endl;
    cout << "1) add a book" << endl;
    cout << "2) search books by prefix" << endl;
    cout << "3) print who borrowed book by name" << endl;
    cout << "4) print library by id" << endl;
    cout << "5) print library by name" << endl;
    cout << "6) add use" << endl;
    cout << "7) user borrow book" << endl;
    cout << "8) user return book" << endl;
    cout << "9) print users" << endl;
    cout << "10) exit" << endl;

    cout << "Enter your menu choice [1-10]:" << endl;
    cin >> choice;

    return choice;
}



int main()
{

    library my_library;

    while (true)
    {
        int choice = menu();
        if (choice == 1)
            my_library.add_book();
        if (choice == 4)
            my_library.print("id");
        if (choice == 5)
            my_library.print("name");
    }

    return 0;
}
