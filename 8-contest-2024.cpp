//Простой стек
#include <cstring>
#include <iostream>

struct Node {
  int val;
  Node *next = nullptr;
};

struct Stack {
  Node *head = nullptr;
  size_t size = 0;

  bool IsEmpty() {
    return head == nullptr;
  }

  void Push(int value) {
    Node *new_node = new Node{value};
    new_node->val = value;
    new_node->next = head;
    head = new_node;
    size++;
  }

  void Pop() {
    if (IsEmpty()) {
      return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
    size--;
  }

  void Back() {
    std::cout << head->val << '\n';
  }

  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }
};

int main() {
  char command[6];
  Stack stack;
  while (true) {
    std::cin >> command;
    if (!strcmp(command, "push")) {
      int n = 0;
      std::cin >> n;
      stack.Push(n);
      std::cout << "ok\n";
    } else if (!strcmp(command, "pop")) {
      stack.Back();
      stack.Pop();
    } else if (!strcmp(command, "back")) {
      stack.Back();
    } else if (!strcmp(command, "size")) {
      std::cout << stack.size << '\n';
    } else if (!strcmp(command, "clear")) {
      stack.Clear();
      std::cout << "ok\n";
    } else if (!strcmp(command, "exit")) {
      std::cout << "bye";
      stack.Clear();
      return 0;
    }
  }
}


//Простая очередь
#include <cstring>
#include <iostream>

struct Node {
  int val;
  Node *next = nullptr;
};

struct Queue {
  Node *head = nullptr;
  Node *tail = nullptr;
  size_t size = 0;

  bool IsEmpty() {
    return head == nullptr;
  }

  void Push(int value) {
    Node *new_node = new Node{value};
    if (IsEmpty()) {
      head = new_node;
      tail = new_node;
      size++;
      return;
    }
    tail->next = new_node;
    tail = new_node;
    size++;
  }

  void Pop() {
    if (IsEmpty()) {
      return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
    if (head == nullptr) {
      tail = nullptr;
    }
    size--;
  }

  void Front() {
    std::cout << head->val << '\n';
  }

  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }
};

int main() {
  char command[6];
  Queue queue;
  while (true) {
    std::cin >> command;
    if (!strcmp(command, "push")) {
      int n = 0;
      std::cin >> n;
      queue.Push(n);
      std::cout << "ok\n";
    } else if (!strcmp(command, "pop")) {
      queue.Front();
      queue.Pop();
    } else if (!strcmp(command, "front")) {
      queue.Front();
    } else if (!strcmp(command, "size")) {
      std::cout << queue.size << '\n';
    } else if (!strcmp(command, "clear")) {
      queue.Clear();
      std::cout << "ok\n";
    } else if (!strcmp(command, "exit")) {
      std::cout << "bye";
      queue.Clear();
      return 0;
    }
  }
}


//Удалите скобки
#include <cstring>
#include <iostream>

struct Node {
  char val;
  Node *next = nullptr;
};

struct Stack {
  Node *head = nullptr;
  size_t size = 0;

  bool IsEmpty() {
    return head == nullptr;
  }

  void Push(char value) {
    Node *new_node = new Node{value};
    new_node->val = value;
    new_node->next = head;
    head = new_node;
    size++;
  }

  void Pop() {
    if (IsEmpty()) {
      return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
    size--;
  }

  char Back() {
    if (head == nullptr) {
      return ' ';
    }
    return head->val;
  }

  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }
};

int main() {
  Stack stack;
  char arr[100001];
  std::cin >> arr;
  for (int i = 0; arr[i] != '\0'; i++) {
    if (arr[i] == ')' && stack.Back() == '(') {
      stack.Pop();
    } else {
      stack.Push(arr[i]);
    }
  }
  std::cout << stack.size;
  stack.Clear();
}


//Контейнеры
#include <iostream>

struct Node {
  int value;
  Node* pr;
};

struct Stack {
  Node* up;
};

void InitStack(Stack& stack) {
  stack.up = nullptr;
}

void StackPush(Stack& stack, int a) {
  Node* tmp = new Node();
  tmp->value = a;
  tmp->pr = stack.up;
  stack.up = tmp;
}

int StackPop(Stack& stack) {
  int value = stack.up->value;
  Node* tmp = stack.up;
  stack.up = stack.up->pr;
  delete tmp;
  return value;
}

int StackBack(const Stack& stack) {
  if (stack.up != nullptr) {
    return stack.up->value;
  }
  return 0;
}

