#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    char* _buffer;
    int _len;
    int _index;
};

int stack_create(struct stack *stack, int len){
    stack->_len = len;
    stack->_index = 0;
    stack->_buffer = malloc(sizeof(char)*len);
    return stack->_buffer != NULL;
}

int stack_push(struct stack *stack, char value){
    if(stack->_index > stack->_len) return 0;
    stack->_buffer[(stack->_index)++] = value;
    return 1;
}

int stack_pop(struct stack *stack, char* value){
    if(stack->_index == 0) return 0;
    *value = stack->_buffer[--(stack->_index)];
    return 1;
}

int stack_len(struct stack *stack, int* len){
    *len = stack->_index;
    return 1;
}

int stack_free(struct stack *stack){
    free(stack->_buffer);
    return 1;
}

int brackets(const char* str){
    struct stack stack;
    int result = 1;
    if(stack_create(&stack,strlen(str)) == 0){
        exit(-1);
    }
    for(int i = 0 ; i < strlen(str) ; i++){
        char t;
        switch(str[i]){
            case '{':
            case '(':
            case '[':
                stack_push(&stack,str[i]);
                break;
            case '}':
                if(stack_pop(&stack,&t) == 0){result = 0;break;}
                if(t != '{'){result = 0;break;}
                break;
            case ')':
                if(stack_pop(&stack,&t) == 0){result = 0;break;}
                if(t != '('){result = 0;break;}
                break;
            case ']':
                if(stack_pop(&stack,&t) == 0){result = 0;break;}
                if(t != '['){result = 0;break;}
                break;
            default:
                break;
        }
    }
    int len;
    stack_len(&stack,&len);
    stack_free(&stack);
    return result && len == 0;
}

int main(int argc, char* argv[]){
    if(argc < 2) return -1;
    int res = brackets(argv[1]);
    printf("Result is: %d\n",res);
    return res;
}
