#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fitness.h"

static exercise *db[MAX_EXERCISES];
static user *users[MAX_USERS];
static int num_items = 0;
static int num_users = 0;
static exercise *complt[MAX_EXER_COMPLT];
static int exercises_complt = 0;
static int currentUser = 0;

int get_num(){
	return num_users;	
	}
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

int read_users(char *filename) {
        FILE *fp;
        if ((fp = fopen(filename, "r")) == NULL)
                return -1;

        
        int age;
	double weight;
	double height;
	char name[36];
	char gender[2];
        for (num_users = 0; fscanf(fp, "%d %lf %lf %s %s", &age, &weight, &height, name, gender) != EOF; num_users++) {
                users[num_users] = malloc(sizeof(user));
                users[num_users]->age = age;
		users[num_users]->weight = weight;
		users[num_users]->height = height;
                strcpy(users[num_users]->name, name);
		strcpy(users[num_users]->gender, gender);
        }
        fclose(fp);
        return num_users;
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
int write_users(char *filename) {
        FILE *fp;
        if ((fp = fopen(filename, "w")) == NULL)
                return -1;
        for (int i = 0; i < num_users; i++) {
                fprintf(fp, "%d %.2lf %.2lf %s %s\n", users[i]->age, users[i]->weight, users[i]->height, users[i]->name, users[i]->gender );
        }
        fclose(fp);
        return 0;
}

int get_num_users() {
	return num_users;
}

void display_exercises() {
	for (int i = 0; i < num_items; i++) {
		printf("%d %s %s %d %d %.1lf %d %d %d %d\n", db[i]->exercisenum, category_to_str(db[i]->category), db[i]->name, db[i]->mins, db[i]->laps, db[i]->mile_distance, db[i]->sets, db[i]->reps, db[i]->resistance, db[i]->calorieburn);

	}
}
void display_users() {
	for (int i = 0; i < num_users; i++) {
		printf("%d %.2lf %.2lf %s %s\n", users[i]->age, users[i]->weight, users[i]->height, users[i]->name, users[i]->gender);

	}
}

char get_user_name() {
	return users[currentUser]->name;
}

void update_user_age(int age){
	users[currentUser]->age = age;
}

void update_user_weight(double weight){
	users[currentUser]->weight = weight;
}

void update_user_height(double height){
	users[currentUser]->height = height;
}

void swap_user(int user){
	if(user<0||user>num_users-1){
	}
	else{
	currentUser = user;
	printf("\n You are now signed in as:  ");
	printf("%s", (users[currentUser]->name));
	}
}

double gain_wt(){
	double calories = metabolic_wt()+500;
	return calories;
}

double lose_wt(){
	double calories = metabolic_wt()-500;
	return calories;
}

double metabolic_wt(){
	double age = (users[currentUser]->age);
	double weight = (users[currentUser]->weight)/2.2046;
	double height = (users[currentUser]->height)/0.032808;
	char gender = (users[currentUser]->gender)[0];
	double calories = 0.0;
	if(gender=='m'){
	calories = 66.5 + (13.75*weight) + (5.003 * height) - (6.775 * age);
	}
	else if(gender=='f'){
	calories = 655.1 + (9.563*weight) + (1.850 * height) - (4.676 * age);
	}
	
	return calories;
}
double body_fat(){
	double weight = (users[currentUser]->weight)/2.2046;
	double height = ((users[currentUser]->height)/0.032808)/100.00;
	double bmi = weight/(height*height);
	return bmi;
	
}

void add_user(int age, double weight, double height, char *name, char *gender){
		
		 
		users[num_users] = malloc(sizeof(user));
		users[num_users]->age = age;
		users[num_users]->weight = weight;
		users[num_users]->height = height;
		strcpy(users[num_users]->name, name);
		strcpy(users[num_users]->gender, gender);
		num_users++;
		currentUser = users[num_users];
		
}

exercise *find_exercise_num(int exercisenum) {
	for (int i = 0; i < num_items; i++) {
		if (db[i]->exercisenum == exercisenum)
			return db[i];
	}
	return 0;
}

exercise *exercise_complt(int exercisenum) {
	for (int i = 0; i < num_items; i++) {
		if (db[i]->exercisenum == exercisenum) {
			exercises_complt++;
			int j = exercises_complt-1;
			complt[j] = db[i];
			return complt[j];
		}
	}
	return 0;
}

char *category_to_str(category c) {
	        switch(c) {
	                case 0:
	                        return "cardio";
	                        break;
	                case 1:
		                return "bike";
		                break;
		        case 2:
		                return "swim";
		                break;
		        case 3:
		                return "weightlift";
		                break;
		        default:
		                return 0;
     }
}
	
category str_to_category(char *s) {
        if (strcmp(s, "cardio") == 0 )
                return cardio;
        else if (strcmp(s, "bike") == 0 )
	        return bike;
	else if (strcmp(s, "swim") == 0 )
	        return swim;
	else if (strcmp(s, "weightlift") == 0 )
	        return weightlift;
	else
	        return 0;
}


