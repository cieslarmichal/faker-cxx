#include "../common/random.h"
#include <cmath>
#include <faker/datatype.h>
#include <faker/number.h>

namespace faker::datatype {

bool boolean() { return random::boolean(0.5f); }

bool boolean(double prob) { return random::boolean(prob); }
}
