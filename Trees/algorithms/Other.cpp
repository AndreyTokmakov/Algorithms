/**============================================================================
Name        : Other.cpp
Created on  : 13.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"
#include "Utilities.h"

namespace
{
    template<typename T>
    std::ostream &operator<<(std::ostream &ostr, const std::vector<T> &list) {
        for (const auto &i: list)
            ostr << " " << i;
        return ostr;
    }

#if 0
    template<typename T>
    std::ostream &operator<<(std::ostream &ostr, const std::list<T> &list) {
        for (const auto &i: list)
            ostr << " " << i;
        return ostr;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &ostr, const std::set<T> &set) {
        for (const auto &i: set)
            ostr << " " << i;
        return ostr;
    }
#endif

    template<typename T>
    std::ostream &operator<<(std::ostream &ostr, const std::deque<T> &list) {
        for (const auto &i: list)
            ostr << " " << i;
        return ostr;
    }

    template<typename T>
    void print_vector(const std::vector<T> &vector, size_t start, size_t end) {
        for (size_t i = start; i <= end; i++)
            std::cout << vector[i] << " ";
        std::cout << std::endl;
    }
}

namespace BinTree_Bad {

    template<typename T = int>
    class Node {
    public:
        T data;
        Node<T>* left;
        Node<T>* right;

    public:
        Node(T d, Node* l, Node* r) : data(d), left(l), right(r) {
        }

        Node(T data) : data  {data}, left {nullptr}, right {nullptr} {
        }
    };


    /* The function Compute the "height" of a tree. Height is the number of
       nodes along the longest path from the root node down to the farthest leaf node.*/
    template<typename T = int>
    T getHeight(Node<T>* node) {
        if (nullptr == node) /* base case tree is empty */
            return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    /* Returns true if binary tree with root as root is height-balanced */
    template<typename T = int>
    bool isBalanced(Node<T>* root)
    {
        int lh; /* for height of left subtree */
        int rh; /* for height of right subtree */

        /* If tree is empty then return true */
        if (nullptr == root)
            return 1;

        /* Get the height of left and right sub trees */
        lh = getHeight(root->left);
        rh = getHeight(root->right);

        if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;

        /* If we reach here then tree is not height-balanced */
        return 0;
    }


    template<typename T = int>
    bool isBalanced(Node<T>* root, int* height)
    {
        int lh = 0, rh = 0;
        if (nullptr == root)
            *height = 0;
        return 1;

        /* Get the heights of left and right subtrees in lh and rh
          And store the returned values in l and r                */
        int l = isBalanced(root->left, &lh);
        int r = isBalanced(root->right, &rh);

        /* Height of current node is max of heights of left and right subtrees plus 1*/
        *height = (lh > rh ? lh : rh) + 1;

        /* If difference between heights of left and right
        subtrees is more than 2 then this node is not balanced
        so return 0 */
        if (abs(lh - rh) >= 2)
            return 0;

            /* If this node is balanced and left and right subtrees
            are balanced then return true */
        else
            return l && r;
    }


    /* Helper function that allocates a new node with the given data
        and NULL left and right pointers. */
    template<typename T = int>
    Node<T>* newNode(T data) {
        return new Node<T>(data);
    }

    void TEST()
    {
        Node<int>* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->left->left->left = newNode(7);

        if (isBalanced(root))
            std::cout << "Tree is balanced" << std::endl;
        else
            std::cout << "Tree is not balanced" << std::endl;

        int height = 0;

        if (isBalanced(root, &height))
            std::cout << "Tree is balanced2" << std::endl;
        else
            std::cout << "Tree is not balanced2" << std::endl;

    }

}

namespace BinTree
{
    class BinaryTree
    {
        Node* root;

        // protected:
    public:
        Node* clear(const Node* node) {
            if (nullptr == node)
                return nullptr;
            {
                this->clear(node->left);
                this->clear(node->right);
                delete node;
            }
            return nullptr;
        }

        Node* insert(int value, Node* node) {
            if (nullptr == node) {
                node = new Node(value);
            }
            else if (value < node->data) {
                node->left = this->insert(value, node->left);
            }
            else if (value > node->data) {
                node->right = this->insert(value, node->right);
            }
            return node;
        }

        Node* getMin(Node* node) {
            if (nullptr == node) {
                return nullptr;
            }
            else if (nullptr == node->left) {
                return node;
            }
            else {
                return this->getMin(node->left);
            }
        }

