/* objects in the game */
/* (not as in "object-oriented", but as in things you pick up) */

/* Where each thing is.  Negative if in the possession of a player. */
int thing_place[] = {
    /* student newspaper */ 1,
    /* idiot */ 0,
    /* discarded newspaper */ 4,
    /* empty coffee cup */ 4,
    /* coffee */ 11,
    /* expensive sandwich */ 11,
    /* crumpled paper */ 14,
    /* USB memory stick */ 3,
    /* pop can */ 15,
    /* credit card form */ 2,
};
int n_thing_place = sizeof thing_place / sizeof thing_place[0];
