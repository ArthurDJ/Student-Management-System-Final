#include<iostream>
#include"Student.h" 

using namespace std;

void Student::Input(int LastId)
{
    id=++LastId;  
    cout << "ѧ�ţ�" << id;  
	cout << "������" ; 
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

