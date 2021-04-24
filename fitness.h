#define MAX_EXERCISES 20
#define MAX_EXER_CHARS 32
#define MAX_EXER_COMPLT 3
#define MAX_USERS 5


typedef enum { cardio, bike, swim, weightlift } category;

typedef struct {
        int exercisenum;
        category category;
        char name[MAX_EXER_CHARS];
        int mins;
        int laps;
        double mile_distance;
        int sets;
        int reps;
        int resistance;
        int calorieburn;
} exercise;

typedef struct {
	char name[36];
	int age;
	double weight;
	char gender[2];
	double height;
} user;

//read/write files
int read_db(char *filename);
int read_users(char *filename);
int write_db(char *filename);
int write_users(char *filename);
category str_to_category(char *s);
char *category_to_str(category c);//
//Store user data: create struct ‘exerciser’ with name, age, weight, gender, height
//Create user
//add_user(string name, int age, double weight, char gender, double height);

//Update user data:  any user status can be modified while running the program
void add_user(int age, double weight, double height, char *name, char *gender); 
void swap_user(int user);
void update_user_age(int age);
void update_user_weight(double weight);
void update_user_height(double height);

//Calculate caloric intake(the following are void functions which use user inputted data to calculate -> weight, age, height, gender

double gain_wt();
double lose_wt();
double metabolic_wt();

//Calculate approximate body mass index

double body_fat();

//Display exercises: saved file with all exercises
void display_exercises();
void display_users();
exercise *find_exercise_num(int exercisenum);
exercise *exercise_complt(int exercisenum);
double calc_body_mass_index(double weight_lbs, double height_ins);
//Log user exercises and calorie burn
//Add to array lists--exercise array, calorie array
//add_exercise(int minutes, string exercise);
//Save data: write file
//Write file saves the file titled in the users name and appends .txt at the end of the name (i.e. Susan.txt)
//Data saved includes name, age, weight, gender, height, exercises performed (array), total calories burned (array)
//Load data: read file
//Read file scans in the file titled in the users name with .txt appended at the end of the name to find the saved file (i.e. Susan.txt)
//Exit without saving
//Ends the program and does not save, save must be performed first by save data if saving is desired.
