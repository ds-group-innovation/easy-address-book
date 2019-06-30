
#include<iostream>
#include "addresslist.h"
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
		LoginMenu()
		{ 	
		}
	    void showMenu()
		{
		    cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"                             这是一个                               \n"<<endl;
			cout<<"                         简单的通信录程序                           \n"<<endl;
			cout<<"                     可以对通信录进行简单管理                       \n"<<endl;
			cout<<"                          欢迎使用通信录                            \n"<<endl;
			cout<<"----------------------------------------------------------------------"<<endl;
			
			system("pause");
			system("cls"); 
			
			cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"                             1. 管理员登录                          \n"<<endl;
			cout<<"                             2.  非管理员                           \n"<<endl;
			cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"请输入您的选择（1或2），如果您输入其它字符，默认进入非管理员菜单：";
			return ;
		} 
		
		int getSelect()
		{
			return this->select;
		}
		
		void setSelect()
		{
			int choice;
			cin>>choice; 
			this->select = choice;
		}
		
		void setPassword()
		{
			cout<<"请输入登录密码："<<endl; 
			string token;
			cin>>token;
			this->password = token;
		}
		
		bool isAdmin()
		{
			if(this->password == "123456")
			    return true;
			else
			    return false;
		}
		
		void handleMenu()
		{
			//LoginMenu.setSelect();
			return ;
		}
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
		
		void showMenu()
		{
			cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"                          输入1. 查看通讯录内所有人的信息           \n"<<endl;
			cout<<"                          输入2. 查看通讯录内某个人的信息           \n"<<endl;
			cout<<"                          输入其它. 退出程序                        \n"<<endl;
			cout<<"----------------------------------------------------------------------"<<endl;
			return ;
		}
		 
		void handleMenu()
	    {
	    	cout<<"请选择您要进行的操作：";
	    	int number;
		    cin>>number;
		    switch(number)
		    {
		    	case 1:this->showAll();break;
		    	case 2:this->search();break;
		    	default:exit(0);break;
	        }
	    }
	    
	    void showAll()
	    {
	    	address_book = load_from_file();
			if(address_book)
			{   
				show_address_list(address_book);
				system("pause");
			}
			system("cls");
			this->showMenu(); 
			this->handleMenu();
		}
	    
	    void search()
		{
		    address_book = load_from_file();
			if(address_book)
			{
			    string name;
	            cout<<"请输入要查看的人的姓名: ";
	            cin>>name;
	            vector<forward_list*> found = search_people(address_book,name);
	            if(found.empty())
					cout<<"通讯录没有这个人";
				else
				{
					cout<<"找到 "<<found.size()<<" 个名为 "<<name<<" 的人，信息如下："<<endl; 
	    			for(auto i=found.begin();i!=found.end();i++)
					{
		    			(*i)->people.showInfo();	
					}	
				}
				system("pause");	
			}
			system("cls");
			this->showMenu(); 
			this->handleMenu();	
		} 
};



/*
  * 管理员
  * CURD的权限都有 
*/ 
class AdminMenu:public Menu{
	private:
		bool has_been_loaded;//标记通讯录是从文件中载入的 
	public:
		void showMenu()
		{
			cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"                          输入1. 新建通信录（在内存中）             \n"<<endl;
			cout<<"                          输入2. 从文件中载入通讯录                 \n"<<endl;
			cout<<"                          输入3. 查看当前通讯录所有人员的信息       \n"<<endl;
			cout<<"                          输入4. 查看当前通讯录中某个人的信息       \n"<<endl;
			cout<<"                          输入5. 向当前通讯录中增加人员信息         \n"<<endl;
			cout<<"                          输入6. 删除当前通讯录中某个人的信息       \n"<<endl;
			cout<<"                          输入7. 存档                               \n"<<endl;
			cout<<"                          输入8. 退出程序                           \n"<<endl;
			cout<<"----------------------------------------------------------------------"<<endl;
			cout<<"\n请选择您想要进行的操作：\n";
			return ;
		}
		
		void handleMenu()
	    {
	    	int number;
		    cin>>number;
		    switch(number)
		    {
		    	case 1:this->createAddressBook();break;
		    	case 2:this->loadAddressBook();break;
		    	case 3:this->showAll();break;
		    	case 4:this->showOne();break;
		    	case 5:this->addPeople();break;
		    	case 6:this->deletePeople();break;
		    	case 7:this->saveFile();break;
		    	case 8:exit(0);break;
				default:
				    cout<<"没有这个选项，请重新选择"<<endl;
					system("pause");
					system("cls");
					this->showMenu();
					this->handleMenu();
					break; 
	        }
	    }
	    
	    void createAddressBook()
		{
			if(address_book)//已有数据 
			{    
			    cout<<"通讯录已有数据，是否要继续新建，新建会覆盖原有数据（yes or no）:";
		        string sure;
				cin>>sure;
				if(sure == "yes")
				{
					address_book = create();
					if(address_book)
			    		cout<<"创建成功，请进行后续操作"<<endl;
					else//未实现 
			    		cout<<"创建失败"<<endl;
					system("pause");
					system("cls");
					this->showMenu();
					this->handleMenu(); 
				}
				else
				{
					cout<<"您选择了不覆盖，请选择其他操作:"<<endl;
					system("pause");
					system("cls");
					this->showMenu();
					this->handleMenu();
				}
			}
			else
			{
			    address_book = create();
				if(address_book)
			    	cout<<"创建成功，请进行后续操作"<<endl;
				else//未实现 
			    	cout<<"创建失败"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu(); 	
			} 
		}
		
