#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX_BOOKS = 100;
const int MAX_USERS = 100;
const int MAX_BOOKS_TO_BORROW = 20;

struct book
{
    int id, total_quantity, borrowed;
    string name;
    string borrowed_users[10];

};

struct user
{
    int id, no_of_borrowed_books;
    string name;
    book borrowed_books[MAX_BOOKS_TO_BORROW];
};

struct library
{
    book books[MAX_BOOKS];
    book curr_book;
    user curr_user;
    user users[MAX_USERS];
    int no_of_books {0};
    int no_of_users {0};
    int id_arr[MAX_BOOKS];
    string names_arr[MAX_BOOKS];

    void add_book()
    {

        cout << "Enter book info: id & name & total quantity: ";
        cin >> curr_book.id >> curr_book.name >> curr_book.total_quantity;
        curr_book.borrowed = 0;

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
                        << " total quantity = " << books[j].total_quantity << " total borrowed = " << books[j].borrowed << endl;
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
                        << " total quantity = " << books[j].total_quantity << " total borrowed = " << books[j].borrowed << endl;
                    }
                }
            }
        }
    }

    void add_user()
    {
        cout << "Enter user name and id: ";
        cin >> curr_user.name >> curr_user.id;
        curr_user.no_of_borrowed_books = 0;
        users[no_of_users] = curr_user;
        no_of_users++;
    }

    int find_user(const string& user_name)
    {
        int idx = -1;
        for(int i=0; i<no_of_users; i++)
        {
            if (users[i].name == user_name)
                idx = i;
        }
        return idx;
    }

    int find_book(const string& book_name)
    {
        int idx = -1;
        for (int i=0; i<no_of_books; i++)
        {
            if (books[i].name == book_name)
                idx = i;
        }
        return idx;
    }

    string get_borrowed_book_ids(const user& user)
    {
        string borrowed_book_str = "";

        for (int i=0; i<user.no_of_borrowed_books; i++)
        {
            borrowed_book_str += to_string(user.borrowed_books[i].id) + " ";
        }
        return borrowed_book_str;
    }

    void borrow_book()
    {
        string user_name, book_name;
        int idx_user, idx_book;

        cout << "Enter user name and book name: ";
        cin >> user_name >> book_name;

        idx_user = find_user(user_name);

        if (idx_user == -1)
        {
            cout << "!!! user not found !!!" << endl;
            return;
        }

        idx_book = find_book(book_name);

        if (idx_book == -1)
        {
            cout << "!!! book not found !!!" << endl;
            return;
        }

        if (books[idx_book].borrowed < books[idx_book].total_quantity)
        {
            books[idx_book].borrowed_users[books[idx_book].borrowed] = users[idx_user].name;
            books[idx_book].borrowed++;
            if (users[idx_user].no_of_borrowed_books < MAX_BOOKS_TO_BORROW)
            {
                users[idx_user].borrowed_books[users[idx_user].no_of_borrowed_books] = books[idx_book];
                users[idx_user].no_of_borrowed_books++;
            }
        }
        else
        {
            cout << "Sorry, No more " << book_name << " book available for borrow" << endl;
            return;
        }
    }

    void return_book()
    {
        string user_name, book_name;
        int idx_user, idx_book;

        cout << "Enter user name and book name: ";
        cin >> user_name >> book_name;

        idx_user = find_user(user_name);

        if (idx_user == -1)
        {
            cout << "!!! user not found !!!" << endl;
            return;
        }

        idx_book = find_book(book_name);

        if (idx_book == -1)
        {
            cout << "!!! book not found !!!" << endl;
            return;
        }

        books[idx_book].borrowed--;

        for(int i=0; i<users[idx_user].no_of_borrowed_books; i++)
        {
            if(users[idx_user].borrowed_books[i].name == book_name)
            {
                users[idx_user].borrowed_books[i].name = "";
                users[idx_user].no_of_borrowed_books--;
            }
        }
    }

    void print_users()
    {
        if (no_of_users == 0)
            return;

        for (int i=0; i<no_of_users; i++)
        {
            cout << "user " << users[i].name << " id " << users[i].id << " borrowed books ids: " << get_borrowed_book_ids(users[i]) << endl;
        }
    }

    void search_book()
    {
        string prefix;
        bool found_book = false;

        cout << "Enter book name prefix: " << endl;
        cin >> prefix;

        for (int i=0; i<no_of_books; i++)
        {
            if (books[i].name.find(prefix) != string::npos)
            {
                cout << books[i].name << endl;
                found_book = true;
            }

        }
        if (!found_book)
            cout << "No books with such prefix" << endl;

    }

    void print_who_borrowed()
    {
        // TODO: update by shifting the elements to the left
        string book_name;
        cout << "Enter book name: ";
        cin >> book_name;
        for (int i=0; i<no_of_books; i++)
        {
            if (books[i].name == book_name)
            {
                for(int j=0; j<books[i].borrowed; j++)
                {
                    cout << books[i].borrowed_users[j] << endl;
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
    cout << "6) add user" << endl;
    cout << "7) user borrow book" << endl;
    cout << "8) user return book" << endl;
    cout << "9) print users" << endl;
    cout << "10) exit" << endl;

    cout << "Enter your menu choice [1-10]: " ;
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
        else if (choice == 2)
            my_library.search_book();
        else if (choice == 3)
            my_library.print_who_borrowed();
        else if (choice == 4)
            my_library.print("id");
        else if (choice == 5)
            my_library.print("name");
        else if (choice == 6)
            my_library.add_user();
        else if (choice == 7)
            my_library.borrow_book();
        else if (choice == 8)
            my_library.return_book();
        else if (choice == 9)
            my_library.print_users();
        else
            cout << "Invalid selection" << endl;
    }

    return 0;
}
