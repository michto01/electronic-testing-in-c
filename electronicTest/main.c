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
    
    printf("App initialized ... \n");
    
    for ( int i = 0; i < testLength; i++ ) {
        printQuestion(test[i]);
    }
    
    //int kk = store("new.math.test", test, testLength);
    
    
    return 0;
}

void printAnswers  ( Question* question ) {
    printf("#-------------------------------------#");
    
    for ( int i = 0; i < question->count; i++ ) {
        printf( "# %lu %s", question->answers[i]->id, question->answers[i]->description );
    }
    
    printf("#-------------------------------------#");
}

void printQuestion ( Question* question ) {
    printf( "%s", question->description );
    printAnswers(question);
}





