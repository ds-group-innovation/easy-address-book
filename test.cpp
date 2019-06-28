#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*  dev���뻷��:  -std=c++11  */ 

//�����������ھۣ������
//ģ�����ϵԽ�࣬�������Խǿ 

class Cperson{
	//������Ա
	//�Զ�����Ĳ���������װ�����������⿪��
	//���ڵķ������Կ������շ����������������� 
	protected:
		string name;                //���� 
		string address;             //��ַ 
		long long phone_number;     //�绰���� 
	    long int postcode;          //�������� 
	public:
		//���캯�� 
		Cperson(){}
		
		Cperson(string na,string addr,long long p_number,long int code):name(na),address(addr),phone_number(p_number),postcode(code){}
		~Cperson(){}
		
		//��ϵ����Ϣ��д,���Կ�������������� 
		void createInfo()
		{
			cout<<"����-��ַ-�绰����-�������룺"<<endl; 
			cin>>this->name>>this->address>>this->phone_number>>this->postcode;
		}
		
		//��ʾ���������Ϣ 
		void showInfo()
		{
			//cout<<"??";
		    cout<<this->name<<"    "<<this->address<<"    "<<this->phone_number<<"    "<<this->postcode<<endl;	
		}
		
		//������������Ϣ���ļ� 
		void saveToFile(ofstream &output)
		{
			output<<this->name<<" "<<this->address<<" "<<this->phone_number<<" "<<this->postcode;
		}
		
		//��������ʱ�ж�����ѯ�������Ƿ�ʱ������ 
		bool sameName(string na)
		{
		    if(this->name == na)
			    return true;
			else
			    return false;	
		}
		 
		//�޸Ķ��������Ϣ�����޸ĳ����������Ϣ 
		void modInfo()
		{
			string flag;
		    cout<<"�����޸�����˵ļ�ͥ��ַ��(yes or no)��: ";
			cin>>flag;
			if(flag == "true")
			{
				string addr;
				cout<<"�������µļ�ͥ��ַ��";
				cin>>addr;
				this->address = addr;
			}
			
			cout<<"�����޸�����˵ĵ绰������(yes or no)��: ";
			cin>>flag;
			if(flag == "true")
			{
				long long number;
				cout<<"�������µĵ绰���룺"; 
				cin>>number;
				this->phone_number = number;
			}
			
			cout<<"�����޸�����˵�����������(yes or no)��: ";
			cin>>flag;
			if(flag == "true")
			{
				long int code;
				cout<<"�������µ��������룺";
				cin>>code;
				this->postcode = code;
			}
		}
		
		//����������� 
		friend istream& operator>>(istream &input,Cperson &person)  
		{
			input>>person.name>>person.address>>person.phone_number>>person.postcode;
			return input;
		}
		
		friend ostream& operator<<(ostream &output,Cperson &person)
		{
			output<<person.name<<person.address<<person.phone_number<<person.postcode<<endl;
		    return output;	
		} 
};

//ͨѶ¼��������(����) 
class forward_list{
	public:
	    Cperson people;
	    forward_list *next;
	//������Ĳ������Կ����÷�����װ���� 
};

forward_list *address_book;

