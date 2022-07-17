#ifndef CONTACT_H
#define CONTACT_H
#include "Address.h"
#include <string>
using namespace std;
#include <iostream>

class Contact
{
private:
string fName;
string lName;
string phoneNumber;
string email;
Address address;

public:
//constructor with all parameters
Contact(string fName1, string lName1, string phoneNumber1, string email1, Address address1);
Contact(string fName1, string lName1, string phoneNumber1, string email1);
//default constructor
Contact();

//input/output functions

friend ostream& operator<<(ostream& out, Contact& a);
friend istream& operator>>(istream& in, Contact& a);

//comparison operators
bool operator!=(Contact a);
bool operator==(Contact a);
bool operator>=(Contact a);
bool operator<=(Contact a);
bool operator<(Contact a);
bool operator>(Contact a);


//mutators
void setFirstName(string name);
void setLastName(string name);
void setPhoneNumber(string name);
void setEmail(string name);
void setAddress(Address address1);


//accessors
string getFirstName();
string getLastName();
string getPhoneNumber();
string getEmail();
Address getAddress();





};

#endif