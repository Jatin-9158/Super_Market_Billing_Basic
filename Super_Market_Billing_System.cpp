#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
using namespace std;
const char* blueText = "\033[1;34m";
const char* redText = "\x1B[31m";
const char* resetText = "\x1B[0m";
class Customer_Registration
{
   private:
        string Name;
        string Mobile_No;
   public:
        void set_Name(string Name)
        {
            this->Name=Name;
        }
        void set_Mobile_No(string Mobile_No)
        {
            this->Mobile_No=Mobile_No;
        }
        string get_Name()
        {
            return Name;
        }
        string get_Mobile_No()
        {
            return Mobile_No;
        }
};
class Item_List
{
   public:
       string Item_Name;
       int Item_No;
       double Item_Price;
       Item_List *next;

}*first_Item=NULL,*temp_Item=NULL,*L1;
void Item_Create()
{
   string Item_Name;
   int Item_No;
   double Item_Price;
   cout<<"\tEnter the Item Name:";
   getline(cin,Item_Name);
   getline(cin,Item_Name);
   cout<<"\tEnter the Quantity:";
   cin>>Item_No;
   cout<<"\tEnter the Item Price:";
   cin>>Item_Price;
   L1=new Item_List();
   L1->Item_Name=Item_Name;
   L1->Item_No=Item_No;
   L1->Item_Price=Item_Price;
   L1->next=NULL;
}
void Item_List_Create()
{
    if(first_Item==NULL)
    {
       Item_Create();
       first_Item=L1;
    }
    else
    {   Item_Create();
        temp_Item=first_Item;
        while(temp_Item->next!=NULL)
        {
             temp_Item=temp_Item->next;
        }
        temp_Item->next=L1;
    }
}
#include <iostream>
#include <cstdlib>
#include <windows.h>

void Bill(Customer_Registration Customer) {
    system("cls");
    string Item_Name;
    int Quantity;
    double Item_Price;
    double Amount = 0;
    bool exitRequested = false;

    cout << "\t\t\tBILL " << endl;
    cout << "\t*******************************************************" << endl;
    cout << "\tName: " << Customer.get_Name() << endl;
    cout << "\tMobile No: " << Customer.get_Mobile_No() << endl;
    cout << "\t*******************************************************" << endl;
    temp_Item = first_Item;
    cout << "\tItem Name\t" << "\tQuantity\t" << "\tPrice per Unit\t" << endl;
    while (temp_Item != NULL) {
        cout << "\t" << temp_Item->Item_Name << "\t\t\t " << temp_Item->Item_No << "\t\t\t   Rs " << temp_Item->Item_Price << endl;
        Amount = Amount + temp_Item->Item_No * temp_Item->Item_Price;
        temp_Item = temp_Item->next;
    }
    cout << "\tBill Amount: Rs " << Amount << endl;
    cout << "\n\tDo you want to exit? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        exitRequested = true;
    }
    Sleep(1000);
    if (exitRequested) {
        delete[] L1;
        exit(0);
    }
    

}

bool Mobile_No_Check(string Mobile_No)
{
   if(Mobile_No.length()==10)
   {
      return true;
   }
   return false;
}
bool Registered(string Name,string Mobile_No)
{
   ifstream infile("E:/Project/Super_Market/Customer_Details.txt",ios::app);
   if(!infile.is_open())
   {
     cout<<redText<<"Error:File Can't Open"<<endl;
   }
   else
   {
    string line;
    while(getline(infile,line))
    {
      string Name1,Mobile_No1;
      stringstream ss;
      char delimiter;
      ss<<line;
      ss>>Name1>>delimiter>>Mobile_No1;
      if(Mobile_No1 == Mobile_No && _stricmp(Name1.c_str(), Name.c_str()) == 0)
      {
         infile.close();
         return true;
      }
    }
    infile.close();
    return false;
   }

}

void Registration(Customer_Registration Customer)
{
    system("cls");
    string Name;
    string Mobile_No;
    cout<<"\tEnter the Name:";
    getline(cin,Name);
    getline(cin,Name);
    Customer.set_Name(Name);
    start:
    cout<<"\tEnter the Mobile No:";
    cin>>Mobile_No;
    if (Mobile_No_Check(Mobile_No))
    {  
        if(Registered(Name,Mobile_No))
        {
           cout<<redText<<"\tMobile Number Already Exists"<<resetText<<endl;
        }
        else
        {
           Customer.set_Mobile_No(Mobile_No);
           ofstream outfile("E:/Project/Super_Market/Customer_Details.txt", ios::out | ios::app);
           if(!outfile)
           {
             cout<<redText<<"\tError No Database Exist"<<resetText<<endl;
           }
           else
           {
             outfile<<"\t"<<Customer.get_Name()<<" : "<<Customer.get_Mobile_No()<<endl;
             cout<<blueText<<"\tUser Registered"<<resetText<<endl;
           }
           outfile.close();
        }

    }
    else
    {
        cout<<redText<<"\tRecheck the Phone Number\n"<<resetText;
        goto start;
    }
  Sleep(1000);
}
void Shopping(Customer_Registration Customer)
{ 
   bool exit=false;
   while (!exit)
   {
      system("cls");
      int val;
      cout<<"\tWelcome to Super Market Billing System"<<endl;
      cout<<"\t**************************************"<<endl;
      cout<<"\t1. Item Add"<<endl;
      cout<<"\t2. Print Bill"<<endl;
      cout<<"\t3. Exit"<<endl;
      cout<<"\tEnter Choice:";
      cin>>val;
      switch(val)
      {
         case 1:
             Item_List_Create();
             break;
         case 2:
              Bill(Customer);
             break;
         case 3:
             exit=true;
             break;
         default:
             break;
      }
   }

}
void Existing_Customer(Customer_Registration Customer)
{

   system("cls");
   string Name;
   string Mobile_No;
   cout<<"\tEnter the Name:";
   getline(cin,Name);
   getline(cin,Name);
   cout<<"\tEnter the Mobile No:";
   cin>>Mobile_No;
   if(!Registered(Name,Mobile_No))
   {
      cout<<redText<<"\tError: Register User First"<<resetText<<endl;
      Sleep(1000);
      exit(0);
   }
   else
   {
      cout<<blueText<<"\tExisting Customer"<<resetText<<endl;
      Sleep(1000);
      system("cls");
      for(int i=5;i>0;i--)
      {
        cout<<blueText<<"\t \t Please Wait for "<<redText<<i<<blueText<<" seconds"<<resetText<<endl;
        Sleep(600);
        system("cls");
      }
   }
   Customer.set_Name(Name);
   Customer.set_Mobile_No(Mobile_No);
   Shopping(Customer);
}

int main()
{
  Customer_Registration Customer;
  bool exit=false;
  while (!exit)
  {
     system("cls");
     int val;
     cout<<"\t Welcome to Super Market Billing System\n";
     cout<<"\t **************************************\n";
     cout<<"\t 1. Register a New Customer\n";
     cout<<"\t 2. Existing Customer\n";
     cout<<"\t 3. Exit\n";
     cout<<"\t Enter the Choice:";
     cin>>val;
     switch(val)
     {
       case 1:
            Registration(Customer);
            break;
       case 2:
            Existing_Customer(Customer);
            break;
       case 3:
            exit=true;
            break;
       
     }
  }
  ofstream outfile("e:/Project/Super_Market/Item_Details_Customer.txt");
  outfile.close();
  return 0;  
}