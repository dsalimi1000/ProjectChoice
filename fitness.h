#define MAX_EXERCISES 20
#define MAX_EXER_CHARS 32
#define MAX_EXER_COMPLT 3

typedef enum { cardio, bike, swim, weightlift } category;
typedef struct {
        int exercisenum;
        category category;
        char name[MAX_EXER_CHARS];
        double mins;
        int laps;
        double distance;
        int sets;
        int reps;
        int resistance;
} exercise;

//read/write files
int read_db(char *filename);
int write_db(char *filename);

//Store user data: create struct ‘exerciser’ with name, age, weight, gender, height
//Create user
add_user(string name, int age, double weight, char gender, double height);

//Update user data:  any user status can be modified while running the program 
update_user_age(int index, int age);
update_user_weight(int index, double weight);
update_user_height(int index, double height);

//Calculate caloric intake(the following are void functions which use user inputted data to calculate -> weight, age, height, gender
Gain weight: ()
get gain_wt
Lose weight: ()
get lose_wt
Maintain weight:()
get metabolic_wt

//Calculate approximate body mass index
Body Fat ()
Get body_fat

//Display exercises: saved file with all exercises
//The assigned number is the general estimated calorie burn (i.e. walking=200 per hour, running=600 per hour)
//Log user exercises and calorie burn
//Add to array lists--exercise array, calorie array
add_exercise(int minutes, string exercise);
//Save data: write file
//Write file saves the file titled in the users name and appends .txt at the end of the name (i.e. Susan.txt)
//Data saved includes name, age, weight, gender, height, exercises performed (array), total calories burned (array)
//Load data: read file
//Read file scans in the file titled in the users name with .txt appended at the end of the name to find the saved file (i.e. Susan.txt)
//Exit without saving
//Ends the program and does not save, save must be performed first by save data if saving is desired.