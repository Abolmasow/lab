#ifndef UNTITLED6_AUTO_COMPLETION_H
#define UNTITLED6_AUTO_COMPLETION_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../string/string_.h"

#define MAX_REQUEST 128


typedef struct request {
    wordDescriptor sequence;
    int position;
} request;


typedef struct requests {
    request request[MAX_REQUEST];
    size_t size;
} requests;

bool is_sub_word(const wordDescriptor word1, const wordDescriptor word2) {
    char* begin1 = word1.begin;
    char* begin2 = word2.begin;

    while (begin1 <= word1.end) {
        if (*begin1 != *begin2)
            return false;

        begin1++;
        begin2++;
    }

    if (word1.end - begin1 > 0)
        return false;

    return true;
}

void free_requests(requests* rs) {
    for (int i = 0; i < rs->size; i++) {
        rs->request[i].position = 0;
        rs->request[i].sequence.begin = NULL;
        rs->request[i].sequence.end = NULL;
    }

    rs->size = 0;
}


void _print_request(request* r) {
    printf("%d ", r->position);
    printWord(r->sequence);
}


void auto_completion(const char* filename) {
    FILE* file = fopen(filename, "r");

    long long int n, q;
    fscanf(file, "%lld", &n);
    fscanf(file, "%lld", &q);

    _bag.size = 0;
    char* begin = _string_buffer;
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", begin);
        getWordWithoutSpace(begin, &_bag.words[_bag.size]);
        begin = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    requests rs = {.size = 0};
    for (int i = 0; i < q; i++) {
        fscanf(file, "%d", &rs.request[i].position);
        fscanf(file, "%s", begin);
        getWordWithoutSpace(begin, &rs.request[i].sequence);
        begin = rs.request[i].sequence.end + 1;
        rs.size++;
    }

    fclose(file);


    file = fopen(filename, "w");

    for (int i = 0; i < q; i++) {
        int amount = 0;
        for (int j = 0; j < n; j++) {
            if (is_sub_word(rs.request[i].sequence, _bag.words[j])) {
                amount++;

                if (amount == rs.request[i].position)
                    fprintf(file,"%d\n", j + 1);
            }
        }
        if (amount < rs.request[i].position)
            fprintf(file,"-1\n");
    }

    fclose(file);

    freeString(_string_buffer);
    freeBag(&_bag);
    free_requests(&rs);
}


void test_auto_completion() {
    const char filename[] = "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests_20_lab\\task_11_test.txt";

    FILE* file = fopen(filename, "w");

    int n = 10;
    int q = 3;
    fprintf(file, "%d %d \n", n, q);
    fprintf(file, "aa    \n");
    fprintf(file, "aaa   \n");
    fprintf(file, "aab   \n");
    fprintf(file, "ab    \n");
    fprintf(file, "abc   \n");
    fprintf(file, "ac    \n");
    fprintf(file, "ba    \n");
    fprintf(file, "daa   \n");
    fprintf(file, "dab   \n");
    fprintf(file, "dadba \n");
    fprintf(file, "4 a   \n");
    fprintf(file, "2 da   \n");
    fprintf(file, "4 da \n");

    fclose(file);


    auto_completion(filename);


    file = fopen(filename, "r");

    int n1, n2, n3;
    fscanf(file, "%d\n", &n1);
    fscanf(file, "%d\n", &n2);
    fscanf(file, "%d\n", &n3);

    fclose(file);

    assert(n1 == 4);
    assert(n2 == 9);
    assert(n3 == -1);
}

#endif //UNTITLED6_AUTO_COMPLETION_H
