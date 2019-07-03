
#include "menu.h"
#include "addresslist.h"

//---------------------------------------------
//��¼
void LoginMenu::showMenu() {
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"                             ����һ��                               \n"<<endl;
	cout<<"                         �򵥵�ͨ��¼����                           \n"<<endl;
	cout<<"                     ���Զ�ͨ��¼���м򵥹���                       \n"<<endl;
	cout<<"                          ��ӭʹ��ͨ��¼                            \n"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;

	system("pause");
	system("cls");

	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"                             1. ����Ա��¼                          \n"<<endl;
	cout<<"                             2.  �ǹ���Ա                           \n"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"����������ѡ��1��2������������������ַ���Ĭ�Ͻ���ǹ���Ա�˵���";
	return ;
}

int LoginMenu::getSelect() {
	return this->select;
}

void LoginMenu::setSelect() {
	int choice;
	cin>>choice;
	this->select = choice;
}

void LoginMenu::setPassword() {
	cout<<"�������¼���룺"<<endl;
	string token;
	cin>>token;
	this->password = token;
}

bool LoginMenu::isAdmin() {
	if(this->password == "123456")
		return true;
	else
		return false;
}

void LoginMenu::handleMenu() {
	//LoginMenu.setSelect();
	return ;
}
//---------------------------------------------




//---------------------------------------------
//�ǹ���Ա
void AuthMenu::showMenu() {
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"                          ����1. �鿴ͨѶ¼�������˵���Ϣ           \n"<<endl;
	cout<<"                          ����2. �鿴ͨѶ¼��ĳ���˵���Ϣ           \n"<<endl;
	cout<<"                          ��������. �˳�����                        \n"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	return ;
}

void AuthMenu::handleMenu() {
	cout<<"��ѡ����Ҫ���еĲ�����";
	int number;
	cin>>number;
	switch(number) {
		case 1:
			this->showAll();
			break;
		case 2:
			this->search();
			break;
		default:
			exit(0);
			break;
	}
}

void AuthMenu::showAll() {
	address_book = load_from_file();
	if(address_book) {
		show_address_list(address_book);
		system("pause");
	}
	system("cls");
	this->showMenu();
	this->handleMenu();
}

void AuthMenu::search() {
	address_book = load_from_file();
	if(address_book) {
		string name;
		cout<<"������Ҫ�鿴���˵�����: ";
		cin>>name;
		vector<forward_list*> found = search_people(address_book,name);
		if(found.empty())
			cout<<"ͨѶ¼û�������";
		else {
			//��������������Ų����ͷ
			show_address_list(address_book);

			for(auto v:found) {
				address_book = move_to_head(address_book,v);
			}
			save_to_file(address_book);
			//��˵�еķ����Ժ�飨Ч�ʣ�

			cout<<"�ҵ� "<<found.size()<<" ����Ϊ "<<name<<" ���ˣ���Ϣ���£�"<<endl;
			for(auto i=found.begin(); i!=found.end(); i++) {
				(*i)->people.showInfo();
			}
		}
		system("pause");
	}
	system("cls");
	this->showMenu();
	this->handleMenu();
}
//---------------------------------------------


//---------------------------------------------
//����Ա
void AdminMenu::showMenu() {
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"                          ����1. �½�ͨ��¼�����ڴ��У�             \n"<<endl;
	cout<<"                          ����2. ���ļ�������ͨѶ¼                 \n"<<endl;
	cout<<"                          ����3. �鿴��ǰͨѶ¼������Ա����Ϣ       \n"<<endl;
	cout<<"                          ����4. �鿴��ǰͨѶ¼��ĳ���˵���Ϣ       \n"<<endl;
	cout<<"                          ����5. ��ǰͨѶ¼��������Ա��Ϣ         \n"<<endl;
	cout<<"                          ����6. ɾ����ǰͨѶ¼��ĳ���˵���Ϣ       \n"<<endl;
	cout<<"                          ����7. �޸ĵ�ǰͨѶ¼��ĳ���˵���Ϣ       \n"<<endl;
	cout<<"                          ����8. �浵                               \n"<<endl;
	cout<<"                          ����9. �˳�����                           \n"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"\n��ѡ������Ҫ���еĲ�����\n";
	return ;
}

void AdminMenu::handleMenu() {
	int number;
	cin>>number;
	switch(number) {
		case 1:
			this->createAddressBook();
			break;
		case 2:
			this->loadAddressBook();
			break;
		case 3:
			this->showAll();
			break;
		case 4:
			this->showOne();
			break;
		case 5:
			this->addPeople();
			break;
		case 6:
			this->deletePeople();
			break;
		case 7:
			this->modPeople();
			break;
		case 8:
			this->saveFile();
			break;
		case 9:
			exit(0);
			break;
		default:
			cout<<"û�����ѡ�������ѡ��"<<endl;
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();
			break;
	}
}

