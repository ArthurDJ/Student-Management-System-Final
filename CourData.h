#include"Course.h"
#include<fstream>

class CourData{
	public:
		int LastId;
		CourData();
		~CourData();
		
		Course *FindId(int id);
		void Display();
		void AddItem();
		void ModifyItem();
		void DelectItem();
		void menu();
	    void Save();
	
	private:
		Course *Head,*End;
		ifstream in;
		ofstream out;
};
