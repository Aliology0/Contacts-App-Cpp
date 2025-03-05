#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include "array.h"
#include "person.h"
#include "contacts.h"
#include "address.h"

using namespace std;

void Display_Menu()
{
    cout << "\n"
         << "\t\t\t==================================" << "\n";
    cout << "\t\t\tContact Books Menu:" << "\n";
    cout << "\t\t\t--------------------------" << "\n";
    cout << "\t\t\t1. Add a new contact." << "\n";
    cout << "\t\t\t2. Search by Last Name." << "\n";
    cout << "\t\t\t3. Search by Relationship." << "\n";
    cout << "\t\t\t4. Print all contacts." << "\n";
    cout << "\t\t\t5. Print Favourite contacts." << "\n";
    cout << "\t\t\t6. Save to File." << "\n";
    cout << "\t\t\t7. Load from file." << "\n";
    cout << "\t\t\t8. Delete contact." << "\n";
    cout << "\t\t\t9. Update contact information." << "\n";
    cout << "\t\t\t10. Share contact." << "\n";
    cout << "\t\t\t11. Reverse contact book." << "\n";
    cout << "\t\t\t12. Exit." << "\n";
    cout << "\t\t\t==================================" << "\n";
    cout << "Enter Your Choice: ";
}

void Display_Table_Header()
{
    cout << "\n";
    cout << left << setw(5) << setfill(' ') << "ID"
         << left << setw(20) << setfill(' ') << "Full Name"
         << left << setw(5) << setfill(' ') << "Age"
         << left << setw(20) << setfill(' ') << "Relationship"
         << left << setw(5) << setfill(' ') << "Fav"
         << left << setw(20) << setfill(' ') << "Phone Number"
         << left << setw(20) << setfill(' ') << "Email Address"
         << left << " Address";
    cout << "\n"
         << "---------------------------------------------------------------------------------------------------------------------------" << "\n";
}

void Display_Contacts(Contacts &C, int i)
{
    cout << left << setw(5) << setfill(' ') << i + 1;
    cout << left << setw(20) << setfill(' ') << C.Get_Contact(i).Get_First_Name() + " " + C.Get_Contact(i).Get_Last_Name();
    cout << left << setw(5) << setfill(' ') << C.Get_Contact(i).Get_Age();
    cout << left << setw(20) << setfill(' ') << C.Get_Contact(i).Get_Relationship();
    cout << left << setw(5) << setfill(' ') << (C.Get_Contact(i).Get_Fav() ? "Yes" : "No");
    cout << left << setw(20) << setfill(' ') << C.Get_Contact(i).Get_Phone_Number(0);
    cout << left << setw(20) << setfill(' ') << C.Get_Contact(i).Get_Email_Address(0);
    cout << left;
    C.Get_Contact(i).Display();
    cout << "\n";
}

void Add_Contact(Contacts &C)
{
    int numbers, emails, age;
    string fname, lname, relationship, street, city, governorate, country, string_fav;
    bool fav;

    cout << "Enter First Name: ";
    cin.ignore();
    getline(cin, fname);
    cout << "Enter Last Name: ";
    getline(cin, lname);
    cout << "Enter Relationship Name: ";
    getline(cin, relationship);
    cout << "Enter Age: ";
    cin >> age;

    cout << "Favourite? (Yes/No): ";
    cin >> string_fav;
    fav = (string_fav == "Yes" || string_fav == "yes");

    cout << "How many phone numbers: ";
    cin >> numbers;
    cin.ignore();
    string *phones = new string[numbers];
    for (int p = 0; p < numbers; p++)
    {
        cout << "Enter Phone Number #" << p + 1 << ": ";
        getline(cin, phones[p]);
    }

    cout << "How many Email Addresses: ";
    cin >> emails;
    cin.ignore();
    string *email_addresses = new string[emails];
    for (int e = 0; e < emails; e++)
    {
        cout << "Enter Email Address #" << e + 1 << ": ";
        getline(cin, email_addresses[e]);
    }

    cout << "Enter Country: ";
    getline(cin, country);
    cout << "Enter Governorate: ";
    getline(cin, governorate);
    cout << "Enter City: ";
    getline(cin, city);
    cout << "Enter Street: ";
    getline(cin, street);

    Address A(country, governorate, city, street);
    Person P(fname, lname, numbers, emails, phones, email_addresses, relationship, age, fav, A);
    C.Add_Contact(P);

    delete[] phones;
    delete[] email_addresses;
}

