#include<iostream>
#include"Student.h" 

using namespace std;

void Student::Input(int LastId)
{
    id=++LastId;  
    cout << "Ñ§ºÅ£º" << id;  
	cout << "ÐÕÃû£º" ; 
	cin >>name;
}

void Student::ReadFole(istream &in)
{
	in >> id >> name;
}

void Student::Show()
{
	cout <<"\t"<<id<<"\t"<<name<<endl; 
}

