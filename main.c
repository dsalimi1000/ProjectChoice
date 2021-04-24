#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitness.h"

void print_menu();
int get_menu_selection(int num);

int main(int argc, char **argv) {

	int num_items = 0;
	int num_users = 0;
	num_users = read_users("users.txt");
	num_items = read_db("exercises.txt");
	
	display_users();
	char input_str[10];
	int menu_input;
	printf("Welcome to the Fitness Tracker!\n\n");
	printf("Enter user first name. If you are new, type 'new': ");
	fgets(input_str, 10, stdin);
	if ((strcmp(input_str, "new"))==1)
		printf("\nWelcome back!\n");
	else{
		get_menu_selection(1);
	}
	
	do {
		printf("\n      MENU\n");
		print_menu();
		printf("Choose a menu option (i.e 1): ");
		scanf("%d", &menu_input);
		if (menu_input < 1 || menu_input > 10)
			printf("Please enter a valid menu option.\n");
		else
			get_menu_selection(menu_input);
	} while (menu_input != 9);





	return 0;
}

void print_menu() {
	printf("1. Add New User \n2. Display Saved Exercises \n3. View Exercise Choices \n4. Swap User \n5. Display BMI and Caloric Intake \n6. \n7. \n8.  \n9. Save\n10. Exit\n\n");
}

int get_menu_selection(int num) {
	int age, num_userX;
	double weight, height;
	char user_name[20], gender[2];
	int usernum = 0;
	switch(num) {
		case 1:
			num_userX = get_num_users();
			printf("numusers = %d\n", num_userX);
			if(num_userX == 5) {
				printf("%\n");
				printf("MAX USERS REACHED. Please delete a user first.");
			} else {
				printf("Please enter the user's first name: ");
				scanf("%s", user_name);
				printf("Please enter your age: ");
				scanf("%d", &age);
				printf("Please enter your weight: ");
				scanf("%lf", &weight);
				printf("Please enter your height: ");
				scanf("%lf", &height);
				printf("Please enter your gender: ");
				scanf("%s", gender);
				add_user(age, weight, height, user_name, gender);
				printf("New user %s was added.\n", user_name);
			}
			break;
		case 3:
			display_exercises();
		case 4:
			printf("Enter the user number to switch to(1-5):  ");
			scanf("%d", &usernum);
			swap_user(usernum-1);
			break;
		case 5: 
			printf("\n Metabolic Rate:  ");
			printf("%lf", metabolic_wt());
			printf("\n Lose a pound a week:  ");
			printf("%lf", lose_wt());
			printf("\n Gain a pound a week:  ");
			printf("%lf", gain_wt());
			printf("\n Body fat percentage:  ");
			printf("%lf", body_fat());
			printf("\n");
			break;
		case 9:
			write_users("users.txt");
			printf("Your profile was saved.");
			break;
		case 10:
			exit(0);
			break;
		
		default:
			printf("Please enter a valid menu option.");
	}		
}
