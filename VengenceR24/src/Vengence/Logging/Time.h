#pragma once

#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>

const char* vget_fmt_time()
{
    static char buffer[80];
    auto now = std::chrono::system_clock::now();
    auto timeNow = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    struct std::tm timeInfo;
    localtime_s(&timeInfo, &timeNow);

    std::strftime(buffer, sizeof(buffer), "%H:%M:%S.", &timeInfo);

    sprintf_s(buffer + 9, sizeof(buffer) - 9, "%03d", static_cast<int>(ms.count()));

    return buffer;
}