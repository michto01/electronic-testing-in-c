//
//  dynstr.h
//  rdf
//
//  Created by Tomas Michalek on 03/01/15.
//  Copyright (c) 2015 cre8iv.eu. All rights reserved.
//

#ifndef __rdf__dynstr__
#define __rdf__dynstr__

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char*  chars;
    size_t capacity;
    size_t length;
} dynstr;

dynstr* ds_create();
void    ds_destroy( dynstr* );

static inline void ds_putc_unsecure( dynstr* s, char c ) {
    *(s->chars + s->length++) = c;
}

bool    ds_resize         ( dynstr*, size_t );
bool    ds_putc           ( dynstr*, char );
bool    ds_finnish        ( dynstr* );


#endif /* defined(__rdf__dynstr__) */