void Search_By_Last_Name(Contacts &C)
{
    string last_name;
    cout << "Enter last name to search: ";
    getline(cin, last_name);

    Display_Table_Header();
    bool found = false;
    for (int i = 0; i < C.Get_Contact_Count(); i++)
    {
        if (C.Get_Contact(i).Get_Last_Name() == last_name)
        {
            Display_Contacts(C, i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No contacts found with last name: " << last_name << "\n";
    }
}

void Search_By_Relationship(Contacts &C)
{
    string relationship;
    cout << "Enter relationship to search: ";
    getline(cin, relationship);

    Display_Table_Header();
    bool found = false;
    for (int i = 0; i < C.Get_Contact_Count(); i++)
    {
        if (C.Get_Contact(i).Get_Relationship() == relationship)
        {
            Display_Contacts(C, i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No contacts found with relationship: " << relationship << "\n";
    }
}

void Print_Favourite_Contacts(Contacts &C)
{
    Display_Table_Header();
    bool found = false;
    for (int i = 0; i < C.Get_Contact_Count(); i++)
    {
        if (C.Get_Contact(i).Get_Fav())
        {
            Display_Contacts(C, i);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No favorite contacts found." << "\n";
    }
}

void Delete_Contact(int index, Contacts &C)
{
    if (index < 0 || index >= C.Get_Contact_Count())
    {
        cout << "Index out of range!" << "\n";
        return;
    }

    C.Remove_Contact(index);
    cout << "Contact deleted successfully!" << "\n";
}

void Update_Contact(int index, Contacts &C)
{
    if (index < 0 || index >= C.Get_Contact_Count())
    {
        cout << "Index out of range!" << "\n";
        return;
    }

    cout << "Updating contact by replacing existing contact at index " << index + 1 << "\n";
    cout << "This will delete the current contact and allow you to enter a new one." << "\n";
    cout << "Are you sure you want to continue? (Yes/No): ";
    string confirmation;
    cin >> confirmation;

    if (confirmation != "Yes" && confirmation != "yes")
    {
        cout << "Update canceled." << "\n";
        return;
    }

    C.Remove_Contact(index);
    cout << "Old contact deleted." << "\n";

    cout << "Please enter the details for the new contact:" << "\n";
    Add_Contact(C);

    cout << "Contact updated successfully!" << "\n";
}

void Share_Contact(Contacts &C)
{
    int index;
    cout << "Enter the index of the contact you want to share: ";
    cin >> index;

    if (index < 0 || index >= C.Get_Contact_Count())
    {
        cout << "Index out of range!" << "\n";
        return;
    }

    cout << "Contact at index " << index << " shared successfully!" << "\n";
}

void Save_To_File(Contacts &C)
{
    ofstream out("Contacts.txt");
    if (!out)
    {
        cout << "Error opening file for writing!" << "\n";
        return;
    }

    for (int i = 0; i < C.Get_Contact_Count(); i++)
    {
        Person person = C.Get_Contact(i);
        Address addr = person.Get_Address();

        out << person.Get_First_Name() << " "
            << person.Get_Last_Name() << " "
            << person.Get_Age() << " "
            << person.Get_Relationship() << " "
            << (person.Get_Fav() ? "Yes" : "No") << " "
            << person.Get_Phone_Number(0) << " "
            << person.Get_Email_Address(0) << " "
            << addr.Get_Country() << " "
            << addr.Get_Governorate() << " "
            << addr.Get_City() << " "
            << addr.Get_Street() << "\n";
    }

    out.close();
    cout << "Contacts saved to file successfully!" << "\n";
}

void Load_From_File(Contacts &C)
{
    ifstream in("Contacts.txt");
    if (!in)
    {
        cout << "Error opening file for reading!" << "\n";
        return;
    }

    string fname, lname, relationship, fav_string, phone, email, country, governorate, city, street;
    int age;
    bool fav;

    while (in >> fname >> lname >> age >> relationship >> fav_string >> phone >> email >> country >> governorate >> city >> street)
    {
        fav = (fav_string == "Yes");

        string *phones = new string[1];
        phones[0] = phone;

        string *emails = new string[1];
        emails[0] = email;

        Address A(country, governorate, city, street);
        Person P(fname, lname, 1, 1, phones, emails, relationship, age, fav, A);

        C.Add_Contact(P);

        delete[] phones;
        delete[] emails;
    }

    in.close();
    cout << "Contacts loaded from file successfully!" << "\n";
}

int main()
{
    Contacts C;
    int Choice;
    bool Main_Menu = true;
    cout << "\t\t\t---- Contacts Information ----" << "\n"
         << "\t\t==============================================" << "\n";

    while (Main_Menu)
    {
        Display_Menu();
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            Add_Contact(C);
            break;
        case 2:
            Search_By_Last_Name(C);
            break;
        case 3:
            Search_By_Relationship(C);
            break;
        case 4:
            Display_Table_Header();
            for (int i = 0; i < C.Get_Contact_Count(); i++)
            {
                Display_Contacts(C, i);
            }
            break;
        case 5:
            Print_Favourite_Contacts(C);
            break;
        case 6:
            Save_To_File(C);
            break;
        case 7:
            Load_From_File(C);
            break;
        case 8:
            int delete_index;
            cout << "Enter index of contact to delete: ";
            cin >> delete_index;
            Delete_Contact(delete_index - 1, C);
            break;
        case 9:
            int update_index;
            cout << "Enter index of contact to update: ";
            cin >> update_index;
            Update_Contact(update_index - 1, C);
            break;
        case 10:
            Share_Contact(C);
            break;
        case 11:
            C.Reverse_Contacts();
            cout << "Contact List has been reversed successfully!" << "\n";
            break;
        case 12:
            Main_Menu = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << "\n";
            break;
        }
    }

    cout << "\n"
         << "\t\t\tThanks For Using The Application !" << "\n\n";
    cout << "Project By: Ali Emad" << "\n";

    return 0;
}
