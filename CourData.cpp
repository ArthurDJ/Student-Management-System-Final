#include<iostream>
#include"CourData.h"

using namespace std;

CourData::CourData(){
	Head = new Course;
	Head->Next = new Course;
	End = Head->Next;
	in.open("course.txt");
	if(!in)
	{
		LastId=0;
		cout << "����һ����ϵͳ��������γ���Ϣ" << endl;
	}
	else
	{
		while(!in.eof())
		{
			End->ReadFole(in);
			LastId=End->CourseId;
			End->Next = new Course;
			End = End->Next;
		}
		in.close(); 
	}
}

CourData::~CourData(){
	Save();
	for(Course * temp; Head->Next!=End ;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

Course *CourData::FindId(int id){
	for(Course *p = Head; p->Next != End; p=p->Next)
	    if(p->Next->CourseId==id) return p; 
			return NULL;
}


void CourData::Save()
{
	out.open("course.txt");
	for(Course *p = Head->Next; p != End; p = p->Next)
	{
		if(p != Head->Next)
		   out << "\n";
	    out << p->CourseId << "\t"
	        << p->CourseName;
	}
	out.close();
}


void CourData::Display()
{
	cout << "------------------------------" << endl;
	cout << "\t�γ̺�\t�γ���"   << endl;
	cout << "------------------------------" << endl;
	for(Course *p = Head->Next; p != End; p = p->Next)
	    p->Show();
    system("pause");
}

void CourData::AddItem()
{
	End->Input(LastId++);
	End->Next = new Course;
	End = End->Next;
	cout << "��ӳɹ���" << endl;
    system("pause");
}

void CourData::ModifyItem()
{
	int id;
	Course *p=NULL;
	cout << "����Ҫ�޸ĵĿγ̺ţ�" ;
	cin >> id;
	if(p=FindId(id))
	{
		cout << "����������Ϣ��" << endl;
		p->Next->Input(--id);
		cout << "�޸ĳɹ���" << endl;
        system("pause");	 
	}
}

void CourData::DelectItem()
{
	int id;
	Course *p=NULL,*temp=NULL;
	cout << "����Ҫɾ���Ŀγ̺ţ�" ;
	cin >> id;
	if(p=FindId(id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "ɾ���ɹ���" << endl;
	 
	}
	else
		cout << "û�ҵ���Ϣ" << endl;
    system("pause");	
}


