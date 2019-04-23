#include<string>

using namespace std;

class Course{
	public:
		int CourseId;
		string CourseName;
		
		Course *Next;
		
		void Input(int LastId);
		void ReadFole(istream &in);
		void Show(); 
};
