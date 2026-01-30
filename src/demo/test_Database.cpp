#include "demo/testAll.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;
import database;
import employee;

using namespace std;
using namespace Records;

int Test_Database()
{
    cout << "测试Database类" << endl;
    Database empDB;

    empDB.addEmployee("Larry", "Greenwald");
    empDB.addEmployee("Jane", "Smith");
    empDB.addEmployee("John", "Doe");

    empDB.getEmployee(1001).promote(5000);
    empDB.getEmployee("Jane", "Smith").promote(7000);
    empDB.getEmployee("John", "Doe").demote(2000);
    empDB.getEmployee("John", "Doe").fire();

    cout << "\n显示所有员工：" << endl;
    empDB.displayAll();

    cout << "\n显示现有员工：" << endl;
    empDB.displayCurrent();

    cout << "\n显示前员工：" << endl;
    empDB.displayFormer();



    cout << "测试Database类2" << endl;
    Employee& emp1 = empDB.addEmployee("Alice", "Johnson");
    emp1.fire();

    Employee& emp2 = empDB.addEmployee("Bob", "Brown");
    emp2.setSalary(60000);

    Employee& emp3 = empDB.addEmployee("Charlie", "Davis");
    emp3.setSalary(1);
    emp3.promote();

    cout << "\n显示所有员工：" << endl;
    empDB.displayAll();

    cout << "\n显示现有员工：" << endl;
    empDB.displayCurrent();
    cout << "\n显示前员工：" << endl;
    empDB.displayFormer();


    cin.get();
    return 0;
}