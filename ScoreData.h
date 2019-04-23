#include"Score.h"

class ScoreData{
	public:
		ScoreData();
		~ScoreData();
		
		Score *FindStuId(int sid,Score *Head);
		Score *FindCourId(int sid,int cid);
		void Save();
		void AddCour();
		void DelectCour();
		void AddSco();
		void ModifySco();
		void Display();
		
	private:
		Score *Head,*End;
		ifstream in;
		ofstream out;
};
