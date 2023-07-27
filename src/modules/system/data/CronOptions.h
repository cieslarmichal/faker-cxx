#pragma once

#include <string>
#include <vector>

namespace faker
{
struct CronOptions {
    bool includeYear = false;
    bool includeNonStandard = false;
};

const std::vector<std::string> CRON_DAY_OF_WEEK = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
}
