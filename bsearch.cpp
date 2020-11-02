#include <iostream>


int binarySearch(int n, int *b, int lo, int hi) {
  if (hi < lo) return -1;
  else {
    int mid = (hi + lo)/2;
    if (n == b[mid]) return b[mid];
    else {
      if (n < b[mid]) return binarySearch(n, b, lo, mid-1);
      else return binarySearch(n, b, mid+1, hi);
    }
  }
}

int imperBinarySearch(int n, int *b, int len) {
  int lo = 0;
  int hi = len;
  while (hi >= lo) {
    int mid = (lo+hi)/2;
    if (n == b[mid]) return b[mid];
    if (n < b[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return -1;
}


int main() {
  int b[7] = {1,2,3,4,5,6,7};
  int n = binarySearch(2, b, 0, std::size(b));
  // int n = imperBinarySearch(1, b, std::size(b));
  std::cout << n << std::endl;
}
