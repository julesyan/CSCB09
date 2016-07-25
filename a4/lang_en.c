#include "mud.h"
#include "lang.h"
#include "nplaces.h"

/* English language data */

#define NTHINGS 10
int lang_nplaces = NPLACES;
int lang_nthings = NTHINGS;

/* ok to use isupper()/tolower() on user input? */
int lang_use_tolower = 1;

char *lang_directions[6][2] = {
    { "north", "n" },
    { "south", "s" },
    { "west", "w" },
    { "east", "e" },
    { "up", "u" },
    { "down", "d" },
};
char *lang_nosuchexit = "There is no way to go that direction.";

char *lang_get = "get";
char *lang_drop = "drop";
char *lang_get_nosuch = "No such object number at this location.";
char *lang_drop_nosuch = "No such object number amongst your possessions.";
char *lang_getdrop_explain = "Say '%s' followed by the number of the object.\n";

char *lang_look[2] = { "look", "l" };
char *lang_inv[2] = { "inv", "i" };
char *lang_inv_heading = "You are currently carrying:";
char *lang_inv_nothing = "Nothing!";

char *lang_poke = "poke";
char *lang_poke_explain = "Say '%s' followed by the number of the person.\n";
char *lang_poked_by = "You have been poked by";
char *lang_arrived = "is now here.";
char *lang_departed = "is no longer here.";

char *lang_toolong = "That command is too long.  Type one or two words.";
char *lang_huh = "I don't understand that command.";
char *lang_req_obj_number = "Sorry, you need to type the object or person's number, not its name.";
char *lang_commandlist = "Type one of:";
char *lang_ok = "OK";

char *lang_say = "say";
char *lang_say_explain = "Type '%s' followed by what you want to say.\n";
char *lang_says_format = "%s says:";

char *lang_yesno[2][2] = {
    { "yes", "y" },
    { "no", "n" }
};

char *lang_youat = "You are at:";
char *lang_youcango = "You can go";
char *lang_go_to = "to";  /* used like: "north %s the cafeteria" */
char *lang_thereis_format = "There is %s here.";

char *lang_handle_request = "Please enter a handle you wish to be known by";

char *lang_place_title[NPLACES] = {
    /*  0 */ "the bus stop area",
    /*  1 */ "the IC building lobby",
    /*  2 */ "the Bladen building entrance",
    /*  3 */ "BV 473",
    /*  4 */ "the Science building entrance",
    /*  5 */ "the 2nd floor of IC",
    /*  6 */ "the stair area of the 3rd floor of IC",
    /*  7 */ "IC 328",
    /*  8 */ "the stair area of the 4th floor of IC",
    /*  9 */ "the CMS department entrance",
    /* 10 */ "ajr's office",
    /* 11 */ "the cafeteria",
    /* 12 */ "the north end of the IC building",
    /* 13 */ "IC 130",
    /* 14 */ "the Environmental Science and Chemistry building",
    /* 15 */ "an IC study area",
    /* 16 */ "IC 120",
};

char *lang_place_detail[NPLACES] = {
    /* bus stop */ "There is a huge queue of students waiting for your bus.\nGood thing you're arriving at UTSC rather than leaving.",
    /* IC lobby */ "An advertisement says, 'spend more and get less!'",
    /* Bladen entrance */ 0,
    /* BV 473 */ "So much work... so little time.",
    /* SW entrance */ 0,
    /* IC 2fl */ "The stairs go up and the stairs go down, as far as the eye can see.",
    /* IC 3fl */ "The stairs go up a little further, but the end is in sight.",
    /* IC 328 */ "ajr isn't here because it's not 17:30 yet.",
    /* IC 4fl */ "The stairs go down as far as the eye can see.",
    /* CMS entrance */ "A large welcoming sign says 'Computer and Mathematical Sciences'.",
    /* ajr */ "You are outside ajr's office, but the door is closed -- ajr isn't here because\nhis office hours are in IC 328!",
    /* cafeteria */ "Strangely enough the queue isn't very long today.",
    /* north IC */ "The newest art exhibit is just a little weird.",
    /* IC 130 */ "There is a midterm test in progress here, and everyone is staring at you.",
    /* env sci */ "You can't go anywhere here, because ajr doesn't know this building and didn't\nput it in the game!",
    /* IC study */ "In response to complaints, a worker is bolting the tables to the floor.",
    /* IC 120 */ "You are 15 minutes early for your class -- enough time to get a coffee if you\nlike.",
};

char *lang_thing[NTHINGS] = {
    /*  0 */ "an interesting student newspaper",
    /*  1 */ "an idiot yelling on a cell phone",
    /*  2 */ "a discarded newspaper",
    /*  3 */ "an empty coffee cup",
    /*  4 */ "a large coffee",
    /*  5 */ "an expensive sandwich",
    /*  6 */ "a crumpled piece of paper",
    /*  7 */ "a USB memory stick",
    /*  8 */ "a pop can",
    /*  9 */ "a shady credit card application form",
};
