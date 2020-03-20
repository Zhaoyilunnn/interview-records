#include <iostream>
#include "functions.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    // test findKMax --> ByteDance -- 02/20/2020
   // treeNode* k_res = nullptr;
   // treeNode root, left, left_left, left_right, right, right_right;
   // root.val = 4;
   // left.val = 2;
   // left_left.val = 1;
   // left_right.val = 3;
   // right.val = 5;
   // right_right.val = 6;
   // root.left = &left;
   // root.right = &right;
   // left.left = &left_left;
   // left.right = &left_right;
   // right.right = &right_right;
   // k_res = findKMax(3, &root);
   // cout << "3rd max element is" << k_res->val << endl;
    // test findKMax

    // test erase --> DingDing -- 02/25/2020
   // vector<int> vctTest = {};
   // erase(vctTest, 4);

    // test symmetryTree --> Tencent -- 02/25/2020
   // auto* root = new treeNode(1);
   // root->left = new treeNode(2);
   // root->right = new treeNode(2);
   // root->left->left = new treeNode(3);
   // root->left->right = new treeNode(4);
   // root->right->right = new treeNode(3);
   // root->right->left = new treeNode(4);
   // root->left->left->left = new treeNode(5);
   // root->right->right->right = new treeNode(5);
   // bool result = symmetryTree(root);
   // if (result)
   //     cout << "The tree is symmetrical" << endl;
   // else
   //     cout << "The tree is asymmetrical" << endl;

    /*test reverseStr --> ByteDance -- 03/02/2020*/
/*
    string strTest = "@@hello@world@";
    auto strRes = reverseStr(strTest);
*/
   /* test insert sort --> ByteDance -- 03/02/2020*/
/*
    vector<int> vctTest = {3, 4, 6, 7, 7, 6, 11, 1, 3, 5, 7, 9};
    vector<int> vctRes = insertSort(vctTest);
*/
    vector<int> test = {4, 2, 2, 3, 2, 2, 2, 2, 1, 1};
    int res = minimumNumber(test);
    return 0;

}
