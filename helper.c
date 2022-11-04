#include "helper.h"

int is_left_bracket(char c){
    switch(c){
        case '{':
        case '(':
        case '[':return 1;
        default: return 0;
    }
}

int is_right_bracket(char c){
    switch(c){
        case '}':
        case ')':
        case ']':return 1;
        default: return 0;
    }
}

void update_counters(char ch, int *curly, int *round, int *square){
    switch(ch){
        case '{': --*curly;break;
        case '(': --*round;break;
        case '[': --*square;break;
        case '}': ++*curly;break;
        case ')': ++*round;break;
        case ']': ++*square;break;
        default: break;
    }
}