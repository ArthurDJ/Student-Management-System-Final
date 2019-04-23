#include<fstream>
#include"Student.h"

using namespace std;

class StuData{
	public:
		int LastId; 
		StuData();
		~StuData();
		
		void Display();
		void AddItem();
		void ModifyItem();
		void DelectItem();
		void menu();
	    void Save();
	    Student *FindId(int id);
	    
	private:
		Student *Head,*End;
		ifstream in;
		ofstream out;
};
