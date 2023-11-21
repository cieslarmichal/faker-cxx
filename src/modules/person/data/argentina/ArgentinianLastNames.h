#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> argentinianLastNames = {
    "Gonzalez",   "Rodriguez",  "Gomez",       "Fernandez",  "Lopez",      "Diaz",       "Martinez",    "Perez",
    "Garcia",     "Sanchez",    "Romero",      "Sosa",       "Torres",     "Alvarez",    "Ruiz",        "Ramirez",
    "Flores",     "Benitez",    "Acosta",      "Medina",     "Herrera",    "Suarez",     "Aguirre",     "Gimenez",
    "Gutierrez",  "Pereyra",    "Rojas",       "Molina",     "Castro",     "Ortiz",      "Silva",       "Nuñez",
    "Luna",       "Juarez",     "Cabrera",     "Rios",       "Morales",    "Godoy",      "Moreno",      "Ferreyra",
    "Dominguez",  "Carrizo",    "Peralta",     "Castillo",   "Ledesma",    "Quiroga",    "Vega",        "Vera",
    "Muñoz",      "Ojeda",      "Ponce",       "Villalba",   "Cardozo",    "Navarro",    "Coronel",     "Vazquez",
    "Ramos",      "Vargas",     "Caceres",     "Arias",      "Figueroa",   "Cordoba",    "Correa",      "Maldonado",
    "Paz",        "Rivero",     "Miranda",     "Mansilla",   "Farias",     "Roldan",     "Mendez",      "Guzman",
    "Aguero",     "Hernandez",  "Lucero",      "Cruz",       "Paez",       "Escobar",    "Mendoza",     "Barrios",
    "Bustos",     "Avila",      "Ayala",       "Blanco",     "Soria",      "Maidana",    "Acuña",       "Leiva",
    "Duarte",     "Moyano",     "Campos",      "Soto",       "Martin",     "Valdez",     "Bravo",       "Chavez",
    "Velazquez",  "Olivera",    "Toledo",      "Franco",     "Ibañez",     "Leguizamon", "Montenegro",  "Delgado",
    "Arce",       "Ibarra",     "Gallardo",    "Santillan",  "Acevedo",    "Aguilar",    "Vallejos",    "Contreras",
    "Alegre",     "Galvan",     "Oviedo",      "Aranda",     "Albornoz",   "Baez",       "Sandoval",    "Barrionuevo",
    "Veron",      "Gauna",      "Zarate",      "Heredia",    "Mercado",    "Monzon",     "Marquez",     "Zalazar",
    "Mamani",     "Coria",      "Segovia",     "Romano",     "Jimenez",    "Salinas",    "Quinteros",   "Barrera",
    "Ortega",     "Cabral",     "Palacios",    "Cejas",      "Quintana",   "Zapata",     "Rosales",     "Altamirano",
    "Nieva",      "Bazan",      "Alonso",      "Burgos",     "Bustamante", "Varela",     "Lescano",     "Aguilera",
    "Paredes",    "Avalos",     "Cuello",      "Aquino",     "Orellana",   "Caballero",  "Reynoso",     "Reyes",
    "Villarreal", "Alarcon",    "Pacheco",     "Tapia",      "Galarza",    "Ocampo",     "Meza",        "Guerrero",
    "Salas",      "Frias",      "Videla",      "Miño",       "Jara",       "Garay",      "Rossi",       "Lezcano",
    "Valenzuela", "Oliva",      "Fuentes",     "Robledo",    "Espindola",  "Nieto",      "Pereira",     "Brizuela",
    "Andrada",    "Maciel",     "Funes",       "Robles",     "Sotelo",     "Cortez",     "Almiron",     "Rivas",
    "Gil",        "Villegas",   "Calderon",    "Vergara",    "Carabajal",  "Ceballos",   "Gallo",       "Palavecino",
    "Barreto",    "Alderete",   "Escudero",    "Saavedra",   "Serrano",    "Almada",     "Galeano",     "Espinosa",
    "Villagra",   "Gerez",      "Solis",       "Ochoa",      "Escalante",  "Luque",      "Amaya",       "Arguello",
    "Salazar",    "Lazarte",    "Barrientos",  "Vidal",      "Machado",    "Ferreira",   "Argañaraz",   "Iglesias",
    "Guevara",    "Centurion",  "Esquivel",    "Lencina",    "Jaime",      "Cano",       "Lujan",       "Espinoza",
    "Palacio",    "Villanueva", "Salvatierra", "Guerra",     "Barraza",    "Bordon",     "Saucedo",     "Ferrari",
    "Costa",      "Rolon",      "Zabala",      "Albarracin", "Duran",      "Peña",       "Tello",       "Quiroz",
    "Montes",     "Alfonso",    "Brito",       "Marin",      "Moreira",    "Olmos",      "Montiel",     "Pintos",
    "Olmedo",     "Bruno",      "Villafañe",   "Arroyo",     "Reinoso",    "Araujo",     "Gorosito",    "Cisneros",
    "Quevedo",    "Montero",    "Barros",      "Moya",       "Basualdo",   "Carballo",   "Insaurralde", "Prieto",
    "Alcaraz",    "Santos",     "Corvalan",    "Chamorro",   "Casas",      "Carranza",   "Moreyra",     "Chaves",
    "Riquelme",   "Arevalo",    "Bogado",      "Sequeira",   "Amarilla",   "Parra",      "Corbalan",    "Veliz",
    "Falcon",     "Moran",      "Cantero",     "Otero",      "Rocha",      "Lobo",       "Cuevas",      "Roman",
    "Caro",       "Jofre",      "Nievas",      "Pinto",      "Arrieta",    "Portillo",   "Rivera",      "Gramajo",
    "Quintero",   "Russo",      "Carrasco",    "Castaño",    "Vivas",      "Gamarra",    "Ludueña",     "Britez",
    "Britos",     "Cortes",     "Becerra",     "Prado",      "Merlo",      "Barboza",    "Hidalgo",     "Olguin",
    "Taborda",    "Tolaba",     "Villa",       "Leon",       "Sarmiento",  "Cañete",     "Gaitan",      "Sanabria",
    "Ovejero",    "Da'Pavon",   "Rey",         "Mora",       "Vasquez",    "Cardenas",   "Cornejo",     "Orellano",
    "Dos'Alaniz", "Araya",      "Vallejo",     "Enriquez",   "Bianchi",    "Barroso",    "Calvo",       "Lemos",
    "Casco",      "Trejo",      "Andrade",     "Balmaceda",
};
}
