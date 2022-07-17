//functions are there but my addNewContacts puts the program in a loop because my = overload got messed up would like a resubmission if possible

#include "ContactBook.h"
#include <fstream>

void mainMenu(){
  
cout<<endl<<"Menu"<<endl<<
"--------------"<<endl<<
"1) Add New Contact"<<endl<<
"2) Delete Old Contact"<<endl<<
"3) Display Contact Info"<<endl<<
"4) Update Contact Info "<<endl<<
"5) Display Entire Contact List"<<endl<<
"6) Exit"<<endl;
}

void firstMenu(){
  cout<<endl<<"Menu"<<endl<<
"--------------"<<endl<<
"1) Create a new Contact Book"<<endl<<
"2) Remove a Contact Book"<<endl<<
"3) Display All Contact Books"<<endl<<
"4) Merge 2 Contact Books together "<<endl<<
"5) Select a Contact Book to modify"<<endl<<
"6) Exit"<<endl;
}

void load(ifstream& in, ContactBook*& abook, int& count){ 
  
string input;
if (!in.eof()){
  
getline(in, input);
   
string input1 = input.substr(0, input.find("|"));
string input2 = input.substr(input.find("|")+1);
abook = new ContactBook(input1, input2);

 
while (input.compare("endofbook|") != 0){
getline(in, input);
if (in.eof()) break;
string inputmod = input; 
string data[10];
for (int i = 0; i < 9; i++){
data[i] = inputmod.substr(0, inputmod.find_first_of("|"));
inputmod = inputmod.substr(inputmod.find_first_of("|") + 1);
}
data[9] = inputmod;

Contact* x = new Contact(data[0], data[1], data[2], data[3]);
Address y(data[4], data[5], data[6], data[7], data[8], data[9]);
x->setAddress(y);
  
abook->addNewContact(x);
  
}
  
//when "endofbook|" is reached, read up to the next line and return
getline(in, input);
count++;
}
  
}

void contactsTotxt(ContactBook** books, int numbooks){
  ofstream out;
out.open("contactbooks.txt");
for (int i = 0; i < numbooks; i++){
out << books[i]->getFName() << "|" << books[i]->getLName() << endl;
for (int j = 0; j < books[i]->amount(); j++){
out << books[i]->atIndex(j).getFirstName() << "|" << books[i]->atIndex(j).getLastName() << "|"
<< books[i]->atIndex(j).getPhoneNumber() << "|" << books[i]->atIndex(j).getEmail()
<< "|" << books[i]->atIndex(j).getAddress().getHome() << "|" << books[i]->atIndex(j).getAddress().getStreet()
<< "|" << books[i]->atIndex(j).getAddress().getApt() << "|" << books[i]->atIndex(j).getAddress().getCity()
<< "|" << books[i]->atIndex(j).getAddress().getState() << "|" << books[i]->atIndex(j).getAddress().getZip() << endl;
}
out << "endofbook|" << endl << endl;
}
}

int main(){ 
  int numbooks = 0;
ContactBook** books = new ContactBook*[5];
ifstream in;
in.open("contactbooks.txt");
string input; //stores the text input from the ContactBooks.txt file.
cout << "Loading txt file"<<endl<<endl;
if (in.is_open()){
  
while (!in.eof()){
load(in, books[numbooks], numbooks);
}
  
}
in.close();
  
  
  
  
while(true){
firstMenu();
int choice=0;
cout<<"Type in an option and press enter: ";
cin>>choice;
switch(choice){
  case 1:
    if (numbooks == 5){
      cout << "max number of contactBooks already entered"<<endl;}
    else{
      string lname;
      string fname;
      books[numbooks] = new ContactBook();
      cout<<"What is the owners first name?"<<endl;\
      cin>>lname;
      cout<<"What is the owners last name?"<<endl;
      cin>>fname;
    books[numbooks]->setOwnerFNAME(fname);
    books[numbooks]->setOwnerlNAME(lname);
    numbooks++;
    }
  break;
  
  case 2:
    {
    string name = "filler";
cout << "Enter the first or last name of the contactbook to be removed";
getline(cin, name);
int index = -1;
for (int i = 0; i < numbooks; i++){
string fullName = books[i]->getFName() + ' ' + books[i]->getLName();

if (name.compare(books[i]->getFName()) == 0) index = i;
else if (name.compare(books[i]->getLName()) == 0) index = i;
else if (name.compare(fullName) == 0) index = i;
}

if (index == -1) {
cout << endl<<"Person does not exist"<<endl;
}
else {
delete[] books[index];
delete books[index];
numbooks--;
}}
  break;
  
  case 3:
    if (numbooks == 0){
    cout << "The list is empty"<<endl;
}
    else{
      for (int i = 0; i < numbooks; i++){
books[i]->displayAllContacts();
}
cout << endl << endl;
    }


  break;
  case 4:
  break;
  case 5:{
    string Name;
    cout<<endl<<"Enter the first or last name of owner for the contact book in the format:"    
    <<endl<< "lastName firstName"<<endl;
    getline(cin, Name);
int index = -1;
for (int i = 0; i < numbooks; i++){
string fullName = books[i]->getFName() + ' ' + books[i]->getLName();

if (Name.compare(books[i]->getFName()) == 0) index = i;
else if (Name.compare(books[i]->getLName()) == 0) index = i;
else if (Name.compare(fullName) == 0) index = i;
}

if (index == -1) {
cout << endl<<"Person does not exist"<<endl;
}
    else{
      
        
      }
    
    
     mainMenu();
    int input;
    cout<<"Type in an option and press enter: ";
    cin>>input;
    
switch(input){
  case 1:
    books[index]->addNewContact();
  break;
  case 2 :
    books[index]->deleteOldContact();
  break;
  case 3:
    books[index]->displayContactInfo();
  break;
  case 4:
    books[index]->updateContactInfo();
  break;
  case 5:
   books[index]->displayAllContacts();
  break;
  case 6:
    exit(0);
  break;
  }
    break;
}
  case 6:
    contactsTotxt(books, numbooks);
    exit(0);
  break;
}
}
}
