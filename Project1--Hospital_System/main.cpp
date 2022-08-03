#include <iostream>

using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECIALIZATION][MAX_QUEUE];
int status[MAX_SPECIALIZATION][MAX_QUEUE];
int no_of_patients[MAX_SPECIALIZATION];


int get_choice()
{
    int choice {0};
    cout << "Enter your choice:" << endl;
    cout << "1) Add new patient" << endl;
    cout << "2) Print all patients" << endl;
    cout << "3) Get next patient" << endl;
    cout << "4) Exit" << endl;
    cin >> choice;

    return choice;

}

void shift_right(int spec)
{
    for (int i=no_of_patients[spec]; i>0; i--)
    {
        names[spec][i] = names[spec][i-1];
        status[spec][i] = status[spec][i-1];
    }

}

void shift_left(int spec)
{
    for (int i=0; i<no_of_patients[spec]; i++)
    {
        names[spec][i] = names[spec][i+1];
        status[spec][i] = status[spec][i+1];
    }


}

void add_new_patient()
{
        string s, name;
        int curr_pos, spec, st;

        cout << "Enter specialization, name, status: " << endl;
        cin >> spec >> name >> st;
        cout << "\n" << endl;

        if (spec > 19)
        {
            cout << "Sorry, specialization cannot be greater then 19" << endl;
            cout << "\n" << endl;
            return;
        }

        curr_pos = no_of_patients[spec];
        if (curr_pos == MAX_QUEUE)
        {
            cout << "Sorry, can't take more patients in specialization " << spec << endl;
            cout << "\n" << endl;
            return;
        }

        if (st == 0)
        {
            names[spec][curr_pos] = name;
            status[spec][curr_pos] = st;
            no_of_patients[spec]++;
        }
        else if (st == 1)
        {
            shift_right(spec);
            names[spec][0] = name;
            status[spec][0] = st;
            no_of_patients[spec]++;
        }
        else
        {
            cout << "Sorry, incorrect status, choose from [0, 1]" << endl;
            cout << "\n" << endl;
        }


        return;
}

void print_patients()
{
    cout << "\n";
    for (int i=0; i<MAX_SPECIALIZATION; i++)
    {
        if (no_of_patients[i] > 0)
        {
            cout << "There are " << no_of_patients[i] << " patients in specialization " << i << endl;

            for (int j=0; j<no_of_patients[i]; j++)
            {
                string st_str = status[i][j] == 0 ? "regular" : "urgent";
                cout << names[i][j] << " " << st_str << endl;
            }
            cout << "\n" << endl;
        }
    }

    return;
}

void get_next_patient()
{
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;


    if (no_of_patients[spec] == 0)
    {
        cout << "No patients at the moment, have rest Dr. \n" << endl;
        return;
    }

    cout << names[spec][0] << " please go with the Dr. \n" << endl;
    shift_left(spec);
    no_of_patients[spec]--;
    return;
}

int main()
{

    while (true)
    {
        int choice = get_choice();

        if (choice == 1)
            add_new_patient();
        else if (choice == 2)
            print_patients();
        else if (choice == 3)
            get_next_patient();
        else
            break;
    }

    return 0;
}
