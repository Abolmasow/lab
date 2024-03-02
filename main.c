#include <stdbool.h>
#include <stdio.h>

// Собирает массив newSet размера newLen, содержащий все элементы из массивов
// firstSet размера firstLen и secondSet размера secondLen без повторений
void unificationOfUnorderedSets(const unsigned int * const firstSet, const int firstLen,
                                const unsigned int * const secondSet, const int secondLen,
                                unsigned int * const newSet, int * const newLen) {
    for (int i = 0; i < firstLen; i++) {
        newSet[i] = firstSet[i];
    }
    int numberOfSecondSetElements = 0;
    for (int j = 0; j < secondLen; j++) {
        int isElementInFirstSet = false;
        for(int k = 0; k < firstLen; k++) {
            if (firstSet[k] == secondSet[j]) {
                isElementInFirstSet = true;
                break;
            }
        }
        if(!isElementInFirstSet) {
            newSet[firstLen + numberOfSecondSetElements] = secondSet[j];
            numberOfSecondSetElements++;
        }
    }
    *newLen = firstLen + numberOfSecondSetElements;
}

// Собирает массив newSet размера newLen, содержащий элементы, которые есть и в
// массиве firstSet размера firstLen, и в массиве secondSet размера secondLen
void intersectionOfUnorderedSets(const unsigned int * const firstSet, const int firstLen,
                                 const unsigned int * const secondSet, const
                                 int secondLen, unsigned int * const newSet,
                                 int * const newLen) {
    int numberOfGoodElements = 0;
    for (int i = 0; i < firstLen; i++) {
        int isElementInSecondSet = false;
        for(int j = 0; j < secondLen; j++) {
            if (secondSet[j] == firstSet[i]) {
                isElementInSecondSet = true;
                break;
            }
        }
        if (isElementInSecondSet) {
            newSet[numberOfGoodElements++] = firstSet[i];
        }
    }
    *newLen = numberOfGoodElements;
}

// Собирает массив newSet размера newLen, содержащий элементы из массива
// firstSet размера firstLen, которых нет в массиве secondSet размера secondLen
void differenceOfUnorderedSets(const unsigned int * const firstSet, const int firstLen,
                               const unsigned int * const secondSet, const int
                               secondLen, unsigned int * const newSet,
                               int * const newLen) {
    int numberOfGoodElements = 0;
    for (int i = 0; i < firstLen; i++) {
        int isElementInSecondSet = false;
        for(int j = 0; j < secondLen; j++) {
            if (secondSet[j] == firstSet[i]) {
                isElementInSecondSet = true;
                break;
            }
        }
        if (!isElementInSecondSet) {
            newSet[numberOfGoodElements++] = firstSet[i];
        }
    }
    *newLen = numberOfGoodElements;
}

// Cобирает массив newSet размера newLen, содержащий элементы из массива firstSet
// размера firstLen, которых нет в массиве secondSet размера secondLen и элементы
// из массива secondSet, которых нет в firstSet
void symmetricDifferenceOfUnorderedSets(const unsigned int * const firstSet, const int firstLen,
                                        const unsigned int * const secondSet, const int secondLen,
                                        unsigned int * const newSet, int * const newLen) {
    int numberOfGoodElements = 0;
    int maxLen = firstLen > secondLen ? firstLen : secondLen;
    for (int i = 0; i < maxLen; i++) {
        int isElementInSecondSet = false;
        for(int j = 0; j < secondLen; j++) {
            if (secondSet[j] == firstSet[i]) {
                isElementInSecondSet = true;
                break;
            }
        }
        if (i < firstLen && !isElementInSecondSet) {
            newSet[numberOfGoodElements++] = firstSet[i];
        }
        int isElementInFirstSet = false;
        for(int k = 0; k < secondLen; k++) {
            if (firstSet[k] == secondSet[i]) {
                isElementInFirstSet = true;
                break;
            }
        }
        if (i < secondLen && !isElementInFirstSet) {
            newSet[numberOfGoodElements++] = secondSet[i];
        }
    }
    *newLen = numberOfGoodElements;
}

