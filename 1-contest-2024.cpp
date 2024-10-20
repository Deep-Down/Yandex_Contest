//Hello, World!
#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

//Гипотенуза
#include <cmath>
#include <iostream>

int main() {
  double a = 0;
  double b = 0;
  double answer = NAN;
  std::cin >> a >> b;
  answer = sqrt(a * a + b * b);
  std::cout << answer << std::endl;
  return 0;
}

//Следующее и предыдущее
#include <iostream>

int main() {
  int num = 0;
  std::cin >> num;
  std::cout << "The next number for the number " << num << " is " << num + 1 << "." << std::endl;
  std::cout << "The previous number for the number " << num << " is " << num - 1 << "." << std::endl;
  return 0;
}

//МКАД
#include <iostream>

int main() {
  int v = 0;
  int t = 0;
  int answer = 0;
  std::cin >> v >> t;
  answer = v * t % 109;
  std::cout << (answer + 109) % 109;
  return 0;
}

//Сумма цифр
#include <iostream>

int main() {
  int a = 0;
  std::cin >> a;
  int decades = a % 10;
  int hundreds = a % 100;
  std::cout << decades + (hundreds - decades) / 10 + (a - hundreds) / 100;
  return 0;
}

//Следующее четное
#include <iostream>

int main() {
  int a = 0;
  std::cin >> a;
  std::cout << a + 2 - a % 2;
  return 0;
}

//Электронные часы
#include <iostream>

int main() {
  int a = 0;
  std::cin >> a;
  int sec = (a % 3600) % 60;
  int min = (a % 3600 - sec) / 60;
  int hours = (a / 3600) % 24;
  int decade_sec = sec / 10;
  int decade_min = min / 10;
  int answer_min = min - decade_min * 10;
  int answer_sec = sec - decade_sec * 10;
  std::cout << hours << ":" << decade_min << answer_min << ":" << decade_sec << answer_sec;
  return 0;
}

//Разность времен
#include <iostream>

int main() {
  int hours1 = 0;
  int minutes1 = 0;
  int seconds1 = 0;
  int hours2 = 0;
  int minutes2 = 0;
  int seconds2 = 0;
  std::cin >> hours1 >> minutes1 >> seconds1 >> hours2 >> minutes2 >> seconds2;
  std::cout << (hours2 * 3600 + minutes2 * 60 + seconds2) - (hours1 * 3600 + minutes1 * 60 + seconds1);
  return 0;
}

//Улитка
#include <iostream>

int main(void) {
  int h = 0;
  int a = 0;
  int b = 0;
  std::cin >> h >> a >> b;
  int count = (h - b - 1) / (a - b) + 1;
  std::cout << count;
  return 0;
}

//Проверьте делимость
#include <iostream>

int main() {
  int n = 0;
  int m = 0;
  int multiplication = 0;
  int division_try1 = 0;
  int division_try2 = 0;
  std::cin >> n >> m;
  division_try1 = n % m;
  division_try2 = m % n;
  multiplication = division_try1 * division_try2;
  std::cout << multiplication + 1;
  return 0;
}

//Максимум из двух чисел
#include <iostream>

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  int diff = a - b;
  int summ = a + b;
  int max = (2 * diff + 1);
  std::cout << (summ + (diff * (max % 2))) / 2;
  return 0;
}

//Четное число
#include <iostream>

int main() {
  int a = 0;
  std::cin >> a;
  int b = a % 2;
  if (b == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
    return 0;
  }
}

//Вискосный год
#include <iostream>

int main() {
  unsigned int a = 0;
  std::cin >> a;
  if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
    return 0;
  }
}