		void loadAddressBook()
		{
		    if(address_book)
			{    
			    cout<<"通讯录已有数据，是否要继续载入，载入会覆盖原有数据（yes or no）:";
		        string sure;
				cin>>sure;
				if(sure == "yes")
				{
					this->has_been_loaded = true;//标记通讯录是从文件中载入的 
					address_book = load_from_file();
					if(address_book)
			    		cout<<"载入成功，请进行后续操作"<<endl;
					else//未实现 
			    		cout<<"载入失败，文件不存在"<<endl;
					system("pause");
					system("cls");
					this->showMenu();
					this->handleMenu(); 
				}
				else
				{
					cout<<"您选择了不覆盖，请选择其他操作:"<<endl;
					system("pause");
					system("cls");
					this->showMenu();
					this->handleMenu();
				}
			}
			else
			{
			    address_book = load_from_file();
				if(address_book)
			    	cout<<"载入成功，请进行后续操作"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu(); 	
			}    	
		}
		
		void showAll()
		{
		    if(address_book)
			{
				system("cls");
				show_address_list(address_book);
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();
			}
			else
			{
			    cout<<"请先新创建通讯录或导入通讯录数据"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();	
			}	
		}
		
		void showOne()
		{
			if(address_book)
			{
			    string name;
	            cout<<"请输入要查看的人的姓名: ";
	            cin>>name;
	            vector<forward_list*> found = search_people(address_book,name);
	            if(found.empty())
					cout<<"通讯录没有这个人";
				else
				{
					cout<<"找到 "<<found.size()<<" 个名为 "<<name<<" 的人，信息如下："<<endl; 
	    			for(auto i=found.begin();i!=found.end();i++)
					{
		    			(*i)->people.showInfo();	
					}	
				}
				system("pause");
				system("cls");
			    this->showMenu(); 
			    this->handleMenu();		
			}
			else
			{
			    cout<<"请先新创建通讯录或导入通讯录数据"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();		
			}
		}
		
		void addPeople()
		{
			if(address_book)
			{ 
			    cout<<"请输入要添加的人员数量：";
				int num;
				cin>>num;
				while(num--)
				    add_person(address_book);
				cout<<"添加成功";
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();	
			}
			else
			{
			    cout<<"请先新创建通讯录或导入通讯录数据"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();		
			}
		}
		
		void deletePeople()
		{
			if(address_book)
			{
				cout<<"当前通讯录所有人员信息如下："<<endl; 
			    show_address_list(address_book);
				string delete_name;
				cout<<"请输入要删除的人的姓名："; 
				cin>>delete_name;
				address_book = delete_people(address_book,delete_name);	
			    system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();	
			}
			else
			{
			    cout<<"请先新创建通讯录或导入通讯录数据"<<endl;
				system("pause");
				system("cls");
				this->showMenu();
				this->handleMenu();		
			}
		}
		
		void saveFile()
		{
			//空文件直接存档 
		    if(is_empty_file())
			{
			    save_to_file(address_book);
				cout<<"存档成功"<<endl;    
			}
			else
			{
			    cout<<"文件中已有数据，是否要覆盖或追加（yes.覆盖 or no.追加，如果您之前进行过载入，请选择覆盖）："<<endl;
				//实际用户没得选择,hahaha~~~ 
				string sure;
				cin>>sure;
				if(sure == "yes")
				{
					save_to_file(address_book);
				    cout<<"存档成功"<<endl;
				} 
				else if(sure == "no")
				{
					save_to_file_not_empty(address_book);
					cout<<"存档成功???"<<endl;	
				}
				else//输入其他直接覆盖 
				{
				    save_to_file(address_book);
				    cout<<"存档成功"<<endl;	
				} 
				/* 
				switch(sure)
				{
				    case 1:
					       save_to_file(address_book);
				           cout<<"存档成功"<<endl;
						   break;
				    case 2:
					       save_to_file_not_empty(address_book);
						   cout<<"存档成功"<<endl;
						   break;      	
				}
				*/	
			}
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();	
		} 
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

void create_menu()
{
	HandleAddressBook *begin = new HandleAddressBook;
	HandleAddressBook *handle = new HandleAddressBook;
	
	
	Menu *begin_login = begin->createMenu(0); 
	begin_login->showMenu();
	
	LoginMenu login;
	login.setSelect();
	
	//管理员 
	if(login.getSelect()==1)
	{
	    int count = 0;
	    while(1)
	    {
		    login.setPassword();
			if(login.isAdmin())
			{
			    Menu* menu = handle->createMenu(login.getSelect()); 
                menu->showMenu();
				menu->handleMenu();
				break;	
			}
			else
			{
				count++;
				if(count == 3)
				{
					cout<<"输入密码错误次数过多，将进入非管理员菜单"<<endl;
					Menu* menu = handle->createMenu(login.getSelect()); 
    	            menu->showMenu();
    	            menu->handleMenu();
					system("pause");
					break;   	
				}
			    cout<<"输入密码错误。请重新输入"<<endl; 
			}
		} 
	}	
	else
	{
		//为非管理员
		Menu* menu = handle->createMenu(login.getSelect()); 
    	menu->showMenu();
		menu->handleMenu();
	}
}
