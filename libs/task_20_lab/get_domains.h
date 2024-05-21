#ifndef UNTITLED6_GET_DOMAINS_H
#define UNTITLED6_GET_DOMAINS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../string/string_.h"

#define MAX_LENGTH_DOMAIN 128
#define MAX_DOMAIN 64

typedef struct domain {
    char name[MAX_LENGTH_DOMAIN];
    int amount;
} domain;


typedef struct domains {
    domain data[MAX_DOMAIN];
    size_t size;
} domains;

int get_word_to_dot(char* begin_search, wordDescriptor* word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    size_t len = strlen_(begin_search);
    word->end = find(word->begin, word->begin + len, '.');

    if (word->end == word->begin + len || *word->end == '\n')
        word->end -= 2;

    return true;
}


void push_domain_in_domains(domains* ds, domain* d) {
    ds->data[ds->size].amount = d->amount;
    copy(d->name, d->name + strlen_(d->name) + 1, ds->data[ds->size].name);
    ds->size++;
}


void merge_equal_domains(domains* ds) {
    for (int i = 0; i < ds->size; i++)
        for (int j = i + 1; j < ds->size; j++) {
            // printf("%d %d %s %s \n\n", ds->data[i].amount, ds->data[j].amount, ds->data[i].name, ds->data[j].name);
            if (strcmp_(ds->data[i].name, ds->data[j].name) == 0 && ds->data[i].amount >= 0 && ds->data[j].amount >= 0) {
                ds->data[i].amount += ds->data[j].amount;
                ds->data[j].amount = -1;
            }

        }
}


void _get_domains(char* s, domains* ds) {
    char* read_ptr = s;

    wordDescriptor amount_as_text, name_domain;
    getWordWithoutSpace(read_ptr, &amount_as_text);
    read_ptr = amount_as_text.end + 1;
    getWordWithoutSpace(read_ptr, &name_domain);

    int k = 1;
    int amount = 0;
    read_ptr = amount_as_text.end;
    while (read_ptr >= amount_as_text.begin) {
        amount += k * (*read_ptr - '0');
        k *= 10;
        read_ptr--;
    }

    read_ptr = name_domain.begin;
    _bag.size = 0;
    while (get_word_to_dot(read_ptr, &_bag.words[_bag.size])) {
        read_ptr = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    for (int i = 0; i < _bag.size; i++) {
        domain d = {.amount = amount};

        char* begin = d.name;
        begin = copy(_bag.words[i].begin, _bag.words[i].end + 1, begin);
        for (int j = i + 1; j < _bag.size; j++)
            begin = copy(_bag.words[j].begin, _bag.words[j].end + 1, begin);

        push_domain_in_domains(ds, &d);
    }

    freeBag(&_bag);
}

void get_domains(const char* filename) {
    FILE* file = fopen(filename, "r");

    domains ds = {.size = 0};

    while (fgets(_string_buffer, 256, file)) {
        _get_domains(_string_buffer, &ds);
        freeString(_string_buffer);
    }

    merge_equal_domains(&ds);

    fclose(file);


    file = fopen(filename, "w");

    for (int i = 0; i < ds.size; i++) {
        if (ds.data[i].amount >= 0)
            fprintf(file, "%d %s\n", ds.data[i].amount, ds.data[i].name);
    }

    fclose(file);
}

void test_get_domains() {
    const char filename[] = "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests_20_lab\\task_4_test.txt";

    FILE* file = fopen(filename, "w");

    char s[100] = "9001 discuss.codeforces.com";
    fprintf(file, "%s\n", s);

    fclose(file);


    get_domains(filename);


    file = fopen(filename, "r");

    char d1[100] = "";
    char d2[100] = "";
    char d3[100] = "";
    fgets(d1, sizeof(d1), file);
    fgets(d2, sizeof(d2), file);
    fgets(d3, sizeof(d3), file);

    fclose(file);

    assert(strcmp_(d1, "9001 discuss.codeforces.com\n") == 0);
    assert(strcmp_(d2, "9001 codeforces.com\n") == 0);
    assert(strcmp_(d3, "9001 com\n") == 0);
}

#endif //UNTITLED6_GET_DOMAINS_H
