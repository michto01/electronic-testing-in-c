//
//  storage.c
//  electronicTest
//
//  Created by Tomas Michalek on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#include "storage.h"

/**
 *  Object lifecycle
 *
 *  @param ans <#ans description#>
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
