#include<iostream>
#include<fstream>
#include"CourData.h"
#include"StuData.h"

using namespace std;

class Score{
	public:
		int stuid;
		int courid;
		int score;
	
	Score *Next;
	
	void Input(bool sco);   //学生选课，不录入成绩 false; 
	void ReadFole(istream &in);
	void Show();
}; 
