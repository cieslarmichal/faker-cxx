#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> serbianMalesFirstNames = {
    "Adam",      "Aleksa",    "Aleksandar", "Aleksej",   "Aljoša",    "Anastasije", "Andrej",   "Andrija",
    "Anej",      "Arsenije",  "Aćim",       "Berislav",  "Blagoje",   "Boban",      "Bogdan",   "Bogoljub",
    "Bojan",     "Boris",     "Borivoje",   "Borjan",    "Boško",     "Boža",       "Božidar",  "Branimir",
    "Branislav", "Branko",    "Budimir",    "Cvijan",    "Cvijetin",  "Dabiživ",    "Damir",    "Damjan",
    "Danilo",    "Danko",     "Darko",      "David",     "Davor",     "Dejan",      "Desimir",  "Dimitrije",
    "Dragan",    "Dragiša",   "Dragoje",    "Dragojlo",  "Dragoljub", "Dragoslav",  "Dragutin", "Draža",
    "Dražen",    "Dren",      "Dušan",      "Duško",     "Filip",     "Filotije",   "Gavrilo",  "Georgije",
    "Gerasim",   "Gligorije", "Gojko",      "Golub",     "Goran",     "Gordan",     "Grgur",    "Grigorije",
    "Hvalimir",  "Ignjat",    "Igor",       "Ilarion",   "Ilija",     "Ivan",       "Ivica",    "Ivo",
    "Jadranko",  "Jakov",     "Jezdimir",   "Jovan",     "Jugoslav",  "Kalinik",    "Kirilo",   "Konstantin",
    "Kosta",     "Kristijan", "Krsto",      "Kuzman",    "Lazar",     "Ljubiša",    "Ljubomir", "Luka",
    "Mališa",    "Marinko",   "Marjan",     "Marko",     "Mateja",    "Mihailo",    "Mihajlo",  "Mija",
    "Mijat",     "Mika",      "Miladin",    "Milan",     "Milanko",   "Mile",       "Mileta",   "Milisav",
    "Milić",     "Miljan",    "Milojica",   "Milomir",   "Milorad",   "Miloš",      "Milutin",  "Miodrag",
    "Miomir",    "Mirko",     "Miroslav",   "Mitar",     "Miša",      "Miško",      "Mladen",   "Momir",
    "Nebojša",   "Nedeljko",  "Nemanja",    "Nenad",     "Neven",     "Nikola",     "Nikša",    "Novak",
    "Obrad",     "Obren",     "Ognjen",     "Oliver",    "Ostoja",    "Paja",       "Pavle",    "Pera",
    "Perica",    "Pero",      "Petar",      "Petko",     "Predrag",   "Prvoslav",   "Radenko",  "Radivoje",
    "Radiša",    "Radmilo",   "Radomir",    "Radosav",   "Radoslav",  "Radovan",    "Radoš",    "Radul",
    "Rajko",     "Ranko",     "Ratimir",    "Raško",     "Relja",     "Rodoljub",   "Saša",     "Simo",
    "Siniša",    "Slavoljub", "Slobodan",   "Srboljub",  "Sredoje",   "Stanislav",  "Stanko",   "Stefan",
    "Stevan",    "Stojan",    "Strahinja",  "Svetislav", "Svetolik",  "Svetomir",   "Tadija",   "Tihomir",
    "Tomislav",  "Vanja",     "Vasil",      "Vasko",     "Velibor",   "Velimir",    "Vidak",    "Vladimir",
    "Vlastimir", "Vojin",     "Vujadin",    "Vuk",       "Vukan",     "Vukašin",    "Vukota",   "Zafir",
    "Zarije",    "Zoran",     "Zvonko",     "Časlav",    "Čedomir",   "Đorđe",      "Đura",     "Đurađ",
};

const std::vector<std::string> serbianFemalesFirstNames = {
    "Adrijana", "Aleksandra", "Ana",      "Anabela",   "Anastasija", "Andrea",     "Andrijana", "Aneta",
    "Anica",    "Anita",      "Anja",     "Anka",      "Anđela",     "Ava",        "Biljana",   "Bisenija",
    "Blagica",  "Bobana",     "Bogdana",  "Bojana",    "Bora",       "Borka",      "Bosiljka",  "Božena",
    "Božica",   "Branka",     "Brankica", "Ceca",      "Dajana",     "Daliborka",  "Damjanka",  "Dana",
    "Danijela", "Danila",     "Danka",    "Darija",    "Darinka",    "Dejana",     "Desanka",   "Dijana",
    "Divna",    "Dobrila",    "Dorotea",  "Draga",     "Dragana",    "Draginja",   "Drina",     "Dubravka",
    "Dunja",    "Dušanka",    "Dušica",   "Duška",     "Elena",      "Eleonora",   "Ema",       "Emilija",
    "Evdokija", "Gabrijela",  "Gala",     "Galina",    "Gorana",     "Gordana",    "Hana",      "Ilinka",
    "Ina",      "Irina",      "Ivanka",   "Jadranka",  "Jana",       "Jasmina",    "Jasna",     "Jelena",
    "Jelica",   "Jelisaveta", "Jelka",    "Jevrosima", "Jovana",     "Jovanka",    "Julia",     "Julijana",
    "Katarina", "Klara",      "Kristina", "Ksenija",   "Lada",       "Lara",       "Leposava",  "Lidija",
    "Ljiljana", "Ljuba",      "Ljubica",  "Magdalena", "Maja",       "Malina",     "Marica",    "Marina",
    "Markika",  "Marta",      "Maša",     "Mašinka",   "Melenija",   "Mia",        "Milana",    "Milanka",
    "Milena",   "Milica",     "Miljana",  "Mina",      "Mira",       "Mirela",     "Mirjana",   "Mirka",
    "Mirna",    "Mitra",      "Mlađana",  "Momira",    "Nada",       "Nadežda",    "Nastja",    "Natalija",
    "Nataša",   "Nađa",       "Neda",     "Nela",      "Neva",       "Nevena",     "Nikoleta",  "Nikolina",
    "Nina",     "Njegomirka", "Ognjana",  "Olga",      "Olgica",     "Olivera",    "Peruna",    "Petra",
    "Petrija",  "Radina",     "Radmila",  "Radojka",   "Rakita",     "Renja",      "Ristana",   "Roksana",
    "Romana",   "Rumena",     "Ruža",     "Sanda",     "Sandra",     "Sanja",      "Sara",      "Selena",
    "Senka",    "Silvija",    "Simonida", "Slava",     "Slavica",    "Slavka",     "Slađana",   "Slobodanka",
    "Smiljana", "Snežana",    "Sofija",   "Sonja",     "Srna",       "Stanislava", "Staša",     "Stefana",
    "Stojanka", "Sunčica",    "Suzana",   "Svetlana",  "Tamara",     "Tanja",      "Tara",      "Tatjana",
    "Tea",      "Teodora",    "Teona",    "Una",       "Vasilisa",   "Vera",       "Verica",    "Veselinka",
    "Vesna",    "Vida",       "Višnja",   "Vladana",   "Vlatka",     "Vojislava",  "Vujica",    "Vukica",
    "Zavida",   "Zora",       "Zorana",   "Zorka",     "Zvezdana",   "Čarna",      "Đurica",    "Željka",
};
}
