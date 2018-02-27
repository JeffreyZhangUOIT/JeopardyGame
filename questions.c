// Global char* question and answer. Messy but will get the job done.
#include <stdio.h>
char* question, answer;

// Grabs question. Returns error or the question itself as a char*.
char* getQuestion(char* category, char* value) {
	FILE* fp;
	char* line;
	line = malloc(100 * sizeof(char));
	fp = fopen("questions.txt", "r");

	while (fgets(line, 100, fp) != EOF) {
		char* token;
		token = strtok(line, ";.");
		if (strcmp(category, token) == 0)
		{
			token = strtok(NULL, ";.");
			if (strcmp(value, token))
			{
				token = strtok(NULL, ";.");
			}
		}
		question = strcpy(question, token);
		token = strtok(NULL, ";.");
		answer = strcpy(answer, token);
		free(line);
		fclose(fp);
		return question;
	}
	
	free(line);
	fclose(fp);
	return "ERROR: No such question." ;
}

// Returns 1 if the playerAnswer is equivalent to the answer. 
// Do not need to add "who is..." or "what is..." to actual answer. Supports multiword answers.
int checkAnswer(char* playerAnswer) {
	char* token1, token2;
	token1 = strok(answer, " ");
	token2 = strok(playerAnswer, " ");
	while (token2 != NULL) {
		if (strcmp(token1, token2) == 0) {
			token1 = strok(NULL, " ");
		}
		token2 = strtok(NULL, " ");
	}
	
	if (strcmp(token1, NULL) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Ditto.
char* getAnswer() {
	return answer;
}

void initialize_game(void)
{
	strcpy(questions[0].question, getQuestion(programming, 100);
	strcpy(questions[0].answer, getAnswer());
	strcpy(questions[1].question, getQuestion(programming, 200);
	strcpy(questions[1].answer, getAnswer());
	strcpy(questions[2].question, getQuestion(programming, 300);
	strcpy(questions[2].answer, getAnswer());
	strcpy(questions[3].question, getQuestion(programming, 400);
	strcpy(questions[3].answer, getAnswer());
	strcpy(questions[4].question, getQuestion(programming, 100);
	strcpy(questions[4].answer, getAnswer());
	strcpy(questions[5].question, getQuestion(programming, 200);
	strcpy(questions[5].answer, getAnswer());
	strcpy(questions[6].question, getQuestion(programming, 300);
	strcpy(questions[6].answer, getAnswer());
	strcpy(questions[7].question, getQuestion(programming, 400);
	strcpy(questions[7].answer, getAnswer());
	strcpy(questions[8].question, getQuestion(programming, 100);
	strcpy(questions[8].answer, getAnswer());
	strcpy(questions[9].question, getQuestion(programming, 200);
	strcpy(questions[9].answer, getAnswer());
	strcpy(questions[10].question, getQuestion(programming, 300);
	strcpy(questions[10].answer, getAnswer());
	strcpy(questions[11].question, getQuestion(programming, 400);
	strcpy(questions[11].answer, getAnswer());
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
