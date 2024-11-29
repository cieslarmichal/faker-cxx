#pragma once

namespace faker::string
{
enum class Uuid
{
    /*
     * Version 1: UUIDs using a timestamp and monotonic counter.
     * Version 3: UUIDs based on the MD5 hash of some data.
     * Version 4: UUIDs with random data.
     * Version 5: UUIDs based on the SHA1 hash of some data.
     * Version 6: UUIDs using a timestamp and monotonic counter (sortable).
     * Version 7: UUIDs using a Unix timestamp (sortable).
     * Version 8: UUIDs using user-defined data.
    */
    V1,
    V2,
    V3,
    V4,
    V5,
    V6,
    V7,
    V8
};
}
