//Побочная диагональ
#include <iostream>

int** Array(int n) {
  int** array = new int*[n];
  for (int i = 0; i < n; ++i) {
    array[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == n - i - 1) {
        array[i][j] = 1;
      } else if (j < n - i - 1) {
        array[i][j] = 0;
      } else {
        array[i][j] = 2;
      }
    }
  }
  return array;
}
int main() {
  int n = 0;
  std::cin >> n;
  int** array = Array(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << "\n";
  }
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}

//Треугольник Паскаля
#include <iostream>

int** Array(int n, int m) {
  int** array = new int*[n];
  for (int i = 0; i < n; ++i) {
    array[i] = new int[m];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 || j == 0) {
        array[i][j] = 1;
      } else {
        array[i][j] = array[i - 1][j] + array[i][j - 1];
      }
    }
  }
  return array;
}
int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int** array = Array(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}

//Заполнение диагоналями 
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int array[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      array[i][j] = 0;
    }
  }
  int num = 0;
  for (int k = 0; k < n * m; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + j == k) {
          array[i][j] = num;
          num += 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << '\n';
  }
}

//Спираль
#include <iostream>

void fillSpiral(int n) {
  int** arr = new int*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }
  int top = 0;
  int bottom = n - 1;
  int left = 0;
  int right = n - 1;
  int value = 1;
  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      arr[top][i] = value;
    }
    top += 2;
    for (int i = top - 1; i <= bottom; i++) {
      arr[i][right] = value;
    }
    right -= 2;
    if (top <= bottom) {
      for (int i = right + 1; i >= left; i--) {
        arr[bottom][i] = value;
      }
      bottom -= 2;
    }
    if (left <= right) {
      int i = bottom + 1;
      for (; i >= top; i--) {
        arr[i][left] = value;
      }
      arr[i + 1][left + 1] = 1;
      left += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j];
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
int main() {
  int n;
  std::cin >> n;
  fillSpiral(n);
  return 0;
}

//Сортировка слиянием
#include <iostream>

void Merge(int* arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int* L = new int[n1];
  int* R = new int[n2];
  for (int i = 0; i < n1; i++) L[i] = arr[left + i];
  for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
  delete[] L;
  delete[] R;
}
void MergeSort(int* arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  MergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  delete[] arr;
  return 0;
}

//Сливайся!
#include <iostream>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n;
  int* arr1 = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }
  std::cin >> m;
  int* arr2 = new int[m];
  for (int i = 0; i < m; i++) {
    std::cin >> arr2[i];
  }
  int* merged_arr = new int[n + m];
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) {
      merged_arr[k] = arr1[i];
      i++;
    } else {
      merged_arr[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < n) {
    merged_arr[k] = arr1[i];
    i++;
    k++;
  }
  while (j < m) {
    merged_arr[k] = arr2[j];
    j++;
    k++;
  }
  for (int i = 0; i < n + m; i++) {
    std::cout << merged_arr[i] << " ";
  }
  std::cout << "\n";
  delete[] arr1;
  delete[] arr2;
  delete[] merged_arr;
  return 0;
}

//Беспамятно сливаем
#include <iostream>
void Copy(const int *src_begin, const int *src_end, int *dest) {
  while (src_begin != src_end) {
    *dest = *src_begin;
    src_begin++;
    dest++;
  }
}
void Swap(int &lhs, int &rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}
void Reverse(int *begin, int *end) {
  if (begin + 1 == end) {
    return;
  }
  while (begin < end) {
    Swap(*begin++, *(--end));
  }
}
void Rotate(int *begin, int *border, int *end) {
  Reverse(begin, border);
  Reverse(border, end);
  Reverse(begin, end);
}
int *LowerBound(int *begin, int *end, int value) {
  size_t size = end - begin;
  int *it;
  while (size > 0) {
    it = begin;
    size_t step = size / 2;
    it += step;
    if (*it < value) {
      begin = ++it;
      size -= step + 1;
    } else {
      size = step;
    }
  }
  return begin;
}
int *UpperBound(int *begin, int *end, int value) {
  size_t size = end - begin;
  int *it;
  while (size > 0) {
    it = begin;
    size_t step = size / 2;
    it += step;
    if (*it <= value) {
      begin = ++it;
      size -= step + 1;
    } else {
      size = step;
    }
  }
  return begin;
}
void InplaceMerge(int *first_begin, int *first_end, int *second_begin,
                  int *second_end) {
  size_t first_size = first_end - first_begin;
  size_t second_size = second_end - second_begin;

  if (first_size == 0 || second_size == 0) {
    return;
  }
  if (first_size == 1 && second_size == 1) {
    if (*second_begin < *first_begin) {
      Swap(*first_begin, *second_begin);
    }
    return;
  }
  int *B1_begin = first_begin;
  int *B1_end;
  int *B2_begin;
  int *B3_begin = second_begin;
  int *B3_end;
  int *B4_begin;
  int *B4_end = second_end;
  if (first_size >= second_size) {
    B1_end = B1_begin + first_size / 2;
    B2_begin = B1_end;
    int *sep = LowerBound(second_begin, second_end, *B2_begin);
    B3_end = sep;
    B4_begin = sep;
  } else {
    B3_end = B3_begin + second_size / 2;
    B4_begin = B3_end;
    int *sep = UpperBound(first_begin, first_end, *B4_begin);
    B1_end = sep;
    B2_begin = sep;
  }
  Rotate(B2_begin, B3_begin, B3_end);
  size_t B3_size = B3_end - B3_begin;
  InplaceMerge(B1_begin, B1_end, B2_begin, B2_begin + B3_size);
  InplaceMerge(B2_begin + B3_size, B3_end, B4_begin, B4_end);
}
int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int *arr = new int[n + m];
  for (int i = 0; i < n + m; i++) {
    std::cin >> arr[i];
  }
  InplaceMerge(arr, arr + n, arr + n, arr + n + m);
  for (int i = 0; i < n + m; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}
