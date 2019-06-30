#ifndef TEST_H
#define TEST_H

#include"addresslist.h"
//----------------------------------------------------------------------------------------------
//以下是测试，可以考虑加个测试类 

//测试create函数 
void new_address_book_test()
{
	address_book = create();
	
	cout<<"加个人"<<endl;
	
	add_person(address_book);
	
	cout<<"通讯录"; 
	show_address_list(address_book);
	
	cout<<"存档"<<endl;
	save_to_file(address_book); 
	
	//save_to_file_not_empty(address_book);
	//forward_list *rear = get_the_rear(address_book);
	//rear->people.show_info();
		
} 

//文件操作测试 
void file_test()
{
	address_book = load_from_file();
	
	//system("cls");
	//system("pause");
	
	show_address_list(address_book);
}

//搜索函数测试 ，对search_person进行测试 
void search_test()
{
	address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"请输入要查找的人的姓名: ";
	cin>>name;
	forward_list* found = search_person(address_book,name);
	 
	
	cout<<"这个比的个人信息"<<endl; 
	cout<<"姓名-地址-电话号码-邮政编码："<<endl;
	
	found->people.showInfo();
	
	
	system("pause"); 
	
	//被查的人挪到表头后 
    show_address_list(address_book);
}

//对search_people函数进行测试 
void search_test_more()
{
	address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"请输入要查找的人的姓名: ";
	cin>>name;
	vector<forward_list*> found = search_people(address_book,name);
	
	if(found.empty())
		cout<<"通讯录没有这个人";
	else
	{
	    for(auto i=found.begin();i!=found.end();i++)
		{
		    (*i)->people.showInfo();	
		}	
	}
}

//对个人信息修改函数进行测试，mod_person_info 
void mod_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"请输入你想要修改信息的人的姓名: ";
	cin>>name;
	mod_person_info(address_book,name);
	
	cout<<"修改后"<<endl;
	show_address_list(address_book);
	system("pause");  
}

//对mod_people_info进行测试 
void mod_more_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"请输入你想要修改信息的人的姓名: ";
	cin>>name;
	mod_people_info(address_book,name);
	
    cout<<"修改后"<<endl;
    system("pause");
	show_address_list(address_book);
				
} 

//对get_the_lastone进行测试 
void lastone_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	
	forward_list *p = address_book->next;
	p = p->next->next;
	
	forward_list *last = get_the_lastone(address_book,p);
	
	cout<<"----------"<<endl;
	last->people.showInfo();
	
	system("pause"); 
		
}

//对move_to_head进行测试 
void move_to_head_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"请输入要查找的人的姓名: ";
	cin>>name;
	forward_list *found = search_person(address_book,name);
	
	system("pause");
	//移动被搞过的人
	address_book = move_to_head(address_book,found);
	
	show_address_list(address_book);
	
	system("pause");
}

//处理单个 
void delete_test()
{
	forward_list *book = load_from_file();
	show_address_list(book);
	string delete_name;
	cout<<"请输入要删除的人的姓名："; 
	cin>>delete_name;
	if(search_person(book,delete_name))
	    book = delete_person(book,delete_name);
	
	cout<<"删除后"<<endl;
	system("pause");
	
	//很奇怪，没释放完，内存泄漏？？？？ 
	//book->people.show_info();
	
	cout<<"---"<<endl;
	
	show_address_list(book);
	
	//cout<<endl<<"???";
	system("pause");	
}

//存在多个同名情况处理 
void delete_more_test()
{
	address_book = load_from_file();
	show_address_list(address_book);
	
	string delete_name;
	cout<<"请输入要删除的人的姓名："; 
	cin>>delete_name;
    
	address_book = delete_people(address_book,delete_name);
	
	cout<<"删除后";
    show_address_list(address_book);
}

//追加操作测试 
void save_to_file_not_empty_test()
{
	address_book = create();
	show_address_list(address_book);
	
	if(!is_empty_file())
	{
		string select;
		cout<<"文件不是空的，已有数据存在，是否要追加信息（yes or no）：";
	    cin>>select;
		if(select == "yes")
		{
			save_to_file_not_empty(address_book); 
		}
	    else//覆盖 
	    {
	    	save_to_file(address_book);
		}
	}
	else
	{
		save_to_file(address_book);
	}
	
	return ;
}

//----------------------------------------------------------------------------------------------

#endif
