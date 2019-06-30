#ifndef ADDRESSLIST_H
#define ADDRESSLIST_H

#include<vector>
#include "people.h"
//ͨѶ¼��������(����) 
class forward_list{
	public:
	    Cperson people;
	    forward_list *next;
	//������Ĳ������Կ����÷�����װ���� 
};

forward_list *address_book;

//β�巨����,��ͷ�ڵ㣬���ڴ���ͨѶ¼ 
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
    //cout<<"��ͨѶ¼��"<<count<<"����"<<endl; 
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
		    cout<<"ɾ���ɹ�";
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
                    cout<<"ɾ���ɹ�";
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
	
	if(!read) return 1;//�ļ�������Ϊ�� 
    
	read.seekg(0, ios::end); //���ļ�ָ��ָ���ļ�ĩ�� 
    streampos fp = read.tellg(); //fpΪ�ļ�ָ���ƫ���� 
    if (int(fp) == 0) // ƫ����Ϊ0��֤���ļ�Ϊ�գ�Ϊ�״ν���ϵͳ
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


//���ԭ���ļ��������ݣ���׷�� 
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
 

//���ļ��м���ͨѶ¼ 
forward_list* load_from_file()
{
    ifstream read("addressBook.txt",ios::in);
    
    //�ж��ļ��Ƿ���� 
    if(!read)
    {
    	cout<<"ͨѶ¼�����ļ�addressBook.txt�����ڣ����ȴ����µ�ͨѶ¼���д浵";
		system("pause");
		return NULL; 
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

#endif
