#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitness.h"

static exercise *db[MAX_EXERCISES];
static int num_items = 0;
static exercise *complt[MAX_EXER_COMPLT];
static int exercises_complt = 0;

int read_db(char *filename) {
        FILE *fp;
        if ((fp = fopen(filename, "r")) == NULL)
                return -1;

        char local_exercise[100], cat[100];
        int exercisenum, mins, laps, sets, reps, calorieburn, resistance;
        double mile_distance;
        for (num_items = 0; fscanf(fp, "%d %s %s %d %d %lf %d %d %d %d ", &exercisenum, cat, local_exercise, &mins, &laps, &mile_distance, &sets, &reps, &resistance, &calorieburn) != EOF; num_items++) {
                db[num_items] = malloc(sizeof(exercise));
                db[num_items]->exercisenum = exercisenum;
                strcpy(db[num_items]->name, local_exercise);
                db[num_items]->category = str_to_category(cat);
                db[num_items]->mins = mins;
                db[num_items]->laps = laps;
                db[num_items]->mile_distance = mile_distance;
                db[num_items]->sets = sets;
                db[num_items]->reps = reps;
                db[num_items]->resistance = resistance;
                db[num_items]->calorieburn = calorieburn;
        }
          fclose(fp);
        return num_items;
}

/*int write_db(char *filename) {
        FILE *fp;
        if ((fp = fopen(filename, "w")) == NULL)
                return -1;
        for (int i = 0; i < num_items; i++) {
                fprintf(fp, "%d %s %s %c %d %.2lf %d\n", db[i]->exercisenum, category_to_str(db[i]->category), db[i]->name, db[i]->mins, db[i]->laps, db[i]->mile_distance, db[i]->sets, db[i]->reps, db[i]->resistance, db[i]->calorieburn);
        }
        fclose(fp);
        return 0;
}*/
