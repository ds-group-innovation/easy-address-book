#ifndef PEOPLE_H
#define PEOPLE_H

#include<iostream>
#include<fstream>
using namespace std;

class Cperson {
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
		Cperson();

		Cperson(string na,string addr,long long p_number,long int code);
		~Cperson();

		//��ϵ����Ϣ��д,���Կ��������������
		void createInfo();

		//��ʾ���������Ϣ
		void showInfo();

		//������������Ϣ���ļ�
		void saveToFile(ofstream &output);

		//��������ʱ�ж�����ѯ�������Ƿ�ʱ������
		bool sameName(string na);

		//�޸Ķ��������Ϣ�����޸ĳ����������Ϣ
		void modInfo();

		//��������������������������Ϣ 
		friend istream& operator>>(istream &input,Cperson &person);

		friend ostream& operator<<(ostream &output,Cperson &person);
};

#endif
