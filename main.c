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
	int num = get_num();
	if(num==0){
		get_menu_selection(1);
	}
	do {
		printf("\n      MENU\n");
		print_menu();
		printf("Choose a menu option (i.e 1): ");
		scanf("%d", &menu_input);
		if (menu_input < 1 || menu_input > 9)
			printf("Please enter a valid menu option.\n");
		else
			get_menu_selection(menu_input);
	} while (menu_input != 8);





	return 0;
}

void print_menu() {
        printf("1. Add New User \n2. View Exercise Choices \n3. Display Saved Exercises\n4. Select User \n5. Display BMI and Caloric Intake \n6. Update user data\n7. save \n8. quit.\n\n");
}

int get_menu_selection(int num) {
	//char filename[] = "test.txt";
	int age, num_userX;
	double weight, height;
	char user_name[20], gender[2], ans[2];
	exercise *ret;
	int exercisenum;
	int usernum = 0;
	switch(num) {
		case 1:
			num_userX = get_num_users();
			printf("numusers = %d\n", num_userX);
			if(num_userX == 5) {
				printf("\n   MAX USERS REACHED. Please delete a user first.");
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
		case 2:
			display_exercises();
			printf("Enter the exercise number for the exercise you completed: \n");
                        scanf("%d", &exercisenum);
                        ret = find_exercise_num(exercisenum);
                        if (ret != 0) {
                                exercise_complt(exercisenum);
                                printf("\nYou saved exercise %s and burned %d calories.\n", ret->name, ret->calorieburn);
                        } else
                                printf("Exercise number not found.");
                        break;
		case 3:
			display_exercises();
			break;
		case 4:
			printf("Enter the user number to switch to(1-5):  ");
			scanf("%d", &usernum);
			swap_user(usernum-1);
			break;
		case 5: 
			printf("\n Metabolic Rate:       ");
			printf("%.2lf", metabolic_wt());
			printf("\n Lose a pound a week:  ");
			printf("%.2lf", lose_wt());
			printf("\n Gain a pound a week:  ");
			printf("%.2lf", gain_wt());
			printf("\n Body fat percentage:  ");
			printf("%.2lf", body_fat());
			printf("\n");
			break;	
		case 6:
			printf("Would you like to update your age? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0||strcmp(ans, "y") == 0) {
				printf("\nEnter age: ");
				scanf("%d", &age);
				update_user_age(age);
			}
			printf("Would you like to update your weight? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0||strcmp(ans, "y") == 0) {
				printf("\nEnter weight: ");
				scanf("%lf", &weight);
				update_user_weight(weight);
			}
			printf("Would you like to update your height? Y or N. ");
			scanf("%s", ans);
			if (strcmp(ans, "Y") == 0||strcmp(ans, "y") == 0) {
				printf("\nEnter height: ");
				scanf("%lf", &height);
				update_user_height(height);
			}
		case 7:
			write_users("users.txt");
			printf("Your profile was saved.");
			break;	
		case 8:
			return 0;
			break;
		default:
			printf("Please enter a valid menu option.");
	}		
}