// Возвращает значение 'истина', если в массиве secondSet размера secondLen
// содержатся все элементы из массива firstSet размера firstLen, иначе - 'ложь'
bool isFirstUnorderedSetIncludeInSecondSet(const unsigned int * const firstSet, const int firstLen,
                                           const unsigned int * const secondSet, const int secondLen) {
    for (int i = 0; i < firstLen; i++) {
        int isElementInSecondSet = false;
        for(int j = 0; j < secondLen; j++) {
            if (secondSet[j] == firstSet[i]) {
                isElementInSecondSet = true;
                break;
            }
        }
        if (!isElementInSecondSet) {
            return false;
        }
    }
    return true;
}

// Возвращает значение 'истина', если массив secondSet размера secondLen и массив
// firstSet размера firstLen состоят из одинаковых элементов, иначе - 'ложь'
bool isEqualUnorderedSeats(const unsigned int * const firstSet, const int firstLen,
                           const unsigned int * const secondSet, const int secondLen) {
    if(firstLen != secondLen) {
        return false;
    }
    for (int i = 0; i < firstLen; i++) {
        int isElementInSecondSet = false;
        for(int j = 0; j < secondLen; j++) {
            if (secondSet[j] == firstSet[i]) {
                isElementInSecondSet = true;
                break;
            }
        }
        if (!isElementInSecondSet) {
            return false;
        }
    }
    return true;
}

// Cобирает массив newSet размера newLen, содержащий элементы из массива universe
// размера universeLen, которых нет в массиве set размера setLen
void additionOfUnorderedSet(const unsigned int * const set, const int setLen,
                            const unsigned int * const universe, const int universeLen,
                            unsigned int * const newSet, int * const newLen) {
    int numberOfGoodElements = 0;
    for (int i = 0; i < universeLen; i++) {
        int isElementInSet = false;
        for(int j = 0; j < setLen; j++) {
            if (set[j] == universe[i]) {
                isElementInSet = true;
                break;
            }
        }
        if (!isElementInSet) {
            newSet[numberOfGoodElements++] = universe[i];
        }
    }
    *newLen = numberOfGoodElements;
}






// Собирает отсортированный по возрастанию массив newSet размера newLen,
// содержащий все элементы из упорядоченных массивов firstSet размера firstLen
// и secondSet размера secondLen без повторений
void unificationOfOrderedSets(const unsigned int * const firstSet, const int firstLen,
                              const unsigned int * const secondSet, const int secondLen,
                              int * const newSet, int * const newLen) {
    int firstSetIndex = 0;
    int secondSetIndex = 0;
    int newSetIndex = 0;
    while (firstSetIndex < firstLen || secondSetIndex < secondLen) {
        if (firstSetIndex < firstLen && (secondSetIndex >= secondLen ||
                                         firstSet[firstSetIndex] < secondSet[secondSetIndex])) {
            if(newSetIndex == 0 || firstSet[firstSetIndex] > newSet[newSetIndex - 1]) {
                newSet[newSetIndex] = firstSet[firstSetIndex];
            }
            else {
                newSetIndex--;
            }
            firstSetIndex++;
        }
        else {
            if (newSetIndex == 0 ||
                secondSet[secondSetIndex] > newSet[newSetIndex - 1]) {
                newSet[newSetIndex] = secondSet[secondSetIndex];
            }
            else {
                newSetIndex--;
            }
            secondSetIndex++;
        }
        newSetIndex++;
    }
    *newLen = newSetIndex;
}

// Собирает отсортированный по возрастанию массив newSet размера newLen,
// содержащий все элементы, которые есть в обоих упорядоченных массивов
// firstSet размера firstLen и secondSet размера secondLen
void intersectionOfOrderedSets(const unsigned int * const firstSet, const int firstLen,
                               const unsigned int * const secondSet, const int
                               secondLen,int * const newSet, int * const newLen) {
    int firstSetIndex = 0;
    int secondSetIndex = 0;
    int newSetIndex = 0;
    while (firstSetIndex < firstLen && secondSetIndex < secondLen) {
        if (firstSet[firstSetIndex] < secondSet[secondSetIndex]) {
            firstSetIndex++;
        }
        else if (firstSet[firstSetIndex] > secondSet[secondSetIndex]){
            secondSetIndex++;
        }
        else {
            newSet[newSetIndex++] = firstSet[firstSetIndex++];
        }
    }
    *newLen = newSetIndex;
}

