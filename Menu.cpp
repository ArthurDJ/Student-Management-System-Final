#include"Menu.h"
#include"ScoreData.h"

void Menu::BaseMenu(){
	quit = false; 
    
    while(!quit)
	{	
		system("cls"); 
	    cout << "***********主菜单************" << endl;
    	cout << "\t1.学生管理系统" << endl;
    	cout << "\t2.选课管理系统" << endl;
    	cout << "\t3.学生选课成绩管理系统" << endl;
    	cout << "\t0.退出" << endl;
    	cout << "***********主菜单************" << endl;
    	cout << "请选择：";
    	
	    cin >> choise;
		switch(choise)
		{
			case 0:
				quit = true;
				break;
			case 1:
				StuMenu();
				quit = false;
				break;
			case 2:
			    CourMenu();
			    quit = false;
			    break;
			case 3:
				ScoreMenu();
				quit = false;
				break;
		}
	} 	
} 

void Menu::StuMenu(){
	StuData stu;
	quit = false; 
    
    while(!quit)
	{	
		system("cls"); 
	    cout << "***********主菜单************" << endl;
    	cout << "\t1.添加学生信息" << endl;
    	cout << "\t2.删除学生信息" << endl;
    	cout << "\t3.修改学生信息" << endl;
		cout << "\t4.打印所有信息" << endl; 
    	cout << "\t0.退出" << endl;
    	cout << "***********主菜单************" << endl;
    	cout << "请选择：";
    	
	    cin >> choise;
		switch(choise)
		{
			case 0:
				quit = true;
				break;
			case 1:
				stu.AddItem();
				break;
			case 2:
			    stu.DelectItem();
			    break;
			case 3:
				stu.ModifyItem();
				break;
			case 4:
				stu.Display();
				break;
		}		
	}
}


void Menu::CourMenu(){
	CourData cour;
	quit = false; 
    
    while(!quit)
	{	    
		system("cls"); 
	    cout << "***********主菜单************" << endl;
    	cout << "\t1.添加课程信息" << endl;
    	cout << "\t2.删除课程信息" << endl;
    	cout << "\t3.修改课程信息" << endl;
		cout << "\t4.打印所有信息" << endl; 
    	cout << "\t0.退出" << endl;
    	cout << "***********主菜单************" << endl;
    	cout << "请选择：";
    	
	    cin >> choise;
		switch(choise)
		{
			case 0:
				quit = true;
				break;
			case 1:
				cour.AddItem();
				break;
			case 2:
			    cour.DelectItem();
			    break;
			case 3:
				cour.ModifyItem();
				break;
			case 4:
				cour.Display();
				break;
		}		
	}
}

void Menu::ScoreMenu()
{
	ScoreData sco;
	quit = false;
	
    while(!quit)
	{	    
		system("cls"); 
	    cout << "***********主菜单************" << endl;
    	cout << "\t1.学生选课" << endl;
    	cout << "\t2.学生选课删除" << endl;
		cout << "\t3.学生选课成绩录入" << endl; 
		cout << "\t4.学生选课成绩修改" << endl; 
		cout << "\t5.打印所有" << endl; 
    	cout << "\t0.退出" << endl;
    	cout << "***********主菜单************" << endl;
    	cout << "请选择：";
    	
	    cin >> choise;
		switch(choise)
		{
			case 0:
				quit = true;
				break;
			case 1:
				sco.AddCour();
				quit = false;
				break;
			case 2:
				sco.DelectCour();
				quit = false;
				break;
			case 3:
				sco.AddSco();
				quit = false;
				break;
			case 4:
				sco.ModifySco();
				quit = false;
				break;
			case 5:
				sco.Display();
				quit = false;
				break;				
		}		
	}
}
