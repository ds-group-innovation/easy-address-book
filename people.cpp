#include "people.h"

Cperson::Cperson() {}

Cperson::Cperson(string na,string addr,long long p_number,long int code):name(na),address(addr),phone_number(p_number),postcode(code) {}
Cperson::~Cperson() {}

//��ϵ����Ϣ��д,���Կ��������������
void Cperson::createInfo() {
	cout<<"���� - ��ַ - �绰���� - �������� "<<endl;
	cin>>this->name>>this->address>>this->phone_number>>this->postcode;
}

//��ʾ���������Ϣ
void Cperson::showInfo() {
	//cout<<"??";
	cout<<this->name<<"    "<<this->address<<"    "<<this->phone_number<<"    "<<this->postcode<<endl;
}

//������������Ϣ���ļ�
void Cperson::saveToFile(ofstream &output) {
	output<<this->name<<" "<<this->address<<" "<<this->phone_number<<" "<<this->postcode;
}

//��������ʱ�ж�����ѯ�������Ƿ�ʱ������
bool Cperson::sameName(string na) {
	if(this->name == na)
		return true;
	else
		return false;
}

//�޸Ķ��������Ϣ�����޸ĳ����������Ϣ
void Cperson::modInfo() {
	string flag;
	cout<<"�����޸�����˵ļ�ͥ��ַ��(yes or no)��: ";
	cin>>flag;
	if(flag == "true") {
		string addr;
		cout<<"�������µļ�ͥ��ַ��";
		cin>>addr;
		this->address = addr;
	}

	cout<<"�����޸�����˵ĵ绰������(yes or no)��: ";
	cin>>flag;
	if(flag == "true") {
		long long number;
		cout<<"�������µĵ绰���룺";
		cin>>number;
		this->phone_number = number;
	}

	cout<<"�����޸�����˵�����������(yes or no)��: ";
	cin>>flag;
	if(flag == "true") {
		long int code;
		cout<<"�������µ��������룺";
		cin>>code;
		this->postcode = code;
	}
}

//�����������
istream& operator>>(istream &input,Cperson &person) {
	cout<<"���� - ��ַ - �绰���� - �������� "<<endl;
	input>>person.name>>person.address>>person.phone_number>>person.postcode;
	return input;
}

ostream& operator<<(ostream &output,Cperson &person) {
	output<<person.name<<person.address<<person.phone_number<<person.postcode<<endl;
	return output;
}
