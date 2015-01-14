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
    Question** test = extract("/Developer/gatema/Experiments/electronicTest/electronicTest/math.test", &testLength);
    
    printf("App initialized ... \n");
    
    for ( int i = 0; i < testLength; i++ ) {
        printQuestion(test[i]);
    }
    
    int kk = store("/Developer/gatema/Experiments/electronicTest/electronicTest/new.math.test", test, testLength);
    
    
    return 0;
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