// Собирает отсортированный по возрастанию массив newSet размера newLen, содержащий
// все элементы, которые есть в упорядоченном массиве firstSet размера firstLen,
// но нет в secondSet размера secondLen
void differenceOfOrderedSets(const unsigned int * const firstSet, const int firstLen,
                             const unsigned int * const secondSet, const int secondLen,
                             int * const newSet, int * const newLen) {
    int firstSetIndex = 0;
    int secondSetIndex = 0;
    int newSetIndex = 0;
    while (firstSetIndex < firstLen) {
        if (firstSet[firstSetIndex] < secondSet[secondSetIndex]) {
            newSet[newSetIndex++] = firstSet[firstSetIndex++];
        }
        else if (firstSet[firstSetIndex] > secondSet[secondSetIndex] &&
                 secondSetIndex < secondLen){
            secondSetIndex++;
        }
        else {
            firstSetIndex++;
            secondSetIndex += secondSetIndex < secondLen;
        }
    }
    *newLen = newSetIndex;
}

// Cобирает упорядоченный по возрастанию массив newSet размера newLen, содержащий
// элементы из упорядоченного массива firstSet размера firstLen, которых нет в массиве
// secondSet размера secondLen и элементы из массива secondSet, которых нет в firstSet
void symmetricDifferenceOfOrderedSets(const unsigned int * const firstSet, const int
firstLen, const unsigned int * const secondSet,
                                      const int secondLen, unsigned int * const newSet,
                                      int * const newLen) {
    int firstSetIndex = 0;
    int secondSetIndex = 0;
    int newSetIndex = 0;
    while (firstSetIndex < firstLen || secondSetIndex < secondLen) {
        if (firstSetIndex < firstLen && secondSetIndex < secondLen) {
            if (firstSet[firstSetIndex] < secondSet[secondSetIndex]) {
                newSet[newSetIndex++] = firstSet[firstSetIndex++];
            }
            else if (firstSet[firstSetIndex] > secondSet[secondSetIndex]) {
                newSet[newSetIndex++] = secondSet[secondSetIndex++];
            }
            else {
                firstSetIndex++;
                secondSetIndex++;
            }
        }
        else if (firstSetIndex < firstLen && secondSetIndex >= secondLen) {
            newSet[newSetIndex++] = firstSet[firstSetIndex++];
        }
        else {
            newSet[newSetIndex++] = secondSet[secondSetIndex++];
        }
    }
    *newLen = newSetIndex;
}

// Возвращает значение 'истина', если в упорядоченном по
// возрастанию массиве secondSet размера secondLen содержатся все элементы
// из упорядоченного массива firstSet размера firstLen, иначе - 'ложь'
bool isFirstOrderedSetIncludeInSecondSet(const unsigned int * const firstSet, const int
firstLen, const unsigned int * const
secondSet, const int secondLen) {
    if (secondLen < firstLen) {
        return false;
    }
    int firstSetIndex = 0;
    int secondSetIndex = 0;
    while (firstSetIndex < firstLen && secondSetIndex < secondLen) {
        if (firstSet[firstSetIndex] < secondSet[secondSetIndex]) {
            return false;
        }
        else if (firstSet[firstSetIndex] > secondSet[secondSetIndex]) {
            secondSetIndex++;
            if (secondSetIndex >= secondLen) {
                return false;
            }
        }
        else {
            firstSetIndex++;
            secondSetIndex++;
        }
    }
    return true;
}

// Возвращает значение 'истина', если упорядоченный по возрастанию массив secondSet
// размера secondLen и упорядоченный массив firstSet размера firstLen состоят из
// одинаковых элементов, иначе - 'ложь'
bool isEqualOrderedSets(const unsigned int * const firstSet, const int firstLen,
                         const unsigned int * const secondSet, const int secondLen) {
    if (firstLen != secondLen) {
        return false;
    }
    for (int i = 0; i < firstLen; i++) {
        if (firstSet[i] != secondSet[i]) {
            return false;
        }
    }
    return true;
}

