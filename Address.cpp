#include "Address.h"
#include <string>
#include <iostream>

using namespace std;

Address::Address() : home(""),
street(""),
apt("none"),
city(""),
state(""),
zip("")
{
	// empty
}

Address::Address(string a, string b, string c, string d, string e, string f){
  home=a;
  street=b;
  apt=c;
  city=d;
  state=e;
  zip=f;
}

string Address::getHome() const
{
	return home;
}

string Address::getStreet() const
{
	return street;
}

string Address::getApt() const
{
	return apt;
}

string Address::getCity() const
{
	return city;
}

string Address::getState() const
{
	return state;
}

string Address::getZip() const
{
	return zip;
}

void Address::output() const
{
	cout << home << " " << street;
	if (apt != "none")
		cout << ", Apt# " << apt;
	cout << endl;
	cout << city << ", " << state << " " << zip << endl;
}

ostream& operator<<(ostream& out, Address& a){
  out << a.home << " " << a.street;
	if (a.apt != "none")
		out << ", Apt# " << a.apt;
	out << endl;
	out << a.city << ", " << a.state << " " << a.zip << endl;
  return out;
}

istream& operator>>(istream& in, Address& a){
  char choice;
	cout << "Apartment or House (a/h):> ";
	in >> choice;
	cout << endl;

	in.ignore(10, '\n');
	cout << "Enter home number (EX: 141-92)___: ";
	getline(in, a.home);
	cout << "Enter street number (EX: 70th RD): ";
	getline(in, a.street);

	if (choice == 'a')
	{
		cout << "Enter Apartment Number: (EX: 1A)_: ";
		getline(in, a.apt);
	}
	else
		a.apt = "none";

	cout << "Enter city (Ex: Flushing)________: ";
	getline(in, a.city);

	cout << "Enter state (EX: NY)_____________: ";
	getline(in, a.state);

	cout << "Enter zip code (EX: 11367)_______: ";
	getline(in, a.zip);
  return in;
}

void Address::input()
{
	char choice;
	cout << "Apartment or House (a/h):> ";
	cin >> choice;
	cout << endl;

	cin.ignore(10, '\n');
	cout << "Enter home number (EX: 141-92)___: ";
	getline(cin, home);
	cout << "Enter street number (EX: 70th RD): ";
	getline(cin, street);

	if (choice == 'a')
	{
		cout << "Enter Apartment Number: (EX: 1A)_: ";
		getline(cin, apt);
	}
	else
		apt = "none";

	cout << "Enter city (Ex: Flushing)________: ";
	getline(cin, city);

	cout << "Enter state (EX: NY)_____________: ";
	getline(cin, state);

	cout << "Enter zip code (EX: 11367)_______: ";
	getline(cin, zip);
}

bool Address:: operator!=(Address a){
  if(street==a.street&&
    apt==a.apt&&
    city==a.city&&
    state==a.state&&
    zip==a.zip){
    return false;
    }
  else{
    return true;
  }
}

bool Address:: operator==(Address a){
        if(street==a.street&&
    apt==a.apt&&
    city==a.city&&
    state==a.state&&
    zip==a.zip){
    return true;
    }
  else{
    return false;
  }
      }

 