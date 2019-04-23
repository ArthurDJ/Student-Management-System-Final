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
	   cout << "����һ����ϵͳ��������ѧ����Ϣ" << endl;
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

Student *StuData::FindId(int id){  //����ƥ��id������ 
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
	cout << "\tѧ��\t����"   << endl;
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
	cout << "��ӳɹ���" << endl;
    system("pause");
}

void StuData::ModifyItem()
{
	int id;
	Student *p=NULL;
	cout << "����Ҫ�޸ĵ�ID��" ;
	cin >> id;
	if(p=FindId(id))
	{
		cout << "����������Ϣ��" << endl;
		p->Next->Input(--id);
		cout << "�޸ĳɹ���" << endl;
        system("pause");	 
	}
}

void StuData::DelectItem()
{
	int id;
	Student *p=NULL,*temp=NULL;
	cout << "����Ҫɾ����ID��" ;
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


