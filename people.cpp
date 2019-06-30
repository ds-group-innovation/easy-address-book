#include "people.h"

Cperson::Cperson() {}

Cperson::Cperson(string na,string addr,long long p_number,long int code):name(na),address(addr),phone_number(p_number),postcode(code) {}
Cperson::~Cperson() {}

//联系人信息填写,可以考虑重载流运算符
void Cperson::createInfo() {
	cout<<"姓名 - 地址 - 电话号码 - 邮政编码 "<<endl;
	cin>>this->name>>this->address>>this->phone_number>>this->postcode;
}

//显示对象个人信息
void Cperson::showInfo() {
	//cout<<"??";
	cout<<this->name<<"    "<<this->address<<"    "<<this->phone_number<<"    "<<this->postcode<<endl;
}

//保存对象个人信息到文件
void Cperson::saveToFile(ofstream &output) {
	output<<this->name<<" "<<this->address<<" "<<this->phone_number<<" "<<this->postcode;
}

//用于搜索时判断所查询的姓名是否时本对象
bool Cperson::sameName(string na) {
	if(this->name == na)
		return true;
	else
		return false;
}

//修改对象个人信息，可修改除姓名外的信息
void Cperson::modInfo() {
	string flag;
	cout<<"你想修改这个人的家庭地址吗(yes or no)？: ";
	cin>>flag;
	if(flag == "true") {
		string addr;
		cout<<"请输入新的家庭地址：";
		cin>>addr;
		this->address = addr;
	}

	cout<<"你想修改这个人的电话号码吗(yes or no)？: ";
	cin>>flag;
	if(flag == "true") {
		long long number;
		cout<<"请输入新的电话号码：";
		cin>>number;
		this->phone_number = number;
	}

	cout<<"你想修改这个人的邮政编码吗(yes or no)？: ";
	cin>>flag;
	if(flag == "true") {
		long int code;
		cout<<"请输入新的邮政编码：";
		cin>>code;
		this->postcode = code;
	}
}

//重载流运算符
istream& operator>>(istream &input,Cperson &person) {
	cout<<"姓名 - 地址 - 电话号码 - 邮政编码 "<<endl;
	input>>person.name>>person.address>>person.phone_number>>person.postcode;
	return input;
}

ostream& operator<<(ostream &output,Cperson &person) {
	output<<person.name<<person.address<<person.phone_number<<person.postcode<<endl;
	return output;
}
