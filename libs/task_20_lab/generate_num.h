#ifndef UNTITLED6_GENERATE_NUM_H
#define UNTITLED6_GENERATE_NUM_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define ASCII_SHIFT 48

char* generate_nums(const char* s) {
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char res[10] = "";

    unsigned int len_s = strlen(s);

    char* rec_ptr = res;
    char* read_ptr = s;
    unsigned int i_ind = 0;
    unsigned int d_ind = len_s;

    while (i_ind != d_ind) {
        if (*read_ptr == 'I') {
            *rec_ptr = (char)(num[i_ind++] + ASCII_SHIFT);
        } else {
            *rec_ptr = (char)(num[d_ind--] + ASCII_SHIFT);
        }

        read_ptr++;
        rec_ptr++;
    }

    *rec_ptr = (char)(num[i_ind] + ASCII_SHIFT);
    *++rec_ptr = '\0';

    char* result = (char*)malloc(strlen(res) + 1);
    strcpy(result, res);

    return result;
}

void test_generate_nums() {
    char s[] = "DDD";
    char check[] = "4321";
    char* res = generate_nums(s);

    assert(strcmp(res, check) == 0);

    free(res);
}

#endif //UNTITLED6_GENERATE_NUM_H
