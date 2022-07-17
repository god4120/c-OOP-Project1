#ifndef ContactBook_H
#define ContactBook_H

#include "Contact.h"

class ContactBook{

private:
  Contact* contactList;
  int size;
  int sizeNum;
  string ownerFName;
  string ownerLname;
  void sort();
  

public:
void addNewContact();
void deleteOldContact();
void displayContactInfo();
void updateContactInfo();
void displayAllContacts();
void grow();
int length();
int amount();
void merge(ContactBook& a);
void addNewContact(Contact* a);
string getFName();
string getLName();
Contact atIndex(int a);
void setOwnerFNAME(string a);
void setOwnerlNAME(string a);



int returnIndex(string firstname, string lastName);

//constructor
ContactBook();
ContactBook(string fname, string lname);

//copy constructor
ContactBook(const ContactBook& a);

//destructor
~ContactBook();

//= overload
ContactBook& operator = (const ContactBook& other);


  
  


};
#endif