//Количество делителей
#include <cmath>
#include <iostream>

int main() {
  int number = 0;
  std::cin >> number;
  int counter = 0;
  for (int i = 1; i <= sqrt(number); i = i + 1) {
    if (number % i == 0) {
      counter = counter + 1;
      if (i != number / i) {
        counter = counter + 1;
      }
    }
  }
  std::cout << counter << std::endl;
  return 0;
}

//Простое число
#include <cmath>
#include <iostream>

int main() {
  unsigned int number = 0;
  std::cin >> number;
  int prime = 1;
  if (number <= 1) {
    prime = 0;
  } else if (number <= 3) {
    prime = 1;
  } else if (number % 2 == 0 || number % 3 == 0) {
    prime = 0;
  } else {
    for (unsigned int i = 5; i * i <= number; i += 6) {
      if (number % i == 0 || number % (i + 2) == 0) {
        prime = 0;
        break;
      }
    }
  }
  if (prime) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}

//Разложение на множители
#include <iostream>
#include <cstdint>

int main() {
  uint64_t number = 0;
  std::cin >> number;
  while (number % 2 == 0) {
    std::cout << 2 << " ";
    number /= 2;
  }
  for (uint64_t i = 3; i * i <= number; i += 2) {
    while (number % i == 0) {
      std::cout << i << " ";
      number /= i;
    }
  }
  if (number > 2) {
    std::cout << number;
  }
  return 0;
}

//В двоичную
#include <iostream>

int main() {
  unsigned int n = 0;
  std::cin >> n;
  if (n == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }
  int i = 31;
  while (((n >> i) & 1) == 0) {
    i--;
  }
  for (; i >= 0; --i) {
    std::cout << ((n >> i) & 1);
  }
  std::cout << std::endl;
  return 0;
}

//Почти простое число
#include <iostream>

int main() {
  unsigned int n = 0;
  std::cin >> n;
  if (n < 6) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  for (unsigned int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      unsigned int why_prime = n / i;
      int prime_i = 1;
      for (unsigned int j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
          prime_i = 0;
          break;
        }
      }
      if (prime_i == 0) {
        continue;
      }
      int is_prime = 1;
      for (unsigned int j = 2; j * j <= why_prime; ++j) {
        if (why_prime % j == 0) {
          is_prime = 0;
          break;
        }
      }
      if (prime_i == 1 && is_prime == 1 && i != why_prime) {
        std::cout << "YES" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}

//Загадочное уравнение
#include <iostream>

int main() {
  int number = 0;
  std::cin >> number;
  int64_t target = number + 1;
  int count = 0;
  for (int64_t x1 = 1; x1 * x1 <= target; ++x1) {
    if (target % x1 == 0) {
      int64_t y1 = target / x1;
      if (x1 - 1 >= 0 && y1 - 1 >= 0) {
        ++count;
      }
      if (x1 != y1 && y1 - 1 >= 0) {
        ++count;
      }
    }
  }
  std::cout << count << std::endl;
  return 0;
}

//ЕГЭ
#include <iostream>
int main() {
  int64_t x = 0;
  std::cin >> x;
  int64_t x_copy = x;
  int64_t digits = 0;
  int n = 0;
  if (x == 0) {
    n = 1;
    digits = 0;
  } else {
    while (x_copy != 0) {
      int64_t r = x_copy % (-2);
      x_copy = x_copy / (-2);
      if (r < 0) {
        r += 2;
        x_copy += 1;
      }
      digits = digits * 2 + r;
      n += 1;
    }
  }
  int64_t rev_digit = 0;
  for (int i = 0; i < n; ++i) {
    int64_t bit = digits % 2;
    digits = digits / 2;
    rev_digit = rev_digit * 2 + bit;
  }
  std::cout << n << std::endl;
  int64_t pow = 1;
  for (int j = 1; j < n; ++j) {
    pow *= 2;
  }
  for (int i = 0; i < n; ++i) {
    int64_t bit = rev_digit / pow;
    std::cout << bit << " ";
    rev_digit = rev_digit % pow;
    pow /= 2;
  }
  return 0;
}

//Обычный мальчик
#include <iostream>

int main() {
  int64_t x = 0;
  int64_t y = -1;
  std::cin >> x;
  if (x >= 4536000) {
    std::cout << 45360 * (1 + x / 45360);
  } else {
    int64_t x_copy = 0;
    for (int64_t i = x; i <= x + x / 100; i++) {
      x_copy = i;
      int divs = 1;
      for (int j = 2; j * j <= i; j++) {
        int counter = 0;
        while (x_copy % j == 0) {
          x_copy /= j;
          counter++;
        }
        divs *= (counter + 1);
      }
      if (x_copy > 1) {
        divs *= 2;
      }
      if (divs >= 100) {
        y = i;
        break;
      }
    }
    std::cout << y << std::endl;
  }
}
