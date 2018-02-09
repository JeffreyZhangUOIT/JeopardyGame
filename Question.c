
// Global char* question and answer. Messy but will get the job done.
#include <stdio.h>
char* question, answer;

// Grabs question. Returns error or the question itself as a char*.
char* getQuestion(char* player, char* category, char* value) {
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