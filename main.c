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
	/*char name[36] = "Daud";
	int age = 21;
	double weight = 195.5;
	char gender[2] = "m";
	double height = 6.2;
	write_users("users.txt");
	printf("%.0lf\n", metabolic_wt());
	printf("%.0lf\n", gain_wt());
	printf("%.0lf\n", lose_wt());
	printf("%.2lf\n", body_fat());
	*/
	char input_str[10];
	int menu_input;
	printf("Welcome to the Fitness Tracker!\n\n");
	printf("Enter user first name. If you are new, type 'new': ");
	fgets(input_str, 10, stdin);
	if (strcmp(input_str, "new") == 0)
		printf("\nWelcome back!\n");
	
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
	printf("1. Add New User\n2. Display Saved Exercises\n3. View Exercise Choices\n4. \n5. \n6. Update Age, Weight, or Height\n7. Save User Profile\n8. Quit\n9. Exit\n\n");
}

int get_menu_selection(int num) {
	//char filename[] = "test.txt";
	int age, num_userX;
	double weight, height;
	char user_name[20], gender[2], ans[2];
	switch(num) {
		case 1:
			num_userX = get_num_users();
			printf("numusers = %d", num_userX);
			if(num_userX == 5) {
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
		case 6:
			printf("Would you like to update your age? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0) {
				printf("\nEnter age: ");
				scanf("%d", &age);
				update_user_age(age);
			}
			printf("Would you like to update your weight? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0) {
				printf("\nEnter weight: ");
				scanf("%lf", &weight);
				update_user_weight(weight);
			}
			printf("Would you like to update your height? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0) {
				printf("\nEnter height: ");
				scanf("%lf", &height);
				update_user_height(height);
			}
			break;
		case 7:
			//write_users(filename);
			printf("Your profile was saved.");
			break;
		case 9:
			exit(0);
			break;
		
		default:
			printf("Please enter a valid menu option.");
	}		
}