        Node* getMax(Node* node) {
            if (nullptr == node) {
                return nullptr;
            }
            else if (nullptr == node->right) {
                return node;
            }
            else {
                return this->getMax(node->right);
            }
        }

        Node* remove(int value, Node* node) {
            Node* temp;
            if (nullptr == node)
                return nullptr;
            else if (value < node->data) {
                node->left = this->remove(value, node->left);
            }
            else if (value > node->data) {
                node->right = remove(value, node->right);
            }
            else if (node->left && node->right) {
                temp = getMin(node->right);
                node->data = temp->data;
                node->right = remove(node->data, node->right);
            }
            else {
                temp = node;
                if (nullptr == node->left)
                    node = node->right;
                else if (nullptr == node->right)
                    node = node->left;
                delete temp;
            }
            return node;
        }

        void inorder(const Node* node) {
            if (nullptr == node)
                return;
            this->inorder(node->left);
            std::cout << node->data << " ";
            this->inorder(node->right);
        }

        Node* find(Node* node, int value) {
            if (nullptr == node)
                return nullptr;
            else if (value < node->data)
                return this->find(node->left, value);
            else if (value > node->data)
                return this->find(node->right, value);
            else
                return node;
        }

        unsigned int getDepth(const Node* node) {
            if (nullptr == node)
                return 1;
            unsigned int left_depth = (nullptr == node->left) ? 0 : this->getDepth(node->left);
            unsigned int right_depth = (nullptr == node->right) ? 0 : this->getDepth(node->right);
            return 1 + std::max(left_depth, right_depth);
        }

        size_t GetDepthEx(const Node* node) const {
            return nullptr == node ? 0 : 1 + std::max(GetDepthEx(node->left), GetDepthEx(node->right));
        }


        bool isNodeBalancedTest(Node* node) {
            if (nullptr == node)
                return 1;

            int lh = GetDepthEx(node->left);
            int rh = GetDepthEx(node->right);
            if (abs(lh - rh) <= 1 && isNodeBalancedTest(node->left) && isNodeBalancedTest(node->right))
                return 1;
            return 0;
        }


    public:
        BinaryTree(Node* node = nullptr) {
            this->root = node;
        }

        BinaryTree(const std::initializer_list<int> list) {
            this->root = nullptr;
            for (const int* iter = std::begin(list); iter != std::end(list); ++iter)
                this->root = this->insert(*iter, this->root);
        }

        ~BinaryTree() {
            this->root = this->clear(root);
        }

        Node* getRoot() const {
            return this->root;
        }

        void insert(int value) {
            this->root = this->insert(value, root);
        }

        void remove(int value) {
            this->root = this->remove(value, root);
        }

        void display() {
            this->inorder(root);
            std::cout << std::endl;
        }

        void search(int value) {
            this->root = this->find(root, value);
        }

        unsigned int getDepth(void) {
            return this->getDepth(this->root);
        }

        unsigned int GetDepthEx(void) const {
            return this->GetDepthEx(this->root);
        }

        bool isBalanced() {
            return this->isNodeBalancedTest(this->root);
        }

        Node* FindLowestCommonAncestorEx(Node* node, int value1, int value2) {
            if (nullptr == node)
                return nullptr;
            if (value1 < node->data && value2 < node->data)
                return this->FindLowestCommonAncestorEx(node->left, value1, value2);
            else if (value1 > node->data && value2 > node->data)
                return this->FindLowestCommonAncestorEx(node->right, value1, value2);
            else
                return node;
        }
    };
}

namespace BinTreeTests {

    BinTree::Node* Find_Routed(BinTree::Node* node, int value, std::vector<BinTree::Node*>& trace) {
        if (nullptr == node)
            return nullptr;
        trace.emplace_back(node);
        if (value < node->data)
            return Find_Routed(node->left, value, trace);
        else if (value > node->data)
            return Find_Routed(node->right, value, trace);
        else
            return node;
    }


    void FindLowestCommonAncestor(BinTree::Node* node, int value1, int value2) {
        std::vector<BinTree::Node*> trace1, trace2;
        Find_Routed(node, value1, trace1);
        Find_Routed(node, value2, trace2);
        auto result = std::mismatch(trace1.begin(), trace1.end(), trace2.begin(), trace2.end());
        std::cout << (*(result.first - 1))->getData() << std::endl;
    }

