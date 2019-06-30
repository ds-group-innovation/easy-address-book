#ifndef ADDRESSLIST_H
#define ADDRESSLIST_H

#include<vector>
#include "people.h"
//通讯录承载链表(单向) 
class forward_list{
	public:
	    Cperson people;
	    forward_list *next;
	//对链表的操作可以考虑用方法封装起来 
};

forward_list *address_book;

//尾插法建表,无头节点，用于创建通讯录 
forward_list* create()
{
    forward_list *head=NULL;    //头节点 
	forward_list *rear=NULL;    //尾节点
	
	forward_list *temp;
	
	int hold_on;
	//控制初始通讯录人数 
	cout<<"输入新通讯录人员数量"<<endl;
	cin>>hold_on;//控制数量 
	while(hold_on)
	{
	    Cperson new_person;
		//new_person.createInfo();
		cin>>new_person;
		
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

//获取通讯录链表表尾的Cperson对象 ，add_person中有用到 
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

//添加人员到通讯录中,在链表尾部添加 
void add_person(forward_list *list)
{
	forward_list *rear = get_the_rear(list);//通讯录链表尾部 
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

//显示通讯录链表 
void show_address_list(forward_list *list)
{
	//system("cls");
	forward_list *s=list;
	cout<<"姓名-地址-电话号码-邮政编码："<<endl; 
	while(s != NULL)
	{
		s->people.showInfo();
		s = s->next;
	}
	
	return ;
}


//获取通讯录链表已有人员数量 
int address_book_person_nums(forward_list *s)
{
	int count;
	forward_list *p=s;
	while(p)
	{
		count++;
		p = p->next;
	}
    //cout<<"该通讯录有"<<count<<"个人"<<endl; 
    return count;
}

//搜索函数，按名字搜索，返回找到第一个人，未考虑同名情况 
forward_list* move_to_head(forward_list *list,forward_list *s); 
forward_list* search_person(forward_list *list,string name)
{
    forward_list *p=list;
	while(p != NULL)
	{
		if(p->people.sameName(name))
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

//返回找到的多个人，考虑同名 
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

//信息修改，单个人，依赖search_person 
void mod_person_info(forward_list *list,string name)
{
    forward_list *temp = search_person(list,name);
    if(temp)
    {
        temp->people.modInfo();
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
			    v->people.showInfo();	
			}
			int z;
			cout<<"你想要修改第几个(1-"<<found.size()<<")人：";
			cin>>z;
			//有元素才可用下标法访问 
			found[z-1]->people.modInfo();
			
			cout<<"修改完成"<<endl; 
		}
		else
		{
		    for(auto v:found)
			    v->people.modInfo();
	        cout<<"修改完成"<<endl;	
		}    
	}
	system("pause"); 	
}

//找到所给人（s）在通讯录链表的上一个位置的人，move_to_head中有用到 
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

//将s移到list表表头，返回新表头 
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

//仅删除找到的第一个姓名为name的人 
forward_list* delete_person(forward_list *list,string name)
{
    forward_list *p;
    forward_list *temp;//用来存放被删除元素的前一个结点 
	
	p = list;
	temp = p;
	
	if(p->people.sameName(name))//就是表头
	{
		//我佛了，不用返回值有个问题。。。。。。 
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

//找到多个 
forward_list* delete_people(forward_list *list,string name)
{
	vector<forward_list*> v_temp = search_people(list,name);
    if(!v_temp.empty())
	{
		cout<<"通讯录中有多个名为"<<name<<"的人，信息如下："<<endl;
		for(auto v:v_temp)
		    v->people.showInfo();
		cout<<"你想要删除第几个的信息？(1-"<<v_temp.size()<<")：";
		int z;
		cin>>z;
		if(z==1)
		{
		    forward_list *p;
            forward_list *temp;//用来存放被删除元素的前一个结点 
	        p = list;
	        temp = p;
	        
	        p = p->next;	
		    delete temp;
		    cout<<"删除成功";
		    return p;
		}
		else
		{
			forward_list *p;
            forward_list *temp;//用来存放被删除元素的前一个结点 
	        p = list;
	        temp = p;
			    
		    p = p->next;
			while(p != NULL)
	        { 
	            if(p == v_temp[z-1])
		        {
                    temp->next = p->next;
                    delete p;
                    cout<<"删除成功";
                    return list;
		        }
		        temp = p;
		        p = p->next;	
	        }   	
		}  
	}
	cout<<"通讯录中不存在名字为 "<<name<<" 的人"<<endl; 
	return list;   
}


//将通讯录存到文件中 
void save_to_file(forward_list *list)
{
    ofstream out("addressBook.txt", ios::out);
    //ofstream out("addressBook.txt",ios::app); 
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

bool is_empty_file()
{
	ifstream read("addressBook.txt", ios::in);
	
	if(!read) return 1;//文件不存在为真 
    
	read.seekg(0, ios::end); //将文件指针指向文件末端 
    streampos fp = read.tellg(); //fp为文件指针的偏移量 
    if (int(fp) == 0) // 偏移量为0，证明文件为空，为首次进入系统
    {
	   read.close();    
	   return true;
    }
	else
    {
    	read.close();
    	return false;
	}
}


//如果原来文件已有内容，则追加 
void save_to_file_not_empty(forward_list *list)
{
    ofstream out("addressBook.txt",ios::app); 
    out<<endl;
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
	out.close();   
}
 

//从文件中加载通讯录 
forward_list* load_from_file()
{
    ifstream read("addressBook.txt",ios::in);
    
    //判断文件是否存在 
    if(!read)
    {
    	cout<<"通讯录数据文件addressBook.txt不存在，请先创建新的通讯录进行存档";
		system("pause");
		return NULL; 
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
	
	    Cperson new_person(name,address,phone_number,postcode);
	    
	    //这部分考虑用构造函数 
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

#endif
