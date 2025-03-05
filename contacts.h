#ifndef CONTACTS_H
#define CONTACTS_H

#include "address.h"
#include "array.h"
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

class Contacts
{
private:
    Array<Person> contacts;

public:
    // Default Constructor
    Contacts() {}

    // Add_Contact
    void Add_Contact(const Person &p)
    {
        contacts.Append(p);
        cout << "Contact added successfully!" << "\n";
    }

    // Remove_Contact
    void Remove_Contact(int index)
    {
        if (index < 0 || index >= contacts.Get_Size())
        {
            cout << "Error: Index out of range!" << "\n";
            return;
        }
        contacts.Delete(index);
    }

    // Update_Contact
    void Update_Contact(int index, const Person &p)
    {
        if (index < 0 || index >= contacts.Get_Size())
        {
            cout << "Error: Index out of range!" << "\n";
            return;
        }
        contacts.Delete(index);
        contacts.Insert(p, index);
        cout << "Contact updated successfully!" << "\n";
    }

    void Reverse_Contacts()
    {
        contacts.Reverse();
    }

    // Display_Contacts
    void Display_Contacts()
    {
        cout << "Contacts List:" << "\n";
        for (int i = 0; i < contacts.Get_Size(); i++)
        {
            cout << "Contact #" << (i + 1) << ":" << "\n";
            contacts.Get_Element(i).Display();
            cout << "\n";
        }
    }

    // Display_Favourite_Contacts
    void Display_Fav_Contacts()
    {
        cout << "Favorite Contacts:" << "\n";
        for (int i = 0; i < contacts.Get_Size(); i++)
        {
            if (contacts.Get_Element(i).Get_Fav())
            {
                cout << "Contact #" << (i + 1) << ":" << "\n";
                contacts.Get_Element(i).Display();
                cout << "\n";
            }
        }
    }

    int Get_Contact_Count() const
    {
        return contacts.Get_Size();
    }

    Person &Get_Contact(int index)
    {
        if (index < 0 || index >= contacts.Get_Size())
        {
            throw out_of_range("Index out of range");
        }
        return contacts.Get_Element(index);
    }

    void Display_Full_Name()
    {
        cout << contacts.Get_Element(0).Get_First_Name() << " " << contacts.Get_Element(0).Get_Last_Name();
    }

    void Display_Age()
    {
        cout << contacts.Get_Element(0).Get_Age();
    }

    void Display_Relationship()
    {
        cout << contacts.Get_Element(0).Get_Relationship();
    }

    void Display_Phone_Number()
    {
        cout << contacts.Get_Element(0).Get_Phone_Number(0);
    }

    void Display_Email_Address()
    {
        cout << contacts.Get_Element(0).Get_Email_Address(0);
    }

    void Display_Favourite()
    {
        if (contacts.Get_Element(0).Get_Fav())
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }

    void Display_Full_Address()
    {
        contacts.Get_Element(0).Display();
    }

    // Search for a contact by name
    void Search_Contact_By_Name(const string &first_name, const string &last_name)
    {
        for (int i = 0; i < contacts.Get_Size(); i++)
        {
            if (contacts.Get_Element(i).Get_First_Name() == first_name && contacts.Get_Element(i).Get_Last_Name() == last_name)
            {
                cout << "Contact found:" << "\n";
                contacts.Get_Element(i).Display();
                return;
            }
        }
        cout << "Contact not found!" << "\n";
    }
};

#endif
