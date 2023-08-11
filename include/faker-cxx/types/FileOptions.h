#pragma once

namespace faker
{
struct FileOptions
{
    int extensionCount = 1;
    struct
    {
        int min = 1;
        int max = 1;
    } extensionRange;
};
}
