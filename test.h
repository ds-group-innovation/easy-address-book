#ifndef TEST_H
#define TEST_H

#include"addresslist.h"
//----------------------------------------------------------------------------------------------
//�����ǲ��ԣ����Կ��ǼӸ������� 

//����create���� 
void new_address_book_test()
{
	address_book = create();
	
	cout<<"�Ӹ���"<<endl;
	
	add_person(address_book);
	
	cout<<"ͨѶ¼"; 
	show_address_list(address_book);
	
	cout<<"�浵"<<endl;
	save_to_file(address_book); 
	
	//save_to_file_not_empty(address_book);
	//forward_list *rear = get_the_rear(address_book);
	//rear->people.show_info();
		
} 

//�ļ��������� 
void file_test()
{
	address_book = load_from_file();
	
	//system("cls");
	//system("pause");
	
	show_address_list(address_book);
}

//������������ ����search_person���в��� 
void search_test()
{
	address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"������Ҫ���ҵ��˵�����: ";
	cin>>name;
	forward_list* found = search_person(address_book,name);
	 
	
	cout<<"����ȵĸ�����Ϣ"<<endl; 
	cout<<"����-��ַ-�绰����-�������룺"<<endl;
	
	found->people.showInfo();
	
	
	system("pause"); 
	
	//�������Ų����ͷ�� 
    show_address_list(address_book);
}

//��search_people�������в��� 
void search_test_more()
{
	address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"������Ҫ���ҵ��˵�����: ";
	cin>>name;
	vector<forward_list*> found = search_people(address_book,name);
	
	if(found.empty())
		cout<<"ͨѶ¼û�������";
	else
	{
	    for(auto i=found.begin();i!=found.end();i++)
		{
		    (*i)->people.showInfo();	
		}	
	}
}

//�Ը�����Ϣ�޸ĺ������в��ԣ�mod_person_info 
void mod_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"����������Ҫ�޸���Ϣ���˵�����: ";
	cin>>name;
	mod_person_info(address_book,name);
	
	cout<<"�޸ĺ�"<<endl;
	show_address_list(address_book);
	system("pause");  
}

//��mod_people_info���в��� 
void mod_more_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"����������Ҫ�޸���Ϣ���˵�����: ";
	cin>>name;
	mod_people_info(address_book,name);
	
    cout<<"�޸ĺ�"<<endl;
    system("pause");
	show_address_list(address_book);
				
} 

//��get_the_lastone���в��� 
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

//��move_to_head���в��� 
void move_to_head_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	string name;
	cout<<"������Ҫ���ҵ��˵�����: ";
	cin>>name;
	forward_list *found = search_person(address_book,name);
	
	system("pause");
	//�ƶ����������
	address_book = move_to_head(address_book,found);
	
	show_address_list(address_book);
	
	system("pause");
}

//������ 
void delete_test()
{
	forward_list *book = load_from_file();
	show_address_list(book);
	string delete_name;
	cout<<"������Ҫɾ�����˵�������"; 
	cin>>delete_name;
	if(search_person(book,delete_name))
	    book = delete_person(book,delete_name);
	
	cout<<"ɾ����"<<endl;
	system("pause");
	
	//����֣�û�ͷ��꣬�ڴ�й©�������� 
	//book->people.show_info();
	
	cout<<"---"<<endl;
	
	show_address_list(book);
	
	//cout<<endl<<"???";
	system("pause");	
}

//���ڶ��ͬ��������� 
void delete_more_test()
{
	address_book = load_from_file();
	show_address_list(address_book);
	
	string delete_name;
	cout<<"������Ҫɾ�����˵�������"; 
	cin>>delete_name;
    
	address_book = delete_people(address_book,delete_name);
	
	cout<<"ɾ����";
    show_address_list(address_book);
}

//׷�Ӳ������� 
void save_to_file_not_empty_test()
{
	address_book = create();
	show_address_list(address_book);
	
	if(!is_empty_file())
	{
		string select;
		cout<<"�ļ����ǿյģ��������ݴ��ڣ��Ƿ�Ҫ׷����Ϣ��yes or no����";
	    cin>>select;
		if(select == "yes")
		{
			save_to_file_not_empty(address_book); 
		}
	    else//���� 
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
