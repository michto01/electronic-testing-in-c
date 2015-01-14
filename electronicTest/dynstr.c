//
//  dynstr.c
//  rdf
//
//  Created by Tomas Michalek on 03/01/15.
//  Copyright (c) 2015 cre8iv.eu. All rights reserved.
//

#include "dynstr.h"

#define MAX_PREALLOC (1024 * 1024)
#define INITIAL_CAPACITY 8

dynstr* ds_create() {
    int     capacity = INITIAL_CAPACITY;
    
    dynstr* result           = malloc(sizeof(dynstr));
            result->chars    = malloc(sizeof(char) * capacity);
            result->length   = 0;
            result->capacity = capacity;
    return  result;
}

void ds_destroy( dynstr* s ) {
    free( s->chars );
    free( s );
}

bool ds_resize( dynstr* s, size_t room ) {
    size_t capacity = s->capacity;
    size_t length   = s->length;
    
    if ( length + room <= capacity ) {
        return true;
    }
    
    capacity = length + room;
    
    if ( capacity < MAX_PREALLOC ) {
        capacity *= 2;
    } else {
        capacity += MAX_PREALLOC;
    }
    
    char* chars = realloc( s->chars, capacity + 1 );
    
    if ( chars == NULL ) {
        return false;
    }
    
    s->chars    = chars;
    s->capacity = capacity;
    return true;
}

bool ds_putc( dynstr* s, char c ) {
    if ( !ds_resize(s, 1) ) {
        return false;
    } else {
        ds_putc_unsecure( s, c );
        return true;
    }
}

bool ds_finnish( dynstr* s ) {
    if ( !ds_resize(s, 1) ) {
        return false;
    } else {
        *(s->chars + s->length) = '\0';
        return true;
    }
}

