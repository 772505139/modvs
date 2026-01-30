export module airline_ticket;

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

export class AirlineTicket
{
    public:
		AirlineTicket();
		~AirlineTicket();

        double calculatePriceInDollars() const;

        std::string getPassengerName() const;
        void setPassengerName(std::string name);

        int getNumberOfMiles() const;
        void setNumberOfMiles(int miles);

        bool hasEliteSuperRewardsStatus() const;
        void setEliteSuperRewardsStatus(bool status);

    private:
        std::string m_passengerName;
        int m_numberOfMiles;
        bool m_hasEliteSuperRewardsStatus;

        //1、在类内初始化数据成员
        //std::string m_passengerName{"unkown Passenger"}; 
        //int m_numberOfMiles{0};
        //bool m_hasEliteSuperRewardsStatus{false};
};


//也可以把实现直接放在接口文件里：
export class AirlineTicketInline
{
    public:
        AirlineTicketInline() {}

        ~AirlineTicketInline() {}

        double calculatePriceInDollars()
        {
            if (hasEliteSuperRewardsStatus()) {
                return 0.0;
            }
            return getNumberOfMiles() * 0.1;
        }

        std::string getPassengerName() { return m_passengerName; }
        void setPassengerName(std::string name) { m_passengerName = name; }

        int getNumberOfMiles() { return m_numberOfMiles; }
        void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

        bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
        void setEliteSuperRewardsStatus(bool status) { m_hasEliteSuperRewardsStatus = status; }

    private:
        std::string m_passengerName {"unkown Passenger"};
        int m_numberOfMiles {0};
        bool m_hasEliteSuperRewardsStatus {false};
};