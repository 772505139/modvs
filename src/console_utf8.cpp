#include "console_utf8.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <clocale>

namespace demo {

void InitConsoleUtf8()
{
#ifdef _WIN32
    // 1) 让控制台按 UTF-8 接收/显示字节流
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

} // namespace demo
