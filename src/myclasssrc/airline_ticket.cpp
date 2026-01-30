//告诉编译器这是一个模块实现单元
module airline_ticket;

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

//2：用 构造函数初始化器 列表 初始化数据成员
AirlineTicket::AirlineTicket()
    : m_passengerName("unkown Passenger") 
    , m_numberOfMiles(0)
    , m_hasEliteSuperRewardsStatus(false)
{}


//3：另一种初始化数据成员的方式
// AirlineTicket::AirlineTicket()
// {
//     //initialize data members if needed
//     m_passengerName = "unkown Passenger";
//     m_numberOfMiles = 0;
//     m_hasEliteSuperRewardsStatus = false;
// }

AirlineTicket::~AirlineTicket()
{
    //destructor body if needed
}

double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardsStatus()) {
        //Elite Super Rewards members fly for free!
        return 0.0;
    }
    // The cost of the ticket is the number of miles times 0.1
    // Real airlines probably have more complex pricing formulas!
    return getNumberOfMiles() * 0.1;
}

std::string AirlineTicket::getPassengerName() const { return m_passengerName; }
void AirlineTicket::setPassengerName(std::string name) { m_passengerName = name; }

int AirlineTicket::getNumberOfMiles() const { return m_numberOfMiles; }
void AirlineTicket::setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

bool AirlineTicket::hasEliteSuperRewardsStatus() const { return m_hasEliteSuperRewardsStatus; }
void AirlineTicket::setEliteSuperRewardsStatus(bool status) { m_hasEliteSuperRewardsStatus = status; }
//other get and set methods have a similar implementation