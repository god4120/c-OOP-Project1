#include "Contact.h"
#include "Address.h"

// default constructor
Contact::Contact() {
  setFirstName("DefaultFName");
  setLastName("DefaultLName");
  setPhoneNumber("1234567890");
  setEmail("default@gmail.com");
  Address defaultA;
  setAddress(defaultA);
}

// constructor with all the parameters
Contact::Contact(string fName1, string lName1, string phoneNumber1,
                 string email1, Address address1) {
  setFirstName(fName1);
  setLastName(lName1);
  setPhoneNumber(phoneNumber1);
  setEmail(email1);
  setAddress(address1);
}

Contact::Contact(string fName1, string lName1, string phoneNumber1, string email1){
  setFirstName(fName1);
  setLastName(lName1);
  setPhoneNumber(phoneNumber1);
  setEmail(email1);
}

// Mutators
void Contact::setFirstName(string name) { fName = name; }
void Contact::setLastName(string name) { lName = name; }
void Contact::setPhoneNumber(string name) {
  if (name.length() != 10) {

    phoneNumber = "Invalid Phone Number";
  } else {
    phoneNumber = name;
  }
}

void Contact::setAddress(Address address1) { address = address1; }

void Contact::setEmail(string name) {
  int caseA = name.find("@");
  int caseB = name.find(".");
  if (caseA < caseB && caseB - caseA > 1) {
    email = name;
  } else {
    email = "Invalid Email";
  }
}

// Accessors
string Contact::getFirstName() { return fName; }
string Contact::getLastName() { return lName; }
string Contact::getPhoneNumber() { return phoneNumber; }
string Contact::getEmail() { return email; }
Address Contact::getAddress() { return address; }

// input/output code
ostream &operator<<(ostream &out, Contact &a) {
  out << endl
      << "First Name:" << a.fName << endl
      << "Last Name:" << a.lName << endl
      << "Phone Number:" << a.phoneNumber << endl
      << "Email:" << a.email << endl
      << "Address:" << a.address << endl;

  return out;
}
istream &operator>>(istream &in, Contact &a) {
  cout << "Enter first name" << endl;
  string fname;
  in >> fname;
  a.setFirstName(fname);
  cout << "Enter last name" << endl;
  string lname;
  in >> lname;
  a.setLastName(lname);
  cout << "Enter phone number" << endl;
  string pnum;
  in >> pnum;
  a.setPhoneNumber(pnum);
  cout << "Enter the email" << endl;
  string em;
  in >> em;
  a.setEmail(em);
  cout << "Enter the address" << endl;
  Address ad;
  in >> ad;
  a.setAddress(ad);
  return in;
}

// comparison operators
bool Contact::operator!=(Contact a) {
  if (lName == a.lName && fName == a.fName && phoneNumber == a.phoneNumber &&
      email == a.email && address == a.address) {
    return false;
  } else {
    return true;
  }
}
bool Contact::operator==(Contact a) {
  if (lName == a.lName && fName == a.fName && phoneNumber == a.phoneNumber &&
      email == a.email && address == a.address) {
    return true;
  } else {
    return false;
  }
}

bool Contact::operator<(Contact a) {
  if (lName < a.lName) {
    return true;
  } else if (lName == a.lName) {
    if (fName < a.fName) {
      return true;
    }
  }
  return false;
}
bool Contact::operator>(Contact a) {
  if (lName > a.lName) {
    return true;
  } else if (lName == a.lName) {
    if (fName > a.fName) {
      return true;
    }
  }
  return false;
}
bool Contact::operator>=(Contact a) {
  if (lName > a.lName) {
    return true;
  } else if (lName == a.lName) {
    if (fName > a.fName) {
      return true;
    }
  } else if (lName == a.lName) {
    return true;
  }
  return false;
}
bool Contact::operator<=(Contact a) {

  if (lName < a.lName) {
    return true;
  } else if (lName == a.lName) {
    if (fName < a.fName) {
      return true;
    }
  }
  if (lName == a.lName) {
    return true;
  }
  return false;
}
