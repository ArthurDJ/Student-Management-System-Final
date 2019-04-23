#include<iostream>
#include<string>

using namespace std;

class Student
{
	public:
		int id;
		string name;
		
	Student *Next;
	
	void Input(int LastId);
	void ReadFole(istream &in);
	void Show();
	
};
