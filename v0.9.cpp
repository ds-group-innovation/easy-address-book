#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Cperson{
	public:
		string name;                //姓名 
		string address;             //地址 
		long long phone_number;     //电话号码 
	    long int postcode;          //邮政编码 
	public:
		//联系人信息填写 
		void create_info()
		{
			cout<<"姓名-地址-电话号码-邮政编码："<<endl; 
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
		//可修改除姓名外的信息 
		void mod_info()
		{
			string flag;
		    cout<<"你想修改这个人的家庭地址吗(true or false)？: ";
			cin>>flag;
			if(flag == "true")
			{
				string addr;
				cout<<"请输入新的家庭地址：";
				cin>>addr;
				this->address = addr;
			}
			
			cout<<"你想修改这个人的电话号码吗(true or false)？: ";
			cin>>flag;
			if(flag == "true")
			{
				long long number;
				cout<<"请输入新的电话号码："; 
				cin>>number;
				this->phone_number = number;
			}
			
			cout<<"你想修改这个人的邮政编码吗(true or false)？: ";
			cin>>flag;
			if(flag == "true")
			{
				long int code;
				cout<<"请输入新的邮政编码：";
				cin>>code;
				this->postcode = code;
			}
		}
};

//通讯录承载链表(单向) 
class forward_list{
	public:
	    Cperson people;
	    forward_list *next;
};

forward_list *address_book;

//尾插法建表,无头节点 
forward_list* create()
{
    forward_list *head=NULL;    //头节点 
	forward_list *rear=NULL;    //尾节点
	
	forward_list *temp;
	
	int hold_on;
	cout<<"输入新通讯录人员数量"<<endl;
	cin>>hold_on;//控制数量 
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

//添加人员到通讯录中,链表尾部添加 
void add_person(forward_list *list)
{
	forward_list *rear = get_the_rear(list);//通讯录链表尾部 
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

//显示通讯录 
void show_address_list(forward_list *list)
{
	system("cls");
	forward_list *p=list;
	cout<<"姓名-地址-电话号码-邮政编码："<<endl; 
	while(p != NULL)
	{
		p->people.show_info();
		p = p->next;
	}
	
	return ;
}

//获取通讯录已有人员数量 
int address_book_person_nums(forward_list *s)
{
	int count;
	forward_list *p=s;
	while(p)
	{
		count++;
		p = p->next;
	}
    cout<<"该通讯录有"<<count<<"个人"<<endl; 
    return count;
}

//返回找到第一个人
forward_list* move_to_head(forward_list *list,forward_list *s); 
forward_list* search_person(forward_list *list,string name)
{
    forward_list *p=list;
	while(p != NULL)
	{
		if(p->people.name == name)
		{
			//将被查询到的人移到表头
			//move_to_head(list,p); 
			return p;//仅仅返回第一个找到的人;
			//可用vector存储多个人; 
		}
		else
		{
			p = p->next;
		}
	}
	cout<<"通讯录中没有这个人";
	return 0;
}

//返回找到的多个人，同名 
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

//信息修改，单个人，依赖search_person 
void mod_person_info(forward_list *list,string name)
{
    forward_list *temp = search_person(list,name);
    if(temp)
    {
        temp->people.mod_info();
	    cout<<"修改完成"<<endl;	
	}
	else
	{
		cout<<"通讯录没有这个人"; 
	}
}

//信息修改，多个同名人，依赖search_people 
void mod_people_info(forward_list *list,string name)
{
    vector<forward_list*> found = search_people(address_book,name);
	if(found.empty())
	    cout<<"通讯录没有这个人"; 
	else
	{
	    if(found.size()>1)
	    {
	    	cout<<"找到"<<found.size()<<"个名字都为"<<name<<"的人,信息如下"<<endl;
			for(auto v:found)
			{
			    v->people.show_info();	
			}
			int z;
			cout<<"你想要修改第几个(1-"<<found.size()<<")人：";
			cin>>z;
			//有元素才可用下标法访问 
			found[z-1]->people.mod_info();
			
			cout<<"修改完成"<<endl; 
		}
		else
		{
		    for(auto v:found)
			    v->people.mod_info();
	        cout<<"修改完成"<<endl;	
		}    
	}
	system("pause"); 	
}

//找到s的上一位朋友 
forward_list* get_the_lastone(forward_list *list,forward_list *s)
{
	forward_list *p = s,*temp;
	
	//一、二位 
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

//s移到list表表头，返回新表头 
forward_list* move_to_head(forward_list *list,forward_list *s)
{
	forward_list *temp,*lastone;
	
	temp = s;
	lastone = get_the_lastone(list,s);
	
    if(s->next==NULL)//它是表尾
	{
		temp->next = list;
		lastone->next = NULL;
		return temp; 
	}
	else if(s == list)//表头 
	    return list; 
	else//不是表尾、表头 
	{
		lastone->next = temp->next;
		temp->next = list;
		return temp;
	}	
} 

//存档 
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

//读取
forward_list* load_from_file()
{
    ifstream read("addressBook.txt",ios::in);
    
    //判断文件是否存在 
    if(!read)
    {
    	cout<<"addressBook.txt文件不存在";
		system("pause");
		exit(0); 
	}
	
	forward_list *head = NULL;
	forward_list *rear = NULL;
	
	while(!read.eof())
	{
		string name;                //姓名 
	    string address;             //地址 
	    long long phone_number;     //电话号码 
	    long int postcode;          //邮政编码 
	
	    //读取信息 
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
//以下是测试 

void new_address_book_test()
{
	address_book = create();
	
	cout<<"加个人"<<endl;
	
	add_person(address_book);
	
	cout<<"通讯录"; 
	show_address_list(address_book);
	
	cout<<"存档"<<endl;
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
	cout<<"请输入要查找的人的姓名: ";
	cin>>name;
	forward_list* found = search_person(address_book,name);
	 
	
	cout<<"这个比的个人信息"<<endl; 
	cout<<"姓名-地址-电话号码-邮政编码："<<endl;
	
	found->people.show_info();
	
	
	system("pause"); 
	
	//被查的人挪到表头后 
    show_address_list(address_book);
}

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
		    (*i)->people.show_info();	
		}	
	}
}

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
	cout<<"请输入要查找的人的姓名: ";
	cin>>name;
	forward_list *found = search_person(address_book,name);
	
	system("pause");
	//移动被搞过的人
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
