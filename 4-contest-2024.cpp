//Сортировка выбором
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  for (int j = 0; j < size; j++) {
    for (int i = j; i < size; i++) {
      if (arr[j] > arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

//Сортировка вставками
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < size - 1; i++) {
    int j = i + 1;
    while ((j > 0) && (arr[j] < arr[j - 1])) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

//Сортировка обменом
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

//Bubble Sort
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  int count = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        count++;
      }
    }
  }

  std::cout << count;
  delete[] arr;
}

//Мекс
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  bool* exists = new bool[size + 1]{false};

  for (int i = 0; i < size; ++i) {
    int nums = 0;
    std::cin >> nums;
    if (nums <= size) {
      exists[nums] = true;
    }
  }

  for (int i = 0; i <= size; ++i) {
    if (!exists[i]) {
      std::cout << i;
      delete[] exists;
      return 0;
    }
  }

  delete[] exists;
}

//Проблема сапожника 
#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int* repair_times = new int[k];
  for (int i = 0; i < k; ++i) {
    std::cin >> repair_times[i];
  }
  for (int i = 0; i < k - 1; ++i) {
    for (int j = 0; j < k - i - 1; ++j) {
      if (repair_times[j] > repair_times[j + 1]) {
        int temp = repair_times[j];
        repair_times[j] = repair_times[j + 1];
        repair_times[j + 1] = temp;
      }
    }
  }

  int count = 0;
  int time_spent = 0;
  for (int i = 0; i < k; ++i) {
    if (time_spent + repair_times[i] <= n) {
      time_spent += repair_times[i];
      ++count;
    } else {
      break;
    }
  }
  std::cout << count;
  delete[] repair_times;
}

//Карточки
#include <iostream>

void CountingSort(int *arr, const int size, int max) {
  int *m = new int[max];
  for (int i = 0; i < max; i++) {
    m[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    m[arr[i]]++;
  }
  int pos = 0;
  for (int i = 0; i < max; i++) {
    while (m[i] > 0) {
      arr[pos] = i;
      pos++;
      m[i]--;
    }
  }
  delete[] m;
}
void Input(int *arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
}
void Print(int *arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}
void PrintReversed(int *arr, const int size) {
  for (int i = size - 1; i >= 0; i--) {
    std::cout << arr[i];
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  int *arr = new int[n];
  Input(arr, n);
  CountingSort(arr, n, 10);
  PrintReversed(arr, n);
  delete[] arr;
}

//Лишнее число
#include <iostream>

int main() {
  int size = 0;
  std::cin >> size;
  int* nums = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> nums[i];
  }
  int single_number = 0;
  for (int i = 0; i < size; ++i) {
    single_number ^= nums[i];
  }
  std::cout << single_number;
  delete[] nums;
}

//Сортировка по последней цифре
#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  if (n == 0) {
    return 0;
  }
  auto* arr = new int64_t[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto* sorted = new int64_t[n];
  int count[10] = {0};
  for (int i = 0; i < n; ++i) {
    int64_t last_digit = arr[i] % 10;
    count[last_digit]++;
  }
  for (int i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    int64_t last_digit = arr[i] % 10;
    sorted[count[last_digit] - 1] = arr[i];
    count[last_digit]--;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << sorted[i];
    if (i != n - 1) {
      std::cout << " ";
    }
  }
  delete[] arr;
  delete[] sorted;
}

//Штабеля
#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  auto **boxes = new int64_t *[n];
  for (int i = 0; i < n; ++i) {
    boxes[i] = new int64_t[k];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cin >> boxes[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < k; ++j) {
      int64_t key = boxes[i][j];
      int l = j - 1;
      while (l >= 0 && boxes[i][l] > key) {
        boxes[i][l + 1] = boxes[i][l];
        --l;
      }
      boxes[i][l + 1] = key;
    }
    bool is_stable = true;
    int64_t sum_above = 0;
    for (int j = 0; j < k; ++j) {
      if (boxes[i][j] < sum_above) {
        is_stable = false;
        break;
      }
      sum_above += boxes[i][j];
    }
    if (is_stable) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  for (int i = 0; i < n; ++i) {
    delete[] boxes[i];
  }
  delete[] boxes;
}

//Точки и отрезки
#include <iostream>

int BinarySearch(int arr[], int size, int value) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  const int k_maxn = 200000;
  const int k_maxm = 100000;
  int start[k_maxn];
  int end[k_maxn];
  int points[k_maxm];
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    if (a > b) {
      int temp = b;
      b = a;
      a = temp;
    }
    start[i] = a;
    end[i] = b;
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> points[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (start[i] > start[j]) {
        int temp = start[i];
        start[i] = start[j];
        start[j] = temp;
      }
      if (end[i] > end[j]) {
        int temp = end[i];
        end[i] = end[j];
        end[j] = temp;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int point = points[i];
    int num_start = BinarySearch(start, n, point);
    int num_end = BinarySearch(end, n, point - 1);
    std::cout << num_start - num_end << " ";
  }
}

//Робот
#include <iostream>
#include <cmath>

