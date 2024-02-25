#include <faker/types/language.h>
#include <stdexcept>

namespace faker {

std::string_view toString(Language language)
{
    switch (language) {
    case Language::English:
        return "English";
    case Language::Polish:
        return "Polish";
    case Language::Italian:
        return "Italian";
    case Language::French:
        return "French";
    case Language::German:
        return "German";
    case Language::Russian:
        return "Russian";
    case Language::Romanian:
        return "Romanian";
    case Language::Hindi:
        return "Hindi";
    case Language::Finnish:
        return "Finnish";
    case Language::Nepali:
        return "Nepali";
    case Language::Spanish:
        return "Spanish";
    case Language::Turkish:
        return "Turkish";
    case Language::Czech:
        return "Czech";
    case Language::Slovak:
        return "Slovak";
    case Language::Ukrainian:
        return "Ukrainian";
    case Language::Danish:
        return "Danish";
    case Language::Swedish:
        return "Swedish";
    case Language::Portuguese:
        return "Portuguese";
    case Language::Norwegian:
        return "Norwegian";
    case Language::Japanese:
        return "Japanese";
    case Language::Hungarian:
        return "Hungarian";
    case Language::Croatian:
        return "Croatian";
    case Language::Greek:
        return "Greek";
    case Language::Slovene:
        return "Slovene";
    case Language::Dutch:
        return "Dutch";
    case Language::Mandarin:
        return "Mandarin";
    case Language::Korean:
        return "Korean";
    case Language::Serbian:
        return "Serbian";
    case Language::Macedonian:
        return "Macedonian";
    case Language::Albanian:
        return "Albanian";
    case Language::Latvian:
        return "Latvian";
    case Language::Irish:
        return "Irish";
    case Language::Belarusian:
        return "Belarusian";
    case Language::Estonian:
        return "Estonian";
    default:
        throw std::invalid_argument("Invalid language");
    }
}
}
