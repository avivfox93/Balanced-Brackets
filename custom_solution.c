#include <stdio.h>
#include <string.h>
#include "helper.h"

struct str_stack{
    const char* _buffer;
    int _len;
    int _index;
};

int str_stack_create(struct str_stack *stack, const char* str){
	stack->_index = 0;
	stack->_buffer = str;
    stack->_len = 0;
    return 1;
}

int str_stack_push(struct str_stack *stack, int index){
    stack->_index = index;
    ++stack->_len;
	return 1;
}

int str_stack_pop(struct str_stack *stack, char* value){
	if(stack->_index < 0 || stack->_len == 0) return 0;
    int curly = 0, round = 0, square = 0;
    do{
        *value = stack->_buffer[(stack->_index)--];
        update_counters(*value, &curly, &round, &square);
        if(curly < 0 || round < 0 || square < 0){
            --stack->_len;
            return 1;
        }
    }while(stack->_index >= 0);
	return 0;
}

int str_stack_len(struct str_stack *stack, int* len){
	*len = stack->_len;
	return 1;
}

int matching_brackets(char left, char right){
    switch(left){
        case '{': return right == '}';
        case '(': return right == ')';
        case '[': return right == ']';
        default: return 0;
    }
}

int brackets(const char *str) {
    struct str_stack stack;
    str_stack_create(&stack, str);
    int len = (int)strlen(str);
    int res;
    for(int i = 0 ; i < len ; ++i){
        if(is_left_bracket(str[i])){//PUSH
            str_stack_push(&stack,i);
        }else if(is_right_bracket(str[i])){//POP
            char value;
            res = str_stack_pop(&stack,&value);
            if(res == 0 || matching_brackets(value,str[i]) == 0){
                return 0;
            }
        }
    }
    str_stack_len(&stack,&len);
    return len == 0;
}

int main(int argc, char* argv[]){
    if(argc < 2) return -1;
    int res = brackets(argv[1]);
    printf("Result is: %d\n",res);
    return 0;
}
