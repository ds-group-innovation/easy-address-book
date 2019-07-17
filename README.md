# 简易通讯录程序（控制台划水~~~）

说明：本程序使用 [Dev-C++](https://sourceforge.net/projects/dev-cpp/)（v5.11） 进行开发，`-std=c++11`。

## UML类图

![]()

## 文件组织结构
```
addressBook.dev           # 项目文件
    addressBook.txt       # 通讯录数据文件
    addresslist.h         # 此处定义了承载通讯录的单链表和对链表操作的函数
    main.cpp              # 主文件
    menu.cpp              # 各个菜单类的实现：LoginMenu、AdminMenu、AuthMenu，实现用于创建工厂实例的creat_menu函数
    menu.h                # 此处定义了与操作菜单相关的类与类内方法，菜单使用简单工厂模式设计，工厂类为HanddleAddressBook。
    people.h              # 定义Person类，以及与通讯录人员有关的方法
    people.cpp            # 实现Person类以及相关方法
    test.cpp              # 测试函数的实现，有点不正规
    test.h
```

**这里所使用的设计模式：简单工厂模式，好像有点不对劲。。。😂**