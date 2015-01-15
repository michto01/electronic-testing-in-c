//
//  main.c
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

//#define N_DEBUG 0
#define IMPORT_LOCATION "/Developer/gatema/Experiments/electronicTest/electronicTest/math.test"
#define EXPORT_LOCATION "/Developer/gatema/Experiments/electronicTest/electronicTest/new.math.test"

#include <stdio.h>
#include "etests.h"

Question* createQuestion();

int main(int argc, const char * argv[]) {
    
    //int exit = FALSE;
    int testLength;
    
    Question** test = extract(IMPORT_LOCATION, &testLength);
    printf("Storage initialized & mapped... \n");

#ifndef N_DEBUG
    for ( int i = 0; i < testLength; i++ ) {
        printQuestion(test[i]);
    }
    
    Question** mock = (Question**) malloc( 2 * sizeof(Question*) );
    mock[0] = createQuestion();
    mock[1] = createQuestion();
    
    store(EXPORT_LOCATION, mock, 2);
#endif
    
    /*
    printf("Select action: ");
    
    do {
        int ch = getchar(); getchar();
        switch ( ch ) {
            case '1':
                if ( TRUE == store(EXPORT_LOCATION, test, testLength) ) {
                    printf("@Test exported");
                }
                break;
                
            case 2:
                Question **mock;
                = (Question**) malloc( 2 * sizeof(Question*) );
                
                break;
                
            default:
                exit = TRUE;
                break;
        }
    } while ( exit != TRUE );
    */
    
    return 0;
}

double scoreQuestion  ( Question* question ) {
    printf("Your answer(s): ");
    
    question->count;
    
    for (int i = 0; i < question->count; i++) {
        //FixMe & implement
    }
    
    return 0.0f;
}

/**
 *  Create new Question Wizard
 *
 *  @return return Question* create new question
 */
Question* createQuestion() {
    Question* question;
    
    if ( NULL == (question = (Question*) malloc(sizeof(Question))) ) {
        printf("Malloc failed\n");
        return NULL;
    }
    
    //ID
    printf("> Give me id: ");
    scanf("%d", &question->id);
    
    
    //DESCTIPTION
    printf(">> Type your question (max ~250 chars): ");
    if ( NULL == (question->description = (char*) malloc(256 * sizeof(char))) ) {
        printf("Malloc failed\n");
        return NULL;
    }
    scanf("%254s[^n]", question->description); // %253 scans only the specyfied lenght avoiding Undefined behaviour
    getchar();
    getchar();
    
    //COUNT
    printf(">>> Specify number of answers for question: ");
    scanf("%d", &question->count);
    
    //ANSWERS
    if( NULL == ( question->answers = (Answer**)  malloc( question->count * sizeof(Answer*) ) ) ) {
        printf("Malloc failed\n");
        return NULL;
    }
    
    for ( int i = 0; i < question->count; i++ ) {
        Answer* answer; if ( NULL == (answer = (Answer*) malloc(sizeof(Answer))) ) {
            printf("Malloc failed\n");
            return NULL;
        }
        
        answer->id = i;
        
        //ANSWER
        printf("< Answer (~250 chars max): ");
        if ( NULL == (answer->description = (char*) malloc(256 * sizeof(char))) ) {
            printf("Malloc failed\n");
            return NULL;
        }
        scanf("%254s", answer->description); // %253 scans only the specyfied length avoiding Undefined Behaviour
        
        //IS_CORRECT
        printf("<< is answer correct [1:0] ?: "); ///FIXME: implemnet checking of type
        scanf("%c", &answer->isCorrect);
        
        question->answers[i] = answer;
    }
    return question;
}

void printAnswers  ( Question* question ) {
    printf("#-------------------------------------#\n");
    
    for ( int i = 0; i < question->count; i++ ) {
        printf( "# %i %s\n", question->answers[i]->id, question->answers[i]->description );
    }
    
    printf("#-------------------------------------#\n");
}

void printQuestion ( Question* question ) {
    printf( "%s\n", question->description );
    printAnswers(question);
}
