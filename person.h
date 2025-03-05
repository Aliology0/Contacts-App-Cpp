#ifndef PERSON_H
#define PERSON_H

#include "address.h"
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string First_Name;
    string Last_Name;
    int Phone_Nums;
    string *Phone_Number;
    int Email_Nums;
    string *Email_Address;
    string Relationship;
    int age;
    bool is_fav;
    Address address;

public:
    // Default Constructor
    Person() : First_Name("EMPTY"), Last_Name("EMPTY"), Phone_Nums(1), Email_Nums(1),
               Relationship("EMPTY"), age(0), is_fav(false), address(Address())
    {
        Phone_Number = new string[1]{"EMPTY"};
        Email_Address = new string[1]{"EMPTY"};
    }

    // Parameterized Constructor
    Person(string First_Name, string Last_Name, int Phone_Nums, int Email_Nums,
           string *Phone_Number, string *Email_Address, string Relationship,
           int age, bool is_fav, Address addr)
        : First_Name(First_Name), Last_Name(Last_Name), Phone_Nums(Phone_Nums),
          Email_Nums(Email_Nums), Relationship(Relationship), age(age),
          is_fav(is_fav), address(addr)
    {
        this->Phone_Number = new string[Phone_Nums];
        for (int i = 0; i < Phone_Nums; i++)
        {
            this->Phone_Number[i] = Phone_Number[i];
        }

        this->Email_Address = new string[Email_Nums];
        for (int i = 0; i < Email_Nums; i++)
        {
            this->Email_Address[i] = Email_Address[i];
        }
    }

    // Copy Constructor
    Person(const Person &copy)
        : First_Name(copy.First_Name), Last_Name(copy.Last_Name),
          Phone_Nums(copy.Phone_Nums), Email_Nums(copy.Email_Nums),
          Relationship(copy.Relationship), age(copy.age),
          is_fav(copy.is_fav), address(copy.address)
    {
        Phone_Number = new string[Phone_Nums];
        for (int i = 0; i < Phone_Nums; i++)
        {
            Phone_Number[i] = copy.Phone_Number[i];
        }

        Email_Address = new string[Email_Nums];
        for (int i = 0; i < Email_Nums; i++)
        {
            Email_Address[i] = copy.Email_Address[i];
        }
    }

    // Copy Assignment Operator
    Person &operator=(const Person &copy)
    {
        if (this == &copy)
            return *this;

        delete[] Phone_Number;
        delete[] Email_Address;

        First_Name = copy.First_Name;
        Last_Name = copy.Last_Name;
        Phone_Nums = copy.Phone_Nums;
        Email_Nums = copy.Email_Nums;
        Relationship = copy.Relationship;
        age = copy.age;
        is_fav = copy.is_fav;
        address = copy.address;

        Phone_Number = new string[Phone_Nums];
        for (int i = 0; i < Phone_Nums; i++)
        {
            Phone_Number[i] = copy.Phone_Number[i];
        }

        Email_Address = new string[Email_Nums];
        for (int i = 0; i < Email_Nums; i++)
        {
            Email_Address[i] = copy.Email_Address[i];
        }

        return *this;
    }

    // Move Constructor
    Person(Person &&move) noexcept
        : First_Name(move.First_Name), Last_Name(move.Last_Name),
          Phone_Nums(move.Phone_Nums), Email_Nums(move.Email_Nums),
          Relationship(move.Relationship), age(move.age),
          is_fav(move.is_fav), address(std::move(move.address)),
          Phone_Number(move.Phone_Number), Email_Address(move.Email_Address)
    {
        move.Phone_Number = nullptr;
        move.Email_Address = nullptr;
        move.Phone_Nums = 0;
        move.Email_Nums = 0;
    }

    // Move Assignment Operator
    Person &operator=(Person &&move) noexcept
    {
        if (this == &move)
            return *this;

        delete[] Phone_Number;
        delete[] Email_Address;

        First_Name = move.First_Name;
        Last_Name = move.Last_Name;
        Phone_Nums = move.Phone_Nums;
        Email_Nums = move.Email_Nums;
        Relationship = move.Relationship;
        age = move.age;
        is_fav = move.is_fav;
        address = std::move(move.address);

        Phone_Number = move.Phone_Number;
        Email_Address = move.Email_Address;

        move.Phone_Number = nullptr;
        move.Email_Address = nullptr;
        move.Phone_Nums = 0;
        move.Email_Nums = 0;

        return *this;
    }

    // Destructor
    ~Person()
    {
        delete[] Phone_Number;
        delete[] Email_Address;
    }

    // Setter Methods
    void Set_First_Name(string First_Name) { this->First_Name = First_Name; }
    void Set_Last_Name(string Last_Name) { this->Last_Name = Last_Name; }
    void Set_Age(int age) { this->age = age; }
    void Set_Relationship(string Relationship) { this->Relationship = Relationship; }
    void Set_Fav(bool is_fav) { this->is_fav = is_fav; }

    void Set_Phone(int index, string Number)
    {
        if (index >= 0 && index < Phone_Nums)
        {
            Phone_Number[index] = Number;
        }
    }

    void Set_Email(int index, string Email)
    {
        if (index >= 0 && index < Email_Nums)
        {
            Email_Address[index] = Email;
        }
    }

    // Getter Methods
    string Get_First_Name() const { return First_Name; }
    string Get_Last_Name() const { return Last_Name; }
    int Get_Age() const { return age; }
    string Get_Relationship() const { return Relationship; }
    bool Get_Fav() const { return is_fav; }
    int Get_Phone_Count() const { return Phone_Nums; }
    int Get_Email_Count() const { return Email_Nums; }

    // Address Getters
    string Get_Country() const { return address.Get_Country(); }
    string Get_Governorate() const { return address.Get_Governorate(); }
    string Get_City() const { return address.Get_City(); }
    string Get_Street() const { return address.Get_Street(); }
    Address Get_Address() const { return address; }

    string Get_Phone_Number(int index) const
    {
        return (index >= 0 && index < Phone_Nums) ? Phone_Number[index] : "NULL";
    }

    string Get_Email_Address(int index) const
    {
        return (index >= 0 && index < Email_Nums) ? Email_Address[index] : "NULL";
    }

        void Display() const
    {
        address.Display();
    }
};

#endif
