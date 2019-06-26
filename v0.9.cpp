#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Cperson{
	public:
		string name;                //���� 
		string address;             //��ַ 
		long long phone_number;     //�绰���� 
	    long int postcode;          //�������� 
	public:
		//��ϵ����Ϣ��д 
		void create_info()
		{
			cout<<"����-��ַ-�绰����-�������룺"<<endl; 
			cin>>this->name>>this->address>>this->phone_number>>this->postcode;
		}
		void show_info()
		{
		    cout<<this->name<<"    "<<this->address<<"    "<<this->phone_number<<"    "<<this->postcode<<endl;	
		}
		void saveToFile(ofstream &output)
		{
			output<<this->name<<" "<<this->address<<" "<<this->phone_number<<" "<<this->postcode;
		}
		//���޸ĳ����������Ϣ 
		void mod_info()
		{
			string flag;
		    cout<<"�����޸�����˵ļ�ͥ��ַ��(true or false)��: ";
			cin>>flag;
			if(flag == "true")
			{
				string addr;
				cout<<"�������µļ�ͥ��ַ��";
				cin>>addr;
				this->address = addr;
			}
			
			cout<<"�����޸�����˵ĵ绰������(true or false)��: ";
			cin>>flag;
			if(flag == "true")
			{
				long long number;
				cout<<"�������µĵ绰���룺"; 
				cin>>number;
				this->phone_number = number;
			}
			
			cout<<"�����޸�����˵�����������(true or false)��: ";
			cin>>flag;
			if(flag == "true")
			{
				long int code;
				cout<<"�������µ��������룺";
				cin>>code;
				this->postcode = code;
			}
		}
};

//ͨѶ¼��������(����) 
class forward_list{
	public:
	    Cperson people;
	    forward_list *next;
};

forward_list *address_book;

//β�巨����,��ͷ�ڵ� 
forward_list* create()
{
    forward_list *head=NULL;    //ͷ�ڵ� 
	forward_list *rear=NULL;    //β�ڵ�
	
	forward_list *temp;
	
	int hold_on;
	cout<<"������ͨѶ¼��Ա����"<<endl;
	cin>>hold_on;//�������� 
	while(hold_on)
	{
	    Cperson new_person;
		new_person.create_info();
		
		temp = new forward_list;
		
		temp->people = new_person;
		
		if(head == NULL)
		    head = temp;
		else
		    rear->next = temp;
		
		rear = temp; 
	    hold_on--; 
	}
	if(rear != NULL)
	    rear->next = NULL;
	
	return head;
} 

forward_list* get_the_rear(forward_list *list)
{
    forward_list *temp = list;
    forward_list *rear = NULL;
    while(temp != NULL)
    {
    	rear = temp;
    	temp = temp->next;
	}
    
	return rear;
} 

//�����Ա��ͨѶ¼��,����β����� 
void add_person(forward_list *list)
{
	forward_list *rear = get_the_rear(list);//ͨѶ¼����β�� 
    forward_list *temp;
    
	Cperson new_person;
    new_person.create_info();
    
    
	temp = new forward_list;
	temp->people = new_person;
	temp->next = NULL;
	
	rear->next = temp; 
    
    //cout<<endl;
    //rear->next->people = new_person;
    //rear->next->next = NULL;
    
	return ;	
}

//��ʾͨѶ¼ 
void show_address_list(forward_list *list)
{
	system("cls");
	forward_list *p=list;
	cout<<"����-��ַ-�绰����-�������룺"<<endl; 
	while(p != NULL)
	{
		p->people.show_info();
		p = p->next;
	}
	
	return ;
}

//��ȡͨѶ¼������Ա���� 
int address_book_person_nums(forward_list *s)
{
	int count;
	forward_list *p=s;
	while(p)
	{
		count++;
		p = p->next;
	}
    cout<<"��ͨѶ¼��"<<count<<"����"<<endl; 
    return count;
}

//�����ҵ���һ����
forward_list* move_to_head(forward_list *list,forward_list *s); 
forward_list* search_person(forward_list *list,string name)
{
    forward_list *p=list;
	while(p != NULL)
	{
		if(p->people.name == name)
		{
			//������ѯ�������Ƶ���ͷ
			//move_to_head(list,p); 
			return p;//�������ص�һ���ҵ�����;
			//����vector�洢�����; 
		}
		else
		{
			p = p->next;
		}
	}
	cout<<"ͨѶ¼��û�������";
	return 0;
}

//�����ҵ��Ķ���ˣ�ͬ�� 
vector<forward_list*> search_people(forward_list *list,string name)
{
    forward_list *p=list;
	vector<forward_list*> v_temp;
	while(p != NULL)
	{
		if(p->people.name == name)
		{
			v_temp.push_back(p); 
			p = p->next; 
		}
		else
		{
			p = p->next;
		}
	}
	
	return v_temp;
}

//��Ϣ�޸ģ������ˣ�����search_person 
void mod_person_info(forward_list *list,string name)
{
    forward_list *temp = search_person(list,name);
    if(temp)
    {
        temp->people.mod_info();
	    cout<<"�޸����"<<endl;	
	}
	else
	{
		cout<<"ͨѶ¼û�������"; 
	}
}

