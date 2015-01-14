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
    
    
    int kk = store("new.math.test", test, testLength);
    
    
    return 0;
}


void printQuestion ( Question* question ) {
    
}

void printAnswers  ( Question* question ) {
    
}



