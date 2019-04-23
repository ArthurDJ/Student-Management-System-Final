#include"StuData.h"

StuData::StuData()
{
	Head = new Student;
	Head->Next = new Student;
	End = Head->Next;
	
	in.open("student.txt");
	if(!in)
	{
		LastId=0;
	   cout << "这是一个新系统，请新添学生信息" << endl;
	}
	else
	{
		while(!in.eof())
		{
			End->ReadFole(in);
			LastId=End->id;
			End->Next = new Student;
			End = End->Next;
		}
		in.close();
	}
}

StuData::~StuData()
{
	Save();
	for(Student * temp; Head->Next!=End ;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

Student *StuData::FindId(int id){  //查找匹配id的数据 
	for(Student *p = Head; p->Next != End; p=p->Next)
		if(p->Next->id==id) return p; 
			return NULL;
}


void StuData::Save()
{
	out.open("student.txt");
	for(Student *p = Head->Next; p != End; p = p->Next)
	{
		if(p != Head->Next)
		   out << "\n";
	    out << p->id << "\t"
	        << p->name;
	}
	out.close();
}

void StuData::Display()
{
	cout << "------------------------------" << endl;
	cout << "\t学号\t姓名"   << endl;
	cout << "------------------------------" << endl;
	for(Student *p = Head ->Next; p != End; p = p->Next)
	    p->Show();
    system("pause");
}

void StuData::AddItem()
{
	End->Input(LastId++);
	End->Next = new Student;
	End = End->Next;
	cout << "添加成功！" << endl;
    system("pause");
}

void StuData::ModifyItem()
{
	int id;
	Student *p=NULL;
	cout << "输入要修改的ID：" ;
	cin >> id;
	if(p=FindId(id))
	{
		cout << "请输入新信息：" << endl;
		p->Next->Input(--id);
		cout << "修改成功！" << endl;
        system("pause");	 
	}
}

void StuData::DelectItem()
{
	int id;
	Student *p=NULL,*temp=NULL;
	cout << "输入要删除的ID：" ;
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