// Cобирает упорядоченный по возрастанию массив newSet размера newLen, содержащий
// элементы из упорядоченного массива universe размера universeLen, которых нет в
// массиве set размера setLen
void additionOfOrderedSet(const unsigned int * const set, const int setLen,
                          const unsigned int * const universe, const int universeLen,
                          unsigned int * const newSet, int * const newLen) {
    int universeIndex = 0;
    int setIndex = 0;
    int newSetIndex = 0;
    while (universeIndex < universeLen) {
        if (universe[universeIndex] < set[setIndex]) {
            newSet[newSetIndex++] = universe[universeIndex++];
        }
        else if (universe[universeIndex] > set[setIndex] && setIndex < setLen){
            setIndex++;
        }
        else {
            universeIndex++;
            setIndex += setIndex < setLen;
        }
    }
    *newLen = newSetIndex;
}




// Собирает отсортированный по возрастанию массив newSet размера newLen,
// содержащий все элементы из упорядоченных массивов firstSet размера firstLen
// и secondSet размера secondLen без повторений
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
void unificationOfSets(const bool * const firstSet, const int firstLen,
                       const bool * const secondSet, const int secondLen,
                       bool * const newSet, int * const newLen) {
    int maxNumberOfSets = (firstLen > secondLen ? firstLen : secondLen);
    for (int i = 0; i < maxNumberOfSets; i++) {
        newSet[i] = i < firstLen && firstSet[i] || i < secondLen && secondSet[i];
    }
    *newLen = maxNumberOfSets;
}

// Собирает отсортированный по возрастанию массив newSet размера newLen,
// содержащий все элементы, которые есть в обоих упорядоченных массивов
// firstSet размера firstLen и secondSet размера secondLen
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
void intersectionOfSets(const bool * const firstSet, const int firstLen,
                        const bool * const secondSet, const int secondLen,
                        bool * const newSet, int * const newLen) {
    int minNumberOfSets = (firstLen < secondLen ? firstLen : secondLen);
    int maxGoodElement = -1;
    for (int i = 0; i < minNumberOfSets; i++) {
        int isGoodElement = firstSet[i] && secondSet[i];
        newSet[i] = isGoodElement;
        maxGoodElement = i * isGoodElement;
    }
    *newLen = maxGoodElement + 1;
}

// Собирает отсортированный по возрастанию массив newSet размера newLen, содержащий
// все элементы, которые есть в упорядоченном массиве firstSet размера firstLen,
// но нет в secondSet размера secondLen
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
void differenceOfSets(const bool * const firstSet, const int firstLen,
                      const bool * const secondSet, const int secondLen,
                      bool * const newSet, int * const newLen) {
    int maxGoodElement = -1;
    for (int i = 0; i < firstLen; i++) {
        int isGoodElement = firstSet[i] && (i >= secondLen || !secondSet[i]);
        newSet[i] = isGoodElement;
        maxGoodElement = i * isGoodElement;
    }
    *newLen = maxGoodElement + 1;
}

// Cобирает упорядоченный по возрастанию массив newSet размера newLen, содержащий
// элементы из упорядоченного массива firstSet размера firstLen, которых нет в массиве
// secondSet размера secondLen и элементы из массива secondSet, которых нет в firstSet
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
void symmetricDifferenceOfSets(const bool * const firstSet, const int firstLen,
                               const bool * const secondSet, const int secondLen,
                               bool * const newSet, int * const newLen) {
    int maxNumberOfSets = (firstLen > secondLen ? firstLen : secondLen);
    int maxGoodElement = -1;
    for (int i = 0; i < maxNumberOfSets; i++) {
        int isGoodElement = i < firstLen && firstSet[i] && (i >= secondLen ||
                                                            !secondSet[i]) || i < secondLen && secondSet[i] &&
                                                                              (i >= firstLen || !firstSet[i]);
        newSet[i] = isGoodElement;
        maxGoodElement = i * isGoodElement;
    }
    *newLen = maxGoodElement + 1;
}

