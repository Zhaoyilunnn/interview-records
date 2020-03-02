//
// Created by zyl on 2020/2/27.
//

#ifndef INTERVIEW_ACCUMULATE_FUNCTIONS_H
#define INTERVIEW_ACCUMULATE_FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

struct treeNode {
    treeNode* right = nullptr;
    treeNode* left = nullptr;
    int val = 0;
    explicit treeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// ByteDance, 02/20/2020, 找到有序二叉树的第K大的元素, 似乎中序遍历就可以了...
treeNode* findKMax(int k, treeNode* root);
// ByteDance, 02/20/2020

// DingDing 02/25/2020
// task 1 --> 假设一个很大数据，比如100万的vector<int>元素都是10以内的整数，写一个函数删除某个元素
//            注意在erase之后要保存it的位置
void erase(vector<int>& vctNums, int num);
// task 2 --> 写一个memcpy
void *memcpy(void* dest, const void* val, std::size_t count);
// DingDing 02/25/2020

// Tencent 02/25/2020 判断二叉树是否是对称二叉树
bool symmetryTree(treeNode* root);
// Tencent 02/25/2020

// ByteDance 03/02/2020
// task 1 --> 反转字符串, e.g. input > @@hello@world@, output > @world@hello@@
string reverseStr(string& strIn);
// task 2 --> 直接插入排序,
vector<int> insertSort(vector<int>& vctIn);
// ByteDance 03/02/2020

#endif //INTERVIEW_ACCUMULATE_FUNCTIONS_H
