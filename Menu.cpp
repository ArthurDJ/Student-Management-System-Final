#include"Menu.h"
#include"ScoreData.h"

void Menu::BaseMenu(){
	quit = false; 
    
    while(!quit)
	{	
		system("cls"); 
	    cout << "***********���˵�************" << endl;
    	cout << "\t1.ѧ������ϵͳ" << endl;
    	cout << "\t2.ѡ�ι���ϵͳ" << endl;
    	cout << "\t3.ѧ��ѡ�γɼ�����ϵͳ" << endl;
    	cout << "\t0.�˳�" << endl;
    	cout << "***********���˵�************" << endl;
    	cout << "��ѡ��";
    	
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
	    cout << "***********���˵�************" << endl;
    	cout << "\t1.���ѧ����Ϣ" << endl;
    	cout << "\t2.ɾ��ѧ����Ϣ" << endl;
    	cout << "\t3.�޸�ѧ����Ϣ" << endl;
		cout << "\t4.��ӡ������Ϣ" << endl; 
    	cout << "\t0.�˳�" << endl;
    	cout << "***********���˵�************" << endl;
    	cout << "��ѡ��";
    	
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
	    cout << "***********���˵�************" << endl;
    	cout << "\t1.��ӿγ���Ϣ" << endl;
    	cout << "\t2.ɾ���γ���Ϣ" << endl;
    	cout << "\t3.�޸Ŀγ���Ϣ" << endl;
		cout << "\t4.��ӡ������Ϣ" << endl; 
    	cout << "\t0.�˳�" << endl;
    	cout << "***********���˵�************" << endl;
    	cout << "��ѡ��";
    	
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
	    cout << "***********���˵�************" << endl;
    	cout << "\t1.ѧ��ѡ��" << endl;
    	cout << "\t2.ѧ��ѡ��ɾ��" << endl;
		cout << "\t3.ѧ��ѡ�γɼ�¼��" << endl; 
		cout << "\t4.ѧ��ѡ�γɼ��޸�" << endl; 
		cout << "\t5.��ӡ����" << endl; 
    	cout << "\t0.�˳�" << endl;
    	cout << "***********���˵�************" << endl;
    	cout << "��ѡ��";
    	
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
