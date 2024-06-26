#include "libs/task/matrix_transposition.h"
#include "libs/task/convert_float_num.h"
#include "libs/task/evaluate_expression.h"
#include "libs/task/special_word.h"
#include "libs/task/leave_longest_word.h"
#include "libs/task/remove_polynomial.h"
#include "libs/task/rearrange_numbers.h"
#include "libs/task/transpose_non_symmetric_matrix.h"
#include "libs/task/get_best_team.h"
#include "libs/task/update_product.h"

int main(){
    // 1
    generate_random_matrix_file("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_1_test_0.txt", 3);
    test_matrix_transpose();
    printf("Exercise 1 - OK\n");

    // 2
    generate_float_file("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_2_test_0.txt", 10);
    test_convert_float();
    printf("Exercise 2 - OK\n");

    // 3
    generate_expression("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_3_test_0.txt");
    test_evaluate();
    printf("Exercise 3 - OK\n");

    // 4
    generate_string("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_4_test_0.txt", "abcdeabcde");
    test_filter_word();
    printf("Exercise 4 - OK\n");

    // 5
    generate_text_file("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_5_test_0.txt",5, 5, 5);
    test_leave_longest();
    printf("Exercise 5 - OK\n");

    // 6
    printf("Exercise 6\n");
    generate_polynomial("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_6_test_0.txt");
    print_polynomial("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_6_test_0.txt");
    test_remove_true_polynomial();
    printf("Exercise 6 - OK\n");

    // 7
    printf("Exercise 7\n");
    generate_numbers_array("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_7_test_0.txt");
    print_numbers_array("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_7_test_0.txt");
    test_rearrange_numbers();
    printf("Exercise 7 - OK\n");

    // 8
    printf("Exercise 8\n");
    generate_non_symmetric_matrix("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_8_test_0.txt");
    print_bin_file_matrix("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_8_test_0.txt");
    test_transpose_non_symmetric_matrix();
    printf("Exercise 8 - OK\n");

    // 9
    printf("Exercise 9\n");
    generate_team("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_9_test_0.txt", 5);
    print_team("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_9_test_0.txt");
    test_get_best_team();
    printf("Exercise 9 - OK\n");

    // 10
    printf("Exercise 10\n");

    generate_product_and_order("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_10_test_01.txt",
                               "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_10_test_02.txt");
    print_product_and_order("C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_10_test_01.txt",
                            "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests\\task_10_test_02.txt");
    test_update_product();
    printf("Exercise 10 - OK\n");
}