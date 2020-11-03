#include <iostream>

int *q;
int **t;
int n;
int s = 0;

void printSolution() {
  std::cout << "A solution is ";
  for (int i = 0; i < n; i++) {
    std::cout << q[i] << " ";
  }
  std::cout << std::endl;
}

void addToThreats(int row, int column, int change) {
  for (int j = row + 1; j < n; j++) {
    t[j][column] += change;
    if (column+(j-row) < n) t[j][column+(j-row)] += change;
    if (column-(j-row) >= 0) t[j][column-(j-row)] += change;
  }
}

void search(int row) {
  if (row == n) {s++; printSolution();}
  else {
    for (q[row] = 0; q[row] < n; q[row]++) {
      if (t[row][q[row]] == 0) {
        addToThreats(row, q[row], 1);
        search(row + 1);  
        addToThreats(row, q[row], -1);
      }
    }
  }
}

int main() {
  std::cout << "Please write the number of queens and grid size: ";
  std::cin >> n;
  q = new int[n];
  t = new int* [n];
  for (int i = 0; i < n; i++) {
    t[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      t[i][j] = 0;
    }
  } 

  search(0);
  std::cout << "Number of solutions: " << s << std::endl;

  delete [] q;
  for (int i = 0; i < n; i++) delete [] t[i];
  delete [] t;
  return 0;
}
