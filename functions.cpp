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
                if (result[j] >= vctIn[i]) {
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


/**********************************************/
/* Solution 1: traverse list and get the position */
/* Solution 2: Use two pointer */
/**********************************************/
listNode *deleteLastNNode(listNode *head, int n) {
    if (!head)
        return nullptr;
    int len = 0;
    listNode* p = head;
    vector<listNode*> vct_addresses;
    while (p->next) {
        vct_addresses.push_back(p);
        p = p->next;
        len++;
    }
    vct_addresses.push_back(nullptr);
    int m = len - n;
    if (m > 0) {
        vct_addresses[m-1]->next = vct_addresses[m+1];
        vct_addresses[m]->next = nullptr;
        return head;
    } else if (m == 0) {
        listNode* temp = head->next;
        head->next = nullptr;
        return temp;
    } else
        return nullptr;
}

listNode *deleteLastNNodePlus(listNode *head, int n) {
    listNode* p_first = head;
    listNode* p_second = head;
    for (int i = 0; p_first != nullptr && i < n; p_first = p_first->next, i++) {
        if (i == n)
            break;
    }
    if (!p_first)
        return nullptr;
    listNode* prev = nullptr;
    while (p_first->next) {
        prev = p_second;
        p_second = p_second->next;
        p_first = p_first->next;
    }
    if (prev) {
        prev->next = p_second->next;
        p_second->next = nullptr;
        return head;
    } else {
        prev = p_second->next; // 此时用prev作为临时变量
        p_second->next = nullptr;
        return prev;
    }
}

int binarySearch(vector<int>& nums, int num) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;   // 取中间位置直接折中就行了不要写成 low + (high - low) / 2
        if (nums[mid] == num)
            return mid;
        else if (nums[mid] < num)
            low = mid + 1;  // 注意这里要 +1
        else
            high = mid - 1;  // 注意 -1
    }
    return -1;
}

/*******************************************************************************/




int sum(vector<int>& nums) {
    int res = 0;
    for (auto num : nums) {
        if (num > 0)
            res += (num+1)/2;
    }
    return res;
}

/*int minimumPart(vector<int>& nums) {
    int res = 0;
    bool int_flag = false; // 表示当前是否存在整牌
    for (int i = 0; i < 8; i++) {
        vector<int> temp = nums;
        bool flag = true;
        int temp_res = 0;

        // 检查是否存在连对
        for (int j = i; j < i+3; j++) {
            if (temp[j] != 2) {
                flag = false;
                break;
            } else
                temp[j] -= 2;
        }
        if (flag) {
            int_flag = true;
            temp_res = 1 + minimumPart(temp);
            if (res == 0 || temp_res < res)
                res = temp_res;
        }

        if (i < 6) {
            temp = nums;
            flag = true;
            // 检查是否存在顺子
            for (int j = i; j < i+5; j++) {
                if (temp[j] == 0) {
                    flag = false;
                    break;
                } else
                    temp[j]--;
            }
            if (flag) {
                int_flag = true;
                temp_res = 1 + minimumPart(temp);
                if (res == 0 || temp_res < res)
                    res = temp_res;
            }
        }
    }
    if (!int_flag)
        return sum(nums); // 如果不存在整牌返回数组中大于零的元素的个数
    else
        return res;
}*/

int minimumNumber(vector<int>& nums) {
    int res = 0;
    bool int_flag = false; // 表示当前是否存在整牌
    for (int i = 0; i < 8; i++) {
        vector<int> temp = nums;
        bool flag = true;
        int temp_res = 0;

        // 检查是否存在连对
        for (int j = i; j < i+3; j++) {
            if (temp[j] != 2) {
                flag = false;
                break;
            } else
                temp[j] -= 2;
        }
        if (flag) {
            int_flag = true;
            temp_res = 1 + minimumNumber(temp);
            if (res == 0 || temp_res < res)
                res = temp_res;
        }

        if (i < 6) {
            temp = nums;
            flag = true;
            // 检查是否存在顺子
            for (int j = i; j < i+5; j++) {
                if (temp[j] == 0) {
                    flag = false;
                    break;
                } else
                    temp[j]--;
            }
            if (flag) {
                int_flag = true;
                temp_res = 1 + minimumNumber(temp);
                if (res == 0 || temp_res < res)
                    res = temp_res;
            }
        }
    }
    if (!int_flag)
        return sum(nums); // 如果不存在整牌返回数组中大于零的元素的个数
    else
        return res;
}


