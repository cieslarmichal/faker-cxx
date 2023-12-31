#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> macedonianMalesLastNames = {
    "Абаџиев",       "Аврамов",      "Аврамовски",   "Аврамчев",        "Ајановски",    "Алексиев",
    "Алексов",       "Алексовски",   "Ангеловски",   "Андов",           "Андонов",      "Андоновски",
    "Андреевски",    "Антонов",      "Анчевски",     "Апостолов",       "Апостолски",   "Арсов",
    "Арсовски",      "Атанасов",     "Атанасовски",  "Атков",           "Ацев",         "Ацевски",
    "Аџимитревски",  "Бабамовски",   "Бабунски",     "Бавтировски",     "Бајалски",     "Бакевски",
    "Балабанов",     "Басаровски",   "Бачовски",     "Беличанец",       "Белковски",    "Беловски",
    "Белогаски",     "Белчев",       "Бендевски",    "Билбиловски",     "Билјановски",  "Бислимовски",
    "Битовски",      "Блажевски",    "Близнаков",    "Богданов",        "Богдановски",  "Богдански",
    "Богоев",        "Богоески",     "Божиков",      "Божинов",         "Божиновски",   "Бојановски",
    "Бојаџи",        "Бојаџиев",     "Боцевски",     "Бошевски",        "Бошков",       "Бошковски",
    "Брезоски",      "Бубуловски",   "Бужаровски",   "Бузев",           "Бујуклиев",    "Бунев",
    "Варсаковски",   "Василевски",   "Василески",    "Васков",          "Величковски",  "Велјанов",
    "Велков",        "Висулчев",     "Владимирски",  "Владов",          "Влахов",       "Влахчев",
    "Вражалски",     "Гаврилски",    "Гајдов",       "Галевски",        "Гапо",         "Гаревски",
    "Генов",         "Георгиев",     "Георгиевски",  "Герасимовски",    "Гермов",       "Геров",
    "Гечевски",      "Гешоски",      "Гигов",        "Гиевски",         "Главаш",       "Глигоров",
    "Глигоровски",   "Голабовски",   "Грабул",       "Грабулоски",      "Грозданов",    "Грошев",
    "Грујовски",     "Групче",       "Гугувчевски",  "Гучев",           "Давидовски",   "Давков",
    "Давчев",        "Давчевски",    "Дамески",      "Дамовски",        "Дворчанец",    "Дејанов",
    "Демниев",       "Деспотовски",  "Дилев",        "Димитриев",       "Димитров",     "Димковски",
    "Димов",         "Димовски",     "Динев",        "Диневски",        "Дирјан",       "Добревски",
    "Доброхотов",    "Додевски",     "Дојчинов",     "Доневски",        "Дракул",       "Дренков",
    "Дрнков",        "Дуганов",      "Дуковски",     "Ѓаконовски",      "Ѓелев",        "Ѓорѓевски",
    "Ѓорчев",        "Ѓузелев",      "Ѓурлуков",     "Ѓурчинов",        "Евремов",      "Едиповски",
    "Ежов",          "Ефтимов",      "Жеков",        "Железаров",       "Жерновски",    "Забазноски",
    "Зафировски",    "Здравев",      "Здравковски",  "Зографски",       "Иванов",       "Ивановски",
    "Иваноски",      "Игновски",     "Игњатовски",   "Икономов",        "Илиев",        "Илиевски",
    "Иљоски",        "Исаковски",    "Ицев",         "Јакимовски",      "Јаконов",      "Јаневски",
    "Јанчевски",     "Јачев",        "Јованов",      "Јовановски",      "Јовчевски",    "Јорданов",
    "Јордановски",   "Јосифовски",   "Јосифоски",    "Јуруков",         "Јурукоски",    "Калајџиски",
    "Калчевски",     "Камберски",    "Кантарџиев",   "Караѓозов",       "Карадак",      "Караман",
    "Каранфиловски", "Карев",        "Каров",        "Каровски",        "Картов",       "Катарџиев",
    "Кепески",       "Керамитчиев",  "Керамичиев",   "Кирјазовски",     "Киселинов",    "Китаноски",
    "Кичевски",      "Кљусев",       "Кодра",        "Колишевски",      "Колозов",      "Кондов",
    "Кондовски",     "Конески",      "Константинов", "Константиновски", "Кордалов",     "Корубин",
    "Костадинов",    "Костовски",    "Котевски",     "Котески",         "Коцаре",       "Коцо",
    "Кочовски",      "Коџоман",      "Крле",         "Крстев",          "Крстевски",    "Крстески",
    "Крцковски",     "Кузмановски",  "Кулишев",      "Куновски",        "Куноски",      "Кушевски",
    "Ладински",      "Лазаревски",   "Лазаров",      "Лазески",         "Лазовски",     "Лакински",
    "Лактински",     "Лапе",         "Лахтов",       "Левенски",        "Лековски",     "Леов",
    "Лечевски",      "Липов",        "Личеноски",    "Лозановски",      "Луловски",     "Љутков",
    "Мазев",         "Мајсторов",    "Македонски",   "Малевски",        "Малески",      "Маловски",
    "Манаковски",    "Мангов",       "Манговски",    "Манев",           "Маневски",     "Манивилов",
    "Манчев",        "Манчевски",    "Маринов",      "Марковски",       "Мартиновски",  "Мартиноски",
    "Масин",         "Матевски",     "Матковски",    "Матовски",        "Маџиров",      "Миладинов",
    "Милосавлев",    "Милошевски",   "Милчин",       "Миљовски",        "Минчев",       "Миовски",
    "Миронски",      "Мисирков",     "Митевски",     "Митревски",       "Митриќески",   "Михајлов",
    "Михајловски",   "Мицев",        "Мицевски",     "Мицковски",       "Мицов",        "Мишковски",
    "Младенов",      "Младеновски",  "Мојсовски",    "Мокров",          "Момировски",   "Мошин",
    "Мукаетов",      "Муратовски",   "Мусалевски",   "Мустачки",        "Најденов",     "Најдовски",
    "Најчески",      "Наков",        "Наневски",     "Настев",          "Наумов",       "Наумовски",
    "Наумчески",     "Начев",        "Неделковски",  "Нестор",          "Несторовски",  "Нетков",
    "Нешковски",     "Николески",    "Николов",      "Николовски",      "Никушев",      "Нинов",
    "Оровчанец",     "Ортаков",      "Османли",      "Павловски",       "Павлоски",     "Пајтонџиев",
    "Паковски",      "Паликрушев",   "Панговски",    "Пандески",        "Пандилов",     "Пандовски",
    "Панков",        "Панов",        "Пановски",     "Панчевски",       "Папрадишки",   "Пејов",
    "Пендовски",     "Пенушлиски",   "Пепељуговски", "Перински",        "Перчинковски", "Петковски",
    "Петров",        "Петровски",    "Петрушев",     "Петрушевски",     "Пиперковски",  "Планински",
    "Подгорец",      "Полежиноски",  "Полјански",    "Попов",           "Поповски",     "Попоски",
    "Преспански",    "Прилепчански", "Прличко",      "Псалтиров",       "Пуцков",       "Равановски",
    "Радически",     "Раковски",     "Рацин",        "Ризов",           "Ристов",       "Ристовски",
    "Ристоски",      "Руменов",      "Русјаков",     "Русоманов",       "Салџиев",      "Санев",
    "Сариевски",     "Светиев",      "Серафимов",    "Серафимовски",    "Сидовски",     "Силјановски",
    "Симов",         "Симовски",     "Симоновски",   "Скаловски",       "Славенски",    "Славески",
    "Сланев",        "Смаќоски",     "Смилевски",    "Смокварски",      "Соколов",      "Солев",
    "Солунски",      "Софрониевски", "Спасеновски",  "Спасов",          "Спасовски",    "Спиров",
    "Спировски",     "Ставрев",      "Ставрески",    "Стаматоски",      "Станков",      "Станковски",
    "Старделов",     "Стеванов",     "Стевковски",   "Стефанов",        "Стефановски",  "Стојанов",
    "Стојановски",   "Стојаноски",   "Стојков",      "Стојковски",      "Стојменски",   "Стојчев",
    "Такев",         "Таковски",     "Талевски",     "Талески",         "Темелкоски",   "Теодосиевски",
    "Терзиев",       "Тодоров",      "Тодоровски",   "Тозија",          "Толевски",     "Томовски",
    "Тофоски",       "Точко",        "Тошев",        "Тошевски",        "Трајковски",   "Тренески",
    "Тренчевски",    "Трифуновски",  "Тројачанец",   "Трпеновски",      "Тушевски",     "Ќамилов",
    "Ќорнаков",      "Ќортошев",     "Ќурчиев",      "Угриновски",      "Узунов",       "Узуновски",
    "Урдин",         "Филиповски",   "Фирфов",       "Фотев",           "Хаџиманов",    "Хаџиниколов",
    "Христов",       "Христовски",   "Цанев",        "Цветановски",     "Цеков",        "Цековски",
    "Ценев",         "Црвенковски",  "Црвенов",      "Чакар",           "Чакмаков",     "Чаловски",
    "Чапаровски",    "Чаушев",       "Чашуле",       "Чевревски",       "Чејковски",    "Чемерски",
    "Чемков",        "Чипан",        "Чокревски",    "Чундев",          "Чупона",       "Чучков",
    "Чушкаров",      "Џамбаз",       "Џамбазов",     "Џаџев",           "Џеков",        "Џинлески",
    "Џорлев",        "Џувалековски", "Џунов",        "Шаревски",        "Шијак",        "Шијаков",
    "Шијаковски",    "Ширилов",      "Шишков",       "Шопов",           "Шоптрајанов",  "Штерјоски",
    "Шулинчевски",
};

