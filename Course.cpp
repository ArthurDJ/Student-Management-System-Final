#include<iostream>
#include"Course.h"

using namespace std;

void Course::Input(int LastId)
{
    CourseId=++LastId; 
    cout << "�γ̺ţ�" << CourseId;  
	cout << "�γ�����" ; 
	cin >>CourseName;;
}

void Course::ReadFole(istream &in)
{
	in >> CourseId >> CourseName;
}

void Course::Show()
{
	cout <<"\t"<<CourseId<<"\t"<<CourseName<<endl; 
}

