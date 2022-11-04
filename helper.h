
#ifndef BALANCED_BRACKETS_HELPER_H
#define BALANCED_BRACKETS_HELPER_H

int is_left_bracket(char c);
int is_right_bracket(char c);
void update_counters(char ch, int *curly, int *round, int *square);

#endif //BALANCED_BRACKETS_HELPER_H
