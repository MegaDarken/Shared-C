#ifndef CHAR_MENU_
#define CHAR_MENU_

void charMenu_present(const int optionCount, char options[optionCount], char **messages);

int charMenu_choice(const int optionCount, char options[optionCount]);

int charMenu_choiceUpper(const int optionCount, char options[optionCount]);
int charMenu_choiceLower(const int optionCount, char options[optionCount]);

int charMenu_presentChoice(const int optionCount, char options[optionCount], char **messages);

#endif //CHAR_MENU_