    void FindLowestCommonAncestor() {
        BinTree::BinaryTree tree{ 33,22,85,10,25,54,125,5,15,30 };

        FindLowestCommonAncestor(tree.getRoot(), 5, 10);
        FindLowestCommonAncestor(tree.getRoot(), 5, 25);
        FindLowestCommonAncestor(tree.getRoot(), 5, 30);

        std::cout << "------------------------------------------ TEST2 ------------------------------------" << std::endl;

        BinTree::Node* lcaNode = tree.FindLowestCommonAncestorEx(tree.getRoot(), 5, 10);
        std::cout << lcaNode->getData() << std::endl;
        lcaNode = tree.FindLowestCommonAncestorEx(tree.getRoot(), 5, 25);
        std::cout << lcaNode->getData() << std::endl;
        lcaNode = tree.FindLowestCommonAncestorEx(tree.getRoot(), 5, 30);
        std::cout << lcaNode->getData() << std::endl;
    }

    //---------------------------------------------------------------------------------------------------------------------------//



    ///////////////////////////////////////////////////////////////////////////////////////////////////////1

    void Remove_Tests() {
        BinTree::BinaryTree tree;
        tree.insert(20);
        tree.insert(25);
        tree.insert(15);
        tree.insert(10);
        tree.insert(30);
        tree.display();
        tree.remove(20);
        tree.display();
        tree.remove(25);
        tree.display();
        tree.remove(30);
        tree.display();
    }


    void TreeTest1() {
        BinTree::BinaryTree tree;
        tree.insert(1);
        tree.insert(3);
        tree.insert(5);
        tree.insert(7);
        tree.insert(25);
        tree.insert(15);
        tree.insert(10);
        tree.insert(30);
        tree.insert(25);
        tree.insert(15);
        tree.insert(10);

        tree.display();

        std::cout << "getDepth  = " << tree.getDepth() << std::endl;
        std::cout << "getDepth2  = " << tree.GetDepthEx() << std::endl;
        std::cout << "isBalanced  = " << tree.isBalanced() << std::endl;
    }

    void BalanceTest() {
        {
            BinTree::BinaryTree tree;
            tree.insert(1);
            tree.insert(6);
            tree.insert(4);
            tree.insert(7);
            tree.insert(5);

            tree.display();
            std::cout << "isBalanced  = " << tree.isBalanced() << std::endl;
        }

        {
            BinTree::BinaryTree tree;
            tree.insert(1);
            tree.insert(6);
            tree.insert(4);
            tree.insert(7);
            tree.insert(5);
            tree.insert(15);
            tree.insert(51);

            tree.display();
            std::cout << "isBalanced  = " << tree.isBalanced() << std::endl;
        }
    }

    bool __is_full_binary_tree(const BinTree::Node* node) {
        if (nullptr == node)
            return true;
        else if (nullptr == node->left && nullptr == node->right)
            return true;
        else if (nullptr != node->left && nullptr != node->right)
            return __is_full_binary_tree(node->left) && __is_full_binary_tree(node->right);
        else
            return false;
    }

    void IsFullBinaryTree() {
        {
            BinTree::BinaryTree tree{ 33, 22, 85, 10 ,30, 54, 125 };
            std::cout << "IsFullBinaryTree = " << std::boolalpha << __is_full_binary_tree(tree.getRoot()) << std::endl;
        }
        {
            BinTree::BinaryTree tree{ 33, 22, 85, 10 ,30, 54, 125 ,343 };
            std::cout << "IsFullBinaryTree = " << std::boolalpha << __is_full_binary_tree(tree.getRoot()) << std::endl;
        }
    }



    void _print_top_view(BinTree::Node* node,
                         std::map<size_t, std::pair<size_t, size_t>>& map,
                         size_t level, size_t distance) {
        if (nullptr == node)
            return;

        // if current level is less than maximum level seen so far for the same horizontal
        // distance or horizontal distance is seen for the first time, update the map
        if (auto it = map.find(distance);  map.end() == it || level < it->second.second) {
            //map.insert_or_assign({ distance, { node->data, level} });
            map[distance] = { node->data, level };
        }
        _print_top_view(node->left, map, level + 1, distance - 1);
        _print_top_view(node->right, map, level + 1, distance + 1);
    }