//β�巨����,��ͷ�ڵ㣬���ڴ���ͨѶ¼��ȫ�µģ� 
forward_list* create()
{
    forward_list *head=NULL;    //ͷ�ڵ� 
	forward_list *rear=NULL;    //β�ڵ�
	
	forward_list *temp;
	
	int hold_on;
	//���Ƴ�ʼͨѶ¼���� 
	cout<<"������ͨѶ¼��Ա����"<<endl;
	cin>>hold_on;//�������� 
	while(hold_on)
	{
	    Cperson new_person;
		new_person.createInfo();
		
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

//��ȡͨѶ¼�����β��Cperson���� ��add_person�����õ� 
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

//�����Ա��ͨѶ¼��,������β����� 
void add_person(forward_list *list)
{
	forward_list *rear = get_the_rear(list);//ͨѶ¼����β�� 
    forward_list *temp;
    
	Cperson new_person;
    new_person.createInfo();
    
    
	temp = new forward_list;
	temp->people = new_person;
	temp->next = NULL;
	
	rear->next = temp; 
    
    //cout<<endl;
    //rear->next->people = new_person;
    //rear->next->next = NULL;
    
	return ;	
}

//��ʾͨѶ¼���� 
void show_address_list(forward_list *list)
{
	//system("cls");
	forward_list *s=list;
	cout<<"����-��ַ-�绰����-�������룺"<<endl; 
	while(s != NULL)
	{
		s->people.showInfo();
		s = s->next;
	}
	
	return ;
}

//��ȡͨѶ¼����������Ա���� 
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

//���������������������������ҵ���һ���ˣ�δ����ͬ����� 
forward_list* move_to_head(forward_list *list,forward_list *s); 
forward_list* search_person(forward_list *list,string name)
{
    forward_list *p=list;
	while(p != NULL)
	{
		if(p->people.sameName(name))
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

//�����ҵ��Ķ���ˣ�����ͬ�� 
vector<forward_list*> search_people(forward_list *list,string name)
{
    forward_list *p=list;
	vector<forward_list*> v_temp;
	while(p != NULL)
	{
		if(p->people.sameName(name))
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
        temp->people.modInfo();
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
			    v->people.showInfo();	
			}
			int z;
			cout<<"����Ҫ�޸ĵڼ���(1-"<<found.size()<<")�ˣ�";
			cin>>z;
			//��Ԫ�زſ����±귨���� 
			found[z-1]->people.modInfo();
			
			cout<<"�޸����"<<endl; 
		}
		else
		{
		    for(auto v:found)
			    v->people.modInfo();
	        cout<<"�޸����"<<endl;	
		}    
	}
	system("pause"); 	
}

//�ҵ������ˣ�s����ͨѶ¼�������һ��λ�õ��ˣ�move_to_head�����õ� 
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

//��s�Ƶ�list���ͷ�������±�ͷ 
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

//��ɾ���ҵ��ĵ�һ������Ϊname���� 
forward_list* delete_person(forward_list *list,string name)
{
    forward_list *p;
    forward_list *temp;//������ű�ɾ��Ԫ�ص�ǰһ����� 
	
	p = list;
	temp = p;
	
	if(p->people.sameName(name))//���Ǳ�ͷ
	{
		//�ҷ��ˣ����÷���ֵ�и����⡣���������� 
	    p = p->next;	
		delete temp;
		return p;
	} 
	
	p = p->next;
    while(p != NULL)
	{ 
	    if(p->people.sameName(name))
		{
            temp->next = p->next;
            delete p;
            return list;
		}
		temp = p;
		p = p->next;	
	}
	return list; 
}

//�ҵ���� 
forward_list* delete_people(forward_list *list,string name)
{
	vector<forward_list*> v_temp = search_people(list,name);
    if(!v_temp.empty())
	{
		cout<<"ͨѶ¼���ж����Ϊ"<<name<<"���ˣ���Ϣ���£�"<<endl;
		for(auto v:v_temp)
		    v->people.showInfo();
		cout<<"����Ҫɾ���ڼ�������Ϣ��(1-"<<v_temp.size()<<")��";
		int z;
		cin>>z;
		if(z==1)
		{
		    forward_list *p;
            forward_list *temp;//������ű�ɾ��Ԫ�ص�ǰһ����� 
	        p = list;
	        temp = p;
	        
	        p = p->next;	
		    delete temp;
		    return p;
		}
		else
		{
			forward_list *p;
            forward_list *temp;//������ű�ɾ��Ԫ�ص�ǰһ����� 
	        p = list;
	        temp = p;
			    
		    p = p->next;
			while(p != NULL)
	        { 
	            if(p == v_temp[z-1])
		        {
                    temp->next = p->next;
                    delete p;
                    return list;
		        }
		        temp = p;
		        p = p->next;	
	        }   	
		}  
	}
	cout<<"ͨѶ¼�в���������Ϊ "<<name<<" ����"<<endl; 
	return list;   
}


//��ͨѶ¼�浽�ļ��� 
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

//���ļ��м���ͨѶ¼ 
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
	
	    Cperson new_person(name,address,phone_number,postcode);
	    
	    //�ⲿ�ֿ����ù��캯�� 
	    /*
		new_person.name = name;
	    new_person.address = address;
	    new_person.phone_number = phone_number;
	    new_person.postcode = postcode; 
	    */
	    
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


//----------------------------------------------------------------------------------------------

int main()
{
	//new_address_book_test();
	
	//file_test();
	
	//search_test(); 
	//search_test_more(); 
    
    //lastone_test(); 
	//move_to_head_test();
    
	//mod_test();
	//mod_more_test();
	
	//delete_test(); 
	delete_more_test();
	return 0;    	
} 
