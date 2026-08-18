#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Convert input to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Random response
void randomResponse(char *responses[], int size) {
    int r = rand() % size;
    printf("Bot: %s\n", responses[r]);
}

// Keyword scoring (Mini AI)
int calculateScore(char input[], char *keywords[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(input, keywords[i]) != NULL) {
            score++;
        }
    }
    return score;
}

int main() {
    char input[200];
    char name[50] = "User";

    srand(time(NULL));

    // Responses
    char *greetings[] = {
        "Hello!", "Hi there!", "Hey!", "Greetings!", "Nice to see you!"
    };

    char *thanks[] = {
        "You're welcome!", "Anytime!", "Glad to help!", "No problem!"
    };

    char *unknown[] = {
        "I didn't understand that.",
        "Try asking differently.",
        "Interesting question!",
        "I'm still learning."
    };

    // Keyword groups
    char *greetKeys[] = {"hello", "hi", "hey"};
    char *studyKeys[] = {"study", "exam", "learn"};
    char *weatherKeys[] = {"weather", "rain", "temperature"};
    char *timeKeys[] = {"time", "clock"};
    char *dateKeys[] = {"date", "day"};

    char *seKeys[] = {"software", "engineering", "software engineering"};
    char *webKeys[] = {"web", "website", "html", "css", "javascript"};
    char *dbKeys[] = {"database", "sql", "dbms"};
    char *aiKeys[] = {"ai", "artificial intelligence", "machine learning"};
    char *networkKeys[] = {"network", "internet", "protocol"};

    printf("===== SMART AI CHATBOT (FINAL VERSION) =====\n");
    printf("Type 'help' to see commands | Type 'bye' to exit\n");

    while (1) {
        printf("\nYou: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        toLowerCase(input);

        // Store name
        if (strstr(input, "my name is")) {
            sscanf(input, "my name is %s", name);
            printf("Bot: Nice to meet you, %s!\n", name);
            continue;
        }

        // Exit
        if (strstr(input, "bye") || strstr(input, "exit")) {
            printf("Bot: Goodbye %s! Have a great day.\n", name);
            break;
        }

        // Scores
        int g = calculateScore(input, greetKeys, 3);
        int s = calculateScore(input, studyKeys, 3);
        int w = calculateScore(input, weatherKeys, 3);
        int t = calculateScore(input, timeKeys, 2);
        int d = calculateScore(input, dateKeys, 2);

        int se = calculateScore(input, seKeys, 3);
        int web = calculateScore(input, webKeys, 5);
        int db = calculateScore(input, dbKeys, 3);
        int ai = calculateScore(input, aiKeys, 3);
        int net = calculateScore(input, networkKeys, 3);

        int max = g;
        int category = 1;

        if (s > max) { max = s; category = 2; }
        if (w > max) { max = w; category = 3; }
        if (t > max) { max = t; category = 4; }
        if (d > max) { max = d; category = 5; }
        if (se > max) { max = se; category = 6; }
        if (web > max) { max = web; category = 7; }
        if (db > max) { max = db; category = 8; }
        if (ai > max) { max = ai; category = 9; }
        if (net > max) { max = net; category = 10; }

        if (max == 0) {
            randomResponse(unknown, 4);
            continue;
        }

        // Responses
        switch (category) {

            case 1:
                randomResponse(greetings, 5);
                break;

            case 2:
                printf("Bot: %s, here are study tips:\n", name);
                printf("- Make a timetable\n- Revise daily\n- Practice problems\n");
                break;

            case 3:
                printf("Bot: Weather is simulated. Stay prepared!\n");
                break;

            case 4: {
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                printf("Bot: Current time is %02d:%02d:%02d\n",
                       t->tm_hour, t->tm_min, t->tm_sec);
                break;
            }

            case 5: {
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                printf("Bot: Today's date is %02d-%02d-%04d\n",
                       t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
                break;
            }

            case 6:
                printf("Bot: Software Engineering is a structured approach to building software.\n");
                printf("Phases: Requirement → Design → Coding → Testing → Maintenance.\n");
                break;

            case 7:
                printf("Bot: Web Development includes:\n");
                printf("Frontend: HTML, CSS, JavaScript\n");
                printf("Backend: Node.js, PHP, Python\n");
                break;

            case 8:
                printf("Bot: DBMS manages data efficiently.\n");
                printf("Examples: MySQL, Oracle, SQL Server.\n");
                break;

            case 9:
                printf("Bot: AI allows machines to think and learn.\n");
                printf("Includes Machine Learning and NLP.\n");
                break;

            case 10:
                printf("Bot: Networking connects devices.\n");
                printf("Key concepts: IP Address, Protocols, Internet.\n");
                break;
        }

        // Thank you response
        if (strstr(input, "thank")) {
            randomResponse(thanks, 4);
        }

        // Help
        if (strstr(input, "help")) {
            printf("\nCommands you can try:\n");
            printf("- hello / hi\n");
            printf("- my name is ___\n");
            printf("- time / date\n");
            printf("- study help\n");
            printf("- weather\n");
            printf("- software engineering\n");
            printf("- web development\n");
            printf("- database / dbms\n");
            printf("- ai / machine learning\n");
            printf("- networking\n");
            printf("- thank you\n");
            printf("- bye\n");
        }
    }

    return 0;
}