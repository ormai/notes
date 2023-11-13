#include <cassert>
#include <cmath>

enum Direction { left = 0, right = 1 };

template <class T> class BinaryTree {
  // Node è di tipo generico
  template <class U> struct Node {
    U info;
    // se si trattasse di un oggetto non si potrebbe fare
    Node *parent = 0, *children[2] = {0, 0};

    Node(const U &_info) : info(_info) {}

    ~Node() {
      delete children[left];
      delete children[right];
    }
  };

protected:
  Node<T> *root = nullptr;

public:
  BinaryTree() = default;

  // qui si legano il tipo dell'albero e dei suoi nodi, T = U
  BinaryTree(const T &a) { root = new Node<T>(a); }

  bool null() { return root == nullptr; }
  bool leaf() { return !null() && child(left).null() && child(right).null(); }

  const T &rootNode() const {
    assert(!null());
    return root->info;
  }

  BinaryTree<T> child(Direction d) const {
    assert(!null());
    BinaryTree<T> tmp;
    tmp.root->children[d];
    return tmp;
  }

  void insertChild(Direction d, BinaryTree<T> &A) {
    assert(!null());

    // il sotto nodo in cui si vuole inserire il figlio deve essere nullo
    assert(child(d).null());

    if (!A.null()) {
      root->children[d] = A.root;
      A.root->parent = root;
    }
  }
};

template <class T> unsigned depth(BinaryTree<T> a) {
  if (a.null())
    return 0;
  unsigned d1 = depth(a.child(left)), d2 = depth(a.dhild(right));
  return (d1 > d2) ? d1 + 1 : d2 + 1;
}

template <class T> bool balanced(BinaryTree<T> a) {
  if (a.null())
    return true;

  // le chiamate ricorsive sono troppe, troppe ripetizioni
  // complessità esponenziale
  return std::abs(depth(a.child(left)) - depth(a.child(right))) <= 1 &&
         balanced(a.child(left)) && balanced(a.child(right));
}

template <class T> bool deepBalanced(BinaryTree<T> A, unsigned &maxDepth) {
  if (A.null()) {
    maxDepth = 0;
    return true;
  }
  int depthLeft, depthRight;

  bool balancedLeft = deepBalanced(A.child(left), depthLeft),
       balancedRight = deepBalanced(A.child(right), depthRight);

  maxDepth = std::max(depthLeft, depthRight) + 1; // restituisci nel parametro
  //
  return balancedLeft && balancedRight && std::abs(depthLeft - depthRight) <= 1;
}
