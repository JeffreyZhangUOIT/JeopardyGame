// Global char* question and answer. Messy but will get the job done.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// initializes categories, answers, answered, point value
void initialize_game(void)
{
	strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "A loop that never ends is referred to as a(n)");
	strcpy(questions[0].answer, "Infinite loop");
	questions[0].value = 100;
	questions[0].answered = false;

	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "What is the most basic language Microsoft made? Visual Basic, DirectX, Batch, C++, .Net namespace");
	strcpy(questions[1].answer, "Visual Basic");
	questions[1].value = 200;
	questions[1].answered = false;

	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "What is the most complicated language? Actionscript, C, C#, .NET, C++, Python");
	strcpy(questions[2].answer, "C++");
	questions[2].value = 300;
	questions[2].answered = false;

	strcpy(questions[3].category, "programming");
	strcpy(questions[3].question, "You have just constructed your first for loop within the Java Language. Which of the following is not a required part of a for loop? Initialization, Condition, Variable, Increment");
	strcpy(questions[3].answer, "Variable");
	questions[3].value = 400;
	questions[3].answered = false;




	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "Stacks are also known as which type of structures");
	strcpy(questions[4].answer, "LIFO");
	questions[4].value = 100;
	questions[4].answered = false;

	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "Which of the following is/are levels of implementation of data structures? Abstract level, Application level, Implementation level, All of the above");
	strcpy(questions[5].answer, "All of the above");
	questions[5].value = 200;
	questions[5].answered = false;

	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "Which level is where the model becomes compatible executable code? Abstract level, Application level, Implementation level");
	strcpy(questions[6].answer, "Implementation level");
	questions[6].value = 300;
	questions[6].answered = false;

	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "A binary search tree whose left subtree and right subtree differ in height by at most 1 unit is called ____ AVL tree, Red-black tree, Lemma tree, None of the above");
	strcpy(questions[7].answer, "AVL tree");
	questions[7].value = 400;
	questions[7].answered = false;




	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "A method defines the form or protocol of the operation, but not its implementation. True, False");
	strcpy(questions[8].answer, "False");
	questions[8].value = 100;
	questions[8].answered = false;

	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "The DBMS acts as an interface between what two components of an enterprise-class database system? Database application and the database, Data and the database, The user and the database application, Database application and SQL");
	strcpy(questions[9].answer, "Database application and the database");
	questions[9].value = 200;
	questions[9].answered = false;

	strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "The following are components of a database except ________ . User data, metadata, reports, indexes");
	strcpy(questions[10].answer, "Reports");
	questions[10].value = 300;
	questions[10].answered = false;

	strcpy(questions[11].category, "databases");
	strcpy(questions[11].question, "The fact that the same operation may apply to two or more classes is called what? Inheritance, Polymorphism, Encapsulation, Multiple classification");
	strcpy(questions[11].answer, "Polymorphism");
	questions[11].value = 400;
	questions[11].answered = false;
}
	       
// display remaining questions and corresponding values
void display_categories(void)
{
	char val[12][20];

	for (int i = 0; i < 12; i++) {
		if (questions[i].answered == false) {
			snprintf(val[i], 20, "%d", questions[i].value);
		} 
		else {
			strcpy(val[i], "   ");
		}
	}
	
	// formatting to make it look nice
	printf("   %s   |   %s   |   %s   \n", categories[0], categories[1], categories[2]);
	printf("  -------------------------------------------------\n");
	printf("      %s      |     %s     |         %s   \n", val[0], val[1],val[2]);
	printf("  -------------------------------------------------\n");
	printf("      %s      |     %s     |         %s   \n", val[3], val[4], val[5]);
	printf("  -------------------------------------------------\n");
	printf("      %s      |     %s     |         %s   \n", val[6], val[7], val[8]);
	printf("  -------------------------------------------------\n");
	printf("      %s      |     %s     |         %s   \n", val[9], val[10], val[11]);
	printf("  -------------------------------------------------\n");
}
	      
// Displays question and its corresponding point value
void display_question(char *category, int value)
{
	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
		}
	}
}
	       
// Returns true if reply matches answer for corresponding category and value
bool valid_answer(char *category, int value, char *answer)
{
	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			if (strcmp(questions[i].answer, answer) == 0) {
				return true;
				break;
			} 
			else {
				return false;
			}
		}
	}
}
	       
// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			if (questions[i].answered == true) {
				rturn true;
				break;
			}
			else {
				return false;
			}
		}
	}
}

// Updates boolean value in questions struct
void question_answered(char *category, int value)
{
	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			questions[i].answered = true;
		}
	}
}