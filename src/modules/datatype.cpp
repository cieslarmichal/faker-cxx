#include <faker/datatype.h>
#include <faker/number.h>

namespace faker::datatype {
bool boolean() { return number::decimal(0., 1.) > 0.5; }

bool boolean(double probability)
{
    if (probability != NAN) {
        double prob = probability;

        if (prob <= 0.f) {
            return false;
        }

        if (prob >= 1.f) {
            return true;
        }

        return number::decimal(0.f, 1.f) < prob;
    }

    return number::decimal(0.f, 1.f) < 0.5f;
}
}
