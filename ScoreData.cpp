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
	   cout << "这是一个新系统，请新添学生信息" << endl;
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

Score *ScoreData::FindStuId(int sid,Score *Head){  //查找匹配学生id的数据 
	for(Score *p = Head; p->Next != End; p=p->Next)
	 	if(p->Next->stuid==sid) return p; 
			return NULL;
}

Score *ScoreData::FindCourId(int sid,int cid){  //查找匹配学生id的数据 
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
	cout << "添加成功！" << endl;
   	system("pause");
}

void ScoreData::DelectCour()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "输入学生ID：" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "-------------------------------------" << endl;
	cout << "\t学号\t姓名\t课程号\t课程名"   << endl;
	cout << "-------------------------------------" << endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "输入要删除的课程号："; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
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

void ScoreData::Display()
{
	cout << "----------------------------------------------" << endl;
	cout << "\t学号\t姓名\t课程号\t课程名\t分数"   << endl;
	cout << "----------------------------------------------" << endl;
	for(Score *p = Head->Next; p != End; p = p->Next)
	    p->Show();
    system("pause");
} 

void ScoreData::AddSco()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "输入学生ID：" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "---------------------------------------------" <<endl;
	cout << "\t学号\t姓名\t课程号\t课程名\t成绩" << endl;
	cout << "---------------------------------------------" <<endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "输入要添加成绩的课程号："; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
	{
		p->Next->Input(true);
		cout << "添加成功" << endl;
	}
	else
	   cout << "输入错误" << endl;
	system("pause"); 
}
		


void ScoreData::ModifySco()
{
	int sid,cid;
	Score *p=NULL,*temp=NULL;
	cout << "输入学生ID：" ;
	cin >> sid;
	p=FindStuId(sid,Head);
	cout << "---------------------------------------------" <<endl;
	cout << "\t学号\t姓名\t课程号\t课程名\t成绩" << endl;
	cout << "---------------------------------------------" <<endl;
	while(p)
	{
		p->Next->Show();
		p=FindStuId(sid,p->Next);
	}
	cout << "输入要修改成绩的课程号："; 
	cin >> cid;
	if(p=FindCourId(sid,cid))
	{
		p->Next->Input(true);
		cout << "修改成功" << endl;
	}
	else
	   cout << "输入错误" << endl;
	system("pause"); 
} 


