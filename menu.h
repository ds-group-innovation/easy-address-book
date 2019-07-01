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
	    int select;//选择：1、管理员登录；2、普通用户（直接进普通用户的菜单）
		string password; 
	public:
		LoginMenu(){}
		
	    void showMenu();
		
		//获取用户菜单选项1、2 
		int getSelect(); 
		
		//用户输入选择 
		void setSelect();
		
		//输入密码 
		void setPassword();
		
		//判断是否是管理员，密码是否正确：123456 
		bool isAdmin(); 
		
		void handleMenu();
};


/*
  * 普通用户
  * 只有查询权限
  * 按人名显示某个人的信息或显示通讯录内所有人员的信息 
*/ 
class AuthMenu:public Menu
{
	protected:
		int number;
	public:
		
		void showMenu();
		
		void handleMenu();
		
	    //显示通讯录文件中所有人员信息 
	    void showAll();
	    
		//查找通讯录文件中某个人的信息 
	    void search();
};



/*
  * 管理员
  * CURD的权限都有 
*/ 
class AdminMenu:public Menu{
	private:
		bool has_been_loaded;//标记通讯录是从文件中载入的 
	public:

		void showMenu();
		
		void handleMenu();
	    
	    //内存中创建通讯录 
	    void createAddressBook();
		
		//从文件加载同蓄奴数据 
		void loadAddressBook();
		
		//显示当前通讯录（内存中）所有信息 
		void showAll();
		
		//显示通讯录（内存中）中某个人的信息 
		void showOne();
		
		//往通讯录（内存中）中添加人员 
		void addPeople();
		
		//删除通讯库（内存中）中的某个人的信息 
		void deletePeople();
		
		//修改通讯录（内存中）中的某个人的信息 
		void modPeople();
		
		//将通讯录（内存中）存到文件中 
		void saveFile();
}; 


//工厂类 
class HandleAddressBook{
	public:
		Menu* createMenu(int flag)
		{
		    switch(flag)
		    {
		    	//1.管理员 
		    	case 0: return new LoginMenu;break;
				case 1: return new AdminMenu;break;
				case 2: return new AuthMenu;break;
				default: return new AuthMenu;break;
			}
		}
};

#endif
