//Обход
#include <iostream>

struct Node {
  int value = 0;
  Node* left;
  Node* right;
};
Node* CreateNode(int value) {
  Node* new_node = new Node();
  new_node->value = value;
  new_node->left = nullptr;
  new_node->right = nullptr;
  return new_node;
}
Node* Insert(Node* root, int value) {
  if (root == nullptr) {
    return CreateNode(value);
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else if (value > root->value) {
    root->right = Insert(root->right, value);
  }
  return root;
}

void InOrderTraversal(Node* root) {
  if (root != nullptr) {
    InOrderTraversal(root->left);
    std::cout << root->value << " ";
    InOrderTraversal(root->right);
  }
}
int main() {
  Node* root = nullptr;
  int num = 0;
  while (std::cin >> num && num != 0) {
    root = Insert(root, num);
  }
  InOrderTraversal(root);
  std::cout << "\n";
  return 0;
}


//Ветки в порядке возрастания
#include <iostream>

struct Tree {
  int value = 0;
  Tree* left_child;
  Tree* right_child;
};

struct Stack {
  Tree** elements;
  int count;
  int capacity;

  void Initialize(int initial_capacity = 100) {
    capacity = initial_capacity;
    elements = new Tree*[capacity];
    count = 0;
  }

  void Push(Tree* node) {
    if (count >= capacity) {
      Push();
    }
    elements[count++] = node;
  }

  Tree* Pop() {
    return (count > 0) ? elements[--count] : nullptr;
  }

  bool IsEmpty() const {
    return count == 0;
  }

  void Clear() {
    delete[] elements;
    elements = nullptr;
    count = 0;
    capacity = 0;
  }

 private:
  void Push() {
    capacity *= 2;
    Tree** new_elements = new Tree*[capacity];
    for (int i = 0; i < count; i++) {
      new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
  }
};

Tree* AddToTree(Tree* root, int value) {
  Tree* new_node = new Tree{value, nullptr, nullptr};
  if (root == nullptr) {
    return new_node;
  }
  Tree* current = root;
  Tree* parent = nullptr;
  while (current != nullptr) {
    parent = current;
    if (value < current->value) {
      current = current->left_child;
    } else if (value > current->value) {
      current = current->right_child;
    } else {
      delete new_node;
      return root;
    }
  }
  if (value < parent->value) {
    parent->left_child = new_node;
  } else {
    parent->right_child = new_node;
  }
  return root;
}
void Print(Tree* root) {
  if (root == nullptr) {
    return;
  }
  Stack traversal_stack;
  traversal_stack.Initialize();
  Tree* current = root;
  bool first_leaf = true;
  while (current != nullptr || !traversal_stack.IsEmpty()) {
    while (current != nullptr) {
      traversal_stack.Push(current);
      current = current->left_child;
    }
    current = traversal_stack.Pop();
    if (current != nullptr) {
      if (current->left_child == nullptr && current->right_child == nullptr) {
        if (first_leaf) {
          std::cout << current->value;
          first_leaf = false;
        } else {
          std::cout << ' ' << current->value;
        }
      }
      current = current->right_child;
    }
  }
  traversal_stack.Clear();
  std::cout << '\n';
}
void ClearTree(Tree* root) {
  if (root == nullptr) {
    return;
  }
  Stack cleanup_stack;
  cleanup_stack.Initialize();
  cleanup_stack.Push(root);
  while (!cleanup_stack.IsEmpty()) {
    Tree* node = cleanup_stack.Pop();
    if (node->left_child != nullptr) {
      cleanup_stack.Push(node->left_child);
    }
    if (node->right_child != nullptr) {
      cleanup_stack.Push(node->right_child);
    }
    delete node;
  }
  cleanup_stack.Clear();
}
int main() {
  Tree* tree_root = nullptr;
  int input_value = 0;

  while (std::cin >> input_value && input_value != 0) {
    tree_root = AddToTree(tree_root, input_value);
  }
  Print(tree_root);
  ClearTree(tree_root);
  return 0;
}


//Ветки количество вершин
#include <iostream>

struct Node {
  int value = 0;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* Insert(Node* root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else if (value > root->value) {
    root->right = Insert(root->right, value);
  }
  return root;
}

int GetHeight(Node* root) {
  if (root == nullptr) return 0;
  int left_height = GetHeight(root->left);
  int right_height = GetHeight(root->right);
  return std::max(left_height, right_height) + 1;
}

int main() {
  Node* root = nullptr;
  int value = 0;
  while (std::cin >> value && value != 0) {
    root = Insert(root, value);
  }
  std::cout << GetHeight(root) << "\n";
  return 0;
}



//Сбалансировано?
#include <iostream>

struct TreeNode {
  int value = 0;
  TreeNode* left;
  TreeNode* right;

  explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {
  }
};

TreeNode* Insert(TreeNode* root, int value) {
  if (!root) {
    return new TreeNode(value);
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else if (value > root->value) {
    root->right = Insert(root->right, value);
  }
  return root;
}

int CheckHeight(TreeNode* root, bool& is_balanced) {
  if (!root) {
    return 0;
  }
  int left_height = CheckHeight(root->left, is_balanced);
  int right_height = CheckHeight(root->right, is_balanced);
  if (std::abs(left_height - right_height) > 1) {
    is_balanced = false;
  }
  return 1 + std::max(left_height, right_height);
}

void FreeTree(TreeNode* root) {
  if (!root) {
    return;
  }
  FreeTree(root->left);
  FreeTree(root->right);
  delete root;
}

int main() {
  TreeNode* root = nullptr;
  int value = 0;
  while (std::cin >> value && value != 0) {
    root = Insert(root, value);
  }
  bool is_balanced = true;
  CheckHeight(root, is_balanced);
  std::cout << (is_balanced ? "YES" : "NO") << "\n";
  FreeTree(root);
  return 0;
}



//Второй максимум
#include <iostream>

class Node {
 public:
  int value = 0;
  Node* left;
  Node* right;
  explicit Node(int val) : value(val), left(nullptr), right(nullptr) {
  }
};

class BinaryTree {
 private:
  Node* root_;

  Node* Insert(Node* node, int value) {
    if (!node) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = Insert(node->left, value);
    } else if (value > node->value) {
      node->right = Insert(node->right, value);
    }
    return node;
  }

  void DeleteTree(Node* node) {
    if (!node) {
      return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
  }

  int FindSecondLargest(Node* node) {
    Node* parent = nullptr;
    while (node->right) {
      parent = node;
      node = node->right;
    }
    if (node->left) {
      node = node->left;
      while (node->right) {
        node = node->right;
      }
      return node->value;
    }
    return parent ? parent->value : -1;
  }

 public:
  BinaryTree() : root_(nullptr) {
  }
  ~BinaryTree() {
    DeleteTree(root_);
  }
  void Insert(int value) {
    root_ = Insert(root_, value);
  }
  bool CanFindSecondLargest() const {
    return root_ && (root_->left || root_->right);
  }
  int GetSecondLargest() {
    return FindSecondLargest(root_);
  }
};

int main() {
  BinaryTree tree;
  int num = 0;
  while (std::cin >> num && num != 0) {
    tree.Insert(num);
  }
  if (tree.CanFindSecondLargest()) {
    std::cout << tree.GetSecondLargest() << "\n";
  } else {
    ;
  }
  return 0;
}



//Traversal BST
#include <iostream>

class Node {
 public:
  int value = 0;
  Node* left;
  Node* right;
  Node* parent;

  explicit Node(int val, Node* par = nullptr) : value(val), left(nullptr), right(nullptr), parent(par) {
  }
};

class BinaryTree {
 private:
  Node* root_;

  Node* Insert(Node* node, int value) {
    if (!node) {
      return new Node(value);
    }
    if (value < node->value) {
      if (!node->left) {
        node->left = new Node(value, node);
      } else {
        Insert(node->left, value);
      }
    } else if (value > node->value) {
      if (!node->right) {
        node->right = new Node(value, node);
      } else {
        Insert(node->right, value);
      }
    }
    return node;
  }

  Node* FindMin(Node* node) {
    while (node && node->left) {
      node = node->left;
    }
    return node;
  }

  Node* NextInOrder(Node* node) {
    if (!node) {
      return nullptr;
    }
    if (node->right) {
      return FindMin(node->right);
    }
    while (node->parent && node == node->parent->right) {
      node = node->parent;
    }
    return node->parent;
  }

  void DeleteTree(Node* node) {
    if (!node) {
      return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
  }

 public:
  BinaryTree() : root_(nullptr) {
  }

  ~BinaryTree() {
    DeleteTree(root_);
  }

  void Insert(int value) {
    if (!root_) {
      root_ = new Node(value);
    } else {
      Insert(root_, value);
    }
  }

  void InOrderTraversal() {
    Node* current = FindMin(root_);
    while (current) {
      std::cout << current->value << " ";
      current = NextInOrder(current);
    }
    std::cout << "\n";
  }
};

int main() {
  BinaryTree tree;
  int num = 0;
  while (std::cin >> num && num != 0) {
    tree.Insert(num);
  }
  tree.InOrderTraversal();
  return 0;
}



//Postorder BST
#include <iostream>

class Node {
 public:
  int value = 0;
  Node* left;
  Node* right;
  explicit Node(int val) : value(val), left(nullptr), right(nullptr) {
  }
};

class Stack {
 private:
  Node** data_;
  int capacity_;
  int top_;
  void Resize() {
    int new_capacity = capacity_ * 2;
    Node** new_data = new Node*[new_capacity];
    for (int i = 0; i <= top_; i++) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  explicit Stack(int initial_capacity = 100) : capacity_(initial_capacity), top_(-1) {
    data_ = new Node*[capacity_];
  }

  ~Stack() {
    delete[] data_;
  }

  void Push(Node* node) {
    if (top_ + 1 >= capacity_) {
      Resize();
    }
    data_[++top_] = node;
  }

  Node* Pop() {
    if (top_ == -1) {
      return nullptr;
    }
    return data_[top_--];
  }

  Node* TopNode() const {
    if (top_ == -1) {
      return nullptr;
    }
    return data_[top_];
  }

  bool IsEmpty() const {
    return top_ == -1;
  }
};

class BinaryTree {
 private:
  Node* root_;
  void DeleteTree(Node* node) {
    if (!node) {
      return;
    }
    Stack stack;
    stack.Push(node);
    while (!stack.IsEmpty()) {
      Node* current = stack.Pop();
      if (current->left) {
        stack.Push(current->left);
      }
      if (current->right) {
        stack.Push(current->right);
      }
      delete current;
    }
  }

 public:
  BinaryTree() : root_(nullptr) {
  }

  ~BinaryTree() {
    DeleteTree(root_);
  }

  Node* BuildTree(int* postorder, int n) {
    if (n == 0) {
      return nullptr;
    }

    Stack stack;
    root_ = new Node(postorder[n - 1]);
    stack.Push(root_);

    for (int i = n - 2; i >= 0; i--) {
      Node* node = new Node(postorder[i]);
      Node* temp = nullptr;

      while (!stack.IsEmpty() && postorder[i] < stack.TopNode()->value) {
        temp = stack.Pop();
      }

      if (temp) {
        temp->left = node;
      } else if (!stack.IsEmpty()) {
        stack.TopNode()->right = node;
      }

      stack.Push(node);
    }
    return root_;
  }

  void InorderTraversal() {
    Node* current = root_;
    Stack stack;

    while (!stack.IsEmpty() || current != nullptr) {
      if (current != nullptr) {
        stack.Push(current);
        current = current->left;
      } else {
        current = stack.Pop();
        if (current->left == nullptr && current->right == nullptr) {
          std::cout << current->value << " ";
        }
        current = current->right;
      }
    }
    std::cout << "\n";
  }
};

int main() {
  int n = 0;
  int num = 0;
  int* postorder = new int[100];
  int capacity = 100;
  while (std::cin >> num && num != 0) {
    if (n >= capacity) {
      capacity *= 2;
      int* new_postorder = new int[capacity];
      for (int i = 0; i < n; i++) {
        new_postorder[i] = postorder[i];
      }
      delete[] postorder;
      postorder = new_postorder;
    }
    postorder[n++] = num;
  }
  BinaryTree tree;
  tree.BuildTree(postorder, n);
  tree.InorderTraversal();
  delete[] postorder;
  return 0;
}



//Следующий
#include <iostream>

struct Node {
  int64_t value = 0;
  Node* left;
  Node* right;

  Node(int64_t val) : value(val), left(nullptr), right(nullptr) {}
};

Node* Insert(Node* root, int64_t val) {
  if (root == nullptr) {
    return new Node(val);
  }
  if (val < root->value) {
    root->left = Insert(root->left, val);
  } else if (val > root->value) {
    root->right = Insert(root->right, val);
  }
  return root;
}

int64_t FindNext(Node* root, int64_t i) {
  int64_t result = -1;
  while (root) {
    if (root->value >= i) {
      result = root->value;
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return result;
}

int main() {
  int n = 0;
  std::cin >> n;

  Node* root = nullptr;
  int64_t last_result = -1;

  while (n--) {
    char op = '0';
    int64_t i = 0;
    std::cin >> op >> i;

    if (op == '+') {
      if (last_result != -1) {
        i = (i + last_result) % 1000000000;
      }
      root = Insert(root, i);
      last_result = -1;
    } else if (op == '?') {
      last_result = FindNext(root, i);
      std::cout << last_result << "\n";
    }
  }
  return 0;
}



//К-ый максимум
#include <iostream>

class List {
 private:
  int* elements_;
  int size_ = 0;
  int capacity_ = 0;

  void Resize() {
    capacity_ *= 2;
    int* new_elements = new int[capacity_];
    for (int i = 0; i < size_; ++i) {
      new_elements[i] = elements_[i];
    }
    delete[] elements_;
    elements_ = new_elements;
  }

  int BSearch(int value) const {
    int left = 0;
    int right = size_ - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (elements_[mid] == value) {
        return mid;
      }
      if (elements_[mid] < value) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

 public:
  explicit List(int initial_capacity = 100) : size_(0), capacity_(initial_capacity) {
    elements_ = new int[capacity_];
  }

  ~List() {
    delete[] elements_;
  }

  void Insert(int value) {
    if (size_ == capacity_) {
      Resize();
    }
    int pos = BSearch(value);
    if (pos < size_ && elements_[pos] == value) {
      return;
    }
    for (int i = size_; i > pos; --i) {
      elements_[i] = elements_[i - 1];
    }
    elements_[pos] = value;
    ++size_;
  }

  void Remove(int value) {
    int pos = BSearch(value);
    if (pos >= size_ || elements_[pos] != value) {
      return;
    }
    for (int i = pos; i < size_ - 1; ++i) {
      elements_[i] = elements_[i + 1];
    }
    --size_;
  }

  int Request(int k) const {
    if (k <= 0 || k > size_) {
      return -1;
    }
    return elements_[k - 1];
  }
};

int main() {
  List list;
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int command = 0;
    int value = 0;
    std::cin >> command >> value;
    if (command == 1) {
      list.Insert(value);
    } else if (command == -1) {
      list.Remove(value);
    } else if (command == 0) {
      std::cout << list.Request(value) << '\n';
    }
  }
  return 0;
}
