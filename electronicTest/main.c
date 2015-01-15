//
//  main.c
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#define N_DEBUG 1
#define IMPORT_LOCATION "/Developer/gatema/Experiments/electronicTest/electronicTest/math.test"
#define EXPORT_LOCATION "/Developer/gatema/Experiments/electronicTest/electronicTest/new.math.test"

#include <stdio.h>
#include "etests.h"

int main(int argc, const char * argv[]) {
    
    int exit = FALSE;
    int testLength;
    
    Question** test = extract(IMPORT_LOCATION, &testLength);
    printf("Storage initialized & mapped... \n");

#ifndef N_DEBUG
    for ( int i = 0; i < testLength; i++ ) {
        printQuestion(test[i]);
    }
#endif
    printf("Select action: ");
    do {
        switch ( getchar() ) {
            case 1:
                getchar();
                if ( TRUE == store(EXPORT_LOCATION, test, testLength) ) {
                    printf("@Test exported");
                }
                break;
                
            default:
                exit = TRUE;
                break;
        }
    } while ( exit != TRUE );
    
    
    return 0;
}

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
    if ( NULL == (question->description = (char*) malloc(sizeof(char))) ) {
        printf("Malloc failed\n");
        return NULL;
    }
    scanf("%253s", question->description); // %253 scans only the specyfied lenght avoiding Undefined behaviour
    
    
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





