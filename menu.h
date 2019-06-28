/*
  * 系统设计模式：工厂模式
  * 菜单模块 
  * 用户登录？？
  * OAuth认证简单模仿实现
  * OOP封装、继承、多态体验 
*/ 
class Menu{
	public:
		//Menu(){}
		//~Menu(){}
		virtual void showMenu() = 0;
};

/*
  * 登录菜单，登录成功即可获得管理员权限，否则为普通用户 
  * 可考虑加入临时登录功能，普通用户升级为管理员 
*/ 
class LoginMenu:public Menu{
	protected: 
	    int select;//选择：1、管理员登录；2、普通用户（直接进普通用户的菜单） 
	public:
	    void showMenu()
		{
			return ;
		} 
};

/*
  * 管理员
  * CURD（Create、Update、Read、Delete）的权限都有
  * 增、删、改、查 
*/ 
class AdminMenu:public Menu{
	protected:
		
};

/*
  * 普通用户
  * 只有查询权限
  * 查询要求根据用户选择显示某个人的某个特定信息或全部信息 
*/ 
class AutuMenu:public Menu{
	protected:
}; 
