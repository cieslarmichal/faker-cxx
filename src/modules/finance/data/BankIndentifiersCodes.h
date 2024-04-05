#pragma once

#include <map>
#include <string>
#include <vector>

#include "faker-cxx/Finance.h"

namespace faker
{
const std::map<Finance::BicCountry, std::vector<std::string>> bankIdentifiersCodesMapping = {
    {Finance::BicCountry::Poland,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}},
    {Finance::BicCountry::UnitedStates,
     {"BOFAUS3N", "CITIUS33", "WELLSFARGO", "USBKUS44", "CHASUS33", "HSBCUS33", "PNCCUS33"}},
    {Finance::BicCountry::UnitedKingdom,
     {"BARCGB22", "HSBCKENW", "LOYDGB21", "NWBKGB2L", "RBOSGB2L", "HSBCGB2L", "DEUTGB2L"}},
    {Finance::BicCountry::Germany,
     {"DEUTDEFF", "DRESDEFF", "COBADEFF", "BYLADEM1", "GENODEFF", "HYVEDEMM", "MALADE51", "NOLADE21", "SOLADEST",
      "UNCRDEFF"}},
    {Finance::BicCountry::Romania,
     {"RNCBROBU", "BRDEROBU", "BTRLRO22", "PIRBROBU", "INGBROBU", "EXIMRO22", "CRDZROBU"}},
    {Finance::BicCountry::France,
     {"BNPAFRPP", "CEPAFRPP", "CRLYFRPP", "SOGEFRPP", "AGRIFRPP", "HSBDFRPP", "CCFRFRPP", "BNORDRPP", "CMCIFRPP"}},
    {Finance::BicCountry::Italy, {"UNCRITMM", "BCITITMM", "INTESA", "UBSPITPA", "BLOPIT22", "CITIITMX", "BNLIITRR"}},
    {Finance::BicCountry::Spain,
     {"CAIXESBB", "BBVAESMM", "SABSESBB", "BSCHESMM", "POPUESMM", "INGDESMM", "CITIES2X", "BCOEESMM"}},
    {Finance::BicCountry::Netherlands,
     {"ABNANL2A", "INGBNL2A", "RABONL2U", "TRIONL2U", "KNABNL2H", "SBINNL2X", "DEUTNL2N"}},
    {Finance::BicCountry::India,
     {"HDFCINBB", "ICICINBB", "SBININBB", "PNBAINBB", "UBININBB", "AXISINBB", "KKBKINBB", "YESBINBB", "IDBIINBB"}}};
}