void Copy(const int *src_begin, const int *src_end, int *dest) {
  while (src_begin != src_end) {
    *dest = *src_begin;
    src_begin++;
    dest++;
  }
}
void Merge(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end, int *result) {
  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin <= *second_begin) {
      *result = *first_begin;
      first_begin++;
    } else {
      *result = *second_begin;
      second_begin++;
    }
    result++;
  }
  Copy(first_begin, first_end, result);
  Copy(second_begin, second_end, result);
}
void MergeSort(int *begin, int *end, int *result) {
  size_t size = end - begin;
  if (size <= 1) {
    return;
  }
  MergeSort(begin, begin + size / 2, result);
  MergeSort(begin + size / 2, end, result);
  Merge(begin, begin + size / 2, begin + size / 2, end, result);
  Copy(result, result + size, begin);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int *numbers = new int[n];
  int sum = 0;
  int *result = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> numbers[i];
    sum += numbers[i];
  }
  MergeSort(numbers, numbers + n, result);
  int pos_sum = 0;
  int neg_sum = 0;
  for (int i = 0; i < k; i++) {
    if (numbers[i] < 0) {
      neg_sum += numbers[i];
    }
    if (numbers[n - i - 1] > 0) {
      pos_sum += numbers[n - i - 1];
    }
  }
  std::cout << std::max(abs(sum - 2 * pos_sum), abs(sum - 2 * neg_sum));
  delete[] numbers;
  delete[] result;
}

//Последовательность 
#include <iostream>

int64_t FindSymbol(int64_t k) {
  int64_t length = 1;
  while (length <= k) {
    length *= 2;
  }
  int64_t result = 0;
  while (length > 1) {
    length /= 2;
    if (k >= length) {
      k -= length;
      result = (result + 1) % 3;
    }
  }
  return result;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t k = 0;
  std::cin >> k;
  std::cout << FindSymbol(k - 1) << "\n";
  return 0;
}

//Сжать чтобы что?
#include <iostream>

char* IntToStr(int num, int& len) {
  char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  if (num == 0) {
    char* res = new char[2];
    res[0] = digits[0];
    res[1] = '\0';
    len = 1;
    return res;
  }
  int temp = num;
  len = 0;
  while (temp > 0) {
    temp /= 10;
    len++;
  }
  char* res = new char[len + 1];
  res[len] = '\0';
  temp = num;
  for (int i = len - 1; i >= 0; i--) {
    res[i] = digits[temp % 10];
    temp /= 10;
  }
  return res;
}
char* CompressString(char str[], int n, int& compressed_length) {
  char* compressed = new char[2 * n + 1];
  int index = 0;
  int i = 0;
  while (i < n) {
    char current_char = str[i];
    int count = 1;
    while ((i + 1 < n) && (str[i + 1] == current_char)) {
      count++;
      i++;
    }
    compressed[index++] = current_char;
    int len = 0;
    char* count_str = IntToStr(count, len);
    for (int j = 0; j < len; j++) {
      compressed[index++] = count_str[j];
    }
    delete[] count_str;
    i++;
  }
  compressed[index] = '\0';
  compressed_length = index;
  return compressed;
}
int StrToInt(char str[], int start, int end) {
  int num = 0;
  for (int i = start; i < end; i++) {
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int digit = 0;
    while (digit < 10 && str[i] != digits[digit]) {
      digit++;
    }
    num = num * 10 + digit;
  }
  return num;
}
char* DecompressString(char str[], int n, int& decompressed_length) {
  char* decompressed = new char[1000001];
  decompressed_length = 0;
  int i = 0;
  while (i < n) {
    char current_char = str[i];
    i++;
    int start = i;
    while (i < n && str[i] >= '0' && str[i] <= '9') {
      i++;
    }
    int end = i;
    int count = StrToInt(str, start, end);
    for (int j = 0; j < count; j++) {
      if (decompressed_length < 1000000) {
        decompressed[decompressed_length++] = current_char;
      }
    }
  }
  decompressed[decompressed_length] = '\0';
  return decompressed;
}
int main(void) {
  int max_n = 1000000;
  char* str = new char[max_n + 1]{0};
  std::cin.getline(str, max_n);
  int n = 0;
  while (str[n] != '\0') {
    n++;
  }
  int compressed_length = 0;
  char* compressed = CompressString(str, n, compressed_length);
  compressed[compressed_length] = '\0';
  std::cout << compressed << "\n";
  int decompressed_length = 0;
  char* decompressed = DecompressString(compressed, compressed_length, decompressed_length);
  decompressed[decompressed_length] = '\0';
  std::cout << decompressed;
  delete[] str;
  delete[] compressed;
  delete[] decompressed;
  return 0;
}

//Проверка анаграмм
#include <iostream>

bool AreAnagrams(const char* s1, const char* s2) {
  int freq[26] = {0};
  for (int i = 0; s1[i] != '\0'; ++i) {
    freq[s1[i] - 'a']++;
  }
  for (int i = 0; s2[i] != '\0'; ++i) {
    freq[s2[i] - 'a']--;
  }
  for (int i = 0; i < 26; ++i) {
    if (freq[i] != 0) {
      return false;
    }
  }
  return true;
}
int main() {
  char s1[1000001];
  char s2[1000001];
  std::cin >> s1 >> s2;
  bool is_anagram = AreAnagrams(s1, s2);
  if (is_anagram) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}