const std::vector<std::string> macedonianFemalesLastNames = {
    "Абаџиева",     "Абова",        "Аврамова",      "Аврамовска",      "Аврамчева",    "Ајановска",    "Алексиева",
    "Алексова",     "Алексовска",   "Ангеловска",    "Андова",          "Андонова",     "Андоновска",   "Андреевска",
    "Антонова",     "Анчевска",     "Апостолова",    "Апостолска",      "Арсова",       "Арсовска",     "Атанасова",
    "Атанасовска",  "Аткова",       "Ацева",         "Ацевска",         "Аџимитревска", "Бабамовска",   "Бабунска",
    "Бавтировска",  "Бајалска",     "Бакевска",      "Балабанова",      "Басаровска",   "Бачовска",     "Беличанец",
    "Белковска",    "Беловска",     "Белогаска",     "Белчева",         "Бендевска",    "Билбиловска",  "Билјановска",
    "Бислимовска",  "Битовска",     "Блажевска",     "Близнакова",      "Богданова",    "Богдановска",  "Богданска",
    "Богоева",      "Богоеска",     "Божикова",      "Божинова",        "Божиновска",   "Бојановска",   "Бојаџи",
    "Бојаџиева",    "Боцевска",     "Бошевска",      "Бошкова",         "Бошковска",    "Брезоска",     "Бубуловска",
    "Бужаровска",   "Бузева",       "Бујуклиева",    "Бунева",          "Варсаковска",  "Василевска",   "Василеска",
    "Васкова",      "Величковска",  "Велјанова",     "Велкова",         "Висулчева",    "Владимирска",  "Владова",
    "Влахова",      "Влахчева",     "Вражалска",     "Гаврилска",       "Гајдова",      "Галевска",     "Гапо",
    "Гаревска",     "Генова",       "Георгиева",     "Георгиевска",     "Герасимовска", "Гермова",      "Герова",
    "Гечевска",     "Гешоска",      "Гигова",        "Гиевска",         "Главаш",       "Глигорова",    "Глигоровска",
    "Голабовска",   "Грабул",       "Грабулоска",    "Грозданова",      "Грошева",      "Грујовска",    "Групче",
    "Гугувчевска",  "Гучева",       "Давидовска",    "Давкова",         "Давчева",      "Давчевска",    "Дамеска",
    "Дамовска",     "Дворчанец",    "Дејанова",      "Демниева",        "Деспотовска",  "Дилева",       "Димитриева",
    "Димитрова",    "Димковска",    "Димова",        "Димовска",        "Динева",       "Диневска",     "Добревска",
    "Додевска",     "Дојчинова",    "Доневска",      "Дракул",          "Дренкова",     "Дрнкова",      "Дуганова",
    "Дуковска",     "Ѓаконовска",   "Ѓелева",        "Ѓорѓевска",       "Ѓорчева",      "Ѓузелева",     "Ѓурлукова",
    "Ѓурчинова",    "Евремова",     "Едиповска",     "Ежова",           "Ефтимова",     "Жекова",       "Железарова",
    "Жерновска",    "Забазноска",   "Зафировска",    "Здравева",        "Здравковска",  "Зографска",    "Иванова",
    "Ивановска",    "Иваноска",     "Игновска",      "Игњатовска",      "Икономова",    "Илиева",       "Илиевска",
    "Иљоска",       "Исаковска",    "Ицева",         "Јакимовска",      "Јаконова",     "Јаневска",     "Јанчевска",
    "Јачева",       "Јованова",     "Јовановска",    "Јовчевска",       "Јорданова",    "Јордановска",  "Јосифовска",
    "Јосифоска",    "Јурукова",     "Јурукоска",     "Калајџиска",      "Калчевска",    "Камберска",    "Кантарџиева",
    "Караѓозова",   "Карадак",      "Караман",       "Каранфиловска",   "Караџа",       "Карева",       "Карова",
    "Каровска",     "Картова",      "Катарџиева",    "Кепеска",         "Керамитчиева", "Керамичиева",  "Кирјазовска",
    "Киселинова",   "Китаноска",    "Кичевска",      "Кљусева",         "Колишевска",   "Колозова",     "Кондова",
    "Кондовска",    "Конеска",      "Константинова", "Константиновска", "Кордалова",    "Коробар",      "Корубин",
    "Костадинова",  "Костовска",    "Котевска",      "Котеска",         "Коцаре",       "Коцо",         "Кочовска",
    "Коџоман",      "Крле",         "Крстева",       "Крстевска",       "Крстеска",     "Крцковска",    "Кузмановска",
    "Кулишева",     "Куновска",     "Куноска",       "Кутурец",         "Кушевска",     "Ладинска",     "Лазаревска",
    "Лазарова",     "Лазеска",      "Лазовска",      "Лакинска",        "Лактинска",    "Лапе",         "Лахтова",
    "Левенска",     "Лековска",     "Леова",         "Лечевска",        "Липова",       "Личеноска",    "Лозановска",
    "Луловска",     "Љуткова",      "Мазева",        "Мајсторова",      "Македонска",   "Малевска",     "Малеска",
    "Маловска",     "Манаковска",   "Мангова",       "Манговска",       "Манева",       "Маневска",     "Манивилова",
    "Манчева",      "Манчевска",    "Маринова",      "Марковска",       "Мартиновска",  "Мартиноска",   "Масин",
    "Матевска",     "Матковска",    "Матовска",      "Маџирова",        "Миладинова",   "Милосавлева",  "Милошевска",
    "Милчин",       "Миљовска",     "Минчева",       "Миовска",         "Миронска",     "Мисиркова",    "Митевска",
    "Митревска",    "Митриќеска",   "Михајлова",     "Михајловска",     "Мицева",       "Мицевска",     "Мицковска",
    "Мицова",       "Мишковска",    "Младенова",     "Младеновска",     "Мојсовска",    "Мокрова",      "Момировска",
    "Мошин",        "Мукаетова",    "Муратовска",    "Мусалевска",      "Мустачки",     "Најденова",    "Најдовска",
    "Најческа",     "Накова",       "Наневска",      "Настева",         "Наумова",      "Наумовска",    "Наумческа",
    "Начева",       "Неделковска",  "Нестор",        "Несторовска",     "Неткова",      "Нешковска",    "Николеска",
    "Николова",     "Николовска",   "Никушева",      "Нинова",          "Оровчанец",    "Ортакова",     "Османли",
    "Павловска",    "Павлоска",     "Пајтонџиева",   "Паковска",        "Паликрушева",  "Панговска",    "Пандеска",
    "Пандилова",    "Пандовска",    "Панкова",       "Панова",          "Пановска",     "Панчевска",    "Папрадишки",
    "Пејова",       "Пендовска",    "Пенушлиска",    "Пепељуговска",    "Перинска",     "Перчинковска", "Петковска",
    "Петрова",      "Петровска",    "Петрушева",     "Петрушевска",     "Пиперковска",  "Планинска",    "Подгорец",
    "Полежиноска",  "Полјанска",    "Попова",        "Поповска",        "Попоска",      "Преспанска",   "Прилепчанска",
    "Прличко",      "Псалтирова",   "Пуцкова",       "Равановска",      "Радическа",    "Раковска",     "Рацин",
    "Реџепова",     "Ризова",       "Ристова",       "Ристовска",       "Ристоска",     "Руменова",     "Русјакова",
    "Русоманова",   "Салџиева",     "Санева",        "Сариевска",       "Светиева",     "Серафимова",   "Серафимовска",
    "Сидовска",     "Силјановска",  "Симова",        "Симовска",        "Симоновска",   "Скаловска",    "Славенска",
    "Славеска",     "Сланева",      "Смаќоска",      "Смилевска",       "Смокварска",   "Соколова",     "Солева",
    "Солунска",     "Софрониевска", "Спасеновска",   "Спасова",         "Спасовска",    "Спирова",      "Спировска",
    "Ставрева",     "Ставреска",    "Стаматоска",    "Станкова",        "Станковска",   "Старделова",   "Стеванова",
    "Стевковска",   "Стефанова",    "Стефановска",   "Стојанова",       "Стојановска",  "Стојаноска",   "Стојкова",
    "Стојковска",   "Стојменска",   "Стојчева",      "Такева",          "Таковска",     "Талевска",     "Талеска",
    "Темелкоска",   "Теодосиевска", "Терзиева",      "Тодорова",        "Тодоровска",   "Тозија",       "Толевска",
    "Томовска",     "Тофоска",      "Точко",         "Тошева",          "Тошевска",     "Трајковска",   "Тренеска",
    "Тренчевска",   "Трифуновска",  "Тројачанец",    "Трпеновска",      "Тушевска",     "Ќамилова",     "Ќорнакова",
    "Ќортошева",    "Ќурчиева",     "Угриновска",    "Узунова",         "Узуновска",    "Урдин",        "Филиповска",
    "Фирфова",      "Фотева",       "Хаџиманова",    "Хаџиниколова",    "Христова",     "Христовска",   "Цанева",
    "Цветановска",  "Цекова",       "Цековска",      "Ценева",          "Црвенковска",  "Црвенова",     "Чакар",
    "Чакмакова",    "Чаловска",     "Чапаровска",    "Чаушева",         "Чашуле",       "Чевревска",    "Чејковска",
    "Чемерска",     "Чемкова",      "Чипан",         "Чокревска",       "Чундева",      "Чупона",       "Чучкова",
    "Чушкарова",    "Џамбаз",       "Џамбазова",     "Џаџева",          "Џекова",       "Џинлеска",     "Џорлева",
    "Џувалековска", "Џунова",       "Шаревска",      "Шијак",           "Шијакова",     "Шијаковска",   "Ширилова",
    "Шишкова",      "Шопова",       "Шоптрајанова",  "Штерјоска",       "Шулинчевска",
};
}
