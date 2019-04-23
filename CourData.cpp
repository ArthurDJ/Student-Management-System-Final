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
		cout << "这是一个新系统，请新添课程信息" << endl;
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
	cout << "\t课程号\t课程名"   << endl;
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
	cout << "添加成功！" << endl;
    system("pause");
}

void CourData::ModifyItem()
{
	int id;
	Course *p=NULL;
	cout << "输入要修改的课程号：" ;
	cin >> id;
	if(p=FindId(id))
	{
		cout << "请输入新信息：" << endl;
		p->Next->Input(--id);
		cout << "修改成功！" << endl;
        system("pause");	 
	}
}

void CourData::DelectItem()
{
	int id;
	Course *p=NULL,*temp=NULL;
	cout << "输入要删除的课程号：" ;
	cin >> id;
	if(p=FindId(id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "删除成功！" << endl;
	 
	}
	else
		cout << "没找到信息" << endl;
    system("pause");	
}


