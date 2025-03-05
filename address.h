#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string Country;
    string Governorate;
    string City;
    string Street;

public:
    Address()
    {
        this->Country = "EMPTY";
        this->Governorate = "EMPTY";
        this->City = "EMPTY";
        this->Street = "EMPTY";
    }

    Address(string Country, string Governorate, string City, string Street)
    {
        this->Country = Country;
        this->Governorate = Governorate;
        this->City = City;
        this->Street = Street;
    }
    void Set_Country(string Country) { this->Country = Country; }
    void Set_Governorate(string Governorate) { this->Governorate = Governorate; }
    void Set_City(string City) { this->City = City; }
    void Set_Street(string Street) { this->Street = Street; }

    string Get_Country() const { return Country; }
    string Get_Governorate() const { return Governorate; }
    string Get_City() const { return City; }
    string Get_Street() const { return Street; }

    void Display() const
    {
        cout << "(" << Country << " , " << Governorate << " , " << City << " , " << Street << ")";
    }
};

#endif // ADDRESS_H
