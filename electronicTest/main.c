//
//  main.c
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#include <stdio.h>
#include "etests.h"

int main(int argc, const char * argv[]) {
    int testLength;
    Question** test = extract("math.test", &testLength);
    
    
    
    return 0;
}

Question** extract( const char* filename, int* length) {
    
    FILE*      file      = NULL;
    Question** questions = NULL;
    
    if ( ( file = fopen(filename, "r") ) == NULL ) {
        return NULL;
    }
    
    unsigned long questionCount;
    
    if ( fscanf( file, "%lu", &questionCount ) != EOF ) {
        
        if ( NULL == (questions = (Question**) malloc( questionCount * sizeof(Question*) )) ) {
            printf("Questions>>> Malloc failed\n");
            return NULL;
        }
        
        unsigned long id     = 0;    // Persistant id of question;
        char    isQuestion   = FALSE;    // Check if question is the valid
        int     answersCount = 0;    // How many answers this question have
        char*   questionText = NULL; // What is the Question description
        
        while( fscanf( file, "\n%c%d %s\n", &isQuestion, &answersCount, questionText ) != EOF ) {
        
            if ( isQuestion == QUESTION_SYMBOL ) {
                
                // Memory allocations for dynamics objects
                Question* question;
                
                // Showing memory test || for purpose of this project not used but alway a good idea
                if ( NULL == (question = (Question*) malloc(sizeof(Question))) ) {
                    printf("Malloc failed\n");
                    return NULL;
                }
                
                Answer** answers = (Answer**)  malloc( answersCount * sizeof(Answer*) );
                
                // Iterate over expected answerCount
                for ( int i = 0; i < answersCount; i++ ) {
                    
                    Answer* ans = (Answer*) malloc(sizeof(Answer)); // Alloc new for temp answer constructor
                    char    isAnswer;
                    
                    ans->isAnswered =  FALSE; // Security null-ation
                    ans->wasCorrect = -1; // Secutiry null-ation
                    
                    fscanf( file, "%c%c %s", &isAnswer, &(ans->isCorrect), ans->description );
                    
                    if ( isAnswer == ANSWER_SYMBOL ) {
                        ans->id = i;
                        answers[i] = ans;
                    }
                    else {
                        freeAnswer(ans);
                        printf("File error (Answer)\n");
                        return NULL;
                    }
                    
                }
                
                question->id          = id;
                question->answers     = answers;
                question->count       = answersCount;
                question->description = questionText;
                
                if ( question->answers != NULL ) {
                    questions[id++] = question;
                }
                else {
                    freeQuestion(question);
                    printf("Error in File\n");
                    return NULL;
                }
            }
        }
    }
    
    *length = (int) questionCount;
    return questions;
}

int store( const char* filename, Question** questions, int length ) {
    
    FILE* file = NULL;
    
    if ( ( file = fopen(filename, "w") ) == NULL ) {
        printf("Error opening the file");
        return FALSE;
    }
    
    fprintf(file, "%d\n", length);
    
    for (int i = 0; i < length; i++) {
        
        /*
         * #3 Very Important question?
         */
        fprintf(file, "\n#%d %s\n", questions[i]->count,questions[i]->description);
        
        int tmpCount = questions[i]->count;
        
        for (int j; j < tmpCount; j++) {
            /* 
             * *$ Correct Answer
             * *  Bad Answer
             */
            fprintf(file, "*%c %s\n", questions[i]->answers[j]->isCorrect ? '$': ' ', questions[i]->answers[j]->description );
        }
    }

    return TRUE;
}

void freeAnswer(Answer* ans) {
    free(ans->description);
    free(ans);
}

void freeQuestion(Question* question) {
    
    if ( question->answers != NULL ) {
        while ( question->count >= 0 ) {
            free(question->answers[question->count--]);
        }
    }
    
    free(question->answers);
    free(question->description);
    free(question);
}