    void Print_Top_View() {
        // BinTree::BinaryTree tree{ 33,22,85,10,30,54,125 };
        BinTree::BinaryTree tree{ 33,22,85,30,54,125,28,27,26 };

        std::map<size_t, std::pair<size_t, size_t>> map;

        _print_top_view(tree.getRoot(), map, 0, 0);

        // traverse the map and print top view
        for (auto it : map)
            std::cout << it.second.first << " ";
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    size_t GetDepth(const BinTree::Node* node) {
        return nullptr == node ? 0 : 1 + std::max(GetDepth(node->left), GetDepth(node->right));
    }

    size_t GetMinDepth(const BinTree::Node* node) {
        if (nullptr == node)
            return 0;
        else if (node->left == nullptr && node->right == nullptr)
            return 1;
        else if (nullptr == node->right)
            return GetMinDepth(node->left) + 1;
        else if (nullptr == node->left)
            return GetMinDepth(node->right) + 1;
        else
            return 1 + std::min(GetMinDepth(node->left), GetMinDepth(node->right));
    }

    void Find_Max_Depth()
    {
        //BinTree::BinaryTree tree {33,22,85,10,30,54,125,5,8,25,32,45,60,120,130};
        BinTree::BinaryTree tree{ 4,2,6,1,3,5,7 };

        std::cout << "Depth1 = " << GetDepth(tree.getRoot()) << std::endl;
        std::cout << "Depth2 = " << tree.getDepth() << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////

    void Find_Min_Depth() {
        BinTree::BinaryTree tree{ 40,20,60,12,30,6,16,50,4,8,7,10 };

        std::cout << "Min depth = " << GetMinDepth(tree.getRoot()) << std::endl;
        std::cout << "Max depth = " << GetDepth(tree.getRoot()) << std::endl;
    }

    size_t __get_depth_test(const BinTree::Node* node) {
        if (nullptr == node)
            return 1;
        unsigned int left = 1, right = 1;
        BinTree::Node* node_prt = node->left;
        while (nullptr != node_prt) {
            left++;
            node_prt = node_prt->left;
        }
        node_prt = node->right;
        while (nullptr != node_prt) {
            right++;
            node_prt = node_prt->right;
        }
        return std::max(left, right);
    }

    struct NodeDepth
    {
        BinTree::Node* node {nullptr};
        size_t depth {0};
    };

    size_t __get_depth_test_2(BinTree::Node* root)
    {
        size_t depth = 1;
        std::vector<NodeDepth> stack {};
        stack.reserve(100);
        NodeDepth dNode { root, depth};

        while (dNode.node || !stack.empty())
        {
            while (dNode.node) {
                stack.push_back(dNode);
                dNode = {dNode.node->left, stack.back().depth + 1};
            }

            dNode = stack.back();
            stack.pop_back();
            depth = std::max(depth, dNode.depth);
            dNode = {dNode.node->right, dNode.depth + 1};
        }
        return depth;
    }


    void Find_Depth_Tests_2()
    {
        BinTree::BinaryTree tree{ 50,20,60,10,25,27,28,29,30,31,32 };
        // BinTree::BinaryTree tree { 12, 5, 15, 3, 7, 13, 17, 8 ,9, 10};  // -->  Depth: 5

        std::cout << "Depth = " << GetDepth(tree.getRoot()) << std::endl;
        std::cout << "Depth = " << tree.getDepth() << std::endl;
        std::cout << "Depth = " << __get_depth_test(tree.getRoot()) << std::endl;
        std::cout << "Depth = " << __get_depth_test_2(tree.getRoot()) << std::endl;
    }

    ///------------------------------------------------------------------------------------------------

    void Find_Depth_PerformanceTests()
    {
        constexpr size_t size {1'000}, testsCount {1000'000};

        const BinTree::BinaryTree tree = [] {
            BinTree::BinaryTree tree;
            for (size_t i = 0; i < size; ++i)
                tree.insert(Utilities::randomIntegerInRange(0, size * 10));
            return tree;
        }();

        if (GetDepth(tree.getRoot()) != __get_depth_test_2(tree.getRoot()))
        {
            std::cerr << "Error!" << std::endl;
            return;
        }

        {
            Utilities::ScopedTimer timer {"Recursive"};
            for (size_t i = 0; i < testsCount; ++i)
                GetDepth(tree.getRoot());
        }

        {
            Utilities::ScopedTimer timer {"Non recursive"};
            for (size_t i = 0; i < testsCount; ++i)
                __get_depth_test_2(tree.getRoot());
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    void _find_node_with_sumX(const BinTree::Node* node, std::unordered_set<int>& values, int X) {
        if (nullptr != node) {
            if (values.end() != values.find(X - node->data)) {
                std::cout << "{" << X - node->data << ", " << node->data << "}" << std::endl;
            }
            values.insert(node->data);
            _find_node_with_sumX(node->left, values, X);
            _find_node_with_sumX(node->right, values, X);
        }
    }

    void Find_Node_WithSumX() {
        std::unordered_set<int> values;
        BinTree::BinaryTree tree{ 40,22,85 ,10,30,54,125 ,5,12 ,25,32 ,45,60, 120,130,4,7,11,15,24,28,31,35,42,50,55,65,100,122,127 };
        _find_node_with_sumX(tree.getRoot(), values, 41);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    void _find_node_with_sumX_2(const BinTree::Node* left, const BinTree::Node* right, int X) {
        std::cout << "[" << left->data << "  " << right->data << "]" << std::endl;
        if (nullptr == left || nullptr == right)
            return;
        const auto actual = left->data + right->data;
        if (actual > X)
            _find_node_with_sumX_2(left->left, right, X);
        else if (actual < X)
            _find_node_with_sumX_2(left, right->right, X);
        else
        {
            std::cout << left->data << "  " << right->data << std::endl;
        }
    }


    void Find_Node_WithSumX_2() {
        std::unordered_set<int> values;
        BinTree::BinaryTree tree{ 40,22,85 ,10,30,54,125 ,5,12 ,25,32 ,45,60, 120,130,4,7,11,15,24,28,31,35,42,50,55,65,100,122,127 };
        _find_node_with_sumX_2(tree.getRoot()->left, tree.getRoot()->right, 41);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    void _reverse_tree(BinTree::Node* node) {
        if (nullptr == node)
            return;

        /*
        BinTree::Node* r = node->right;
        node->right = node->left;
        node->left = r;
        */

        std::swap(node->right, node->left);

        _reverse_tree(node->left);
        _reverse_tree(node->right);
    }


    void ReverseTree() {
        // BinTree::BinaryTree tree { 40,22,85 ,10,30,54,125 ,5,12 ,25,32 ,45,60, 120,130,4,
        //                           7,11,15,24,28,31,35,42,50,55,65,100,122,127 };
        BinTree::BinaryTree tree{ 40,22,85 ,10,30,54,125 ,5,12 ,25,32 ,45,60, 120,130 };

        tree.display();

        _reverse_tree(tree.getRoot());

        tree.display();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    int FindMaxInNon_BST_Tree(const BinTree::Node* node) {
        /// Just MAX
        /// return nullptr == node->right ? node->getData() : FindMaxInNon_BST_Tree(node->right);
        static int max_val = std::numeric_limits<int>::min();
        if (nullptr != node) {
            max_val = std::max(max_val, node->data);
            FindMaxInNon_BST_Tree(node->left);
            FindMaxInNon_BST_Tree(node->right);
        }
        return max_val;
    }

    void Find_MaxElement_NotForBST() {
        BinTree::BinaryTree tree{ 50,20,67,10,23,27,28,29,30,311,32 };
        std::cout << "Real max: " << tree.getMax(tree.getRoot())->getData() << std::endl;
        std::cout << "Real max: " << FindMaxInNon_BST_Tree(tree.getRoot()) << std::endl;

    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    int _find_maximum_path_sum_between_nodes(const BinTree::Node* node) {
        static int max_path = std::numeric_limits<int>::min();
        if (nullptr == node)
            return max_path;
        else if (nullptr == node->left && nullptr == node->right)
            return node->data;

        // Find maximum sum in left and right subtree. Also find maximum node to
        // leaf sums in left and right  subtrees and store them in ls and rs
        int ls = _find_maximum_path_sum_between_nodes(node->left);
        int rs = _find_maximum_path_sum_between_nodes(node->right);

        // If both left and right children exist
        if (node->left && node->right) {
            max_path = std::max(max_path, ls + rs + node->data);
            // Return maximum possible value for root being  on one side
            return std::max(ls, rs) + node->data;
        }

        // If any of the two children is empty, return root sum for root being on one side
        return (nullptr == node->left) ? rs + node->data : ls + node->data;
    }

    /// RIGHT ONE
    std::pair<int, int> _find_maximum_path_sum_between_nodes2(const BinTree::Node* node) {
        int max_path = node->data;
        int max_subtree = node->data;
        int full_path = node->data;

        if (node->left) {
            auto [path, tree] = _find_maximum_path_sum_between_nodes2(node->left);
            max_path = std::max(max_path, path + node->data);
            max_subtree = std::max(max_subtree, tree);
            full_path += path;
        }
        if (node->right) {
            auto [path, tree] = _find_maximum_path_sum_between_nodes2(node->right);
            max_path = std::max(max_path, path + node->data);
            max_subtree = std::max(max_subtree, tree);
            full_path += path;
        }

        max_subtree = std::max(max_subtree, std::max(full_path, max_path));
        return {max_path, max_subtree};
    }

    void Find_Maximum_PathSum_BetweenNodes() {
        BinTree::BinaryTree tree{ 40,25,85 ,10,30,55,125 };

        std::cout << _find_maximum_path_sum_between_nodes(tree.getRoot()) << std::endl;
        std::cout << _find_maximum_path_sum_between_nodes2(tree.getRoot()).second << std::endl;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////


    int _sumElementsInRange(BinTree::Node* node, int lower, int upper) {
        if (nullptr == node)
            return 0;
        int result = _sumElementsInRange(node->left, lower, upper);
        if (node->data >= lower && node->data <= upper)
            result += node->data;
        return result + _sumElementsInRange(node->right, lower, upper);
    }

    void Sum_Elements_InRange() {
        BinTree::BinaryTree tree{ 5,3,8,2,4,6,8 };
        int result = _sumElementsInRange(tree.getRoot(), 4, 9);
        std::cout << result << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    size_t _size(const BinTree::Node* node) {
        return nullptr == node ? 0 : 1 + _size(node->left) + _size(node->right);
    }

    bool _is_bst(const BinTree::Node* node) {
        if (nullptr == node)
            return true;
        else if (nullptr != node->left && node->left->data > node->data)
            return false;
        else if (!_is_bst(node->left))
            return false;
        else if (nullptr != node->right && node->right->data < node->data)
            return false;
        else if (!_is_bst(node->right))
            return false;
        else
            return true;
    }

    size_t _max_Bst(const BinTree::Node* node) {
        return true == _is_bst(node) ? _size(node) : std::max(_max_Bst(node->left), _max_Bst(node->right));
    }

    int _inorder_walk_test(const BinTree::Node* node) {
        static int prev = std::numeric_limits<int>::min(), max = 0, curr = 0;
        if (nullptr == node)
            return 0;
        _inorder_walk_test(node->left);

        curr = prev < node->data ? curr + 1 : 1;
        max = std::max(max, curr);
        // std::cout << node->data << " " << prev << "  " << curr << std::endl;

        prev = node->data;

        _inorder_walk_test(node->right);
        return max;
    }

    void Find_Largest_BST_Sub() {
        /*
        BinTree::Node* root = new BinTree::Node(15);
        root->right = new BinTree::Node(14);
        root->right->left = new BinTree::Node(12);
        root->right->right = new BinTree::Node(25);
        root->left = new BinTree::Node(2);
        */

        BinTree::Node* root = new BinTree::Node(50);
        root->left = new BinTree::Node(20);
        root->right = new BinTree::Node(60);
        root->left->left = new BinTree::Node(5);
        root->left->right = new BinTree::Node(10);
        root->right->left = new BinTree::Node(55);
        root->right->left->left = new BinTree::Node(45);
        root->right->right = new BinTree::Node(70);
        root->right->right->left = new BinTree::Node(65);
        root->right->right->right = new BinTree::Node(80);

        std::cout << "Size = " << _size(root) << std::endl;
        std::cout << "Max BST = " << _max_Bst(root) << std::endl;

        std::cout << std::endl;
        std::cout << "Max BST ( inorder walk test) = " << _inorder_walk_test(root) << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    void __print_level(const BinTree::Node* node,
                       size_t depth,
                       size_t level_to_print,
                       size_t currn_velel,
                       [[maybe_unused]] char leg)
    {
        if (level_to_print == currn_velel) {
            size_t x = depth - level_to_print;
            std::cout << std::right << std::setfill(' ') << std::setw(x * 8) << (nullptr == node ? 0 : node->getData());
        }
        else {
            __print_level(node->left, depth, level_to_print, currn_velel + 1, '/');
            __print_level(node->right, depth, level_to_print, currn_velel + 1, '\\');
        }
    }


    void __pritty_print(const BinTree::BinaryTree& tree) {
        //std::cout << std::right << std::setfill(' ') << std::setw((depth - currn_velel -1) * 8) << node->getData() << std::endl;
        //std::cout << "    "  << "/" << "    " << "\\" << std::endl;
        //BinTree


        const size_t depth = tree.GetDepthEx();
        for (size_t i = 1; i <= depth; i++) {
            __print_level(tree.getRoot(), depth, i, 1, '|');
            std::cout << std::endl;
        }
    }

    void Pritty_Print_Test() {
        BinTree::BinaryTree tree{ 33, 22, 85, 10, 30, 54, 125,2244 };
        __pritty_print(tree);
    }
}


namespace Trees::Complete_Tree
{
    void Count_Levels()
    {
        int elements_count = 15;
        std::cout << "if tree has " << elements_count << " elements so height is: " << (int)log2(elements_count) << std::endl;
    }

    void Count_Elements() {
        int height = 4;
        int min = pow(height - 1, 2) - 1;
        int max = pow(height, 2) - 1;
        std::cout << "if tree height is " << height << " then it has [" << min << " - " << max << "] elements" << std::endl;
    }

    int __count(const BinTree::Node* root) {
        return root == nullptr ? 0 : 1 + __count(root->left) + __count(root->right);
    }

    bool __is_complete(const BinTree::Node* root, int index, int n) {
        if (root == nullptr)  // Null node - noop
            return true;
        if (index >= n) // If the index of this node is beyond the range, we have a gap somewhere.
            return false;
        // Recurse to 2*i+1 and 2*i+2
        return __is_complete(root->left, 2*index+1, n) &&
               __is_complete(root->right, 2*index+2, n);
    }

    bool __is_complete_binary_tree(const BinTree::BinaryTree& tree) {
        int cnt = __count(tree.getRoot());
        return __is_complete(tree.getRoot(), 0, cnt);
    }

    void IsCompletedTree()
    {
        BinTree::BinaryTree tree1 { 33, 22, 85, 10 ,30, 54, 125 };
        BinTree::BinaryTree tree2 { 33, 22, 85, 10 ,30, 54 };

        std::cout << std::boolalpha << __is_complete_binary_tree(tree1) << std::endl;
        std::cout << std::boolalpha << __is_complete_binary_tree(tree2) << std::endl;
    }

    //------------------------------------------------------------------------------

    void _is_completed_tree_map(const BinTree::Node* node, std::unordered_map<int, int> & values, int level) {
        if (nullptr == node)
            return;
        ++values[level];
        _is_completed_tree_map(node->left, values, level + 1);
        _is_completed_tree_map(node->right, values, level + 1);
    }

    void _is_completed_tree_map(const BinTree::Node* node) {
        std::unordered_map<int, int> values;
        _is_completed_tree_map(node, values, 0);

        for (const auto& [k,v]: values) {
            std::cout << k << " = " << v << ", expected: " << std::pow(2, k) << std::endl;
        }
    }

    void IsCompletedTree_MAP()
    {
        BinTree::BinaryTree tree1 { 33, 22, 85, 10 ,30, 54, 125 };
        _is_completed_tree_map(tree1.getRoot());
    }
}

namespace Trees::Check_Is_BST
{
    bool isBST(BinTree::Node* node, int min, int max) {
        if (nullptr == node)
            return true;
        if (node->data < min || node->data > max)
            return false;
        return isBST(node->left, min, node->data - 1) && isBST(node->right, node->data + 1, max);
    }

    bool isBST2(BinTree::Node* root, int& prev) {
        if (root) {
            if (false == isBST2(root->left, prev))
                return false;
            if (root->data <= prev) {
                return false;
            }
            prev = root->data;
            //std::cout << prev << std::endl;
            return isBST2(root->right, prev);
        }
        return true;
    }

    bool isBinarySearchTree(const BinTree::Node* node) {
        if (nullptr == node)
            return true;
        else if (nullptr != node->left && node->left->data > node->data)
            return false;
        else if (false == isBinarySearchTree(node->left))
            return false;
        else if (nullptr != node->right && node->right->data < node->data)
            return false;
        else if (false == isBinarySearchTree(node->right))
            return false;
        else
            return true;
    }

    bool isBinarySearchTree_Inorder(const BinTree::Node* node, int& previous) {
        if (nullptr == node)
            return true;
        else if (false == isBinarySearchTree_Inorder(node->left, previous))
            return false;
        else if (previous >= node->data)
            return false;
        previous = node->data;
        return isBinarySearchTree_Inorder(node->right, previous);
    }

    bool isBinarySearchTree_Inorder2(const BinTree::Node* node) {
        static int previous = std::numeric_limits<int>::min();
        if (nullptr == node)
            return true;
        else if (!isBinarySearchTree_Inorder2(node->left))
            return false;
        else if (previous > node->data)
            return false;
        previous = node->data;
        return isBinarySearchTree_Inorder2(node->right);
    }

    bool isBinarySearchTree_Inorder3(const BinTree::Node* node) {
        if (!node)
            return true;
        if (!isBinarySearchTree_Inorder3(node->left))
            return false;
        static int previous = node->data; // That's the difference
        // std::cout << node->data << "  " << previous << std::endl;
        if (previous > node->data)
            return false;
        previous = node->data;
        return isBinarySearchTree_Inorder3(node->right);
    }

    void CheckIs_BTS()
    {
        BinTree::BinaryTree tree{ 33,22,85,10,30,54,125 };
        // BinTree::BinaryTree tree { 33,22,85};

        std::cout << std::boolalpha << isBinarySearchTree(tree.getRoot()) << std::endl;

        int p = INT32_MIN;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder(tree.getRoot(), p) << std::endl;

        std::cout << std::boolalpha << isBinarySearchTree_Inorder2(tree.getRoot()) << std::endl;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder3(tree.getRoot()) << std::endl;
        std::cout << std::boolalpha << isBST(tree.getRoot(), INT32_MIN, INT32_MIN) << std::endl;

        int prev = INT32_MIN;
        std::cout << isBST2(tree.getRoot(), prev) << std::endl;
    }

    void CheckIs_BTS_2() {
        BinTree::Node* root = new BinTree::Node(10);
        root->right = new BinTree::Node(20);
        root->right->left = new BinTree::Node(12);
        root->right->right = new BinTree::Node(25);

        root->left = new BinTree::Node(2);


        std::cout << std::boolalpha << isBinarySearchTree(root) << std::endl;

        int p = INT32_MIN;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder(root, p) << std::endl;

        std::cout << std::boolalpha << isBinarySearchTree_Inorder2(root) << std::endl;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder3(root) << std::endl;
        std::cout << std::boolalpha << isBST(root, INT32_MIN, INT32_MIN) << std::endl;

        int prev = INT32_MIN;
        std::cout << isBST2(root, prev) << std::endl;
    }

    bool _is_bst_non_recursive(BinTree::Node* node)
    {
        std::vector<BinTree::Node*> stack {};
        BinTree::Node *curr = node;

        int previous = std::numeric_limits<int>::min();
        while (nullptr != curr || !stack.empty())
        {   /* Reach the left most Node of the curr Node */
            while (nullptr != curr)
            { /* place pointer to a tree node on the stack before traversing the node's left subtree */
                stack.push_back(curr);
                curr = curr->left;
            }

            curr = stack.back(); // Current must be NULL at this point
            stack.pop_back();

            if (previous > curr->data)
                return false;

            previous = curr->data;
            curr = curr->right;
        }
        return true;
    }

    void CheckIs_BTS_NonRecursive()
    {
        BinTree::Node* root = new BinTree::Node(10);

        root->right = new BinTree::Node(20);
        root->right->left = new BinTree::Node(12);
        root->right->right = new BinTree::Node(25);

        root->left = new BinTree::Node(6);
        root->left->left = new BinTree::Node(3);
        root->left->right = new BinTree::Node(9);

        /*
        int p = std::numeric_limits<int>::min();
        std::cout << std::boolalpha << isBinarySearchTree(root) << std::endl;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder(root, p) << std::endl;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder2(root) << std::endl;
        std::cout << std::boolalpha << isBinarySearchTree_Inorder3(root) << std::endl;
        */
        std::cout << std::boolalpha << _is_bst_non_recursive(root) << std::endl;
    }
}

namespace Trees::Min_and_Max_Elements
{

    BinTree::Node* KthLargestUsingMorrisTraversal(BinTree::Node* root, size_t k)
    {
        BinTree::Node* curr = root, *Klargest = nullptr;

        size_t count = 0;
        while (curr) {
            // if right child is NULL
            if (nullptr == curr->right) {
                // first increment count and check if count = k
                if (++count == k)
                    Klargest = curr;
                // otherwise move to the left child
                curr = curr->left;
            }
            else {
                // find inorder successor of current Node
                BinTree::Node* succ = curr->right;
                while (succ->left && succ->left != curr)
                    succ = succ->left;
                if (succ->left == nullptr) {
                    succ->left = curr;    // set left child of successor to the current Node
                    curr = curr->right;   // move current to its right
                }  // restoring the tree back to original binary search tree removing threaded links
                else {
                    succ->left = nullptr;
                    if (++count == k)
                        Klargest = curr;
                    // move current to its left child
                    curr = curr->left;
                }
            }
        }
        return Klargest;
    }

    void Find_N_th_Largest_MorrisTraversal()
    {
        BinTree::BinaryTree tree{ 33,22,85,10,30,54,125,5,8,25,32,45,60,120,130 };

        size_t K = 4;
        auto res = KthLargestUsingMorrisTraversal(tree.getRoot(), K);
        std::cout << res->data << std::endl;
    }
}

void TreesAlgorithms::Other()
{

}

