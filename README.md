# ProjectChoice
project choice repository

Daud Salimi and Tamra Arant
CPSC 305, Professor Cooper
March 26, 2021

Fitness Tracker Program Specification

INTRODUCTION
Project Scope
The Fitness Tracker Program recommends and tracks exercises performed by a user as well as provides relative fitness data. Specific data points related to exercising are recorded, used in calculation, and saved to a user’s profile. A user’s age, weight, gender, and height are inputs used to calculate specific data points such as a user’s basal metabolic rate, recommended caloric intake, and body mass index (BMI). A user may view a list of recommended exercises with the estimated calorie burn and log the exercises performed with actual total calories burned. In conclusion, the program provides fitness calculations, recommends and logs completed exercises, and saves user fitness data.
   
DESCRIPTION
Functionality
The program will store a user’s first name, age, weight, gender, and height. It will use this information to calculate a user’s basal metabolic rate and the caloric intake required to gain or to lose a pound or two pounds a week. The program will have functionality to display exercise options and their associated calorie burning benefits. (Ex. 30 minutes walking: 250 calories burned). The program will store and save all the user information in a file if the user chooses to save data. The program will also allow the user to input their exercises and have access to how many calories these exercises burned based on how many minutes they were performed, not dependent on user data. Other functionality will include a body mass index calculator.

Features
Store user data: create struct ‘exerciser’ with name, age, weight, gender, height
Create user
add_user(string name, int age, double weight, char gender, double height)
Update user data:  any user status can be modified while running the program.
Update user data
update_user_age(int index, int age)
update_user_weight(int index, double weight)
update_user_height(int index, double height)
Calculate caloric intake(the following are void functions which use user inputted data to calculate -> weight, age, height, gender
Gain weight: ()
get gain_wt
Lose weight: ()
get lose_wt
Maintain weight:()
get metabolic_wt
Calculate approximate body mass index
Body Fat ()
Get body_fat
Display exercises: saved file with all exercises
The assigned number is the general estimated calorie burn (i.e. walking=200 per hour, running=600 per hour)
Log user exercises and calorie burn
Add to array lists--exercise array, calorie array
add_exercise(int minutes, string exercise)
Save data: write file
Write file saves the file titled in the users name and appends .txt at the end of the name (i.e. Susan.txt)
Data saved includes name, age, weight, gender, height, exercises performed (array), total calories burned (array)
Load data: read file
Read file scans in the file titled in the users name with .txt appended at the end of the name to find the saved file (i.e. Susan.txt)
Exit without saving
Ends the program and does not save, save must be performed first by save data if saving is desired.

EXTERNAL INTERFACE
User Interface
The program first prompts a user to select whether he or she is a new user or returning user. A new user is prompted to enter his or her first_name, age, weight, gender, and height. A returning user must enter his or her first_name.

New user menu:
Enter New Exerciser
Returning user menu:
Load Exerciser Profile
Established users are presented with the following menu options:
View Exercises with Calorie Burn
Calorie Intake to Lose Weight
Calorie Intake to Gain Weight
Metabolic rate(Maintain Weight)
BMI Calculator
Update Weight, Age or Height
Log Exercises and Calories Burned
Save Profile
Exit without saving

If the user previously created and saved a profile, the user may load the saved data. A user may view a preloaded list of exercises and the estimated calorie burn.
