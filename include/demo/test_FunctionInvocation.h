#pragma once
//#include <compare>

namespace demo {
    void myFunction1(int i, char c);
    int addNumbers(int a, int b);
    double addNumbers(double a, double b);
    [[nodiscard("Return value of myFunction2() should not be ignored")]] int myFunction2();
    int myFunction3(int param1, [[maybe_unused]] double param2);
    [[noreturn]] void forceProgramTermination();
    bool isDongleAvailable();
    bool isFeatureLicensed(int featureId);
    [[deprecated("This function is deprecated and should not be used.lgw")]] void myFunction3();
}