//��Ϣ�޸ģ����ͬ���ˣ�����search_people 
void mod_people_info(forward_list *list,string name)
{
    vector<forward_list*> found = search_people(address_book,name);
	if(found.empty())
	    cout<<"ͨѶ¼û�������"; 
	else
	{
	    if(found.size()>1)
	    {
	    	cout<<"�ҵ�"<<found.size()<<"�����ֶ�Ϊ"<<name<<"����,��Ϣ����"<<endl;
			for(auto v:found)
			{
			    v->people.show_info();	
			}
			int z;
			cout<<"����Ҫ�޸ĵڼ���(1-"<<found.size()<<")�ˣ�";
			cin>>z;
			//��Ԫ�زſ����±귨���� 
			found[z-1]->people.mod_info();
			
			cout<<"�޸����"<<endl; 
		}
		else
		{
		    for(auto v:found)
			    v->people.mod_info();
	        cout<<"�޸����"<<endl;	
		}    
	}
	system("pause"); 	
}

//�ҵ�s����һλ���� 
forward_list* get_the_lastone(forward_list *list,forward_list *s)
{
	forward_list *p = s,*temp;
	
	//һ����λ 
	if(p == list || p == list->next)return list;
    
    p = list->next;
	while(p != NULL)
	{
	    temp = p; 
		p = p->next;
		if(p == s)
	        return temp;        	
	}   	
} 

//s�Ƶ�list���ͷ�������±�ͷ 
forward_list* move_to_head(forward_list *list,forward_list *s)
{
	forward_list *temp,*lastone;
	
	temp = s;
	lastone = get_the_lastone(list,s);
	
    if(s->next==NULL)//���Ǳ�β
	{
		temp->next = list;
		lastone->next = NULL;
		return temp; 
	}
	else if(s == list)//��ͷ 
	    return list; 
	else//���Ǳ�β����ͷ 
	{
		lastone->next = temp->next;
		temp->next = list;
		return temp;
	}	
} 

//�浵 
void save_to_file(forward_list *list)
{
    ofstream out("addressBook.txt", ios::out);
    int person_nums = address_book_person_nums(list); 
	forward_list *p=list;
	while(p!=NULL)
	{
	    p->people.saveToFile(out);
	    if(person_nums>1)
	        out<<endl;
		p = p->next;
		person_nums--;	
	}	
} 

//��ȡ
forward_list* load_from_file()
{
    ifstream read("addressBook.txt",ios::in);
    
    //�ж��ļ��Ƿ���� 
    if(!read)
    {
    	cout<<"addressBook.txt�ļ�������";
		system("pause");
		exit(0); 
	}
	
	forward_list *head = NULL;
	forward_list *rear = NULL;
	
	while(!read.eof())
	{
		string name;                //���� 
	    string address;             //��ַ 
	    long long phone_number;     //�绰���� 
	    long int postcode;          //�������� 
	
	    //��ȡ��Ϣ 
	    read>>name>>address>>phone_number>>postcode;
	
	    Cperson new_person;
	    
	    new_person.name = name;
	    new_person.address = address;
	    new_person.phone_number = phone_number;
	    new_person.postcode = postcode; 
	    
	    forward_list *temp = new forward_list;
	    temp->people = new_person; 
	
	    if(head == NULL)
		    head = temp;
		else
		    rear->next = temp;
		
		rear = temp;
	}
	if(rear != NULL)
	{
		rear->next = NULL;
	}
	//show_address_list(head);
	return head;
} 

//----------------------------------------------------------------------------------------------
//�����ǲ��� 

void new_address_book_test()
{
	address_book = create();
	
	cout<<"�Ӹ���"<<endl;
	
	add_person(address_book);
	
	cout<<"ͨѶ¼"; 
	show_address_list(address_book);
	
	cout<<"�浵"<<endl;
	save_to_file(address_book); 
	//forward_list *rear = get_the_rear(address_book);
	//rear->people.show_info();
		
} 

void file_test()
{
	address_book = load_from_file();
	
	//system("cls");
	//system("pause");
	
	show_address_list(address_book);
}

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
	
	found->people.show_info();
	
	
	system("pause"); 
	
	//�������Ų����ͷ�� 
    show_address_list(address_book);
}

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
		    (*i)->people.show_info();	
		}	
	}
}

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

void lastone_test()
{
    address_book = load_from_file();
	show_address_list(address_book);
	
	forward_list *p = address_book->next;
	p = p->next->next;
	
	forward_list *last = get_the_lastone(address_book,p);
	
	cout<<"----------"<<endl;
	last->people.show_info();
	
	system("pause"); 
		
}

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

//----------------------------------------------------------------------------------------------

int main()
{
	//new_address_book_test();
	
	//file_test();
	
	//search_test(); 
	//search_test_more(); 
    
    //lastone_test(); 
	move_to_head_test();
    
	//mod_test();
	//mod_more_test();
	return 0;    	
} 
