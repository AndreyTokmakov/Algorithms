/**============================================================================
Name        : Other.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : LinkedList algorithms entry point
============================================================================**/

#include "../common.h"
#include "../LinkedListAlgorithms.h"

#include <unordered_set>
#include <forward_list>

namespace LinkedListAlgorithms
{

    template<typename T>
    Node<T>* _reserve_sublists(Node<T>* head) {
        Node<int>* next = head;

        while (nullptr != next) {
            if (0 == next->data % 2) {
            }
            next = next->next;
        }
        std::cout << std::endl;
        return head;
    }

    void Reverse_Sublists_Operations() {
        Node<int>* list = InitList({ 1, 2, 8, 9, 12, 16 });
        PrintList(list);
        Node<int>* result = _reserve_sublists(list);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<T>* _make_reverse_list(Node<T>* root) {
        Node<int>* prev = new Node<int>(root->data);

        Node<int>* node = root->next;
        while (nullptr != node) {
            Node<int>* current = new Node<int>(node->data, prev);
            prev = current;
            node = node->next;
        }
        return prev;
    }

    void Make_Reversed_FromList() {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });

        PrintList(root);
        root = _make_reverse_list(root);
        PrintList(root);
    }


    template<typename T>
    size_t _get_length(Node<T>* root) {
        size_t len = 0;
        while (nullptr != root) {
            root = root->next;
            len++;
        }
        return len; // Return root
    }

    template<typename T>
    size_t _get_length_2(const Node<T>* root) {
        return nullptr == root ? 0 : 1 + _get_length_2(root->next);
    }

    void GetLength() {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9 });
        PrintList(root);
        std::cout << "Length: " << _get_length(root) << std::endl;
        std::cout << "Length: " << _get_length_2(root) << std::endl;
    }

    void findMiddle(const Node<int>* root) {
        size_t steps = 0;
        const Node<int>* mid = root;
        while (nullptr != root) {
            root = root->next;
            if (0 == (steps++) % 2)
                mid = mid->next;
        }
        std::cout << mid->data << std::endl;
    }

    void findMiddle2(const Node<int>* root) {
        const Node<int>* slow = root, *fast = root;
        while (nullptr != fast && nullptr != fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        std::cout << slow->data << std::endl;
    }

    void FindMiddleElement() {
        Node<int>* root = InitList({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });

        findMiddle(root);
        findMiddle2(root);

    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* merge_recursion(Node<T>* node1, Node<T>* node2) {
        if (nullptr == node1)
            return node2;
        else if (nullptr == node2)
            return node1;

        if (node1->data < node2->data) {
            node1->next = merge_recursion(node1->next, node2);
            return node1;
        }
        else {
            node2->next = merge_recursion(node1, node2->next);
            return node2;
        }
    }

    void Merge_Two_Lists() {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        PrintList(list1);
        PrintList(list2);
        Node<int>* result = merge_recursion(list1, list2);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    Node<int>* merge(Node<int>* node1, Node<int>* node2);

    Node<int>* merge2(Node<int>* node1, Node<int>* node2) {
        node1->next = merge(node1->next, node2);
        return node1;
    }

    Node<int>* merge(Node<int>* node1, Node<int>* node2) {
        if (nullptr == node1)
            return node2;
        else if (nullptr == node2)
            return node1;
        return node1->data < node2->data ? merge2(node1, node2) : merge2(node2, node1);
    }

    void Merge_Two_Lists_2() {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        PrintList(list1);
        PrintList(list2);
        Node<int>* result = merge(list1, list2);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* merge_recursion_non_recur(Node<T>* node1,
                                         Node<T>* node2)
    {
        Node<int>* root = nullptr;
        if (node1->data < node2->data) {
            root = node1;
            node1 = node1->next;
        } else {
            root = node2;
            node2 = node2->next;
        }

        Node<int>* node = root;
        while (node1 && node2)
        {
            if (node1->data < node2->data) {
                node->next = node1;
                node1 = node1->next;
            }
            else {
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }

        return root;
    }

    void Merge_Two_Lists_NonRecursive()
    {
        Node<int>* list1 = InitList({ 0,2,4,6,8,10,12,14 });
        Node<int>* list2 = InitList({ 1,3,5,7,9,11,13,15 });

        const Node<int>* result = merge_recursion_non_recur(list1, list2);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _insert_into_sorted_list(Node<T>* root, T value) {
        Node<T>* node = root, * previous = nullptr, * newNode = new Node<T>(value);
        if (nullptr == node)
            return newNode;
        else if (node->data > value) {
            newNode->next = node;
            node = newNode;
            return node;
        }

        while (nullptr != node) {
            if (node->data > value) {
                newNode->next = node;
                previous->next = newNode;
                break;
            }
            previous = node;
            node = node->next;
        }
        return root;
    }

    void Insert_Into_Sorted_List() {
        {
            Node<int>* list = InitList({ 1,2,4,6,8,10,12,14 });
            PrintList(list);

            Node<int>* result = _insert_into_sorted_list(list, 9);
            PrintList(result);
        }
        {
            Node<int>* list = InitList({ 1,2,4,6,8,10,12,14 });
            PrintList(list);

            Node<int>* result = _insert_into_sorted_list(list, 0);
            PrintList(result);
        }
        {
            Node<int>* list = nullptr;
            PrintList(list);

            Node<int>* result = _insert_into_sorted_list(list, 11);
            PrintList(result);
        }
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _insert_into_sorted_list_2(Node<T>* root, T value) {
        Node<T>* newNode = new Node<T>(value);
        if (nullptr == root || root->data > value) {
            newNode->next = root;
            return newNode;
        }

        Node<T>* previous = root, * next = root->next;
        while (nullptr != next) {
            if (next->data > value) {
                newNode->next = next;
                previous->next = newNode;
                return root;
            }

            previous = next;
            next = previous->next;
        }
        return root;
    }

    void Insert_Into_Sorted_List_2() {
        Node<int>* list = InitList({ 1,2,4,6,8,10,12,14 });
        PrintList(list);

        Node<int>* result = _insert_into_sorted_list_2(list, 9);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _insert_into_sorted_list_3(Node<T>* root, T value)
    {
        Node<T>* const new_node = new Node<T>(value);
        if (nullptr == root || root->data > value) {
            new_node->next = root;
            return new_node;
        }

        Node<T> *node = root->next, *prev = root;
        while (nullptr != node && node->data <= value) {
            prev = node;
            node = node->next;
        }

        prev->next = new_node;
        new_node->next = node;

        return root;
    }

    void Insert_Into_Sorted_List_3()
    {
        Node<int>* list = InitList({ 1,2,4,6,8,10,12,14 });
        PrintList(list);

        Node<int>* result = _insert_into_sorted_list_3(list, 9);
        PrintList(result);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>*  _delete_nodes(Node<T>* root, const T value) {
        Node<T>* next = root->next, * prev = nullptr;
        while (nullptr != root && value == root->data)
            root = root->next;

        prev = root;
        next = nullptr != root ? root->next : nullptr;

        while (nullptr != next) {
            if (value != next->data) {
                prev->next = next;
                prev = prev->next;
            }
            next = next->next;
        }
        return root;
    }

    void DeleteNodes_ByValue()
    {
        for (const std::vector<int>& data: std::vector<std::vector<int>> {
                { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,5,5 }
        })
        {
            Node<int>* list = InitList(data);
            PrintList(list, "  -->  ");
            PrintList(_delete_nodes(list, 5), "\n\n");
        }
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _delete_nodes_2(Node<T>* root, const T value) {
        while (nullptr != root && value == root->data)
            root = root->next;

        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root;
    }

    void DeleteNodes_ByValue2()
    {
        for (const std::vector<int>& data: std::vector<std::vector<int>> {
                { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,1,5,5,2,4,5,5,5,7,8,9 }, { 5,5,5 }
        })
        {
            Node<int>* list = InitList(data);
            PrintList(list, "  -->  ");
            PrintList(_delete_nodes_2(list, 5), "\n\n");
        }
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _delete_nodes_3(Node<T>* root, const T value) {
        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root && root->data == value ? root->next : root;
    }

    void DeleteeNodes_ByValue3() {
        Node<int>* list = InitList({ 5,5,5,1,5,5,2,4,5,5,5,7,8,9 });
        PrintList(list, "  -->  ");
        list = _delete_nodes_3(list, 5);
        PrintList(list);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* _delete_node_by_pos(Node<T>* root, size_t pos) {
        // TODO: return root->next IF pos == 0
        Node<T>* node = root;
        while (nullptr != node && node->next != nullptr) {
            pos--;
            if (0 == pos) {
                node->next = node->next->next;
                return root;
            }
            node = node->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* _delete_node_by_pos_2(Node<T>* root, size_t pos) {
        // TODO: return root->next IF pos == 0
        Node<T>* previous = root, *current = root ? root->next : nullptr;
        while (nullptr != current) {
            pos--;
            if (0 == pos) {
                previous->next = current->next;
                return root;
            }
            previous = current;
            current = previous->next;
        }
        return root;
    }

    template<typename T>
    Node<int>* _delete_node_by_pos_3(Node<T>* root, size_t pos) {
        if (0 == pos)
            return root->next;

        Node<T>* previous = root;
        while (nullptr != root) {
            if (pos--)
                previous = root;
            else {
                previous->next = root->next;
                break;
            }
            root = previous->next;
        }
    }


    void DeleteeNodes_By_Position() {
        {
            Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
            PrintList(list, "  -->  ");
            list = _delete_node_by_pos(list, 1);
            PrintList(list);
        }
        {
            Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
            PrintList(list, "  -->  ");
            list = _delete_node_by_pos(list, 8);
            PrintList(list);
        }
        {
            Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
            PrintList(list, "  -->  ");
            list = _delete_node_by_pos_2(list, 1);
            PrintList(list);
        }
        {
            Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
            list = nullptr;
            PrintList(list, "  -->  ");
            _delete_node_by_pos_3(list, 1);
            PrintList(list);
        }
    }

    //----------------------------------------------------------------------------------

    template<typename T>
    Node<int>* _delete_K_node_from_the_end(Node<T>* root, int K) {
        Node<T>* node = root, * tmp{ nullptr };
        while (nullptr != node) {
            if (K-- == 0)
                tmp = root;
            else if (K < 0) {
                tmp = tmp->next;
            }
            node = node->next;
        }
        tmp->next = tmp->next->next;
        return root;
    }

    void Delete_K_Element_From_the_End() {
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
        PrintList(list, "  -->  ");
        list = _delete_K_node_from_the_end(list, 2);
        PrintList(list);
    }

    //----------------------------------------------------------------------------------


    template<typename T>
    Node<int>* _move_to_the_end(Node<T>* root, const T value) {
        while (nullptr != root && value == root->data)
            root = root->next;

        Node<T>* tail = nullptr;
        Node<T>* current = root, * previous = nullptr;
        while (nullptr != current) {
            if (value == current->data) {
                previous->next = current->next;
                if (nullptr == tail)
                    tail = current;
                else
                    tail->next = current;
            }
            else {
                previous = current;
            }
            current = previous->next;
        }

        std::cout << previous->data << std::endl;

        return root;
    }


    void MoveAllOccurrencesToTheEnd_TEST() {
        Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
        PrintList(list);
        list = _move_to_the_end(list, 2);
        PrintList(list);
    }

    //----------------------------------------------------------------------//

    template<typename T>
    Node<int>* delete_duplices(Node<T>* root) {
        Node<T>* prev = root, * next = nullptr != root ? root->next : nullptr;
        std::unordered_set<T> tmp = { root->data };

        while (nullptr != next) {
            if (true == tmp.insert(next->data).second) {
                prev->next = next;
                prev = prev->next;
            }
            next = next->next;
        }
        return root;
    }

    template<typename T>
    void remove_duplicates(Node<T>* node) {
        Node<T>* previous = nullptr;
        std::unordered_set<T> tmp;

        while (nullptr != node) {
            if (false == tmp.insert(node->data).second)
                previous->next = node->next;
            else
                previous = node;
            node = previous->next;
        }
    }

    template<typename T>
    void remove_duplicates_2(Node<T>* node) {
        Node<T>* previous = nullptr;
        std::unordered_set<T> tmp;

        while (nullptr != node) {
            if (false == tmp.insert(node->data).second) {
                previous->next = node->next;
                node = previous->next;
            }
            previous = node;
            if (nullptr == node)
                return;
            node = node->next;
        }
    }

    void Delete_Duplicates()
    {
        std::cout << "--------------------- Test1: ------------------\n" << std::endl;
        {
            Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
            PrintList(list, "  -->  ");
            PrintList(delete_duplices(list), "\n\n");
        }
        std::cout << "\n--------------------- Test2: ------------------\n" << std::endl;
        {
            Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
            PrintList(list, "  -->  ");
            remove_duplicates(list);
            PrintList(list);
        }
        std::cout << "\n--------------------- Test3: ------------------\n" << std::endl;
        {
            Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,7,8 });
            PrintList(list, "  -->  ");
            remove_duplicates_2(list);
            PrintList(list);
        }
    }

    //----------------------------------------------------------------------//

    template<typename T>
    void remove_duplicates_sorted(Node<T>* node) {
        Node<T>* previous = nullptr;
        while (nullptr != node) {
            if (node->next && node->data == node->next->data)
                previous->next = node->next;
            else
                previous = node;
            node = previous->next;
        }
    }

    void Delete_Duplicates_InSortedList() {
        Node<int>* list = InitList({ 1,2,3,3,4,5,6,6,6,6,7,8 });
        PrintList(list, "  -->  ");
        remove_duplicates_sorted(list);
        PrintList(list);
    }

    //----------------------------------------------------------------------//

    void Reverse_Even_Subarrays()
    {
        Node<int>* list = InitList({ 2, 18, 24, 3, 5, 7, 9, 6, 12 }); // -> 24, 18, 2, 3, 5, 7, 9, 12, 6
        Node<int>* node = list;

        Node<int>* start = nullptr, * end = nullptr;
        std::vector<int> values;
        while (nullptr != node) {
            std::cout << node->data << std::endl;

            if (0 == node->data % 2) {
                values.push_back(node->data);
                if (nullptr == start)
                    start = node;
                end = node;
            }
            else {
                std::reverse(values.begin(), values.end());
                for (int i : values) {
                    start->data = i;
                    start = start->next;
                }
                start = nullptr;
                end = nullptr;
                values.clear();
            }
            node = node->next;
        }

        std::reverse(values.begin(), values.end());
        for (int i : values) {
            start->data = i;
            start = start->next;
        }
    }

    //---------------------------------------------------------------------------------//

    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end(Node<T>* root, T value) {
        assert(nullptr != root);
        Node<int>* start = nullptr, * tmp1 = nullptr;
        Node<int>* tail = nullptr, * tmp2 = nullptr;
        while (nullptr != root) {
            if (value != root->data) {
                if (nullptr == start) {
                    start = root;
                    tmp1 = start;
                }
                else {
                    tmp1->next = root;
                    tmp1 = tmp1->next;
                }
            }
            else {
                if (nullptr == tail) {
                    tail = root;
                    tmp2 = tail;
                }
                else {
                    tmp2->next = root;
                    tmp2 = tmp2->next;
                }
            }
            root = root->next;
        }
        tmp2->next = nullptr;
        tmp1->next = tail;
        return start;
    }

    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_GOOD_BEST(Node<T>* root, const T value)
    {
        Node<T> *node1 {nullptr}, *start { nullptr }, *node2 {nullptr}, *tail {  nullptr };
        while (root)
        {
            if (value != root->data) {
                if (!node1)
                    start = node1 = root;
                else {
                    node1->next = root;
                    node1 = node1->next;
                }
            }
            else {
                if (!node2)
                    tail = node2 = root;
                else {
                    node2->next = root;
                    node2 = node2->next;
                }
            }
            root = root->next;
        }

        node2->next = nullptr;
        node1->next = tail;

        return start;
    }



    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_2(Node<T>* root, T value) {
        assert(nullptr != root);
        Node<int>* start = nullptr, * tmp1 = nullptr;
        Node<int>* tail = nullptr, * tmp2 = nullptr;
        while (nullptr != root) {
            if (value != root->data) {
                if (nullptr == start) {
                    start = root;
                    tmp1 = start;
                }
                else {
                    tmp1->next = root;
                    tmp1 = tmp1->next;
                }
            }
            else {
                if (nullptr == tail) {
                    tail = root;
                    tmp2 = tail;
                }
                else {
                    tmp2->next = root;
                    tmp2 = tmp2->next;
                }
            }
            root = root->next;
        }
        tmp2->next = nullptr;
        tmp1->next = tail;
        return start;
    }

    template<typename T>
    Node<int>* __move_all_occurrences_to_th_end_TEST(Node<T>* root,
                                                     T value)
    {
        Node<T>* tailRoot, *tail = nullptr;
        if (value == root->data) {
            tail = (tailRoot = root);
            root = root->next;
        }

        Node<T>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data) {
                previous->next = current->next;
                if (!tail)
                    tail = (tailRoot = current);
                else {
                    tail->next = current;
                    tail = tail->next;
                }
            }
            else
                previous = current;
            current = previous->next;
        }

        tail->next = nullptr;
        previous->next = tailRoot;
        return root;
    }

    void MoveAllOccurrencesToTheEnd()
    {
        /*
		{
			Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
			PrintList(list);
			Node<int>* result = __move_all_occurrences_to_th_end(list, 2);
			PrintList(result);
		}
        */

        /** Best solution so far**/
        {
            Node<int>* list = InitList({2,2,2,1,1});
            PrintList(list);
            Node<int>* result = __move_all_occurrences_to_th_end_GOOD_BEST(list, 2);
            PrintList(result);
        }


        /*
		{
			Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
			PrintList(list);
			Node<int>* result = __move_all_occurrences_to_th_end_2(list, 2);
			PrintList(result);
		}
        {
            Node<int>* list = InitList({ 2,2,2,2,3,4,5,6,7,2,2,2,8,9,10 });
            //PrintList(list);
            Node<int>* result = __move_all_occurrences_to_th_end_TEST(list, 2);
            PrintList(result);

        }
        */
    }
}

namespace LinkedListAlgorithms::JustTests
{

    // Delete node by values
    template<typename T>
    Node<int>* _delete_node_(Node<T>* root, const T value) {
        while (nullptr != root && root->data == value)
            root = root->next;

        Node<int>* previous = root, * current = root ? root->next : nullptr;
        while (nullptr != current) {
            if (value == current->data)
                previous->next = current->next;
            else
                previous = current;
            current = previous->next;
        }
        return root;
    }

    // Delete node by values
    template<typename T>
    Node<int>* _reverse_(Node<T>* node) {
        Node<int>* previous = nullptr, * next = node;
        while (nullptr != node) {
            next = node->next;

            node->next = previous;
            previous = node;

            node = next;
        }
        return previous;
    }

    template<typename T>
    Node<T>* _reverse_test(Node<T>* root) {
        // void  _reverse_test(Node<T>* root) {
        assert(nullptr != root);
        Node<int>* previous = nullptr, * next = nullptr, * node = root;
        while (nullptr != node) {
            next = node->next;
            node->next = previous;
            previous = node;
            node = next;
        }
        return previous;
    }

    template<typename T>
    Node<T>* _reverse_test_rec(Node<T>* root, Node<T>* prev = nullptr) {
        root->next->next = prev;
        return root->next;
    }

    void SOME_TESTS() {
#if 0   // Delete list test //
        Node<int>* list = InitList({ 5,1,5,5,2,4,5,5,5,7,8,9 });
		PrintList(list);
		list = _delete_node_(list, 5);
		PrintList(list);
#endif

#if 0   // Reverse list test 1 //
        Node<int>* list = InitList({ 1,2,3,4,5 });
		PrintList(list);
		list = _reverse_(list);
		PrintList(list);
		std::cout << "Done" << std::endl;
#endif

#if 0   // Reverse list test 2 //
        Node<int>* list = InitList({ 1,2,3,4,5,6,7,8,9 });
		PrintList(list);
		list = _reverse_test(list);
		PrintList(list);
		std::cout << "Done" << std::endl;
#endif



        auto* root = new Node<int>(0);;
        Node<int>* node = root;

        for (int i = 1; i < 10; ++i)
        {
            node->next = new Node<int>(i);
            node = node->next;
        }

        PrintList(root);

    }
}



void LinkedListAlgorithms::Other() {

}