#include<iostream>
#include"Score.h"

using namespace std;

void Score::Input(bool sco)
{
	StuData stu;
	Student *sp=NULL;
	if(!sco)
	{
		while(true){
			cout << "输入学生id："; 
			cin >> stuid;
			if(sp=stu.FindId(stuid))
			{
					cout << "------------------------------" << endl;
					cout << "\t学号\t姓名"   << endl;
					cout << "------------------------------" << endl;
				sp->Next->Show();
				break;
			}
			else
				continue;
		}

		CourData cour;
		cour.Display();
		cout << "选择课程：";
		cin >> courid;
		score = -1;
	}
	else
	{
		cout << "输入成绩："; 
		cin >> score; 
	}	
}

void Score::ReadFole(istream &in)
{
	in >> stuid >> courid >> score;
}

void Score::Show()
{
	StuData st;
	Student *sp;
	CourData cou;
	Course *cp;
	
	sp=st.FindId(stuid);
	cp=cou.FindId(courid);

	cout <<"\t"<<stuid<<"\t"<<sp->Next->name
		 <<"\t"<<courid<<"\t"<<cp->Next->CourseName;
	if(score != -1 )
	{
		cout <<"\t"<<score; 
	}
	cout << endl;
}

