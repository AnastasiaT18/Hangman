#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void drawhangman(int mistakes){
 setcolor(WHITE);
 line(5, 700, 5, 200);
 line(5, 200, 205, 200);
 line(205, 200, 205, 260);

if (mistakes >= 1){
    circle(205, 280, 20);
}

if (mistakes >= 2){
    rectangle(195, 300, 215, 360);
}

if (mistakes >= 3){
    line(195, 300, 180, 360);
}

if (mistakes >= 4){
    line(215, 300, 230, 360);
}

if (mistakes >= 5){
    line(195, 360, 170, 430);
}

if (mistakes >= 6){
    line(215, 360, 240, 430);
}
}

void chooseword(int level, char* word){
    FILE *file;
    int count = 0;
    srand(time(NULL));
    int n = rand() % 5 ;

   switch(level){
   case 1: 
   
    file = fopen("level1.txt", "r");
    if (file == NULL){
        printf("ERROR opening file.");
    }

    while (fgets(word, 20, file) != NULL){
        count++;
        if (count == n){
            fclose(file);
            break;

        }
    }
    break;
    case 2:
    file = fopen("level2.txt", "r");
    if (file == NULL){
        printf("ERROR opening file.");
    }

    while (fgets(word, 20, file) != NULL){
        count++;
        if (count == n){
            fclose(file);
            break;

        }
    }
    break;

   case 3:
   file = fopen("level3.txt", "r");
    if (file == NULL){
        printf("ERROR opening file.");
    }

    while (fgets(word, 20, file) != NULL){
        count++;
        if (count == n){
            fclose(file);
            break;

        }
    }
    break;

    case 4:
    file = fopen("level4.txt", "r");
    if (file == NULL){
        printf("ERROR opening file.");
    }

    while (fgets(word, 20, file) != NULL){
        count++;
        if (count == n){
            fclose(file);
            break;

        }
    }
    break;

   case 5:
    file = fopen("level5.txt", "r");
    if (file == NULL){
        printf("ERROR opening file.");
    }

    while (fgets(word, 20, file) != NULL){
        count++;
        if (count == n){
            fclose(file);
            break;

        }
    }
    break;
}
}

void multiplayer(char * word){
    printf("Player 1, enter a word:\n");
    scanf("%s", word);
    getchar();
    printf("\x1b[A");
    printf("\r");
    for(int i=0; i<strlen(word); i++){
      printf("*");
    }
    printf("\r");
    fflush(stdout);
}

int main(){
    
char word[20];
char guess;
char status[20];
int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);

int mistakes = 0;
int correct = 0;
int found;
int count = 0;
FILE *file;


int level = 1;

printf("-------------------WELCOME TO HANGMAN!------------------\n");
outtextxy(160,10, "---------WELCOME TO HANGMAN!---------");
delay(3000);

outtextxy(170,25, "Let the guessing begin!");
printf("Let the guessing begin!\n");
delay(5000);
cleardevice();


int k;
printf("Choose an option:\n 1. Single Player \n 2. Multiplayer");
scanf("%d", &k);


while(level<=5){
    if (k==1){
      chooseword(level, word);
    }
    else if (k==2){
        multiplayer(word);
    }


printf("\n-------Level %d --------\n", level);

int length = strlen(word);   //se alege cuv
    if (length > 0 && (word[length - 1] == '\n' || word[length - 1] == '\r')) {
    word[length-1] = '\0';}



for(int i=0; i<=strlen(word)-1;i++){  //se stabileste status
    status[i] = '_';
}
status[strlen(word)]='\0';

while(mistakes<6 && correct < strlen(word)){  //incepe jocul
   
    found = 0;
     cleardevice();
     
     drawhangman(mistakes);
     if (level == 1){
        outtextxy(250, 20, "LEVEL 1"); }
     if (level == 2){
     outtextxy(250, 20, "LEVEL 2");}
     if (level == 3){
     outtextxy(250, 20, "LEVEL 3");}
     if (level == 4){
     outtextxy(250, 20, "LEVEL 4");}
      if (level == 5){
     outtextxy(250, 20, "LEVEL 5");}
     delay(100);

     outtextxy(265, 100, status);
     
     
     printf("Current status: %s\n", status);
     scanf(" %c", &guess);
     printf("Guess: %c ", guess); 
  for (int i=0;i<strlen(word);i++){
     if (status[i] == guess){
        correct = correct;
        found = 1;
     }
     else if (guess == word[i]){
        status[i] = guess;
        correct++;
        found = 1;
     }
     
}
if (found == 0){
    mistakes++;
} 
}




if (mistakes == 6){
    cleardevice();
    outtextxy(200,200, "YOU LOST THE LEVEL !\n YOU ARE OUT! BYE!");
    delay(5000);
    printf("You lost level %d!", level);
    break;

    
}
if (correct ==  strlen(word)){ 
    cleardevice();
    outtextxy(200,200, "YOU WON THE LEVEL!");
    delay(5000);
    printf("You won level %d!\n", level);
    level++;
    mistakes = 0;
    correct = 0;
}

}

if (level == 6){
    printf("Congratulations! You won the game!");
}
else{
printf("You are out! Bye!");
}
 

   

getch();
closegraph();

    return 0;
}