//
//  objects.c
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#include "objects.h"
#include "commons.h"

/**
 *  Object lifecycle
 */

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
