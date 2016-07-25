#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mud.h"
#include "map.h"

/* directions sequence: north, south, west, east, up, down */
struct placeinfo places[] = {

    { "bus", { "iclobby", 0, "bladen", 0, 0, 0 } },
    { "iclobby", { "icnorth", "bus", "ic130", "cafe", "ic2fl", 0 } },
    { "bladen", { 0, 0, "science", "bus", "bv473", 0 } },
    { "bv473", { 0, 0, 0, 0, 0, "bladen" } },
    { "science", { 0, 0, 0, "bladen", 0, 0 } },
    { "ic2fl", { 0, 0, 0, 0, "ic3fl", "iclobby" } },
    { "ic3fl", { 0, 0, "ic328", 0, "ic4fl", "ic2fl" } },
    { "ic328", { 0, 0, 0, "ic3fl", 0, 0 } },
    { "ic4fl", { 0, 0, "cms", 0, 0, "ic2fl" } },
    { "cms", { "ajr", 0, 0, "ic4fl", 0, 0 } },
    { "ajr", { 0, "cms", 0, "ic4fl", 0, 0 } },
    { "cafe", { 0, 0, "iclobby", 0, 0, 0 } },
    { "icnorth", { "envsci", "iclobby", "study", "ic120", 0, 0 } },
    { "ic130", { 0, 0, 0, "iclobby", 0, 0 } },
    { "envsci", { 0, "icnorth", 0, 0, 0, 0 } },
    { "study", { 0, 0, 0, "icnorth", 0, 0 } },
    { "ic120", { 0, 0, "icnorth", 0, 0, 0 } },
};
int nplaces = sizeof places / sizeof places[0];

struct placeindex {
    char *label;
    int index;
};
int mycompare(const void *a, const void *b) {
    return(strcmp(((struct placeindex *)a)->label,((struct placeindex *)b)->label));
}
int myfind(struct placeindex *pi, char *label) {
    struct placeindex key, *result;
    key.label = label;
    result = bsearch(&key, pi, nplaces, sizeof pi[0], mycompare);
    if (!result) {
	fprintf(stderr, "fatal error in map.c: can't find label '%s'\n",
		label);
	exit(1);
    }
    return(result->index);
}


void map_setup()
{
    int i, j;
    struct placeindex pi[sizeof places / sizeof places[0]];

    for (i = 0; i < nplaces; i++) {
	pi[i].label = places[i].label;
	pi[i].index = i;
    }
    qsort(pi, nplaces, sizeof pi[0], mycompare);

    for (i = 0; i < nplaces; i++) {
	for (j = 0; j < NDIRECTIONS; j++) {
	    if (places[i].exit_label[j])
		places[i].exit_loc[j] = myfind(pi, places[i].exit_label[j]);
	    else
		places[i].exit_loc[j] = -1;
	}
    }
}
