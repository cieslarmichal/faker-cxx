#include "conversions.h"

namespace faker::utils {
double celsius_to_fahrenheit(double celsius) { return (celsius * 9.0 / 5.0) + 32; }

double kpa_to_psi(double kPa) { return kPa * 0.14503773773375; }

double mile_to_km(double miles) { return miles * 1.609344; }
}
