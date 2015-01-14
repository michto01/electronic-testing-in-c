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

bool ds_putc_codepoint( dynstr* s, int cp ) {
    
    if ( cp < 0 || cp > 0x10ffff ) {
        return false;
    }
    else if ( cp < 0x80 )  {
        return ds_putc(s, cp & 0x7F);
    }
    else if ( cp < 0x800 ) {
        if ( !ds_resize(s, 2) )
            return false;
        ds_putc_unsecure(s, 0xC0 | ((cp >> 6) & 0x1F));
        ds_putc_unsecure(s, 0x80 |  (cp & 0x3F));
    }
    else if (cp < 0x10000) {
        if ( !ds_resize(s, 3) )
            return false;
        ds_putc_unsecure(s, 0xE0 | ((cp >> 12) & 0xF));
        ds_putc_unsecure(s, 0x80 | ((cp >> 6)  & 0x3F));
        ds_putc_unsecure(s, 0x80 |  (cp & 0x3F));
    }
    else {
        if ( !ds_resize(s, 4) )
            return false;
        ds_putc_unsecure(s, 0xF0 | ((cp >> 18) & 0x7));
        ds_putc_unsecure(s, 0x80 | ((cp >> 12) & 0x3F));
        ds_putc_unsecure(s, 0x80 | ((cp >> 6)  & 0x3F));
        ds_putc_unsecure(s, 0x80 |  (cp & 0x3F));
    }
    
    return true;
}

bool ds_finnish( dynstr* s ) {
    if ( !ds_resize(s, 1) ) {
        return false;
    } else {
        *(s->chars + s->length) = '\0';
        return true;
    }
}

