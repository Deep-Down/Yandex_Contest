//Быстрая сортировка
#include <iostream>

void Swap(int &lhs, int &rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}
int PartitionHoare(int *arr, int low, int high);
void QuickSortHoare(int *arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pi = PartitionHoare(arr, low, high);
  QuickSortHoare(arr, low, pi);
  QuickSortHoare(arr, pi + 1, high);
}
int PartitionHoare(int *arr, int low, int high) {
  int pivot = arr[(low + high) / 2];
  int i = low;
  int j = high;
  while (true) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i >= j) {
      return j;
    }
    Swap(arr[i++], arr[j--]);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSortHoare(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

//Абитуренты
#include <iostream>

void IterativeQuickSort(auto* array, int64_t size) {
  int64_t new_size = 2 * size;
  auto* low_high_stack = new int64_t[new_size];
  int64_t top = 0;
  low_high_stack[top++] = 0;
  low_high_stack[top++] = size - 1;
  while (top > 0) {
    int64_t high = low_high_stack[--top];
    int64_t low = low_high_stack[--top];
    int64_t pivot = array[high];
    int64_t left = low;
    int64_t right = high - 1;
    while (left <= right) {
      if (array[left] <= pivot) {
        ++left;
      } else {
        std::swap(array[left], array[right]);
        --right;
      }
    }
    std::swap(array[left], array[high]);
    if (low < left - 1) {
      low_high_stack[top++] = low;
      low_high_stack[top++] = left - 1;
    }
    if (left + 1 < high) {
      low_high_stack[top++] = left + 1;
      low_high_stack[top++] = high;
    }
  }
  delete[] low_high_stack;
}
int64_t FindOptimalGap(auto* data, int64_t length, int64_t min_groups, int64_t group_size) {
  int64_t left_bound = 0;
  int64_t right_bound = data[length - 1] - data[0];
  int64_t optimal_gap = right_bound;
  while (left_bound <= right_bound) {
    int64_t mid_gap = left_bound + (right_bound - left_bound) / 2;
    int64_t current_count = 0;
    for (int64_t i = 0; i + group_size <= length;) {
      if (data[i + group_size - 1] - data[i] <= mid_gap) {
        ++current_count;
        i += group_size;
      } else {
        ++i;
      }
      if (current_count >= min_groups) {
        break;
      }
    }
    if (current_count >= min_groups) {
      optimal_gap = mid_gap;
      right_bound = mid_gap - 1;
    } else {
      left_bound = mid_gap + 1;
    }
  
  return optimal_gap;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t num_elements = 0;
  int64_t required_groups = 0;
  int64_t segment_length = 0;
  std::cin >> num_elements >> required_groups >> segment_length;
  auto* sequence = new int64_t[num_elements];
  for (int64_t i = 0; i < num_elements; ++i) {
    std::cin >> sequence[i];
  }
  IterativeQuickSort(sequence, num_elements);
  int64_t result = FindOptimalGap(sequence, num_elements, required_groups, segment_length);
  std::cout << result;
  delete[] sequence;
  return 0;
}

//Закраска прямой
#include <iostream>

void QuickSort(int* start, int* end, int left, int right);
int Partition(int* start, int* end, int left, int right);
int Check(int a, int b);
int main() {
  int interval_count = 0;
  std::cin >> interval_count;
  int* start_points = new int[interval_count];
  int* end_points = new int[interval_count];
  for (int i = 0; i < interval_count; i++) {
    std::cin >> start_points[i] >> end_points[i];
  }
  QuickSort(start_points, end_points, 0, interval_count - 1);
  int painted_length = 0;
  int active_start = start_points[0];
  int active_end = end_points[0];
  for (int i = 1; i < interval_count; i++) {
    if (start_points[i] <= active_end) {
      active_end = Check(active_end, end_points[i]);
    } else {
      painted_length += active_end - active_start;
      active_start = start_points[i];
      active_end = end_points[i];
    }
  }
  painted_length += active_end - active_start;
  std::cout << painted_length << "\n";
  delete[] start_points;
  delete[] end_points;
  return 0;
}
int Check(int a, int b) {
  if (a >= b) {
    return a;
  }
  return b;
}
int Partition(int* start, int* end, int left, int right) {
  int pivot = start[right];
  int i = left;
  for (int j = left; j < right; j++) {
    if (start[j] < pivot || (start[j] == pivot && end[j] < end[right])) {
      if (i != j) {
        start[i] ^= start[j];
        start[j] ^= start[i];
        start[i] ^= start[j];
        end[i] ^= end[j];
        end[j] ^= end[i];
        end[i] ^= end[j];
      }
      i++;
    }
  }
  if (i != right) {
    start[i] ^= start[right];
    start[right] ^= start[i];
    start[i] ^= start[right];
    end[i] ^= end[right];
    end[right] ^= end[i];
    end[i] ^= end[right];
  }
  return i;
}
void QuickSort(int* start, int* end, int left, int right) {
  if (left < right) {
    int pivot_idx = Partition(start, end, left, right);
    QuickSort(start, end, left, pivot_idx - 1);
    QuickSort(start, end, pivot_idx + 1, right);
  }
}

//Трое лучших
#include <iostream>

void Swap(int& lhs, int& rhs) {
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}
int PartitionHoare(int* arr, int low, int high) {
  int pivot = arr[(low + high) / 2];
  int i = low;
  int j = high;
  while (true) {
    while (arr[i] < pivot) {
      i = i + 1;
    }
    while (arr[j] > pivot) {
      j = j - 1;
    }
    if (i >= j) {
      return j;
    }
    Swap(arr[i++], arr[j--]);
  }
}
void QuickSortHoare(int* arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot_id = PartitionHoare(arr, low, high);
  QuickSortHoare(arr, low, pivot_id);
  QuickSortHoare(arr, pivot_id + 1, high);
}
int main() {
  int n = 0;
  int mathematics = 0;
  int physics = 0;
  int informatics = 0;
  std::cin >> n;
  char first_name[1000][1001];
  char last_name[1000][1001];
  int* summ = new int[n];
  int* index_summ = new int[n];
  for (int i = 0; i < n; i = i + 1) {
    std::cin >> last_name[i];
    std::cin >> first_name[i];
    std::cin >> mathematics >> physics >> informatics;
    summ[i] = mathematics + physics + informatics;
  }
  int count = 0;
  int position_summ = 0;
  for (int max_summ = 15; max_summ >= 3; max_summ--) {
    for (int j = 0; j < n; j = j + 1) {
      if (summ[j] == max_summ) {
        index_summ[position_summ] = j;
        position_summ++;
        count++;
      }
    }
    if (count >= 3) {
      break;
    }
  }
  QuickSortHoare(index_summ, 0, position_summ - 1);
  for (int i = 0; i < position_summ; i = i + 1) {
    std::cout << last_name[index_summ[i]] << " " << first_name[index_summ[i]] << "\n";
  }
  delete[] summ;
  delete[] index_summ;
}

//Трубочист
#include <iostream>

template <typename T>
void Copy(const T *src_begin, const T *src_end, T *dest) {
  while (src_begin != src_end) {
    *dest = *src_begin;
    src_begin++;
    dest++;
  }
}
template <typename T>
void Merge(const T *first_begin, const T *first_end, const T *second_begin, const T *second_end, T *result) {
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
template <typename T>
void MergeSort(T *begin, T *end, T *result) {
  size_t size = end - begin;
  if (size <= 1) {
    return;
  }
  MergeSort(begin, begin + size / 2, result);
  MergeSort(begin + size / 2, end, result);
  Merge(begin, begin + size / 2, begin + size / 2, end, result);
  Copy(result, result + size, begin);
}
void Shift(int *arr, int size) {
  int tmp = arr[0];
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      arr[i] = tmp;
      break;
    }
    arr[i] = arr[(i + 1) % size];
  }
}
void Check(int *arr_without_burn, int n, int k, int burn_house, int left, int right, int &min_diff, int *arr_with_burn,
           int *best_arr) {
  for (int i = 0; i < k; i++) {
    arr_with_burn[i] = arr_without_burn[i];
  }
  arr_with_burn[k] = burn_house;
  for (int i = k; i < n - 1; i++) {
    arr_with_burn[i + 1] = arr_without_burn[i];
  }
  if (left == 1) {
    int l = 0;
    int r = k - 1;
    while (l < r) {
      std::swap(arr_with_burn[l], arr_with_burn[r]);
      l++;
      r--;
    }
  }
  if (right == 1) {
    int l = k + 1;
    int r = n - 1;
    while (l < r) {
      std::swap(arr_with_burn[l], arr_with_burn[r]);
      l++;
      r--;
    }
  }
  int diff = 0;
  for (int i = 0; i < n - 1; i++) {
    diff += abs(arr_with_burn[i + 1] - arr_with_burn[i]);
  }
  if (diff < min_diff) {
    min_diff = diff;
    for (int i = 0; i < n; i++) {
      best_arr[i] = arr_with_burn[i];
    }
  }
}
int main() {
  int n = 0;
  int k = 0;
  std::cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int burn_house = 0;
  std::cin >> k;
  k--;
  burn_house = arr[k];
  int *arr_without_burn = new int[n - 1];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (i == k) {
      continue;
    }
    arr_without_burn[j] = arr[i];
    j++;
  }
  int *result = new int[n];
  MergeSort(arr_without_burn, arr_without_burn + n - 1, result);
  int min_diff = 1000000000;
  int *arr_with_burn = new int[n];
  int *best_arr = new int[n];
  for (int i = 0; i < n; i++) {
    best_arr[i] = arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int left = 0; left < 2; left++) {
      for (int right = 0; right < 2; right++) {
        Check(arr_without_burn, n, k, burn_house, left, right, min_diff, arr_with_burn, best_arr);
      }
    }
    Shift(arr_without_burn, n - 1);
  }
  for (int i = 0; i < n; i++) {
    std::cout << best_arr[i] << " ";
  }
  delete[] arr;
  delete[] result;
  delete[] arr_without_burn;
  delete[] arr_with_burn;
  delete[] best_arr;
}

