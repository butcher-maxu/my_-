/*
现有一链表头指针，给一个定值x，编写一段代码将所有小于x的节点排在其余节点之前，
且不改变相对顺序，返回重新排列后的链表头指针。
示例：
输入：{1,4,3},4
输出: {1，3，4}

*/

#include <iostream>

// 链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode *smallerHead =
        new ListNode(0); // 哨兵节点，指向小于x的节点链表的头指针
    ListNode *smallerTail = smallerHead; // 指向小于x的节点链表的尾指针
    ListNode *greaterHead =
        new ListNode(0); // 哨兵节点，指向大于等于x的节点链表的头指针
    ListNode *greaterTail = greaterHead; // 指向大于等于x的节点链表的尾指针

    ListNode *curr = head; // 当前遍历的节点指针

    while (curr != nullptr) {
        if (curr->val < x) {
            // 当前节点小于x，将节点链接到小于x的链表中
            smallerTail->next = curr;
            smallerTail = curr;
        } else {
            // 当前节点大于等于x，将节点链接到大于等于x的链表中
            greaterTail->next = curr;
            greaterTail = curr;
        }

        curr = curr->next;
    }

    greaterTail->next =
        nullptr; // 将大于等于x的链表尾指针指向nullptr，防止出现环

    smallerTail->next =
        greaterHead->next; // 将小于x的链表和大于等于x的链表连接起来

    // 返回重新排列后的链表头指针（去掉哨兵节点）
    return smallerHead->next;
}

// 创建链表
ListNode *createLinkedList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// 打印链表
void printLinkedList(ListNode *head) {
    ListNode *curr = head;

    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, n);

    std::cout << "原始链表：";
    printLinkedList(head);

    int x = 4;

    ListNode *newHead = partition(head, x);

    std::cout << "重新排列后的链表：";
    printLinkedList(newHead);

    return 0;
}