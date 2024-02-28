#include "book_data.h"

namespace faker::book::data {
const std::array<std::string_view, 100> authors = { "Shakespeare, William", "Smollett, T. (Tobias)",
    "Dumas, Alexandre", "Montgomery, L. M. (Lucy Maud)", "Melville, Herman", "Alcott, Louisa May",
    "Eliot, George", "Forster, E. M. (Edward Morgan)", "Austen, Jane", "Merrill, Frank T.",
    "Dickens, Charles", "Gaskell, Elizabeth Cleghorn", "Von Arnim, Elizabeth",
    "Brock, C. E. (Charles Edmund)", "Fielding, Henry", "Wagner, Richard", "Twain, Mark",
    "Doyle, Arthur Conan", "Dostoyevsky, Fyodor", "Packard, Vance",
    "Adams, Clifford R. (Clifford Rose)", "Wilde, Oscar", "Garnett, Constance", "Carroll, Lewis",
    "Nietzsche, Friedrich Wilhelm", "Tolstoy, Leo", "Stevenson, Robert Louis",
    "Wells, H. G. (Herbert George)", "Shelley, Mary Wollstonecraft",
    "Howard, Robert E. (Robert Ervin)", "Baum, L. Frank (Lyman Frank)",
    "Chesterton, G. K. (Gilbert Keith)", "Homer", "Plato", "Rizal, José", "Christie, Agatha",
    "Joyce, James", "Jowett, Benjamin", "Poe, Edgar Allan", "Verne, Jules", "Thoreau, Henry David",
    "Kafka, Franz", "Stoker, Bram", "Kipling, Rudyard", "Doré, Gustave", "Widger, David",
    "Fitzgerald, F. Scott (Francis Scott)", "Russell, Bertrand", "Swift, Jonathan",
    "Dante Alighieri", "Wyllie, David", "Hugo, Victor", "Lang, Andrew", "Maude, Aylmer",
    "Burton, Richard Francis, Sir", "Maude, Louise", "Hawthorne, Nathaniel", "Conrad, Joseph",
    "London, Jack", "Goethe, Johann Wolfgang von", "James, Henry", "Scott, Walter",
    "Chekhov, Anton Pavlovich", "Pope, Alexander", "Ibsen, Henrik", "Cervantes Saavedra, Miguel de",
    "Balzac, Honoré de", "Grimm, Jacob", "Grimm, Wilhelm", "Lovecraft, H. P. (Howard Phillips)",
    "Burroughs, Edgar Rice", "Shaw, Bernard", "Gilman, Charlotte Perkins",
    "Wodehouse, P. G. (Pelham Grenville)", "Hotten, John Camden", "Morley, Henry",
    "Machiavelli, Niccolò", "Derbyshire, Charles E.", "Barrie, J. M. (James Matthew)",
    "Brontë, Charlotte", "Defoe, Daniel", "Ward, Grady", "Levy, Oscar", "Burnett, Frances Hodgson",
    "Schopenhauer, Arthur", "Buckley, Theodore Alois", "Milne, A. A. (Alan Alexander)",
    "Marriott, W. K. (William Kenaz)", "Vatsyayana", "Potter, Beatrix", "Ormsby, John",
    "Bhide, Shivaram Parashuram", "Butler, Samuel", "Indrajit, Bhagavanlal", "Maupassant, Guy de",
    "Hapgood, Isabel Florence", "Chambers, Robert W. (Robert William)", "Marx, Karl",
    "Eliot, T. S. (Thomas Stearns)", "Hardy, Thomas" };

const std::array<std::string_view, 3> book_formats {
    "Paperback",
    "Hardcover",
    "Kindle",
};

const std::array<std::string_view, 25> genres
    = { "Adventure stories", "Classics", "Crime", "Fairy tales, fables, and folk tales", "Fantasy",
          "Historical fiction", "Horror", "Humour and satire", "Literary fiction", "Mystery",
          "Poetry", "Plays", "Romance", "Science fiction", "Short stories", "Thrillers", "War",
          "Women’s fiction", "Young adult", "Non-fiction", "Autobiography and memoir", "Biography",
          "Essays", "Non-fiction novel", "Self-help" };

const std::array<std::string_view, 263> publishers = { "Academic Press", "Ace Books",
    "Addison-Wesley", "Adis International", "Airiti Press", "Andrews McMeel Publishing",
    "Anova Books", "Anvil Press Poetry", "Applewood Books", "Apress", "Athabasca University Press",
    "Atheneum Books", "Atheneum Publishers", "Atlantic Books", "Atlas Press", "Ballantine Books",
    "Banner of Truth Trust", "Bantam Books", "Bantam Spectra", "Barrie & Jenkins", "Basic Books",
    "BBC Books", "Harvard University Press", "Belknap Press", "Bella Books",
    "Bellevue Literary Press", "Berg Publishers", "Berkley Books", "Bison Books",
    "Black Dog Publishing", "Black Library", "Black Sparrow Books", "Blackie and Son Limited",
    "Blackstaff Press", "Blackwell Publishing", "John Blake Publishing", "Bloodaxe Books",
    "Bloomsbury Publishing Plc", "Blue Ribbon Books", "Book League of America", "Book Works",
    "Booktrope", "Borgo Press", "Bowes & Bowes", "Boydell & Brewer", "Breslov Research Institute",
    "Brill Publishers", "Brimstone Press", "Broadview Press", "Burns & Oates",
    "Butterworth-Heinemann", "Caister Academic Press", "Cambridge University Press",
    "Candlewick Press", "Canongate Books", "Carcanet Press", "Carlton Books",
    "Carlton Publishing Group", "Carnegie Mellon University Press", "Casemate Publishers",
    "Cengage Learning", "Central European University Press", "Chambers Harrap",
    "Charles Scribner's Sons", "Chatto and Windus", "Chick Publications", "Chronicle Books",
    "Churchill Livingstone", "Cisco Press", "City Lights Publishers", "Cloverdale Corporation",
    "D. Appleton & Company", "D. Reidel", "Da Capo Press", "Daedalus Publishing",
    "Dalkey Archive Press", "Darakwon Press", "David & Charles", "DAW Books", "Dedalus Books",
    "Del Rey Books", "E. P. Dutton", "Earthscan", "ECW Press", "Eel Pie Publishing",
    "Eerdmans Publishing", "Edupedia Publications", "Ellora's Cave", "Elsevier",
    "Emerald Group Publishing", "Etruscan Press", "Faber and Faber", "FabJob", "Fairview Press",
    "Farrar, Straus & Giroux", "Fearless Books", "Felony & Mayhem Press", "Firebrand Books",
    "Flame Tree Publishing", "Focal Press", "G. P. Putnam's Sons", "G-Unit Books",
    "Gaspereau Press", "Gay Men's Press", "Gefen Publishing House", "George H. Doran Company",
    "George Newnes", "George Routledge & Sons", "Godwit Press", "Golden Cockerel Press",
    "Hachette Book Group USA", "Hackett Publishing Company", "Hamish Hamilton", "Happy House",
    "Harcourt Assessment", "Harcourt Trade Publishers", "Harlequin Enterprises Ltd",
    "Harper & Brothers", "Harper & Row", "HarperCollins", "HarperPrism", "HarperTrophy",
    "Harry N. Abrams, Inc.", "Harvard University Press", "Harvest House",
    "Harvill Press at Random House", "Hawthorne Books", "Hay House", "Haynes Manuals",
    "Heyday Books", "HMSO", "Hodder & Stoughton", "Hodder Headline", "Hogarth Press",
    "Holland Park Press", "Holt McDougal", "Horizon Scientific Press", "Ian Allan Publishing",
    "Ignatius Press", "Imperial War Museum", "Indiana University Press", "J. M. Dent",
    "Jaico Publishing House", "Jarrolds Publishing", "Karadi Tales", "Kensington Books",
    "Kessinger Publishing", "Kodansha", "Kogan Page", "Koren Publishers Jerusalem",
    "Ladybird Books", "Leaf Books", "Leafwood Publishers", "Left Book Club", "Legend Books",
    "Lethe Press", "Libertas Academica", "Liberty Fund", "Library of America", "Lion Hudson",
    "Macmillan Publishers", "Mainstream Publishing", "Manchester University Press",
    "Mandrake of Oxford", "Mandrake Press", "Manning Publications", "Manor House Publishing",
    "Mapin Publishing", "Marion Boyars Publishers", "Mark Batty Publisher", "Marshall Cavendish",
    "Marshall Pickering", "Martinus Nijhoff Publishers", "Mascot Books", "Matthias Media",
    "McClelland and Stewart", "McFarland & Company", "McGraw-Hill Education",
    "McGraw Hill Financial", "Medknow Publications", "Naiad Press", "Nauka", "NavPress",
    "New Directions Publishing", "New English Library", "New Holland Publishers",
    "New Village Press", "Newnes", "No Starch Press", "Nonesuch Press", "Oberon Books",
    "Open Court Publishing Company", "Open University Press", "Orchard Books", "O'Reilly Media",
    "Orion Books", "Packt Publishing", "Palgrave Macmillan", "Pan Books",
    "Pantheon Books at Random House", "Papadakis Publisher", "Parachute Publishing", "Parragon",
    "Pathfinder Press", "Paulist Press", "Pavilion Books", "Peace Hill Press", "Pecan Grove Press",
    "Pen and Sword Books", "Penguin Books", "Random House", "Reed Elsevier", "Reed Publishing",
    "SAGE Publications", "St. Martin's Press", "Salt Publishing", "Sams Publishing",
    "Schocken Books", "Scholastic Press", "Charles Scribner's Sons", "Seagull Books",
    "Secker & Warburg", "Shambhala Publications", "Shire Books", "Shoemaker & Hoard Publishers",
    "Shuter & Shooter Publishers", "Sidgwick & Jackson", "Signet Books", "Simon & Schuster",
    "T & T Clark", "Tachyon Publications", "Tammi", "Target Books", "Tarpaulin Sky Press",
    "Tartarus Press", "Tate Publishing & Enterprises", "Taunton Press", "Taylor & Francis",
    "Ten Speed Press", "UCL Press", "Unfinished Monument Press",
    "United States Government Publishing Office", "University of Akron Press",
    "University of Alaska Press", "University of California Press", "University of Chicago Press",
    "University of Michigan Press", "University of Minnesota Press", "University of Nebraska Press",
    "Velazquez Press", "Verso Books", "Victor Gollancz Ltd", "Viking Press", "Vintage Books",
    "Vintage Books at Random House", "Virago Press", "Virgin Publishing", "Voyager Books", "Brill",
    "Allen Ltd", "Zed Books", "Ziff Davis Media", "Zondervan" };

const std::array<std::string_view, 19> book_series = {
    "Harry Potter",
    "The Lord of the Rings",
    "Game of Thrones",
    "Sherlock Holmes",
    "Percy Jackson",
    "The Hunger Games",
    "The Chronicles of Narnia",
    "Dune",
    "The Maze Runner",
    "The Wheel of Time",
    "A Song of Ice and Fire",
    "Discworld",
    "The Dark Tower",
    "The Hitchhiker's Guide to the Galaxy",
    "The Foundation Series",
    "His Dark Materials",
    "Outlander",
    "The Inheritance Cycle",
    "The Dresden Files",
};

const std::array<std::string_view, 100> titles = { "Romeo and Juliet", "Moby Dick",
    "A Room with a View", "Middlemarch", "Little Women",
    "The Complete Works of William Shakespeare", "The Blue Castle", "The Enchanted April",
    "The Adventures of Ferdinand Count Fathom", "Cranford", "The Expedition of Humphry Clinker",
    "The Adventures of Roderick Random", "History of Tom Jones, a Foundling", "Twenty Years After",
    "My Life", "Pride and Prejudice", "The grisly horror", "Alice's Adventures in Wonderland",
    "Frankenstein; Or, The Modern Prometheus", "Dracula", "The Picture of Dorian Gray",
    "A Tale of Two Cities", "The Adventures of Sherlock Holmes", "Metamorphosis",
    "The Great Gatsby", "Dora", "Ulysses", "The Count of Monte Cristo, Illustrated",
    "The Brothers Karamazov", "War and Peace", "Hitting the line", "The Yellow Wallpaper",
    "The slang dictionary", "Crime and Punishment", "The book of antelopes", "Travels in Kordofan",
    "Bunny Brown and his sister Sue on the rolling ocean", "The Iliad", "The Prince",
    "Grimms' Fairy Tales", "Great Expectations", "The Romance of Lust",
    "The Wonderful Wizard of Oz", "Moby Multiple Language Lists of Common Words",
    "The Kama Sutra of Vatsyayana", "The trial of Sacco and Vanzetti", "A Modest Proposal",
    "Beyond Good and Evil", "Tractatus Logico-Philosophicus", "Anna Karenina",
    "Thus Spake Zarathustra", "Jane Eyre", "Don Quixote", "Anne of Green Gables",
    "On the Duty of Civil Disobedience", "Treasure Island", "A Doll's House", "The nugget finders",
    "Meditations", "The Works of Edgar Allan Poe", "Demonology and Devil-lore",
    "A Study in Scarlet", "Winnie-the-Pooh", "Second Treatise of Government",
    "Adventures of Huckleberry Finn", "The Adventures of Tom Sawyer",
    "The Importance of Being Earnest: A Trivial Comedy for Serious People",
    "Walden, and On The Duty Of Civil Disobedience", "The Strange Case of Dr. Jekyll and Mr. Hyde",
    "Wuthering Heights", "The War of the Worlds", "The Philippines a Century Hence", "The Prophet",
    "The Republic", "Calculus Made Easy", "Little Women", "Ruth Fielding in Alaska",
    "The Rámáyan of Válmíki",
    "The adventures of Uncle Wiggily the bunny rabbit gentleman with the twinkling pink nose",
    "The divine comedy", "Peter Pan", "The King in Yellow", "The Odyssey", "Les Misérables",
    "The Scarlet Letter", "The Time Machine", "Emma", "A reference hand-book for nurses",
    "The Problems of Philosophy", "Carmilla", "Dao De Jing: A Minimalist Translation",
    "Notes from the Underground ", "Through the Looking-Glass", "My Bondage and My Freedom",
    "Essays of Michel de Montaigne", "The Magazine of History", "Josefine Mutzenbacher",
    "Heart of Darkness", "David Copperfield", "Three Men in a Boat (To Say Nothing of the Dog)" };

const std::array<std::string_view, 15> translators = {
    "Gregory Rabassa",
    "Edith Grossman",
    "Charlotte Mandell",
    "David Bellos",
    "Ann Goldstein",
    "C.K. Scott Moncrieff",
    "Lydia Davis",
    "Richard Howard",
    "Elliott Colla",
    "Katherine Silver",
    "Ros Schwartz",
    "Jennifer Croft",
    "Michael Hofmann",
    "Maureen Freely",
    "Natasha Wimmer",
};
}
