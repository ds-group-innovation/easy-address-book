/*
  * ϵͳ���ģʽ������ģʽ
  * �˵�ģ�� 
  * �û���¼����
  * OAuth��֤��ģ��ʵ��
  * OOP��װ���̳С���̬���� 
*/ 
class Menu{
	public:
		//Menu(){}
		//~Menu(){}
		virtual void showMenu() = 0;
};

/*
  * ��¼�˵�����¼�ɹ����ɻ�ù���ԱȨ�ޣ�����Ϊ��ͨ�û� 
  * �ɿ��Ǽ�����ʱ��¼���ܣ���ͨ�û�����Ϊ����Ա 
*/ 
class LoginMenu:public Menu{
	protected: 
	    int select;//ѡ��1������Ա��¼��2����ͨ�û���ֱ�ӽ���ͨ�û��Ĳ˵��� 
	public:
	    void showMenu()
		{
			return ;
		} 
};

/*
  * ����Ա
  * CURD��Create��Update��Read��Delete����Ȩ�޶���
  * ����ɾ���ġ��� 
*/ 
class AdminMenu:public Menu{
	protected:
		
};

/*
  * ��ͨ�û�
  * ֻ�в�ѯȨ��
  * ��ѯҪ������û�ѡ����ʾĳ���˵�ĳ���ض���Ϣ��ȫ����Ϣ 
*/ 
class AutuMenu:public Menu{
	protected:
}; 
