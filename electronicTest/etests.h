//
//  etests.h
//  electronicTest
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#ifndef electronicTest_etests_h
#define electronicTest_etests_h

#include "commons.h"
#include "storage/storage.h"
#include "objects/objects.h"

/*
 *   Controllers
 */

double      scoreQuestion  (Question*);    // percentage from the question correct/correctAnsers * 100;
Answer**    correctAnswers (Answer**);

/*
 *   Presentation layer
 */
void        printQuestion (Question*);
void        printAnswers  (Question*);


#endif
