#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> irishLastNames = {
    "Murphy",      "Kelly",       "Byrne",      "Walsh",      "Ryan",       "Doyle",      "Lynch",      "Mccarthy",
    "Brennan",     "Dunne",       "Murray",     "Burke",      "Smith",      "Daly",       "Nolan",      "Kennedy",
    "Fitzgerald",  "Gallagher",   "Flynn",      "Collins",    "Power",      "Quinn",      "Farrell",    "Carroll",
    "Kavanagh",    "Connolly",    "Healy",      "Clarke",     "Duffy",      "Doherty",    "Brady",      "Whelan",
    "Kenny",       "Fitzpatrick", "Moore",      "Keane",      "Moran",      "Reilly",     "Mcgrath",    "Barry",
    "Foley",       "Hayes",       "Maher",      "Buckley",    "Martin",     "Casey",      "Roche",      "Hughes",
    "Smyth",       "Browne",      "Butler",     "Mcmahon",    "Hogan",      "Griffin",    "Egan",       "White",
    "Sweeney",     "Cullen",      "Hickey",     "Ward",       "Cunningham", "Maguire",    "Lyons",      "Mcdonnell",
    "Delaney",     "Cronin",      "Sheehan",    "Keogh",      "Mccormack",  "Higgins",    "Curran",     "Cahill",
    "Mcloughlin",  "Boyle",       "Crowley",    "Mckenna",    "Sheridan",   "Molloy",     "Barrett",    "Flanagan",
    "King",        "Moloney",     "Phelan",     "Dowling",    "Mooney",     "Mcnamara",   "Corcoran",   "Costello",
    "Hennessy",    "Malone",      "Lawlor",     "Conway",     "Fox",        "Kearney",    "Carey",      "Dempsey",
    "Duggan",      "Donnelly",    "Mccabe",     "Mcdermott",  "Dolan",      "Gleeson",    "Cleary",     "Joyce",
    "Mcdonagh",    "Kelleher",    "Mcdonald",   "Jones",      "Redmond",    "Mchugh",     "Conroy",     "Coleman",
    "Reynolds",    "Coughlan",    "Cummins",    "Kinsella",   "Hurley",     "Dillon",     "Fleming",    "Lee",
    "Keating",     "Clancy",      "Tobin",      "Breen",      "Campbell",   "Leahy",      "Sullivan",   "Morrissey",
    "Leonard",     "Rooney",      "Greene",     "Mahon",      "Finn",       "Coffey",     "Cassidy",    "Forde",
    "Heffernan",   "Long",        "Bourke",     "Cooney",     "Madden",     "Hynes",      "Mcevoy",     "Woods",
    "Williams",    "Finnegan",    "Kirwan",     "Geraghty",   "Morris",     "Wilson",     "Doran",      "Larkin",
    "Meehan",      "Hegarty",     "Galvin",     "Harrington", "Mulligan",   "Allen",      "Farrelly",   "Fahy",
    "Kiely",       "Jordan",      "Mcguinness", "Conlon",     "Kane",       "Lennon",     "Callaghan",  "Mccann",
    "Coyle",       "Boland",      "Twomey",     "Morgan",     "Monaghan",   "Treacy",     "Gorman",     "Dalton",
    "Quigley",     "Reid",        "Mcgovern",   "Mitchell",   "Noonan",     "Bradley",    "Keenan",     "Brown",
    "Russell",     "Mulcahy",     "Fagan",      "Dooley",     "Wall",       "Davis",      "Mclaughlin", "Mullen",
    "Horgan",      "Burns",       "Dwyer",      "Carr",       "Tierney",    "Keegan",     "Purcell",    "Cotter",
    "Naughton",    "Kearns",      "Scanlon",    "Lane",       "Fogarty",    "Horan",      "Thompson",   "Murtagh",
    "Harte",       "Fallon",      "Flood",      "Wallace",    "Hannon",     "Grant",      "Hanley",     "Scully",
    "Kehoe",       "Johnston",    "Slattery",   "Ahern",      "Glynn",      "Taylor",     "Connor",     "Corrigan",
    "Scott",       "Kiernan",     "Curtin",     "Rogers",     "Gannon",     "Bolger",     "Shanahan",   "Regan",
    "Flaherty",    "Donohoe",     "Nugent",     "Behan",      "Mannion",    "Gibbons",    "Donovan",    "Quirke",
    "Bergin",      "Clifford",    "Downey",     "Graham",     "Hyland",     "Quinlan",    "Henry",      "Mcmanus",
    "Prendergast", "Gaffney",     "Robinson",   "Moriarty",   "Carolan",    "Gavin",      "Condon",     "Mcgowan",
    "Coyne",       "Moco",        "Young",      "Bennett",    "Mcgee",      "Mcnally",    "Mullins",    "Brophy",
    "Howard",      "Matthews",    "Hayden",     "Fitzsimons", "Obrien",     "Gill",       "Feeney",     "Reidy",
    "Brosnan",     "Donoghue",    "Darcy",      "Mcsweeney",  "Jennings",   "Johnson",    "Walshe",     "Cox",
    "Cooke",       "Moynihan",    "Stewart",    "Owens",      "Geoghegan",  "Sheehy",     "Ennis",      "Lawless",
    "Crowe",       "Shannon",     "Gray",       "Boylan",     "Mangan",     "Rice",       "Holland",    "Furlong",
    "Jackson",     "Connell",     "Vaughan",    "Oconnor",    "Sexton",     "Maloney",    "Whyte",      "Devine",
    "Broderick",   "Anderson",    "Hunt",       "English",    "Halpin",     "Blake",      "Dunphy",     "Mcguire",
    "Harris",      "Walker",      "Devlin",     "Mcbride",    "O'brien",    "O'connor",   "O'sullivan", "O'neill",
    "O'reilly",    "O'connell",   "O'donnell",  "O'shea",     "O'leary",    "O'keeffe",   "O'donovan",  "O'mahony",
    "O'callaghan", "O'donoghue",  "O'rourke",   "O'toole",    "O'dwyer",    "O'driscoll", "O'grady",    "O'regan",
    "O'malley",    "O'riordan",   "O'gorman",   "O'halloran", "O'hara",     "O'meara",    "O'loughlin", "O'flynn",
    "O'hanlon",    "O'dowd",      "O'flaherty", "O'byrne",    "O'carroll",  "O'farrell",

};
}