//Быстрый поиск в массиве
#include <iostream>

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int Partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (arr[j] < pivot) {
      i++;
      Swap(arr[i], arr[j]);
    }
  }
  Swap(arr[i + 1], arr[high]);
  return i + 1;
}
void QuickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot_index = Partition(arr, low, high);
    QuickSort(arr, low, pivot_index - 1);
    QuickSort(arr, pivot_index + 1, high);
  }
}
int LowerBound(int arr[], int n, int x) {
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] >= x) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
int UpperBound(int arr[], int n, int x) {
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] > x) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  int n = 0;
  std::cin >> n;
  int arr[100000];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);
  int k = 0;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    int l = 0;
    int r = 0;
    std::cin >> l >> r;
    int left_index = LowerBound(arr, n, l);
    int right_index = UpperBound(arr, n, r);
    int count = right_index - left_index;
    std::cout << count << " ";
  }
  return 0;
}

//Для любителей статистики
#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  if (n <= 0 || n > 70000) {
    return 1;
  }
  int* data = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> data[i];
  }
  int q = 0;
  std::cin >> q;
  if (q <= 0 || q > 70000) {
    delete[] data;
    return 1;
  }
  char* result = new char[q + 1];
  int l = 0;
  int r = 0;
  int x = 0;
  for (int i = 0; i < q; ++i) {
    std::cin >> l >> r >> x;
    if (l < 1) l = 1;
    if (r > n) r = n;
    if (l > r || x <= 0 || x >= 100000) {
      result[i] = '0';
      continue;
    }
    bool found = false;
    for (int j = l - 1; j < r; ++j) {
      if (data[j] == x) {
        found = true;
        break;
      }
    }
    result[i] = found ? '1' : '0';
  }
  result[q] = '\0';
  std::cout << result;
  delete[] data;
  delete[] result;
  return 0;
}
