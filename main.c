#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitness.h"
int main(){
	read_users("users.txt");
	read_db("exercises.txt");
	display_users();
	char name[36] = "Daud";
	int age = 21;
	double weight = 195.5;
	char gender[2] = "m";
	double height = 6.2;
	write_users("users.txt");
	printf("%.0lf\n", metabolic_wt());
	printf("%.0lf\n", gain_wt());
	printf("%.0lf\n", lose_wt());
	printf("%.2lf\n", body_fat());
}
