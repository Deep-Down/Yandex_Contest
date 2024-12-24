//Стильная Одежда
#include <iostream>

void QuickSort(int* arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = arr[(left + right) / 2];
  int i = left;
  int j = right;
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  if (left < j) {
    QuickSort(arr, left, j);
  }
  if (i < right) {
    QuickSort(arr, i, right);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;
  std::cin >> n1;
  int* caps = new int[n1];
  for (int i = 0; i < n1; ++i) {
    std::cin >> caps[i];
  }

  std::cin >> n2;
  int* shirts = new int[n2];
  for (int i = 0; i < n2; ++i) {
    std::cin >> shirts[i];
  }

  std::cin >> n3;
  int* pants = new int[n3];
  for (int i = 0; i < n3; ++i) {
    std::cin >> pants[i];
  }

  std::cin >> n4;
  int* shoes = new int[n4];
  for (int i = 0; i < n4; ++i) {
    std::cin >> shoes[i];
  }

  QuickSort(caps, 0, n1 - 1);
  QuickSort(shirts, 0, n2 - 1);
  QuickSort(pants, 0, n3 - 1);
  QuickSort(shoes, 0, n4 - 1);

  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int min_diff = 1000000;
  int best_cap = 0;
  int best_shirt = 0;
  int best_pant = 0;
  int best_shoe = 0;

  while (i < n1 && j < n2 && k < n3 && l < n4) {
    int current_min = caps[i];
    if (shirts[j] < current_min) {
      current_min = shirts[j];
    }
    if (pants[k] < current_min) {
      current_min = pants[k];
    }
    if (shoes[l] < current_min) {
      current_min = shoes[l];
    }

    int current_max = caps[i];
    if (shirts[j] > current_max) {
      current_max = shirts[j];
    }
    if (pants[k] > current_max) {
      current_max = pants[k];
    }
    if (shoes[l] > current_max) {
      current_max = shoes[l];
    }

    int current_diff = current_max - current_min;
    if (current_diff < min_diff) {
      min_diff = current_diff;
      best_cap = caps[i];
      best_shirt = shirts[j];
      best_pant = pants[k];
      best_shoe = shoes[l];
    }

    if (current_min == caps[i]) {
      ++i;
    } else if (current_min == shirts[j]) {
      ++j;
    } else if (current_min == pants[k]) {
      ++k;
    } else {
      ++l;
    }
  }

  std::cout << best_cap << " " << best_shirt << " " << best_pant << " " << best_shoe << '\n';

  delete[] caps;
  delete[] shirts;
  delete[] pants;
  delete[] shoes;

  return 0;
}


//Чебурашка и крокодил Гена
#include <iostream>

char* ReadInputString(int max_length) {
  char* str = new char[max_length + 1]{0};
  std::cin.getline(str, max_length + 1);
  return str;
}

int GetStringLength(char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

void CheckIndex(int* indices, int* erase, int size) {
  for (int i = 0; i < size; i++) {
    std::cin >> indices[i];
    int pos = indices[i] - 1;
    if (pos >= 0 && pos < size) {
      erase[pos] = i + 1;
    }
  }
}

bool Assemble(char* text, char* pattern, int* erase, int text_len, int pattern_len, int t) {
  int j = 0;
  for (int i = 0; i < text_len && j < pattern_len; i++) {
    if (erase[i] > t && text[i] == pattern[j]) {
      j++;
    }
  }
  return (j == pattern_len);
}

int FindMax(char* text, char* pattern, int* erase, int text_len, int pattern_len) {
  int left = 0;
  int right = text_len;
  int best_t = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (Assemble(text, pattern, erase, text_len, pattern_len, mid)) {
      best_t = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return best_t;
}

int main() {
  const int max_length = 200000;
  char* text = ReadInputString(max_length);
  int text_len = GetStringLength(text);
  char* pattern = ReadInputString(max_length);
  int pattern_len = GetStringLength(pattern);

  if (pattern_len > text_len) {
    std::cout << 0;
    delete[] text;
    delete[] pattern;
    return 0;
  }

  int* indices = new int[text_len];
  int* erase = new int[text_len]{0};
  CheckIndex(indices, erase, text_len);
  int max = FindMax(text, pattern, erase, text_len, pattern_len);
  std::cout << max;
  delete[] text;
  delete[] pattern;
  delete[] indices;
  delete[] erase;
  return 0;
}


//Сортировка подсчетом
#include <iostream>

int main() {
  const int max_temp = 1000000;
  int n = 0;
  std::cin >> n;
  if (n == 0) {
    return 0;
  }

  int count[max_temp + 1] = {0};
  for (int i = 0; i < n; ++i) {
    int temp = 0;
    std::cin >> temp;
    count[temp]++;
  }

  for (int i = 0; i <= max_temp; ++i) {
    while (count[i] > 0) {
      std::cout << i << "\n";
      count[i]--;
    }
  }
  return 0;
}


//Сложение без сложения
#include <iostream>

int Sum(int a, int b) {
  if (b == 0) {
    return a;
  }
  return Sum(a + 1, b - 1);
}

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  std::cout << Sum(a, b) << "\n";
  return 0;
}


//Без массивов
#include <iostream>

void PrintReversed(int n) {
  if (n == 0) {
    return;
  }
  int element = 0;
  std::cin >> element;
  PrintReversed(n - 1);
  std::cout << element << "\n";
}
int main() {
  int n = 0;
  std::cin >> n;
  PrintReversed(n);
  return 0;
}


//Быстрое возведение в степень
#include <iostream>
double FastPow(double a, unsigned int n) {
  double result = 1.0;
  while (n > 0) {
    if (n % 2 == 1) {
      result *= a;
    }
    a *= a;
    n /= 2;
  }
  return result;
}
int main() {
  double a = 0;
  unsigned int n = 0;
  std::cin >> a >> n;
  std::cout << FastPow(a, n) << "\n";
}


//Количество вызовов функции Фибоначчи
#include <iostream>

int Fibonacci(int n, int& count) {
  count++;
  if (n == 1 || n == 2) {
    return 1;
  }
  return Fibonacci(n - 1, count) + Fibonacci(n - 2, count);
}

int main() {
  int n = 0;
  std::cin >> n;
  int call_count = 0;
  Fibonacci(n, call_count);
  std::cout << call_count << "\n";
  return 0;
}


//Разделяй
#include <cmath>
#include <iostream>

int FindMinDifference(int* arr, int n, int index, int sum1, int sum2) {
  if (index == n) {
    return std::abs(sum1 - sum2);
  }
  int include_in_first_set = FindMinDifference(arr, n, index + 1, sum1 + arr[index], sum2);
  int include_in_second_set = FindMinDifference(arr, n, index + 1, sum1, sum2 + arr[index]);
  return std::min(include_in_first_set, include_in_second_set);
}

int main() {
  int n = 0;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int min_difference = FindMinDifference(arr, n, 0, 0, 0);
  std::cout << min_difference << std::endl;
  delete[] arr;
  return 0;
}


//Перестановки
#include <iostream>

void BubbleSort(char arr[], int length) {
  for (int i = 0; i < length - 1; ++i) {
    for (int j = 0; j < length - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        char temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void GeneratePermutations(char input[], int size, char current[], bool is_used[], int pos) {
  if (pos == size) {
    current[size] = '\0';
    std::cout << current << '\n';
    return;
  }
  for (int i = 0; i < size; ++i) {
    if (!is_used[i]) {
      is_used[i] = true;
      current[pos] = input[i];
      GeneratePermutations(input, size, current, is_used, pos + 1);
      is_used[i] = false;
    }
  }
}

int main() {
  const int max_length = 8;
  char input_str[max_length + 1] = {0};
  std::cin.getline(input_str, max_length + 1);
  int str_length = 0;
  while (str_length < max_length && input_str[str_length] != '\0') {
    str_length++;
  }
  BubbleSort(input_str, str_length);
  char current_perm[max_length + 1] = {0};
  bool is_used[max_length] = {false};
  GeneratePermutations(input_str, str_length, current_perm, is_used, 0);
  return 0;
}


//Пары делимых
#include <cstdint>
#include <iostream>

uint64_t CalcIntSqrt(uint64_t x) {
  if (x <= 1) {
    return x;
  }
  uint64_t low = 1;
  uint64_t high = x;
  uint64_t result = 0;
  while (low <= high) {
    uint64_t mid = low + (high - low) / 2;
    if (mid <= x / mid) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}
uint64_t CalculatePairs(uint64_t number) {
  uint64_t total_pairs = 0;
  uint64_t sqrt_val = CalcIntSqrt(number);

  for (uint64_t i = 1; i <= sqrt_val; ++i) {
    total_pairs += number / i;
  }
  uint64_t threshold = number / (sqrt_val + 1);
  for (uint64_t k = 1; k <= threshold; ++k) {
    uint64_t upper_bound = number / k;
    uint64_t lower_bound = number / (k + 1) + 1;
    total_pairs += k * (upper_bound - lower_bound + 1);
  }
  return total_pairs;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t = 0;
  std::cin >> t;
  while (t--) {
    uint64_t number = 0;
    std::cin >> number;
    std::cout << CalculatePairs(number) << '\n';
  }
  return 0;
}
