#include <iostream>
#include <fstream>
# include <string>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

void Merge(int numbers[], int left, int j, int right) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = nullptr;

   mergePos = 0;
   mergedSize = right - left + 1;
   leftPos = left;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= right) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= right) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[left + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

void MergeSort(int numbers[], int left, int right) {
   int j;
   
   if (left < right) {
      j = (left + right) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, left, j);
      MergeSort(numbers, j + 1, right);
      
      // Merge left and right partition in sorted order
      Merge(numbers, left, j, right);
   }
}

// int main() {
//    int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
//    const int NUMBERS_SIZE = 8;
//    int i;
   
//    cout << "UNSORTED: ";
//    for(i = 0; i < NUMBERS_SIZE; ++i) {
//       cout << numbers[i] << " ";
//    }
//    cout << endl;
   
//    MergeSort(numbers, 0, NUMBERS_SIZE - 1);
   
//    cout << "SORTED: ";
//    for(i = 0; i < NUMBERS_SIZE; ++i) {
//       cout << numbers[i] << " ";
//    }
//    cout << endl;
   
//    return 0;
// }

int main(int argc,char* argv[]){
    //cout << "im in main" << endl;
    ifstream inFile1;

    ifstream inFile2;

    inFile1.open(argv[2]);
    inFile2.open(argv[3]);

    if (argv[1][0] == 'i'){
        //cout << "i got here";
        int arr1[20000];
        int arr2[20000];

        int arr1Size, arr2Size;

        int i = 0;

        while (inFile1 >> arr1[i]){

            i++;
        }

        arr1Size = i;
        i = 0;

        while (inFile2 >> arr2[i]){

            i++;
        }

        arr2Size = i;

        MergeSort(arr1,0,arr1Size-1);
        MergeSort(arr2,0,arr2Size-1);

        int last = INT_MAX;

        for (int one = 0; one < arr1Size;one++){
            for (int two = 0;two < arr2Size;two++){
                if (arr1[one] == arr2[two] && arr1[one] != last){
                    last = arr1[one];
                    cout << arr1[one] << endl;
                }

            }

        }

        // cout << "print sorted lists: " << endl;

        // for (int k = 0; k<arr1Size;k++){
        //     cout << arr1[k] << endl;

        // }
        // cout << endl <<endl;

        // for (int k = 0; k<arr2Size;k++){
        //     cout << arr2[k] << endl;

        // } 

   }

    if (argv[1][0] == 's'){
        cout << " im in string";
        string arr1[20000];
        string arr2[20000];

        int i = 0;

        while (inFile1 >> arr1[i]){

            i++;
        }

        i=0;

        while (inFile2 >> arr2[i]){

            i++;
        }


    }

    return 0;
}