#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Node {
public:
    int value;
    Node* parent;
    vector<Node*> children;
    int degree;
    bool marked;

    Node(int val) {
        value = val;
        parent = NULL;
        degree = 0;
        marked = false;
    }
};

class BinomialHeap {
public:
    vector<Node*> trees;
    Node* min_node;
    int count;

    BinomialHeap() {
        min_node = NULL;
        count = 0;
    }

    bool is_empty() {
        return min_node == NULL;
    }

    int get_min() {
        if (!min_node) throw runtime_error("Heap is empty");
        return min_node->value;
    }

    int size() {
        return count;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        BinomialHeap temp;
        temp.trees.push_back(newNode);
        temp.count = 1;
        merge(temp);
    }

    void merge(BinomialHeap& other) {
        trees.insert(trees.end(), other.trees.begin(), other.trees.end());
        count += other.count;
        _consolidated();
        _find_min();
    }

    int extract_min() {
        if (is_empty()) throw runtime_error("Heap is empty");

        Node* minNode = min_node;
        // Remove minNode from root list
        trees.erase(remove(trees.begin(), trees.end(), minNode), trees.end());
        // Create a new heap from minNode’s children
        BinomialHeap temp;
        temp.trees = minNode->children;
        for (auto* child : temp.trees)
            child->parent = NULL;  // detach from old parent
        merge(temp);
        count--;
        int minValue = minNode->value;
        delete minNode; // optional
        _find_min();
        return minValue;
    }

    void decrease_key(Node* node, int new_value) {
        if (new_value >= node->value)
            throw invalid_argument("New value must be smaller");
        node->value = new_value;
        _bubble_up(node);
    }

private:
    void _bubble_up(Node* node) {
        Node* parent = node->parent;
        while (parent != NULL && node->value < parent->value) {
            swap(node->value, parent->value);
            node = parent;
            parent = node->parent;
        }
    }

    void _link(Node* tree1, Node* tree2) {
        if (tree1->value > tree2->value)
            swap(tree1, tree2);
        tree2->parent = tree1;
        tree1->children.push_back(tree2);
        tree1->degree++;
    }

    void _find_min() {
        min_node = NULL;
        for (Node* node : trees) {
            if (!min_node || node->value < min_node->value) {
                min_node = node;
            }
        }
    }

    void _consolidated() {
        if (count == 0) return;

        int max_degree = static_cast<int>(floor(log2(count))) + 2;
        vector<Node*> degree_to_tree(max_degree, NULL);

        while (!trees.empty()) {
            Node* current = trees.back();
            trees.pop_back();
            int degree = current->degree;

            while (degree_to_tree[degree] != NULL) {
                Node* other = degree_to_tree[degree];
                degree_to_tree[degree] = NULL;

                if (current->value < other->value)
                    _link(current, other);
                else
                    _link(other, current);

                degree++;
            }
            degree_to_tree[degree] = current;
        }

        trees.clear();
        min_node = NULL;
        for (Node* node : degree_to_tree) {
            if (node) {
                trees.push_back(node);
                if (!min_node || node->value < min_node->value)
                    min_node = node;
            }
        }
    }
};
