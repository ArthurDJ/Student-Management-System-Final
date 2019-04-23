#include<iostream>
#include"Course.h"

using namespace std;

void Course::Input(int LastId)
{
    CourseId=++LastId; 
    cout << "¿Î³ÌºÅ£º" << CourseId;  
	cout << "¿Î³ÌÃû£º" ; 
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

