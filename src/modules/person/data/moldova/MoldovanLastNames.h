#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> moldovanLastNames = {
    "Rusu",       "Ceban",     "Ciobanu",   "Lungu",      "Cebotari",   "Munteanu",  "Popa",      "Gutu",
    "Rotari",     "Balan",     "Sirbu",     "Cojocari",   "Grosu",      "Melnic",    "Rotaru",    "Cojocaru",
    "Rosca",      "Turcan",    "Moraru",    "Morari",     "Cazacu",     "Cretu",     "Muntean",   "Botnari",
    "Ursu",       "Bivol",     "Russu",     "Ivanov",     "Popovici",   "Lupu",      "Mocanu",    "Chiriac",
    "Plamadeala", "Luca",      "Negru",     "Guzun",      "Turcanu",    "Miron",     "Popescu",   "Railean",
    "Arnaut",     "Florea",    "Cebanu",    "Popov",      "Plesca",     "Prodan",    "Andronic",  "Sandu",
    "Ivanova",    "Rusnac",    "Buga",      "Burlacu",    "Musteata",   "Malai",     "Borta",     "Croitor",
    "Bejenari",   "Cusnir",    "Pascari",   "Grecu",      "Golban",     "Oprea",     "Cernei",    "Pinzari",
    "Gheorghita", "Caraman",   "Bostan",    "Istrati",    "Spinu",      "Frunza",    "Cazac",     "Darii",
    "Lisnic",     "Raileanu",  "Bors",      "Josan",      "Topal",      "Croitoru",  "Birca",     "Colesnic",
    "Botnaru",    "Brinza",    "Gherman",   "Petrov",     "Postica",    "Bulat",     "Dragan",    "Chicu",
    "Cucu",       "Mardari",   "Carp",      "Postolachi", "Covali",     "Uzun",      "Platon",    "Gaina",
    "Radu",       "Antoci",    "Caraus",    "Albu",       "Codreanu",   "Tcaci",     "Gonta",     "Bejan",
    "Cara",       "Baciu",     "Ursachi",   "Bodrug",     "Ungureanu",  "Lupascu",   "Macovei",   "Ciubotaru",
    "Braga",      "Mihailov",  "Rata",      "Condrea",    "Pascal",     "Creciun",   "Craciun",   "Terzi",
    "Stratan",    "Moisei",    "Ciumac",    "Diaconu",    "Gangan",     "Cucos",     "Mereuta",   "Nastas",
    "Tataru",     "Capatina",  "Leahu",     "Goncear",    "Focsa",      "Bordian",   "Marin",     "Botezatu",
    "Crudu",      "Adam",      "Graur",     "Novac",      "Bitca",      "Esanu",     "Marian",    "Furtuna",
    "Apostol",    "Popova",    "Catana",    "Robu",       "Frunze",     "Secrieru",  "Bargan",    "Matei",
    "Andries",    "Mirza",     "Boboc",     "Stratulat",  "Paladi",     "Anghel",    "Cibotari",  "Trifan",
    "Butnaru",    "Mamaliga",  "Busuioc",   "Scripnic",   "Racu",       "Placinta",  "Jalba",     "Nistor",
    "Hincu",      "Bogdan",    "Cristea",   "David",      "Popusoi",    "Marcu",     "Gisca",     "Tofan",
    "Sava",       "Roman",     "Lazari",    "Erhan",      "Luchian",    "Balaban",   "Costin",    "Dodon",
    "Cotorobai",  "Bujor",     "Dabija",    "Vieru",      "Olaru",      "Macari",    "Mereacre",  "Dontu",
    "Lesnic",     "Prisacari", "Burca",     "Mazur",      "Moldovan",   "Olari",     "Gorea",     "Ababii",
    "Lazar",      "Casian",    "Gavriliuc", "Cecan",      "Duca",       "Lupasco",   "Lavric",    "Burlac",
    "Chirilov",   "Banari",    "Pislari",   "Oleinic",    "Grigoras",   "Ciorba",    "Gavrilita", "Manoli",
    "Prepelita",  "Anton",     "Sirghi",    "Burduja",    "Damian",     "Covalenco", "Cirlan",    "Cojuhari",
    "Bagrin",     "Ignat",     "Jardan",    "Stirbu",     "Moroz",      "Toma",      "Pintea",    "Eni",
    "Mocan",      "Arabadji",  "Perju",     "Gutan",      "Babin",      "Taran",     "Svet",      "Cheban",
    "Arama",      "Enachi",    "Dascal",    "Neagu",      "Cioban",     "Chistol",   "Lefter",    "Schiopu",
    "Groza",      "Petrova",   "Chihai",    "Baltag",     "Cebotaru",   "Donica",    "Bodiu",     "Buruiana",
    "Druta",      "Cozma",     "Grigorita", "Boico",      "Danilov",    "Cantir",    "Lozan",     "Caldare",
    "Negara",     "Palii",     "Bejenaru",  "Melnik",     "Gilca",      "Creanga",   "Nicolaev",  "Damaschin",
    "Calancea",   "Pogor",     "Gutul",     "Lupan",      "Colta",      "Gogu",      "Revenco",   "Pasat",
    "Buza",       "Stavila",   "Scutari",   "Moldovanu",  "Bologan",    "Savin",     "Efros",     "Puscas",
    "Paduret",    "Axenti",    "Butuc",     "Isac",       "Chirita",    "Danu",      "Costiuc",   "Catan",
    "Bolocan",    "Cuciuc",    "Sevcenco",  "Iovu",       "Bulgac",     "Belous",    "Scutelnic", "Leu",
    "Ciolac",     "Eremia",    "Negura",    "Romanciuc",  "Besliu",     "Chiosa",    "Demian",    "Iurcu",
    "Ciornii",    "Filip",     "Pruteanu",  "Gaidarji",   "Covalciuc",  "Proca",     "Movila",    "Gritco",
    "Pinzaru",    "Bulgaru",   "Bunescu",   "Baran",      "Mindru",     "Buzu",      "Pascaru",   "Savciuc",
    "Lesan",      "Scurtu",    "Harea",     "Grama",      "Bondarenco", "Buzdugan",  "Vlas",      "Gincu",
    "Cujba",      "Sevciuc",   "Loghin",    "Morozan",    "Avram",      "Sula",      "Virlan",    "Manole",
    "Arseni",     "Ionita",    "Chiperi",   "Pasa",       "Babii",      "Rotar",
};
}
