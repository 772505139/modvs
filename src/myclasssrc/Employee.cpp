module employee;    //首行声明：本模块名。
import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;
using namespace std;

namespace Records {
    Employee::Employee(const string& firstName, const string& lastName)
        : m_firstName{firstName}, m_lastName{lastName}
    {
    }

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() { m_hired = true; }
    void Employee::fire() { m_hired = false; }

    void Employee::display() const
    {
        cout << format("Employee: {} {}", getFirstName(), getLastName()) << endl;
        cout << format("---------------------") << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << '\n';
        cout << format("Employee Number: {}", getEmployeeNumber()) << endl;
        cout << format("Salary: {}\n", getSalary()) << endl;
    }

    //Getter and setters
    void Employee::setFirstName(const string& firstName)
    {
        m_firstName = firstName;
    }

    const string& Employee::getFirstName() const
    {
        return m_firstName;
    }

    void Employee::setLastName(const string& lastName)
    {
        m_lastName = lastName;
    }

    const string& Employee::getLastName() const
    {
        return m_lastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        m_employeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const
    {
        return m_employeeNumber;
    }

    void Employee::setSalary(int newSalary)
    {
        m_salary = newSalary;
    }

    int Employee::getSalary() const
    {
        return m_salary;
    }

    bool Employee::isHired() const
    {
        return m_hired;
    }


}