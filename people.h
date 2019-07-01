#ifndef PEOPLE_H
#define PEOPLE_H

#include<iostream>
#include<fstream>
using namespace std;

class Cperson {
		//保护成员
		//对对象本身的操作尽量封装起来，不对外开放
		//类内的方法可以考虑用驼峰命名法，便于区分
	protected:
		string name;                //姓名
		string address;             //地址
		long long phone_number;     //电话号码
		long int postcode;          //邮政编码
	public:
		//构造函数
		Cperson();

		Cperson(string na,string addr,long long p_number,long int code);
		~Cperson();

		//联系人信息填写,可以考虑重载流运算符
		void createInfo();

		//显示对象个人信息
		void showInfo();

		//保存对象个人信息到文件
		void saveToFile(ofstream &output);

		//用于搜索时判断所查询的姓名是否时本对象
		bool sameName(string na);

		//修改对象个人信息，可修改除姓名外的信息
		void modInfo();

		//重载流运算符，输入输出个人信息 
		friend istream& operator>>(istream &input,Cperson &person);

		friend ostream& operator<<(ostream &output,Cperson &person);
};

#endif
