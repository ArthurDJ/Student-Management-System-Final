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
	
	void Input(bool sco);   //ѧ��ѡ�Σ���¼��ɼ� false; 
	void ReadFole(istream &in);
	void Show();
}; 
