#include "ContactBook.h"

//returns length of list and total size
int ContactBook::length(){
  return sizeNum;
}

int ContactBook:: amount(){
  return size;
}
//adds new contact to contactList
void ContactBook::addNewContact(){
  if(size<sizeNum){
       cin>>contactList[sizeNum];
  }
  else{
    grow();
    cin>>contactList[sizeNum];
  }
  sizeNum++;
  size=size+1;
  sort();
  }

void ContactBook::addNewContact(Contact* a){
  if(size<sizeNum){
       contactList[sizeNum]=*a;
    
  }
  else{
    grow();
    contactList[sizeNum]=*a;
  }
  sizeNum++;
  size=size+1;
  sort();
  cout<<3;
}

void ContactBook::sort(){
int index = 0;
for (int i = 0; i < sizeNum; i++){
string test = contactList[i].getLastName();
for (int j = i; j < sizeNum; j++){
if (test.compare(contactList[j].getLastName()) > 0){
test = contactList[j].getLastName();
index = j;
}
else if (test.compare(contactList[j].getLastName()) == 0){
string test2 = contactList[i].getFirstName();
if (test2.compare(contactList[j].getFirstName()) > 0){
Contact temps = contactList[i];
contactList[i] = contactList[j];
contactList[j] = temps;
}
}
}
Contact temp = contactList[i];
contactList[i] = contactList[index];
contactList[sizeNum] = temp;
}
}

void ContactBook::merge(ContactBook& a){ 
for (int i = 0; i < a.amount(); i++){

  if(size<sizeNum){
       contactList[sizeNum]=a.contactList[i];
  }
  else{
    grow();
    contactList[sizeNum]=a.contactList[i];
  }
  sizeNum++;
  size=size+1;
  sort();
}
sort();
}

//deletes a contact from contactList
void ContactBook::deleteOldContact(){
  string last;
  string first;
  cout<<"type the first and last name of who you want to delete(ei. Smith John)"<<endl;
  cin>>last;
  cin>>first;
  int index=returnIndex(first,last);
  if(index!=999){
    for(int i=index;i<size-1;i++){
      contactList[index]=contactList[index+1];
    }
    size--;
    Contact *temp=new Contact[size];
    for(int i=0;i<size-1;i++){
      temp[i]=contactList[i];
    }
    delete[] contactList;
    contactList=temp;
  
  sizeNum--;
    }
  
  else{
    cout<<last<<" "<<first<<" was not in the contact book"<<endl;
  }
  sort();
}

//displays a singular searched contact 
void ContactBook::displayContactInfo(){
  string last;
  string first;
  cout<<"type the first and last name of who you want to display(ei. Smith John)"<<endl;
  cin>>last;
  cin>>first;
  int index=returnIndex(first,last);
  if(index!=999){
    cout<<contactList[index];
  }
  else{
    cout<<last<<" "<<first<<" was not in the contact book"<<endl;
  }
  
}

//updates the info for a contact 
void ContactBook::updateContactInfo(){
  string last;
  string first;
  cout<<endl<<"Type the last and first name of who you want to display(ei. Smith John)"<<endl;
  cin>>last;
  cin>>first;
  cout<<endl<<"Type the number corrosponding to the field you want to change"<<endl<<"0) All of them"<<endl<<"1) First Name"<<endl<<"2) Last Name"<<endl<<"3) Phone Number"<<endl<<"4) Email"<<endl<<"5) Address"<<endl;
  int choice;
  cin>>choice;
  int index=returnIndex(first,last);
  if(index!=999){
      string fn;
      string ln;
      Address ad;
      string em;
      string pn;
    switch(choice){
      case 0:
        cin>>contactList[index];
      break;
      case 1:
        cout<<endl<<"Enter new first name"<<endl;
      
        cin>>fn;
        contactList[index].setFirstName(fn);
        break;
      case 2:
        cout<<endl<<"Enter new last name"<<endl;
        
        cin>>ln;
        contactList[index].setLastName(fn);
        
      break;
      case 3:
        cout<<endl<<"Enter new phone number"<<endl;
        
        cin>>pn;
        contactList[index].setPhoneNumber(pn);
        
      break;
      case 4:
        cout<<endl<<"Enter new email"<<endl;
        
        cin>>em;
        contactList[index].setEmail(em);
      break;
      case 5:
        cout<<endl<<"Enter new address"<<endl;
        
        cin>>ad;
        contactList[index].setAddress(ad);
      break;

      
    }
    
  }
  else{
    cout<<last<<" "<<first<<" was not in the contact book"<<endl;
  }
  
  
}

//displays all of the contacts 
void ContactBook::displayAllContacts(){
  for(int i=0;i<sizeNum;i++){
    cout<<endl<<"Contact "<<i<<endl<<"--------------";
    cout<<contactList[i];
    cout<<endl;
  }
  }

//constructor for ContactBook
ContactBook::ContactBook(){
 size=10;
  sizeNum=0;
  contactList=new Contact[size];
  Contact a;
 for(int i=0;i<size;i++){   
   contactList[i]=a;
 }
}

ContactBook::ContactBook(string fname, string lname){
  ownerFName=fname;
  ownerLname=lname;
  size=10;
  sizeNum=0;
  contactList=new Contact[size];
  Contact a;
 for(int i=0;i<size;i++){   
   contactList[i]=a;
 }
}

//returns 999 if name is not in contactList
int ContactBook::returnIndex(string firstname,string lastname){
  int index=999;
  for(int i=0;i<sizeNum;i++){
    if(contactList[i].getFirstName()==firstname && contactList[i].getLastName()==lastname ){
      index=i;
    }
  }
  return index;
}

void ContactBook::grow(){
  Contact *temp=new Contact[size+1];
    for(int i=0;i<size;i++){
      temp[i]=contactList[i];
    }
    delete[] contactList;
    contactList=temp;
    cin>>contactList[sizeNum];
  
}

ContactBook::ContactBook(const ContactBook& a){
  size=a.size;
  for(int i=0;i<size;i++){
    contactList[i]=a.contactList[i];
  }
}

ContactBook::~ContactBook()
{
    if (contactList != NULL)
    {
        delete [] contactList;
        contactList = NULL;
    }
}

ContactBook& ContactBook::operator = (const ContactBook& other)
{
    
if (this != &other){


if (contactList != NULL){

delete[] contactList;
}

//here is where the data is actually copied into the new array (hence, it looks like the copy constructor's code):
sizeNum = other.sizeNum;
size = other.size;
contactList = new Contact[size];

for (int i = 0; i < sizeNum; i++){
contactList[i] = (other.contactList[i]);
}

}//closes if (this != &other)
return *this;
}
string ContactBook::getFName(){
  return ownerFName;
}
string ContactBook::getLName(){
  return ownerLname;
}
Contact ContactBook::atIndex(int a){
  return contactList[a];
}
void ContactBook::setOwnerFNAME(string a){
  ownerFName=a;
}
void ContactBook::setOwnerlNAME(string a){
  ownerLname=a;
}
  

