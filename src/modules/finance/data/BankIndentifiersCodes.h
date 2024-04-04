#pragma once

#include <map>
#include <string>
#include <vector>

#include "faker-cxx/types/BicCountry.h"

namespace faker
{
const std::map<BicCountry, std::vector<std::string>> bankIdentifiersCodesMapping = {
    {BicCountry::Poland,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}},
    {BicCountry::United_States, {"BOFAUS3N", "CITIUS33", "WELLSFARGO", "USBKUS44", "CHASUS33", "HSBCUS33", "PNCCUS33"}},
    {BicCountry::United_Kingdom, {"BARCGB22", "HSBCKENW", "LOYDGB21", "NWBKGB2L", "RBOSGB2L", "HSBCGB2L", "DEUTGB2L"}},
    {BicCountry::Germany,
     {"DEUTDEFF", "DRESDEFF", "COBADEFF", "BYLADEM1", "GENODEFF", "HYVEDEMM", "MALADE51", "NOLADE21", "SOLADEST",
      "UNCRDEFF"}},
    {BicCountry::Romania, {"RNCBROBU", "BRDEROBU", "BTRLRO22", "PIRBROBU", "INGBROBU", "EXIMRO22", "CRDZROBU"}},
    {BicCountry::France,
     {"BNPAFRPP", "CEPAFRPP", "CRLYFRPP", "SOGEFRPP", "AGRIFRPP", "HSBDFRPP", "CCFRFRPP", "BNORDRPP", "CMCIFRPP"}},
    {BicCountry::Italy, {"UNCRITMM", "BCITITMM", "INTESA", "UBSPITPA", "BLOPIT22", "CITIITMX", "BNLIITRR"}},
    {BicCountry::Spain,
     {"CAIXESBB", "BBVAESMM", "SABSESBB", "BSCHESMM", "POPUESMM", "INGDESMM", "CITIES2X", "BCOEESMM"}},
    {BicCountry::Netherlands, {"ABNANL2A", "INGBNL2A", "RABONL2U", "TRIONL2U", "KNABNL2H", "SBINNL2X", "DEUTNL2N"}},
    {BicCountry::India,
     {"HDFCINBB", "ICICINBB", "SBININBB", "PNBAINBB", "UBININBB", "AXISINBB", "KKBKINBB", "YESBINBB", "IDBIINBB"}}};
}
