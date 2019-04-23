#include<iostream>
#include"ScoreData.h"

using namespace std;

ScoreData::ScoreData()
{
	Head = new Score;
	Head->Next = new Score;
	End = Head->Next;
	in.open("score.txt");
	if(!in)
	   cout << "����һ����ϵͳ��������ѧ����Ϣ" << endl;
	else
	{
		while(!in.eof())
		{
			End->ReadFole(in);
			End->Next = new Score;
			End = End->Next;
		}
		in.close();
	}
}

ScoreData::~ScoreData()
{
	Save();
	for(Score * temp; Head->Next!=End ;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}

Score *ScoreData::FindStuId(int sid,Score *Head){  //����ƥ��ѧ��id������ 
	for(Score *p = Head; p->Next != End; p=p->Next)
	 	if(p->Next->stuid==sid) return p; 
			return NULL;
}

Score *ScoreData::FindCourId(int sid,int cid){  //����ƥ��ѧ��id������ 
	for(Score *p = Head; p->Next != End; p=p->Next)
	 	if(p->Next->courid==cid && p->Next->stuid==sid) return p; 
			return NULL;
}

void ScoreData::Save()
{
	out.open("score.txt");
	for(Score *p = Head->Next; p != End; p = p->Next)
	{
		if(p != Head->Next)
		   out << "\n";
	    out << p->stuid << "\t"
	        << p->courid << "\t"
	        << p->score;
	}
	out.close();
}

void ScoreData::AddCour()
{
	End->Input(false);
	End->Next = new Score;
	End = End->Next;
	cout << "��ӳɹ���" << endl;
   	system("pause");
}

void ScoreData::DelectCour()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "����ѧ��ID��" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "-------------------------------------" << endl;
	cout << "\tѧ��\t����\t�γ̺�\t�γ���"   << endl;
	cout << "-------------------------------------" << endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "����Ҫɾ���Ŀγ̺ţ�"; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
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

void ScoreData::Display()
{
	cout << "----------------------------------------------" << endl;
	cout << "\tѧ��\t����\t�γ̺�\t�γ���\t����"   << endl;
	cout << "----------------------------------------------" << endl;
	for(Score *p = Head->Next; p != End; p = p->Next)
	    p->Show();
    system("pause");
} 

void ScoreData::AddSco()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "����ѧ��ID��" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "---------------------------------------------" <<endl;
	cout << "\tѧ��\t����\t�γ̺�\t�γ���\t�ɼ�" << endl;
	cout << "---------------------------------------------" <<endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "����Ҫ��ӳɼ��Ŀγ̺ţ�"; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
	{
		p->Next->Input(true);
		cout << "��ӳɹ�" << endl;
	}
	else
	   cout << "�������" << endl;
	system("pause"); 
}
		


void ScoreData::ModifySco()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "����ѧ��ID��" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "---------------------------------------------" <<endl;
	cout << "\tѧ��\t����\t�γ̺�\t�γ���\t�ɼ�" << endl;
	cout << "---------------------------------------------" <<endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "����Ҫ�޸ĳɼ��Ŀγ̺ţ�"; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
	{
		p->Next->Input(true);
		cout << "�޸ĳɹ�" << endl;
	}
	else
	   cout << "�������" << endl;
	system("pause"); 
} 


