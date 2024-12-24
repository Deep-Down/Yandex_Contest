//Декартово дерево. Построение. Быстрое постоение.
#include <iostream>

struct Node {
  int key = 0;
  int priority = 0;
  int left = 0;
  int right = 0;
};

void Init(Node *&nodes, int &node_count, int &root, int size);
void Destroy(Node *&nodes);
int Create(Node *nodes, int &node_count, int key, int priority);
void Split(Node *nodes, int current, int key, int &left, int &right);
int Merge(Node *nodes, int left, int right);
int Insert(Node *nodes, int &root, int node);
void Preorder(Node *nodes, int idx);
void ReadNodes(Node *nodes, int &root, int &node_count, int n);
void PrintPreorder(Node *nodes, int root);

int main() {
  int n = 0;
  std::cin >> n;

  Node *nodes = nullptr;
  int node_count = 0;
  int root = -1;

  Init(nodes, node_count, root, n);
  ReadNodes(nodes, root, node_count, n);
  PrintPreorder(nodes, root);
  Destroy(nodes);

  return 0;
}

void Init(Node *&nodes, int &node_count, int &root, int size) {
  nodes = new Node[size];
  node_count = 0;
  root = -1;
}

void Destroy(Node *&nodes) {
  delete[] nodes;
  nodes = nullptr;
}

int Create(Node *nodes, int &node_count, int key, int priority) {
  nodes[node_count].key = key;
  nodes[node_count].priority = priority;
  nodes[node_count].left = -1;
  nodes[node_count].right = -1;
  return node_count++;
}

void Split(Node *nodes, int current, int key, int &left, int &right) {
  if (current == -1) {
    left = -1;
    right = -1;
    return;
  }
  if (nodes[current].key < key) {
    Split(nodes, nodes[current].right, key, nodes[current].right, right);
    left = current;
  } else {
    Split(nodes, nodes[current].left, key, left, nodes[current].left);
    right = current;
  }
}

int Merge(Node *nodes, int left, int right) {
  if (left == -1 || right == -1) {
    return left == -1 ? right : left;
  }
  if (nodes[left].priority < nodes[right].priority) {
    nodes[left].right = Merge(nodes, nodes[left].right, right);
    return left;
  }
  nodes[right].left = Merge(nodes, left, nodes[right].left);
  return right;
}

int Insert(Node *nodes, int &root, int node) {
  if (root == -1) {
    return node;
  }
  if (nodes[node].priority < nodes[root].priority) {
    Split(nodes, root, nodes[node].key, nodes[node].left, nodes[node].right);
    return node;
  }
  if (nodes[node].key < nodes[root].key) {
    nodes[root].left = Insert(nodes, nodes[root].left, node);
  } else {
    nodes[root].right = Insert(nodes, nodes[root].right, node);
  }
  return root;
}

void Preorder(Node *nodes, int idx) {
  if (idx == -1) {
    return;
  }
  std::cout << nodes[idx].key << '\n';
  Preorder(nodes, nodes[idx].left);
  Preorder(nodes, nodes[idx].right);
}

void ReadNodes(Node *nodes, int &root, int &node_count, int n) {
  for (int i = 0; i < n; i++) {
    int key = 0;
    int priority = 0;
    std::cin >> key >> priority;
    int node = Create(nodes, node_count, key, priority);
    root = Insert(nodes, root, node);
  }
}
void PrintPreorder(Node *nodes, int root) {
  Preorder(nodes, root);
}




//Следующий (treap)
#include <iostream>

