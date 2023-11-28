#pragma once

#include "Bio.h"
#include "BioHelper.h"


namespace faker
{
    bool BioHelper::checkTokenFormat(const std::string& bio)
    {
        std::smatch matches;
        // 
        if (std::regex_match(bio, matches, firstRegex)){
            // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part vector.
            bio_part.
            matches[0]
            
        }
    }
}
