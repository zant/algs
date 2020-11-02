#include <iostream>

void printArr(int arr[], int size) {
  std::cout << "[ ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

class InsertionSort {
public:
  InsertionSort(int *arr, int arr_size) : m_size(arr_size) {
    m_arr = new int[arr_size];
    
    std::copy(arr, arr+arr_size, m_arr);
  };

  ~InsertionSort() {
    delete m_arr; 
  };

  void sort() {
    for (int j = 1; j < m_size; j++) {
      int key = m_arr[j];
      int i = j - 1;
      while (i >= 0 && m_arr[i] > key) {
        m_arr[i + 1] = m_arr[i];
        i--;
      }
      m_arr[i + 1] = key;
    }
  }

  void sort_des() {
    for (int j = 1; j < m_size; j++) {
      int key = m_arr[j];
      int i = j - 1;
      while (i >= 0 && m_arr[i] < key) {
        m_arr[i + 1] = m_arr[i];
        i--;
      }
      m_arr[i + 1] = key;
    }
  }

public:
  int m_size;
  int *m_arr;
};


int main() {
  int a[] = {2,4,3,1};
  InsertionSort is = InsertionSort((int *)&a, std::size(a));
  is.sort();
  printArr(is.m_arr, is.m_size);
  is.sort_des();
  printArr(is.m_arr, is.m_size);
}