// Возвращает значение 'истина', если в упорядоченном по
// возрастанию массиве secondSet размера secondLen содержатся все элементы
// из упорядоченного массива firstSet размера firstLen, иначе - 'ложь'
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
bool isFirstSetIncludeInSecondSet(const bool * const firstSet, const int firstLen,
                                  const bool * const secondSet, const int secondLen) {
    if (secondLen < firstLen) {
        return false;
    }
    for (int i = 0; i < firstLen; i++) {
        if (firstSet[i] != secondSet[i]) {
            return false;
        }
    }
    return true;
}

// Возвращает значение 'истина', если упорядоченный по возрастанию массив secondSet
// размера secondLen и упорядоченный массив firstSet размера firstLen состоят из
// одинаковых элементов, иначе - 'ложь'
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
bool isEqualSeats(const bool * const firstSet, const int firstLen,
                  const bool * const secondSet, const int secondLen) {
    if (firstLen != secondLen) {
        return false;
    }
    for (int i = 0; i < firstLen; i++) {
        if (firstSet[i] != secondSet[i]) {
            return false;
        }
    }
    return true;
}

// Cобирает упорядоченный по возрастанию массив newSet размера newLen, содержащий
// элементы из упорядоченного массива universe размера universeLen, которых нет в
// массиве set размера setLen
// Для всех массивов действует правило(Если в массиве A есть элемент i,
// то элемент a[i] = 'истина' иначе - 'ложь')
void additionOfSet(const bool * const set, const int setLen,
                   const bool * const universe, const int universeLen,
                   bool * const newSet, int * const newLen) {
    int maxGoodElement = -1;
    for (int i = 0; i < universeLen; i++) {
        int isGoodElement = universe[i] && (i >= setLen || !set[i]);
        newSet[i] = isGoodElement;
        maxGoodElement = i * isGoodElement;
    }
    *newLen = maxGoodElement + 1;
}

int main() {
    int lenA, lenB, lenC;
    printf("Input len of set A\n");
    scanf("%d", &lenA); // вводим мощность множества A
    unsigned int a[lenA];
    printf("Input A elements\n");
    for (int i = 0; i < lenA; i++) { // вводим элементы множества A
        scanf("%d", &a[i]);
    }
    printf("Input len of set B\n");
    scanf("%d", &lenB); // вводим мощность множества B
    unsigned int b[lenB];
    printf("Input B elements\n");
    for (int i = 0; i < lenB; i++) { // вводим элементы множества B
        scanf("%d", &b[i]);
    }
    printf("Input len of set C\n");
    scanf("%d", &lenC); // вводим мощность множества C
    unsigned int c[lenC];
    printf("Input C elements\n");
    for (int i = 0; i < lenC; i++) { // вводим элементы множества C
        scanf("%d", &c[i]);
    }
    // производим вычисления
    int lenE = lenB;
    unsigned int e[lenE];
    differenceOfOrderedSets(b, lenB, a, lenA, e, &lenE);
    int lenF = lenB + lenC;
    unsigned int f[lenF];
    unificationOfOrderedSets(b, lenB, c, lenC, f, &lenF);
    int lenG = lenA;
    unsigned int g[lenG];
    differenceOfOrderedSets(a, lenA, f, lenF, g, &lenG);
    int lenH = lenC;
    unsigned int h[lenH];
    differenceOfOrderedSets(c, lenC, a, lenA, h, &lenH);
    int lenEG = lenE + lenG;
    unsigned int eg[lenEG];
    unificationOfOrderedSets(e, lenE, g, lenG, eg, &lenEG);
    int lenD = lenEG + lenH;
    unsigned int d[lenD];
    unificationOfOrderedSets(eg, lenEG, h, lenH, d, &lenD);
    printf("\na) D = {");
    for (int i = 0; i < lenD; i++) { // выводим элементы множества D
        printf("%d", d[i]);
        if (i != lenD - 1) {
            printf(", ");
        }
        else {
            printf("}\n");
        }
    }
    return 0;
}