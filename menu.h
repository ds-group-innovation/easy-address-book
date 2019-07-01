#ifndef MENU_H
#define MENU_H

#include<iostream>
using namespace std;
 
class Menu{
	public:
		//Menu(){}
		//~Menu(){}
		virtual void showMenu() = 0;
		virtual void handleMenu() = 0;
};

 
class LoginMenu:public Menu{
	protected: 
	    int select;//ѡ��1������Ա��¼��2����ͨ�û���ֱ�ӽ���ͨ�û��Ĳ˵���
		string password; 
	public:
		LoginMenu(){}
		
	    void showMenu();
		
		//��ȡ�û��˵�ѡ��1��2 
		int getSelect(); 
		
		//�û�����ѡ�� 
		void setSelect();
		
		//�������� 
		void setPassword();
		
		//�ж��Ƿ��ǹ���Ա�������Ƿ���ȷ��123456 
		bool isAdmin(); 
		
		void handleMenu();
};


/*
  * ��ͨ�û�
  * ֻ�в�ѯȨ��
  * ��������ʾĳ���˵���Ϣ����ʾͨѶ¼��������Ա����Ϣ 
*/ 
class AuthMenu:public Menu
{
	protected:
		int number;
	public:
		
		void showMenu();
		
		void handleMenu();
		
	    //��ʾͨѶ¼�ļ���������Ա��Ϣ 
	    void showAll();
	    
		//����ͨѶ¼�ļ���ĳ���˵���Ϣ 
	    void search();
};



/*
  * ����Ա
  * CURD��Ȩ�޶��� 
*/ 
class AdminMenu:public Menu{
	private:
		bool has_been_loaded;//���ͨѶ¼�Ǵ��ļ�������� 
	public:

		void showMenu();
		
		void handleMenu();
	    
	    //�ڴ��д���ͨѶ¼ 
	    void createAddressBook();
		
		//���ļ�����ͬ��ū���� 
		void loadAddressBook();
		
		//��ʾ��ǰͨѶ¼���ڴ��У�������Ϣ 
		void showAll();
		
		//��ʾͨѶ¼���ڴ��У���ĳ���˵���Ϣ 
		void showOne();
		
		//��ͨѶ¼���ڴ��У��������Ա 
		void addPeople();
		
		//ɾ��ͨѶ�⣨�ڴ��У��е�ĳ���˵���Ϣ 
		void deletePeople();
		
		//�޸�ͨѶ¼���ڴ��У��е�ĳ���˵���Ϣ 
		void modPeople();
		
		//��ͨѶ¼���ڴ��У��浽�ļ��� 
		void saveFile();
}; 


//������ 
class HandleAddressBook{
	public:
		Menu* createMenu(int flag)
		{
		    switch(flag)
		    {
		    	//1.����Ա 
		    	case 0: return new LoginMenu;break;
				case 1: return new AdminMenu;break;
				case 2: return new AuthMenu;break;
				default: return new AuthMenu;break;
			}
		}
};

#endif
