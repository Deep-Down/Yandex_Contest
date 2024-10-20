//Number Complement. Baby Steps
#include <iostream>

int main() {
  unsigned int num = 0;
  std::cin >> num;
  unsigned int mask = 0;
  unsigned int temp = num;
  while (temp > 0) {
    mask = (mask << 1) | 1;
    temp >>= 1;
  }
  unsigned int complement = (~num) & mask;
  std::cout << complement << std::endl;
  return 0;
}

//Squares of a Sorted Array
#include <iostream>

int main() {
  const int size = 10000;
  int nums[size];
  for (int i = 0; i < size; i++) {
    std::cin >> nums[i];
  }
  int result[size];
  int left = 0;
  int right = size - 1;
  int index = size - 1;
  
  while (left <= right) {
    int left_square = nums[left] * nums[left];
    int right_square = nums[right] * nums[right];
    
    if (left_square > right_square) {
      result[index] = left_square;
      left++;
    } else {
      result[index] = right_square;
      right--;
    }
    index--;
  }

  for (int i = 0; i < size; i++) {
    std::cout << result[i] << " ";
  }
}

//Move Zeroes
#include <iostream>

int main() {
  const int max_size = 10000;
  int nums[max_size];

  for (int i = 0; i < max_size; ++i) {
    std::cin >> nums[i];
  }
  int non_zero_index = 0;
  for (int i = 0; i < max_size; ++i) {
    if (nums[i] != 0) {
      nums[non_zero_index] = nums[i];
      ++non_zero_index;
    }
  }
  for (int i = non_zero_index; i < max_size; ++i) {
    nums[i] = 0;
  }
  for (int i = 0; i < max_size; ++i) {
    std::cout << nums[i] << " ";
  }
  return 0;
}

//Single Number - Single Step
#include <iostream>

int main() {
  const int size = 9999;
  int nums[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> nums[i];
  }
  int single_number = 0;
  for (int i = 0; i < size; ++i) {
    single_number ^= nums[i];
  }
  std::cout << single_number;
  return 0;
}

//Multiplication of two matrices
#include <iostream>

int main() {
  const int rows = 3;
  const int cols = 3;
  int64_t first_matrix[rows][cols];
  int64_t second_matrix[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cin >> first_matrix[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cin >> second_matrix[i][j];
    }
  }
  int64_t result_matrix[rows][cols] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < 3; k++) {
        result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
        // std::cout << first_matrix[i][k] << "\t" << second_matrix[k][j] <<
        // "\t" << result_matrix[i][j] << std::endl;
      }
    }
  }
  std::cout << result_matrix[0][0] << " " << result_matrix[0][1] << " " << result_matrix[0][2] << "\n";
  std::cout << result_matrix[1][0] << " " << result_matrix[1][1] << " " << result_matrix[1][2] << "\n";
  std::cout << result_matrix[2][0] << " " << result_matrix[2][1] << " " << result_matrix[2][2] << "\n";
}

//Sieve of Eratosthenes. Final Step
#include <iostream>

int main() {
  int64_t a = 0;
  int64_t b = 0;
  std::cin >> a >> b;
  for (int64_t i = a; i <= b; i++) {
    int prime = 1;
    if (i <= 3) {
      prime = 1;
    } else if (i % 2 == 0 || i % 3 == 0) {
      prime = 0;
    } else {
      for (unsigned int j = 5; j * j <= b; j += 6) {
        if (i % j == 0 || i % (j + 2) == 0) {
          prime = 0;
          break;
        }
      }
    }
    if (prime) {
      std::cout << i << "\n";
    } else {
      ;
    }
  }
}

//Двоичный поиск
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int* arr_n = new int[n];
  int* arr_k = new int[k];

  for (int i = 0; i < n; i++) {
    std::cin >> arr_n[i];
  }
  for (int i = 0; i < k; i++) {
    std::cin >> arr_k[i];
  }
  for (int i = 0; i < k; i++) {
    int key = arr_k[i];
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr_n[mid] == key) {
        found = true;
        break;
      }
      if (arr_n[mid] < key) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (found) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  delete[] arr_n;
  delete[] arr_k;
}

//Поляна дров
#include <cmath>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double v_p = 0;
  double v_f = 0;
  double a = 0;

  std::cin >> v_p >> v_f >> a;

  double left = 0;
  double right = 1;
  double x = 0;

  while (fabs((left + right) / 2 - x) > 0.00001) {
    x = (left + right) / 2;
    double dx = x / (sqrt(x * x + (a - 1) * (a - 1)) * v_p) + (x - 1) / (sqrt((x - 1) * (x - 1) + a * a) * v_f);
    if (dx < 0) {
      left = x;
    } else {
      right = x;
    }
  }
  std::cout << x;
  return 0;
}

//Дюбели и сверла
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  int* drills = new int[n];
  int* dowels = new int[m];

  for (int i = 0; i < n; i++) {
    std::cin >> drills[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> dowels[i];
  }
  int min_diff = 1000000000;

  for (int i = 0; i < n; i++) {
    int left = 0;
    int right = m - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int current_diff = (drills[i] > dowels[mid]) ? (drills[i] - dowels[mid]) : (dowels[mid] - drills[i]);
      if (current_diff < min_diff) {
        min_diff = current_diff;
      }
      if (dowels[mid] < drills[i]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  std::cout << min_diff << "\n";
  delete[] drills;
  delete[] dowels;
  return 0;
}

//Очень легкая задача
#include <iostream>

int main() {
  int n = 0;
  int x = 0;
  int y = 0;
  std::cin >> n >> x >> y;

  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }
  int left = 0;
  int right = (n - 1) * y;
  int result = right;

  while (left <= right) {
    int mid = (left + right) / 2;
    int copies = mid / x + mid / y;
    if (copies >= n - 1) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  std::cout << result + x << "\n";
}

//Дипломы
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t w = 0;
  int64_t h = 0;
  int64_t n = 0;
  std::cin >> w >> h >> n;
  int64_t left = 0;
  int64_t right = 1;
  while ((right / w) * (right / h) < n) {
    right *= 2;
  }
  while (right > left + 1) {
    int64_t mid = (left + right) / 2;
    if ((mid / w) * (mid / h) >= n) {
      right = mid;
    } else {
      left = mid;
    }
  }
  std::cout << right << std::endl;
}

//Коровы в стойла
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int* arr = new int[10001];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int left = 1;
  int right = arr[n - 1] - arr[0];
  int result = 0;
  while (left <= right) {
    int mid = (left + right) / 2;
    int last_pos = arr[0];
    int cow = 1;
    for (int i = 1; i < n; i++) {
      if (arr[i] - last_pos >= mid) {
        cow++;
        last_pos = arr[i];
      }
    }
    if (cow >= k) {
      result = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  std::cout << result << "\n";
  delete[] arr;
}