void AdminMenu::createAddressBook() {
	if(address_book) { //��������
		cout<<"ͨѶ¼�������ݣ��Ƿ�Ҫ�����½����½��Ḳ��ԭ�����ݣ�yes or no��:";
		string sure;
		cin>>sure;
		if(sure == "yes") {
			address_book = create();
			if(address_book)
				cout<<"�����ɹ�������к�������"<<endl;
			else//δʵ��
				cout<<"����ʧ��"<<endl;
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();
		} else {
			cout<<"��ѡ���˲����ǣ���ѡ����������:"<<endl;
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();
		}
	} else {
		address_book = create();
		if(address_book)
			cout<<"�����ɹ�������к�������"<<endl;
		else//δʵ��
			cout<<"����ʧ��"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::loadAddressBook() {
	if(address_book) {
		cout<<"ͨѶ¼�������ݣ��Ƿ�Ҫ�������룬����Ḳ��ԭ�����ݣ�yes or no��:";
		string sure;
		cin>>sure;
		if(sure == "yes") {
			this->has_been_loaded = true;//���ͨѶ¼�Ǵ��ļ��������
			address_book = load_from_file();
			if(address_book)
				cout<<"����ɹ�������к�������"<<endl;
			else//δʵ��
				cout<<"����ʧ�ܣ��ļ�������"<<endl;
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();
		} else {
			cout<<"��ѡ���˲����ǣ���ѡ����������:"<<endl;
			system("pause");
			system("cls");
			this->showMenu();
			this->handleMenu();
		}
	} else {
		address_book = load_from_file();
		if(address_book)
			cout<<"����ɹ�������к�������"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::showAll() {
	if(address_book) {
		system("cls");
		show_address_list(address_book);
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	} else {
		cout<<"�����´���ͨѶ¼����ͨѶ¼����"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::showOne() {
	if(address_book) {
		string name;
		cout<<"������Ҫ�鿴���˵�����: ";
		cin>>name;
		vector<forward_list*> found = search_people(address_book,name);
		if(found.empty())
			cout<<"ͨѶ¼û�������";
		else {
			//��������������Ų����ͷ
			show_address_list(address_book);

			for(auto v:found) {
				address_book = move_to_head(address_book,v);
			}
			//save_to_file(address_book);
			//��˵�еķ����Ժ�飨Ч�ʣ�

			cout<<"�ҵ� "<<found.size()<<" ����Ϊ "<<name<<" ���ˣ���Ϣ���£�"<<endl;
			for(auto i=found.begin(); i!=found.end(); i++) {
				(*i)->people.showInfo();
			}
		}
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	} else {
		cout<<"�����´���ͨѶ¼����ͨѶ¼����"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::addPeople() {
	if(address_book) {
		cout<<"������Ҫ��ӵ���Ա������";
		int num;
		cin>>num;
		while(num--)
			add_person(address_book);
		cout<<"��ӳɹ�";
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	} else {
		cout<<"�����´���ͨѶ¼����ͨѶ¼����"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::deletePeople() {
	if(address_book) {
		cout<<"��ǰͨѶ¼������Ա��Ϣ���£�"<<endl;
		show_address_list(address_book);
		string delete_name;
		cout<<"������Ҫɾ�����˵�������";
		cin>>delete_name;
		address_book = delete_people(address_book,delete_name);
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	} else {
		cout<<"�����´���ͨѶ¼����ͨѶ¼����"<<endl;
		system("pause");
		system("cls");
		this->showMenu();
		this->handleMenu();
	}
}

void AdminMenu::modPeople() {
	if(address_book) {
		cout<<"��ǰͨѶ¼������Ա��Ϣ���£�"<<endl;
		show_address_list(address_book);
		cout<<"��������Ҫ�޸ĵ��˵�������"<<endl;

		string mod_name;
		cin>>mod_name;
		mod_people_info(address_book,mod_name);
		cout<<"�޸����"<<endl;
	} else {
		cout<<"�����´���ͨѶ¼����ͨѶ¼����"<<endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
	this->handleMenu();
}


void AdminMenu::saveFile() {
	//���ļ�ֱ�Ӵ浵
	if(is_empty_file()) {
		save_to_file(address_book);
		cout<<"�浵�ɹ�"<<endl;
	} else {
		cout<<"�ļ����������ݣ��Ƿ�Ҫ���ǻ�׷�ӣ�yes.���� or no.׷�ӣ������֮ǰ���й����룬��ѡ�񸲸ǣ���"<<endl;
		//ʵ���û�û��ѡ��,hahaha~~~
		string sure;
		cin>>sure;
		if(sure == "yes") {
			save_to_file(address_book);
			cout<<"�浵�ɹ�"<<endl;
		} else if(sure == "no") {
			save_to_file_not_empty(address_book);
			cout<<"�浵�ɹ�???"<<endl;
		} else { //��������ֱ�Ӹ���
			save_to_file(address_book);
			cout<<"�浵�ɹ�"<<endl;
		}
		/*
		switch(sure)
		{
		    case 1:
			       save_to_file(address_book);
		           cout<<"�浵�ɹ�"<<endl;
				   break;
		    case 2:
			       save_to_file_not_empty(address_book);
				   cout<<"�浵�ɹ�"<<endl;
				   break;
		}
		*/
	}
	system("pause");
	system("cls");
	this->showMenu();
	this->handleMenu();
}
//---------------------------------------------



 
void create_menu()
{
	HandleAddressBook *begin = new HandleAddressBook;
	HandleAddressBook *handle = new HandleAddressBook;
	
	
	Menu *begin_login = begin->createMenu(0); 
	begin_login->showMenu();
	
	LoginMenu login;
	login.setSelect();
	
	//����Ա 
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
					cout<<"�����������������࣬������ǹ���Ա�˵�"<<endl;
					Menu* menu = handle->createMenu(login.getSelect()); 
    	            menu->showMenu();
    	            menu->handleMenu();
					system("pause");
					break;   	
				}
			    cout<<"���������������������"<<endl; 
			}
		} 
	}	
	else
	{
		//Ϊ�ǹ���Ա
		Menu* menu = handle->createMenu(login.getSelect()); 
    	menu->showMenu();
		menu->handleMenu();
	}
}
