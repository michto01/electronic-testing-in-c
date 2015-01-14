//
//  etests.h
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#ifndef electronicTest_etests_h
#define electronicTest_etests_h


#include <stdlib.h>
#include <stdbool.h>

#define QUESTION_SYMBOL '#'
#define   ANSWER_SYMBOL '*'
#define  CORRECT_SYMBOL '$'

#define TRUE  1
#define FALSE 0

typedef struct _answer {
    unsigned   long id;
    char       isCorrect;
    char       isAnswered;
    char       wasCorrect;
    char*      description;
} Answer;

typedef struct _question {
    unsigned   long id;
    char*      description;
    int        count;
    Answer**   answers;
} Question;

/*
 *   Presistance layer
 */
int         store   (const char*, Question**, int);  // save test to file
Question**  extract (const char*, int*); // read questions from file + show useof pointers with normal type -> like scanf()

/*
 *   Object Lifecycle
 */

void freeAnswer(Answer*);
void freeQuestion(Question*);

/*
 *   Controllers
 */

double      scoreQuestion(Question*);    // percentage from the question correct/correctAnsers * 100;



Answer** correctAnswers(Answer**);

#endif
