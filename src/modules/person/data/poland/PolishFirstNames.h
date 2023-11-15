#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> polishMalesFirstNames = {
    "Aaron",      "Abraham",     "Adam",        "Adrian",     "Atanazy",    "Agaton",      "Alan",       "Albert",
    "Aleksander", "Aleksy",      "Alfred",      "Alwar",      "Ambroży",    "Anatol",      "Andrzej",    "Antoni",
    "Apollinary", "Apollo",      "Arkady",      "Arkadiusz",  "Archibald",  "Arystarch",   "Arnold",     "Arseniusz",
    "Artur",      "August",      "Baldwin",     "Bazyli",     "Benedykt",   "Beniamin",    "Bernard",    "Bertrand",
    "Bertram",    "Borys",       "Brajan",      "Bruno",      "Cezary",     "Cecyliusz",   "Karol",      "Krystian",
    "Krzysztof",  "Klarencjusz", "Klaudiusz",   "Klemens",    "Konrad",     "Konstanty",   "Konstantyn", "Kornel",
    "Korneliusz", "Korneli",     "Cyryl",       "Cyrus",      "Damian",     "Daniel",      "Dariusz",    "Dawid",
    "Dionizy",    "Demetriusz",  "Dominik",     "Donald",     "Dorian",     "Edgar",       "Edmund",     "Edward",
    "Edwin",      "Efrem",       "Efraim",      "Eliasz",     "Eleazar",    "Emil",        "Emanuel",    "Erast",
    "Ernest",     "Eugeniusz",   "Eustracjusz", "Fabian",     "Feliks",     "Florian",     "Franciszek", "Fryderyk",
    "Gabriel",    "Gedeon",      "Galfryd",     "Jerzy",      "Gerald",     "Gerazym",     "Gilbert",    "Gonsalwy",
    "Grzegorz",   "Gwido",       "Harald",      "Henryk",     "Herbert",    "Herman",      "Hilary",     "Horacy",
    "Hubert",     "Hugo",        "Ignacy",      "Igor",       "Hilarion",   "Innocenty",   "Hipolit",    "Ireneusz",
    "Erwin",      "Izaak",       "Izajasz",     "Izydor",     "Jakub",      "Jeremi",      "Jeremiasz",  "Hieronim",
    "Joachim",    "Jan",         "Janusz",      "Jonatan",    "Józef",      "Jozue",       "Julian",     "Juliusz",
    "Justyn",     "Kalistrat",   "Kazimierz",   "Wawrzyniec", "Laurenty",   "Laurencjusz", "Łazarz",     "Leon",
    "Leonard",    "Leonid",      "Ludwik",      "Łukasz",     "Lucjan",     "Magnus",      "Makary",     "Marceli",
    "Marek",      "Marcin",      "Mateusz",     "Maurycy",    "Maksym",     "Maksymilian", "Michał",     "Miron",
    "Modest",     "Mojżesz",     "Natan",       "Natanael",   "Nazariusz",  "Nazary",      "Nestor",     "Mikołaj",
    "Nikodem",    "Olaf",        "Oleg",        "Oliwier",    "Onufry",     "Orestes",     "Oskar",      "Ansgary",
    "Osmund",     "Pankracy",    "Pantaleon",   "Patryk",     "Patrycjusz", "Patrycy",     "Paweł",      "Piotr",
    "Filemon",    "Filip",       "Platon",      "Polikarp",   "Porfiry",    "Porfiriusz",  "Prokles",    "Prokul",
    "Prokop",     "Kwintyn",     "Randolf",     "Rafał",      "Rajmund",    "Reginald",    "Rajnold",    "Ryszard",
    "Robert",     "Roderyk",     "Roger",       "Roland",     "Roman",      "Romeo",       "Rudolf",     "Samson",
    "Samuel",     "Salwator",    "Sebastian",   "Serafin",    "Sergiusz",   "Seweryn",     "Zygmunt",    "Sylwester",
    "Szymon",     "Salomon",     "Spirydion",   "Stanisław",  "Szczepan",   "Stefan",      "Terencjusz", "Teodor",
    "Tomasz",     "Tymoteusz",   "Tobiasz",     "Walenty",    "Walentyn",   "Walerian",    "Walery",     "Wiktor",
    "Wincenty",   "Witalis",     "Włodzimierz", "Władysław",  "Błażej",     "Walter",      "Walgierz",   "Wacław",
    "Wilfryd",    "Wilhelm",     "Ksawery",     "Ksenofont",  "Zachariasz", "Zachary"};

const std::vector<std::string> polishFemalesFirstNames = {
    "Ada",        "Adelajda",   "Agata",     "Agnieszka", "Agrypina",   "Aida",      "Aleksandra", "Alicja",
    "Alina",      "Amanda",     "Anastazja", "Angela",    "Andżelika",  "Angelina",  "Anna",       "Hanna",
    "Antonina",   "Ariadna",    "Aurora",    "Barbara",   "Beatrycze",  "Berta",     "Brygida",    "Kamila",
    "Karolina",   "Kornelia",   "Katarzyna", "Cecylia",   "Chloe",      "Krystyna",  "Klara",      "Klaudia",
    "Klementyna", "Konstancja", "Koralia",   "Daria",     "Diana",      "Dina",      "Dorota",     "Edyta",
    "Eleonora",   "Eliza",      "Elżbieta",  "Izabela",   "Elwira",     "Emilia",    "Estera",     "Eudoksja",
    "Eudokia",    "Eugenia",    "Ewa",       "Ewelina",   "Ferdynanda", "Florencja", "Franciszka", "Gabriela",
    "Gertruda",   "Gloria",     "Gracja",    "Jadwiga",   "Helena",     "Henryka",   "Nadzieja",   "Ida",
    "Ilona",      "Irena",      "Irma",      "Izolda",    "Jakubina",   "Joanna",    "Janina",     "Żaneta",
    "Ginewra",    "Józefina",   "Judyta",    "Julia",     "Julita",     "Justyna",   "Kira",       "Cyra",
    "Kleopatra",  "Larysa",     "Laura",     "Laurencja", "Laurentyna", "Lea",       "Leila",      "Liliana",
    "Lilianna",   "Lilia",      "Lilla",     "Liza",      "Ludwika",    "Luiza",     "Łucja",      "Lucja",
    "Lidia",      "Amabela",    "Magdalena", "Malwina",   "Małgorzata", "Greta",     "Marianna",   "Maryna",
    "Marta",      "Martyna",    "Maria",     "Matylda",   "Maja",       "Melania",   "Michalina",  "Monika",
    "Noemi",      "Natalia",    "Nikola",    "Nina",      "Olga",       "Olimpia",   "Oliwia",     "Ofelia",
    "Patrycja",   "Paula",      "Pelagia",   "Penelopa",  "Filipa",     "Paulina",   "Rachela",    "Rebeka",
    "Regina",     "Renata",     "Rozalia",   "Róża",      "Roksana",    "Rufina",    "Ruta",       "Sabina",
    "Sara",       "Serafina",   "Sybilla",   "Sylwia",    "Zofia",      "Stella",    "Stefania",   "Zuzanna",
    "Tamara",     "Tacjana",    "Tekla",     "Teodora",   "Teresa",     "Walentyna", "Waleria",    "Wanesa",
    "Wiara",      "Weronika",   "Wiktoria",  "Wirginia",  "Bibiana",    "Bibianna",  "Wanda",      "Wilhelmina",
    "Ksawera",    "Ksenia",     "Zoe"};
}
