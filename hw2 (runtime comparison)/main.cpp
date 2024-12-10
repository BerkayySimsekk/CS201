#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;

//a linear search algorithm that returns the index of the found key; if it is unable to find the key, it returns -1
int linearSearch(const int* array, const int size, const int key) {
    for(int i = 0; i < size; i++)
        if(array[i] == key)
            return i;

    return -1;
}

//a recursive linear search algorithm that looks for the key starting at the end of the given array, it returns index of the found key or -1
int linearSearchRecursive(const int* array, const int size, const int key) {
    if (size == 0)
        return -1;
    if(array[size - 1] == key)
        return size - 1;

    return linearSearchRecursive(array, size - 1, key);
}

//a binary search algorithm that returns the index of the found key, it returns -1 if the key is not found
int binarySearch(const int* array, int start, int end, const int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (array[mid] == key)
            return mid;
        if (array[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

//a binary search algorithm that returns the index of the found key, it returns -1 if the key is not found
int jumpSearch(const int* array, const int size, const int key) {
    int block = sqrt(size);

    int previous = 0;
    while (array[min(block, size)-1] < key)
    {
        previous = block;
        block += sqrt(size);
        if (previous >= size)
            return -1;
    }

    while (array[previous] < key)
    {
        previous++;

        if (previous == min(block, size))
            return -1;
    }
    if (array[previous] == key)
        return previous;

    return -1;
}

//this algorithm does random linear search by choosing a random index and not using that chosen random index for the next times;
//it returns the index of the found key, it returns -1 if the key is not found
int randomLinearSearch(const int* array, const int size, const int key) {
    int* indexes = new int[size];

    for(int i = 0; i < size; i++) {
        indexes[i] = i;
    }

    int remainingSize = size;
    for(int i = 0; i < size; i++) {
        int randomIndex = rand() % remainingSize;
        if(array[indexes[randomIndex]] == key) {
            int i = indexes[randomIndex];
            delete[] indexes;
            return i;
        }

        int temp = indexes[remainingSize - 1];
        indexes[remainingSize - 1] = indexes[randomIndex];
        indexes[randomIndex] = temp;

        remainingSize--;
    }

    delete[] indexes;
    return -1;

}

//the dividing operation for the quick sort algorithm that sorts the integers in the array in ascending order
int divide(int* array, const int start, const int end) {
    int pivot = array[end];
    int i = start;

    for (int j = start; j < end; j++)
        if (array[j] < pivot) {
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
        }

    int temp = array[end];
    array[end] = array[i];
    array[i] = temp;

    return i;
}

//sorting the integers in the array in ascending order by using quick sort algorithm which uses recursion
void quickSort(int* array, const int start, const int end) {
    if(start < end) {
        int k = divide(array, start, end);
        quickSort(array, start, k - 1);
        quickSort(array, k + 1, end);
    }
}

int main() {
    int randomNum;
    const int sizeForPointerContainingArray = 10;
    int sizeForIntegerContainingArray = 5;

    //this array holds the arrays with different sizes
    int** arraysWithDifferentSizes = new int*[sizeForPointerContainingArray];

    //initiating the arrays with different sizes, filling them up with random numbers and sorting them in ascending order
    for (int i = 0; i < sizeForPointerContainingArray; i++) {
        arraysWithDifferentSizes[i] = new int[sizeForIntegerContainingArray];

        for(int n = 0; n < sizeForIntegerContainingArray; n++) {
            randomNum = rand() % (sizeForIntegerContainingArray * 10 + 1);
            arraysWithDifferentSizes[i][n] = randomNum;
        }

        quickSort(arraysWithDifferentSizes[i], 0, sizeForIntegerContainingArray - 1);

        sizeForIntegerContainingArray *= 5;
    }

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;

    //this bit finds the running times of linear search for arrays with different sizes for four different scenarios; these scenarios are that the key can be in the beginning,
    //middle, end of the array ,or it can be non-existent in the array
    cout << "Execution times for linear search: " << endl;
    sizeForIntegerContainingArray = 5;
    for(int i = 0; i < sizeForPointerContainingArray; i++) {
        startTime = std::chrono::system_clock::now();
        linearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 4]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the beginning with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 2]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the middle with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][static_cast<int>(sizeForIntegerContainingArray / 1.2)]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the end with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, sizeForIntegerContainingArray * 10 + 1);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is not found with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        sizeForIntegerContainingArray *= 5;
    }

    //this bit finds the running times of binary search for arrays with different sizes for four different scenarios; these scenarios are that the key can be in the beginning,
    //middle, end of the array ,or it can be non-existent in the array
    cout << "Execution times for binary search: " << endl;
    sizeForIntegerContainingArray = 5;
    for(int i = 0; i < sizeForPointerContainingArray; i++) {
        startTime = std::chrono::system_clock::now();
        for(int j = 0; j < 100; j++)
            binarySearch(arraysWithDifferentSizes[i],0, sizeForIntegerContainingArray - 1, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 4]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() / 100 << " milliseconds for the key that is close to the beginning with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        for(int j = 0; j < 100; j++)
            binarySearch(arraysWithDifferentSizes[i],0, sizeForIntegerContainingArray - 1, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 2]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() / 100 << " milliseconds for the key that is close to the middle with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        for(int j = 0; j < 100; j++)
            binarySearch(arraysWithDifferentSizes[i],0, sizeForIntegerContainingArray - 1, arraysWithDifferentSizes[i][static_cast<int>(sizeForIntegerContainingArray / 1.2)]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() / 100 << " milliseconds for the key that is close to the end with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        for(int j = 0; j < 100; j++)
            binarySearch(arraysWithDifferentSizes[i],0, sizeForIntegerContainingArray - 1, sizeForIntegerContainingArray * 10 + 1);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() / 100 << " milliseconds for the key that is not found with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        sizeForIntegerContainingArray *= 5;
    }

    //this bit finds the running times of jump search for arrays with different sizes for four different scenarios; these scenarios are that the key can be in the beginning,
    //middle, end of the array ,or it can be non-existent in the array
    cout << "Execution times for jump search: " << endl;
    sizeForIntegerContainingArray = 5;
    for(int i = 0; i < sizeForPointerContainingArray; i++) {
        startTime = std::chrono::system_clock::now();
        jumpSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 4]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the beginning with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        jumpSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 2]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the middle with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        jumpSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][static_cast<int>(sizeForIntegerContainingArray / 1.2)]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the end with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        jumpSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, sizeForIntegerContainingArray * 10 + 1);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is not found with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        sizeForIntegerContainingArray *= 5;
    }

    //this bit finds the running times of random linear search for arrays with different sizes for four different scenarios; these scenarios are that the key can be in the beginning,
    //middle, end of the array ,or it can be non-existent in the array
    cout << "Execution times for random linear Search: " << endl;
    sizeForIntegerContainingArray = 5;
    for(int i = 0; i < sizeForPointerContainingArray; i++) {
        startTime = std::chrono::system_clock::now();
        randomLinearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 4]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the beginning with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        randomLinearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 2]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the middle with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        randomLinearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][static_cast<int>(sizeForIntegerContainingArray / 1.2)]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the end with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        randomLinearSearch(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, sizeForIntegerContainingArray * 10 + 1);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is not found with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        sizeForIntegerContainingArray *= 5;
    }

    //this bit finds the running times of linear search for arrays with different sizes for four different scenarios; these scenarios are that the key can be in the beginning,
    //middle, end of the array ,or it can be non-existent in the array (I had to manually increase the stack size for this part in the CMakeLists.txt file)
    cout << "Execution times for recursive linear search: " << endl;
    sizeForIntegerContainingArray = 5;
    for(int i = 0; i < sizeForPointerContainingArray; i++) {
        startTime = std::chrono::system_clock::now();
        linearSearchRecursive(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 4]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the beginning with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearchRecursive(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][sizeForIntegerContainingArray / 2]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the middle with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearchRecursive(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, arraysWithDifferentSizes[i][static_cast<int>(sizeForIntegerContainingArray / 1.2)]);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is close to the end with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        startTime = std::chrono::system_clock::now();
        linearSearchRecursive(arraysWithDifferentSizes[i], sizeForIntegerContainingArray, sizeForIntegerContainingArray * 10 + 1);
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds for the key that is not found with an array size of "<< sizeForIntegerContainingArray << "." << endl;

        sizeForIntegerContainingArray *= 5;
    }

    for(int i = 0; i < sizeForPointerContainingArray; i++)
        delete[] arraysWithDifferentSizes[i];
    delete[] arraysWithDifferentSizes;

    return 0;
}


