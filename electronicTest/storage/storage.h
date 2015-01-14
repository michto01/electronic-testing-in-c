//
//  storage.h
//  electronicTest : Presistance layer
//
//  Created by Lucie Urbanova on 14/01/15.
//  Copyright (c) 2015 lucieurbanova.cz. All rights reserved.
//

#ifndef __electronicTest__storage__
#define __electronicTest__storage__

#include "commons.h"
#include "objects.h"

int         store   (const char*, Question**, int);  // save test to file
Question**  extract (const char*, int*);             // read questions from file + show useof pointers with normal type -> like scanf()



#endif /* defined(__electronicTest__storage__) */