bool StackEmpty(const Stack& stack) {
  return stack.up == nullptr;
}

void StackFree(Stack& stack) {
  while (!StackEmpty(stack)) {
    StackPop(stack);
  }
}

int main(void) {
  int n = 0;
  std::cin >> n;
  const int max_size = 501;
  auto cont = new Stack[max_size];
  for (int i = 0; i < max_size; i++) {
    InitStack(cont[i]);
  }
  if (n == 2) {
    bool ok = true;
    bool first = true;
    int k = 0;
    std::cin >> k;
    int tmp = 0;
    int i = 0;
    int j = 0;
    if (k > 0) {
      std::cin >> tmp;
      i = 1;
      while (tmp == 1 && i < k) {
        std::cin >> tmp;
        i++;
      }
      j = (tmp == 2) ? 1 : 0;
      while (i < k) {
        std::cin >> tmp;
        if (tmp == 1) {
          ok = false;
        }
        j++;
        i++;
      }
    }
    std::cin >> k;
    if (k > 0) {
      std::cin >> tmp;
      i = 1;
      while (tmp == 2 && i < k) {
        std::cin >> tmp;
        i++;
      }
      if (j && tmp == 1) {
        ok = false;
      } else if (tmp == 1) {
        first = false;
      }
      if (tmp == 1) {
        j++;
      }
      while (i < k) {
        std::cin >> tmp;
        if (tmp == 2) {
          ok = false;
        }
        j++;
        i++;
      }
    }
    if (ok) {
      if (first) {
        for (int idx = 0; idx < j; ++idx) {
          std::cout << "1 2" << std::endl;
        }
      } else {
        for (int idx = 0; idx < j; ++idx) {
          std::cout << "2 1" << std::endl;
        }
      }
    } else {
      std::cout << "0";
    }
    delete[] cont;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int k = 0;
    std::cin >> k;
    if (k > 0) {
      int tmp = 0;
      std::cin >> tmp;
      int j = 1;
      while (tmp == i && j < k) {
        std::cin >> tmp;
        j++;
      }
      if (tmp != i) {
        StackPush(cont[i], tmp);
      }
      while (j < k) {
        std::cin >> tmp;
        StackPush(cont[i], tmp);
        j++;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    while (!StackEmpty(cont[i])) {
      while (!StackEmpty(cont[i]) && StackEmpty(cont[StackBack(cont[i])])) {
        int popped = StackPop(cont[i]);
        std::cout << i << " " << popped << std::endl;
      }
      while (!StackEmpty(cont[i]) && !StackEmpty(cont[StackBack(cont[i])])) {
        int popped = StackPop(cont[i]);
        std::cout << i << " " << n << std::endl;
        StackPush(cont[n], popped);
      }
    }
    while (!StackEmpty(cont[i])) {
      int popped = StackPop(cont[i]);
      std::cout << i << " " << n << std::endl;
      StackPush(cont[n], popped);
    }
  }
  int save = 1;
  int qsave = 0;
  while (!StackEmpty(cont[n])) {
    int tmp = StackPop(cont[n]);
    if (tmp == n) {
      std::cout << n << " " << save << std::endl;
      qsave++;
    } else if (tmp == save) {
      save = 1 + (save % 2);
      for (int idx = 0; idx < qsave; idx++) {
        std::cout << tmp << " " << save << std::endl;
      }
      std::cout << n << " " << tmp << std::endl;
    } else {
      std::cout << n << " " << tmp << std::endl;
    }
  }
  for (int idx = 0; idx < qsave; idx++) {
    std::cout << save << " " << n << std::endl;
  }
  for (int i = 1; i <= n; i++) {
    StackFree(cont[i]);
  }
  StackFree(cont[n]);
  delete[] cont;
  return 0;
}


//Маджонг
#include <iostream>

struct Tile {
  int row;
  int col;
};

struct Node {
  int color;
  Node* next;
};

struct Context {
  int m;
  int n;
  int total_colors;
  int** board;
  Tile** color_positions;
  int* leftmost_row;
  int* rightmost_row;
  int* topmost_col;
  int* bottommost_col;
  bool* removed_flags;
  bool* in_queue_flags;
  int* answer;
  int max_moves;
};

void Enqueue(Node*& root, Node*& tail, int color) {
  Node* new_node = new Node;
  new_node->color = color;
  new_node->next = nullptr;
  if (tail == nullptr) {
    root = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
}

int Dequeue(Node*& root, Node*& tail) {
  if (root == nullptr) {
    return -1;
  }
  int color = root->color;
  Node* temp = root;
  root = root->next;
  if (root == nullptr) {
    tail = nullptr;
  }
  delete temp;
  return color;
}

bool IsRemovable(int color, Context* ctx) {
  if (ctx->removed_flags[color]) {
    return false;
  }
  Tile t1 = ctx->color_positions[color][0];
  Tile t2 = ctx->color_positions[color][1];
  if (ctx->leftmost_row[t1.row] == t1.col && ctx->leftmost_row[t2.row] == t2.col) {
    return true;
  }
  if (ctx->rightmost_row[t1.row] == t1.col && ctx->rightmost_row[t2.row] == t2.col) {
    return true;
  }
  if (ctx->topmost_col[t1.col] == t1.row && ctx->topmost_col[t2.col] == t2.row) {
    return true;
  }
  if (ctx->bottommost_col[t1.col] == t1.row && ctx->bottommost_col[t2.col] == t2.row) {
    return true;
  }
  return false;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Context ctx;
  ctx.max_moves = 0;
  std::cin >> ctx.m >> ctx.n;
  ctx.total_colors = (ctx.m * ctx.n) / 2;
  ctx.board = new int*[ctx.m];
  for (int i = 0; i < ctx.m; i++) {
    ctx.board[i] = new int[ctx.n];
    for (int j = 0; j < ctx.n; j++) {
      std::cin >> ctx.board[i][j];
    }
  }
  ctx.color_positions = new Tile*[ctx.total_colors + 1];
  for (int i = 1; i <= ctx.total_colors; i++) {
    ctx.color_positions[i] = new Tile[2];
  }
  int* color_count = new int[ctx.total_colors + 1];
  for (int i = 1; i <= ctx.total_colors; i++) {
    color_count[i] = 0;
  }
  for (int i = 0; i < ctx.m; i++) {
    for (int j = 0; j < ctx.n; j++) {
      int color = ctx.board[i][j];
      if (color != 0) {
        ctx.color_positions[color][color_count[color]].row = i;
        ctx.color_positions[color][color_count[color]].col = j;
        color_count[color]++;
      }
    }
  }
  delete[] color_count;
  ctx.leftmost_row = new int[ctx.m];
  ctx.rightmost_row = new int[ctx.m];
  for (int i = 0; i < ctx.m; i++) {
    int lm = -1;
    for (int j = 0; j < ctx.n; j++) {
      if (ctx.board[i][j] != 0) {
        lm = j;
        break;
      }
    }
    ctx.leftmost_row[i] = lm;
    int rm = -1;
    for (int j = ctx.n - 1; j >= 0; j--) {
      if (ctx.board[i][j] != 0) {
        rm = j;
        break;
      }
    }
    ctx.rightmost_row[i] = rm;
  }
  ctx.topmost_col = new int[ctx.n];
  ctx.bottommost_col = new int[ctx.n];
  for (int j = 0; j < ctx.n; j++) {
    int tm = -1;
    for (int i = 0; i < ctx.m; i++) {
      if (ctx.board[i][j] != 0) {
        tm = i;
        break;
      }
    }
    ctx.topmost_col[j] = tm;
    int bm = -1;
    for (int i = ctx.m - 1; i >= 0; i--) {
      if (ctx.board[i][j] != 0) {
        bm = i;
        break;
      }
    }
    ctx.bottommost_col[j] = bm;
  }
  ctx.removed_flags = new bool[ctx.total_colors + 1];
  ctx.in_queue_flags = new bool[ctx.total_colors + 1];
  for (int c = 1; c <= ctx.total_colors; c++) {
    ctx.removed_flags[c] = false;
    ctx.in_queue_flags[c] = false;
  }
  ctx.answer = new int[ctx.total_colors];
  Node* root = nullptr;
  Node* tail = nullptr;
  for (int i = 1; i <= ctx.total_colors; i++) {
    Tile t1 = ctx.color_positions[i][0];
    Tile t2 = ctx.color_positions[i][1];
    bool removable = false;
    if (ctx.leftmost_row[t1.row] == t1.col && ctx.leftmost_row[t2.row] == t2.col) {
      removable = true;
    }
    if (ctx.rightmost_row[t1.row] == t1.col && ctx.rightmost_row[t2.row] == t2.col) {
      removable = true;
    }
    if (ctx.topmost_col[t1.col] == t1.row && ctx.topmost_col[t2.col] == t2.row) {
      removable = true;
    }
    if (ctx.bottommost_col[t1.col] == t1.row && ctx.bottommost_col[t2.col] == t2.row) {
      removable = true;
    }
    if (removable) {
      Enqueue(root, tail, i);
      ctx.in_queue_flags[i] = true;
    }
  }
  while (root != nullptr) {
    int current_color = Dequeue(root, tail);
    ctx.in_queue_flags[current_color] = false;
    if (ctx.removed_flags[current_color]) {
      continue;
    }
    if (IsRemovable(current_color, &ctx)) {
      ctx.removed_flags[current_color] = true;
      ctx.max_moves++;
      ctx.answer[ctx.max_moves - 1] = current_color;
      Tile t1 = ctx.color_positions[current_color][0];
      Tile t2 = ctx.color_positions[current_color][1];
      ctx.board[t1.row][t1.col] = 0;
      ctx.board[t2.row][t2.col] = 0;
      for (int k = 0; k < 2; k++) {
        int row = (k == 0) ? t1.row : t2.row;
        int new_lm = -1;
        for (int j = 0; j < ctx.n; j++) {
          if (ctx.board[row][j] != 0) {
            new_lm = j;
            break;
          }
        }
        if (ctx.leftmost_row[row] != new_lm) {
          ctx.leftmost_row[row] = new_lm;
          if (new_lm != -1) {
            int new_color = ctx.board[row][new_lm];
            if (!ctx.removed_flags[new_color] && !ctx.in_queue_flags[new_color] && IsRemovable(new_color, &ctx)) {
              Enqueue(root, tail, new_color);
              ctx.in_queue_flags[new_color] = true;
            }
          }
        }
        int new_rm = -1;
        for (int j = ctx.n - 1; j >= 0; j--) {
          if (ctx.board[row][j] != 0) {
            new_rm = j;
            break;
          }
        }
        if (ctx.rightmost_row[row] != new_rm) {
          ctx.rightmost_row[row] = new_rm;
          if (new_rm != -1) {
            int new_color = ctx.board[row][new_rm];
            if (!ctx.removed_flags[new_color] && !ctx.in_queue_flags[new_color] && IsRemovable(new_color, &ctx)) {
              Enqueue(root, tail, new_color);
              ctx.in_queue_flags[new_color] = true;
            }
          }
        }
      }
      for (int k = 0; k < 2; k++) {
        int col = (k == 0) ? t1.col : t2.col;
        int new_tm = -1;
        for (int i = 0; i < ctx.m; i++) {
          if (ctx.board[i][col] != 0) {
            new_tm = i;
            break;
          }
        }
        if (ctx.topmost_col[col] != new_tm) {
          ctx.topmost_col[col] = new_tm;
          if (new_tm != -1) {
            int new_color = ctx.board[new_tm][col];
            if (!ctx.removed_flags[new_color] && !ctx.in_queue_flags[new_color] && IsRemovable(new_color, &ctx)) {
              Enqueue(root, tail, new_color);
              ctx.in_queue_flags[new_color] = true;
            }
          }
        }
        int new_bm = -1;
        for (int i = ctx.m - 1; i >= 0; i--) {
          if (ctx.board[i][col] != 0) {
            new_bm = i;
            break;
          }
        }
        if (ctx.bottommost_col[col] != new_bm) {
          ctx.bottommost_col[col] = new_bm;
          if (new_bm != -1) {
            int new_color = ctx.board[new_bm][col];
            if (!ctx.removed_flags[new_color] && !ctx.in_queue_flags[new_color] && IsRemovable(new_color, &ctx)) {
              Enqueue(root, tail, new_color);
              ctx.in_queue_flags[new_color] = true;
            }
          }
        }
      }
    }
  }
  std::cout << ctx.max_moves << "\n";
  for (int i = 0; i < ctx.max_moves; i++) {
    std::cout << ctx.answer[i] << (i < ctx.max_moves - 1 ? ' ' : '\n');
  }
  for (int i = 1; i <= ctx.total_colors; i++) {
    delete[] ctx.color_positions[i];
  }
  delete[] ctx.color_positions;
  for (int i = 0; i < ctx.m; i++) {
    delete[] ctx.board[i];
  }
  delete[] ctx.board;
  delete[] ctx.leftmost_row;
  delete[] ctx.rightmost_row;
  delete[] ctx.topmost_col;
  delete[] ctx.bottommost_col;
  delete[] ctx.removed_flags;
  delete[] ctx.in_queue_flags;
  delete[] ctx.answer;
  Node* current = root;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  return 0;
}


//Гоблины
#include <iostream>

struct Node {
  int value;
  Node* prev;
  Node* next;
};

void AddLeft(Node*& left_root, Node*& left_tail, int& left_size, Node* node) {
  if (!left_root) {
    left_root = left_tail = node;
  } else {
    left_tail->next = node;
    node->prev = left_tail;
    left_tail = node;
  }
  left_size++;
}

void AddRight(Node*& right_root, Node*& right_tail, int& right_size, Node* node) {
  if (!right_root) {
    right_root = right_tail = node;
  } else {
    right_tail->next = node;
    node->prev = right_tail;
    right_tail = node;
  }
  right_size++;
}

void Balance(Node*& left_root, Node*& left_tail, int& left_size, Node*& right_root, Node*& right_tail,
             int& right_size) {
  while (left_size > right_size + 1) {
    Node* temp = left_tail;
    left_tail = left_tail->prev;
    if (left_tail) {
      left_tail->next = nullptr;
    } else {
      left_root = nullptr;
    }
    temp->prev = nullptr;
    temp->next = right_root;
    if (right_root) {
      right_root->prev = temp;
    } else {
      right_tail = temp;
    }
    right_root = temp;
    left_size--;
    right_size++;
  }
  while (right_size > left_size) {
    Node* temp = right_root;
    right_root = right_root->next;
    if (right_root) {
      right_root->prev = nullptr;
    } else {
      right_tail = nullptr;
    }
    temp->next = nullptr;
    temp->prev = left_tail;
    if (left_tail) {
      left_tail->next = temp;
    } else {
      left_root = temp;
    }
    left_tail = temp;
    right_size--;
    left_size++;
  }
}

void ProcessPlus(Node*& left_root, Node*& left_tail, int& left_size, Node*& right_root, Node*& right_tail,
                 int& right_size, int x) {
  Node* node = new Node;
  node->value = x;
  node->prev = nullptr;
  node->next = nullptr;
  AddRight(right_root, right_tail, right_size, node);
  Balance(left_root, left_tail, left_size, right_root, right_tail, right_size);
}

void ProcessStar(Node*& left_root, Node*& left_tail, int& left_size, Node*& right_root, Node*& right_tail,
                 int& right_size, int x) {
  Node* node = new Node;
  node->value = x;
  node->prev = nullptr;
  node->next = nullptr;
  AddLeft(left_root, left_tail, left_size, node);
  Balance(left_root, left_tail, left_size, right_root, right_tail, right_size);
}

void ProcessMinus(Node*& left_root, Node*& left_tail, int& left_size, Node*& right_root, Node*& right_tail,
                  int& right_size) {
  if (left_root) {
    std::cout << left_root->value << '\n';
    Node* temp = left_root;
    left_root = left_root->next;
    if (left_root) {
      left_root->prev = nullptr;
    } else {
      left_tail = nullptr;
    }
    delete temp;
    left_size--;
  } else if (right_root) {
    Node* temp = right_root;
    right_root = right_root->next;
    if (right_root) {
      right_root->prev = nullptr;
    } else {
      right_tail = nullptr;
    }
    std::cout << temp->value << '\n';
    delete temp;
    right_size--;
  }
  Balance(left_root, left_tail, left_size, right_root, right_tail, right_size);
}

void Clean(Node*& root) {
  while (root) {
    Node* temp = root;
    root = root->next;
    delete temp;
  }
}

int main(void) {
  int n = 0;
  std::cin >> n;
  Node* left_root = nullptr;
  Node* left_tail = nullptr;
  Node* right_root = nullptr;
  Node* right_tail = nullptr;
  int left_size = 0;
  int right_size = 0;
  for (int i = 0; i < n; i++) {
    char cmd = 0;
    std::cin >> cmd;
    if (cmd == '+') {
      int x = 0;
      std::cin >> x;
      ProcessPlus(left_root, left_tail, left_size, right_root, right_tail, right_size, x);
    } else if (cmd == '*') {
      int x = 0;
      std::cin >> x;
      ProcessStar(left_root, left_tail, left_size, right_root, right_tail, right_size, x);
    } else if (cmd == '-') {
      ProcessMinus(left_root, left_tail, left_size, right_root, right_tail, right_size);
    }
  }
  Clean(left_root);
  Clean(right_root);
  return 0;
}
