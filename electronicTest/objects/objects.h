//
//  objects.h
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#ifndef electronicTest_objects_h
#define electronicTest_objects_h

typedef struct _answer {
    int        id;
    char       isCorrect;
    char       isAnswered;
    char       wasCorrect;
    char*      description;
} Answer;

typedef struct _question {
    int        id;
    char*      description;
    int        count;
    Answer**   answers;
} Question;

/*
 *   Object Lifecycle
 */

void freeAnswer   (Answer*);
void freeQuestion (Question*);

#endif
