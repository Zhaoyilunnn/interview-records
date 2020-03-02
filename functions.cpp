//
// Created by zyl on 2020/2/27.
//

#include "functions.h"

treeNode* findKMax(int k, treeNode* root) {
    vector<treeNode*> vctTree;
    vector<treeNode*> vctStack;
    treeNode* top = nullptr;
    treeNode* p = root;
    while (nullptr != p) {
        vctStack.push_back(p);
        p = p->left;
    }
    top = vctStack[vctStack.size()-1];
    while (!vctStack.empty()) {
        vctStack.pop_back();
        vctTree.push_back(top);
        if (nullptr != top->right) {
            p = top->right;
            while (nullptr != p) {
                vctStack.push_back(p);
                p = p->left;
            }
        }
        top = vctStack[vctStack.size()-1];
    }
    return vctTree[vctTree.size()-k];
}

void erase(vector<int>& vctNums, int num) {
    vector<int >::iterator start, end;
    start = end = vctNums.end();
    auto it = vctNums.begin();
    auto temp = vctNums.end();
    while (it != vctNums.end()) {
        if (*it == num) {
            if (start == vctNums.end()) {
                start = it;
                end = start;
                temp = it-1;
            } else
                end++;
            it++;
        }
        else if (start != vctNums.end()) {
            if (end == start)
                vctNums.erase(start);
            else
                vctNums.erase(start, end+1);
            start = vctNums.end();
            it = temp+1;
        } else
            it++;
    }
}

void *memcpy(void* dest, const void* val, std::size_t count) {
    char *tmp = (char*)dest;
    const char *s = (char*)val;
    while (count--)
        *tmp++ = *s++ ;
    return dest;
}

bool isSymmetryTree(treeNode* root_first, treeNode* root_second) {
    if (!root_first && !root_second)
        return true;
    if (root_first && root_second) {
        if (root_first->val == root_second->val)
            return isSymmetryTree(root_first->left, root_second->right) && isSymmetryTree(root_first->right, root_second->left);
        else
            return false;
    } else
        return false;
}

bool symmetryTree(treeNode* root) {
    if (!root)
        return true;
    return isSymmetryTree(root->left, root->right);
}

string reverseStr(string& strIn) {
    string strRes;
    string::iterator it;
    string::iterator start = strIn.end();
    string::iterator end = strIn.end();
    for (it = strIn.end()-1; it != strIn.begin(); it--) {
        if (*it == '@') {
            if (end != strIn.end()) {
                start = it + 1;
                strRes += strIn.substr(start-strIn.begin(), end-start+1);
                start = strIn.end();
                end = strIn.end();
            }
            strRes.push_back(*it);
        } else {
            if (end == strIn.end())
                end = it;
        }
    }
    if (*it == '@' && strIn.end() != end) {
        start = it + 1;
        strRes += strIn.substr(start - strIn.begin(), end - start + 1);
    }
    strRes.push_back(*it);
    return strRes;
}

vector<int> insertSort(vector<int>& vctIn) {
    vector<int> result;
    int j = 0;
    for (int i = 0; i < vctIn.size(); i++) {
        if (i == 0)
            result.push_back(vctIn[i]);
        else {
            for (j = 0; j < result.size(); j++) {
                if (result[j] < vctIn[i])
                    continue;
                else {
                    result.insert(result.begin() + j, vctIn[i]);
                    break;
                }
            }
            if (j == result.size())
                result.push_back(vctIn[i]);
        }
    }
    return result;
}