struct CustomSet {
  static const int kMaxSize = 300000;
  int64_t data[kMaxSize];
  int size = 0;
  void Add(int64_t x) {
    int left = 0;
    int right = size;
    while (left < right) {
      int mid = (left + right) / 2;
      if (data[mid] < x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left < size && data[left] == x) {
      return;
    }

    for (int i = size; i > left; --i) {
      data[i] = data[i - 1];
    }
    data[left] = x;
    ++size;
  }

  int64_t Next(int64_t i) {
    int left = 0;
    int right = size;
    while (left < right) {
      int mid = (left + right) / 2;
      if (data[mid] < i) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left == size) {
      return -1;
    }
    return data[left];
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 0;
  std::cin >> n;

  CustomSet s;
  char op = '0';
  int64_t x = 0;
  while (n--) {
    std::cin >> op >> x;
    if (op == '+') {
      s.Add(x);
    } else if (op == '?') {
      std::cout << s.Next(x) << "\n";
    }
  }
  return 0;
}



//К-ый элемент дерева
#include <iostream>

struct CustomSet {
  static const int kMaxSize = 300000;
  int64_t data[kMaxSize];
  int size = 0;

  void Add(int64_t x) {
    int left = 0;
    int right = size;
    while (left < right) {
      int mid = (left + right) / 2;
      if (data[mid] < x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left < size && data[left] == x) {
      return;
    }
    for (int i = size; i > left; --i) {
      data[i] = data[i - 1];
    }
    data[left] = x;
    ++size;
  }

  int64_t Order(int64_t k) {
    if (k >= size || k < 0) {
      return -1;
    }
    return data[k];
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  std::cin >> n;
  CustomSet s;
  char op = '0';
  int64_t x = 0;
  while (n--) {
    std::cin >> op >> x;
    if (op == '+') {
      s.Add(x);
    } else if (op == '?') {
      std::cout << s.Order(x) << "\n";
    }
  }
  return 0;
}



//(Не) Массив
#include <iostream>

class Treap {
 private:
  struct Node {
    int value;
    unsigned int priority;
    int left;
    int right;
    int size;
  };
  Node* nodes_;
  int node_count_;
  int root_;
  int max_size_;
  unsigned int seed_;
  unsigned int GeneratePriority() {
    seed_ = seed_ * 1103515245 + 12345;
    return seed_ & 0x7fffffff;
  }
  void UpdateSize(int idx) {
    if (idx == -1) {
      return;
    }
    int left_size = (nodes_[idx].left != -1) ? nodes_[nodes_[idx].left].size : 0;
    int right_size = (nodes_[idx].right != -1) ? nodes_[nodes_[idx].right].size : 0;
    nodes_[idx].size = left_size + right_size + 1;
  }
  void Split(int current, int key, int& left, int& right, int add = 0) {
    if (current == -1) {
      left = -1;
      right = -1;
      return;
    }
    int cur_key = add + ((nodes_[current].left != -1) ? nodes_[nodes_[current].left].size : 0);
    if (key <= cur_key) {
      Split(nodes_[current].left, key, left, nodes_[current].left, add);
      right = current;
    } else {
      Split(nodes_[current].right, key, nodes_[current].right, right, cur_key + 1);
      left = current;
    }
    UpdateSize(current);
  }
  int Merge(int left, int right) {
    if (left == -1 || right == -1) {
      return (left != -1) ? left : right;
    }
    if (nodes_[left].priority > nodes_[right].priority) {
      nodes_[left].right = Merge(nodes_[left].right, right);
      UpdateSize(left);
      return left;
    }
    nodes_[right].left = Merge(left, nodes_[right].left);
    UpdateSize(right);
    return right;
  }
  int BuildTreap(int* arr, int n) {
    int root = -1;
    for (int i = 0; i < n; i++) {
      int node = CreateNode(arr[i]);
      root = Merge(root, node);
    }
    return root;
  }
  int CreateNode(int value) {
    nodes_[node_count_].value = value;
    nodes_[node_count_].priority = GeneratePriority();
    nodes_[node_count_].left = -1;
    nodes_[node_count_].right = -1;
    nodes_[node_count_].size = 1;
    return node_count_++;
  }
  int GetKth(int current, int k) {
    if (current == -1) {
      return -1;
    }
    int left_size = (nodes_[current].left != -1) ? nodes_[nodes_[current].left].size : 0;
    if (k < left_size) {
      return GetKth(nodes_[current].left, k);
    }
    if (k == left_size) {
      return nodes_[current].value;
    }
    return GetKth(nodes_[current].right, k - left_size - 1);
  }

 public:
  explicit Treap(int max_nodes) {
    max_size_ = max_nodes * 4;
    nodes_ = new Node[max_size_];
    node_count_ = 0;
    root_ = -1;
    seed_ = 123456789;
  }
  ~Treap(void) {
    delete[] nodes_;
  }
  void Build(int* arr, int n) {
    root_ = BuildTreap(arr, n);
  }
  int Get(int index) {
    return GetKth(root_, index);
  }
  void ToBegin(int l, int r) {
    int left = -1;
    int middle = -1;
    int right = -1;
    Split(root_, l, left, right);
    Split(right, r - l, middle, right);
    root_ = Merge(middle, left);
    root_ = Merge(root_, right);
  }
};

int main(void) {
  int n = 0;
  std::cin >> n;
  Treap treap(n);
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  treap.Build(arr, n);
  delete[] arr;
  int k = 0;
  std::cin >> k;
  for (int i = 0; i < k; i++) {
    char op = ' ';
    std::cin >> op;
    if (op == '?') {
      int idx = 0;
      std::cin >> idx;
      int ans = treap.Get(idx);
      std::cout << ans << '\n';
    } else if (op == 'b') {
      int l = 0;
      int r = 0;
      std::cin >> l >> r;
      treap.ToBegin(l, r);
    }
  }
  return 0;
}
