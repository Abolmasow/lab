#ifndef LAB_VECTORVOID_H
#define LAB_VECTORVOID_H

#include <limits.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
// например, если вектор хранит int -
// то поле baseTypeSize = sizeof(int)
// если вектор хранит float -
// то поле baseTypeSize = sizeof(float)
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений.
vectorVoid create_vector_void(size_t capacity, size_t base_type_size);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve_v(vectorVoid *v, size_t new_capacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear_v(vectorVoid *v);

// освобождает память, выделенную под неиспользуемые элементы.
void vector_shrink_to_fit_v(vectorVoid *v);

// освобождает память, выделенную вектору.
void delete_vector_v(vectorVoid *v);

// проверки на то, является ли вектор пустым.
bool is_empty_v(vectorVoid *v);

// проверки на то, является ли вектор полным.
bool is_full_v(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v.
void get_vector_value_v(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source;
void set_vector_value_v(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент из вектора.
void pop_back_v(vectorVoid *v);

// добавляет элемент x в конец вектора.
void push_back_v(vectorVoid *v, void *source);

#endif //LAB_VECTORVOID_H
