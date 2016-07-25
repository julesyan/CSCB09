#include "mud.h"
#include "lang.h"
#include "nplaces.h"

/* French language data */

#define NTHINGS 10
int lang_nplaces = NPLACES;
int lang_nthings = NTHINGS;

/* ok to use isupper()/tolower() on user input? */
int lang_use_tolower = 1;

char *lang_directions[6][2] = {
    { "nord", "n" },
    { "sud", "s" },
    { "ouest", "o" },
    { "est", "e" },
    { "haut", "h" },
    { "bas", "b" },
};
char *lang_nosuchexit = "Ce n'est pas possible d'aller dans cette direction.";

char *lang_get = "prendre";
char *lang_drop = "laisser";
char *lang_get_nosuch = "L'objet avec cette nombre n'est pas ici.";
char *lang_drop_nosuch = "Vous n'avez pas l'objet avec cette nombre.";
char *lang_getdrop_explain = "Dire '%s' suivi par le nombre de l'objet.\n";

char *lang_look[2] = { "regarder", "r" };
char *lang_inv[2] = { "inv", "i" };
char *lang_inv_heading = "Vous avez maintenant:";
char *lang_inv_nothing = "Rien!";

char *lang_poke = "poke";
char *lang_poke_explain = "Dire '%s' suivi par le nombre de la personne.\n";
char *lang_poked_by = "Vous avez été envoyé un poke par";
char *lang_arrived = "est arrivé(e).";
char *lang_departed = "n'est plus ici.";

char *lang_toolong = "Cette commande est trop longue.  Ecrire un ou deux mots.";
char *lang_huh = "Je ne comprends pas cette commande.";
char *lang_req_obj_number = "Désolé, vous devez écrire la nombre de l'objet ou de la personne, pas son nom.";
char *lang_commandlist = "Ecrire un de ce qui suit:";
char *lang_ok = "OK";

char *lang_say = "dire";
char *lang_say_explain = "Taper '%s' suivi par ce que vous voulez dire.\n";
char *lang_says_format = "%s dit:";

char *lang_yesno[2][2] = {
    { "oui", "o" },
    { "non", "n" }
};

char *lang_youat = "Vous êtes à:";
char *lang_youcango = "Vous pouvez aller";
char *lang_go_to = "à";  /* used like: "north %s the cafeteria" */
char *lang_thereis_format = "Il y a %s ici.";

char *lang_handle_request = "Veuillez écrire un «handle» que vous souhaitez être connu par";

char *lang_place_title[NPLACES] = {
    /*  0 */ "l'arrêt autobus",
    /*  1 */ "le hall du bâtiment IC",
    /*  2 */ "l'entrée du bâtiment Bladen",
    /*  3 */ "BV 473",
    /*  4 */ "l'entrée du bâtiment Sciences",
    /*  5 */ "le 2eme étage d'IC",
    /*  6 */ "la zone des escaliers du 3eme étage d'IC",
    /*  7 */ "IC 328",
    /*  8 */ "la zone des escaliers du 4eme étage d'IC",
    /*  9 */ "l'entrée de département de CMS",
    /* 10 */ "le bureau ajr",
    /* 11 */ "la cafétéria",
    /* 12 */ "l'extrémité nord du bâtiment IC",
    /* 13 */ "IC 130",
    /* 14 */ "le bâtiment Sciences de l'Environnement et du Chimie",
    /* 15 */ "une zone d'étude dans IC",
    /* 16 */ "IC 120",
};

char *lang_place_detail[NPLACES] = {
    /* bus stop */ "Il y a une énorme file d'étudiants attendant votre autobus.  Bonne chose que\nvous arrivez à UTSC plutôt que de laisser.",
    /* IC lobby */ "Une publicité indique: «Dépensez plus! Obtenez moins!»",
    /* Bladen entrance */ 0,
    /* BV 473 */ "Tant de travail... si peu d'heures.",
    /* SW entrance */ 0,
    /* IC 2fl */ "Les escaliers montent et les escaliers descendent, aussi loin que l'œil peut voir.",
    /* IC 3fl */ "Les escaliers montent un peu plus loin, mais la fin est en vue.",
    /* IC 328 */ "ajr n'est pas ici parce que ce n'est pas encore 17:30.",
    /* IC 4fl */ "Les escaliers descendent, aussi loin que l'œil peut voir.",
    /* CMS entrance */ "Un grand signe de bienvenue dit «Computer and Mathematical Sciences» (sciences informatique et mathématique).",
    /* ajr */ "Vous êtes bureau de ajr extérieur, mais la porte est fermée -- ajr n'est pas\nici parce que ses heures de bureau sont en IC 328!",
    /* cafeteria */ "Étrangement, la file n'est pas très long aujourd'hui.",
    /* north IC */ "L'objet exposé d'art le plus nouveau est un peu étrange.",
    /* IC 130 */ "Il y a un test en cours ici, et tout le monde vous regarde.",
    /* env sci */ "Vous ne pouvez pas aller nulle part ici, parce qu'ajr ne connait pas ce bâtiment\net n'a pas le mis dans le jeu!",
    /* IC study */ "En réponse aux plaintes, un ouvrier boulonne les tables au sol.",
    /* IC 120 */ "Vous êtes à 15 minutes à l'avance de votre classe -- assez de temps pour prendre\nun café si vous le souhaitez.",
};

char *lang_thing[NTHINGS] = {
    /*  0 */ "un journal étudiant intéressant",
    /*  1 */ "un idiot qui hurle à un téléphone portable",
    /*  2 */ "un journal jeté",
    /*  3 */ "une tasse de café vide",
    /*  4 */ "un gros café",
    /*  5 */ "un sandwich cher",
    /*  6 */ "un papier chiffonné",
    /*  7 */ "un clé USB",
    /*  8 */ "un peut de soude",
    /*  9 */ "un formulaire de demande de carte de crédit ombragé",
};
