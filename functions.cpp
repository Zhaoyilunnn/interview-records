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


/*****************************************************************/
/* Solution:    traverse, if str1[i] != str2[i],
 *                  for j = i+1 : n
 *                      if str1[j] != str1[i] && str2[j] != str2[i]
 *                          swap
 *                          */
/*****************************************************************/
int minOperations(string& str1, string& str2) {
    int res = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            bool flag = true;
            for (int j = i+1; j < str1.size(); j++) {
                if (str1[j] != str1[i] && str2[j] != str2[i]) {
                    char temp = str1[j];
                    str1[j] = str1[i];
                    str1[i] = temp;
                    flag = false;
                    res++;
                    break;
                }
            }
            if (flag) {
                str1[i] = str2[i];
                res++;
            }
        }
    }
    return res;
}


/*****************************************************************/
/* Description: Dynamic programming a[i][j] comes from a[i-1][j-2]
 * and a[i][j-3] */
/*****************************************************************/
double rate(int a, int b) {
    vector<double> init(b+1, 0);
    vector<vector<double>> stores(a+1, init);
    for (int i = 0; i < a+1; i++)
        stores[i][0] = 1.0;
    for (int i = 0; i < b+1; i++)
        stores[0][i] = 0.0;
    for (int i = 1; i < a+1; i++) {
        for (int j = 1; j < b+1; j++) {
            auto x = (double)i;
            auto y = (double)j;
            double win_first = x / (x + y);
            double win_second_1 = 0;
            double win_second_2 = 0;
            if (y >= 3) win_second_1 = y / (x + y) * (y - 1) / (x + y - 1) * (y - 2) / (x + y - 2) * stores[i][j-3];
            if (y >= 2) win_second_2 = y / (x + y) * (y - 1) / (x + y - 1) * x / (x + y - 2) * stores[i-1][j-2];
            stores[i][j] = win_first + win_second_1 + win_second_2;
        }
    }
    return stores[a][b];
}

int maxStringLength(vector<string> &Str, int num) {
    vector<string> init;
    vector<vector<string>> strMap(26, init);
    for (auto ch : Str)
        strMap[ch[0] - 'a'].push_back(ch);
    // DFS
    int result = 0;
    int temp = 0;
    stack<pair<int, int>> combinations;
    // push the first set of element;
    for (int i = 0; i < strMap.size(); i++) {
        if (!strMap[i].empty()) {
            for (int j = 0; j < strMap[i].size(); j++)
                combinations.push(make_pair(i, j));
            break;
        }
    }

    // how to store the length??
    vector<int> lengths;
    while (!combinations.empty()) {
        int m = combinations.top().first;
        int n = combinations.top().second;
        string word = strMap[m][n];
        temp += word.size();
        combinations.pop();

        bool flag = true;  // whether reach the end of the graph
        for (int i = word[word.size()-1] - 'a'; i < 26; i++) {
            if (!strMap[i].empty()) {
                flag = false;
                for (int j = 0; j < strMap[i].size(); j++)
                    combinations.push(make_pair(i, j));
                break;
            }
        }
        if (flag)
            temp -= word.size();
    }
    return 0;
}


int numRoute(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int result = 0;
    vector<int> prev_row;
    for (int i = 1; i < m; i++) {
        vector<int> row(n, 0);
        result = 0;
        for (int j = 1; j < n; j++) {
            result += prev_row[j];
            row.push_back(result);
        }
        prev_row = row;
    }
    return result;
}


string addStr(string& s1, string& s2) {
    string res;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int flag = 0;
    int sum = 0;
    char curr_digit;
    while (i >= 0 && j >= 0) {
        int d1 = s1[i] - '0';
        int d2 = s2[j] - '0';
        sum = d1 + d2 + flag;
        if (sum >= 10) {
            curr_digit = sum - 10 + '0';
            flag = 1;
        } else {
            curr_digit = sum + '0';
            flag = 0;
        }
        res.insert(res.begin(), curr_digit);
        i--;
        j--;
    }
    while (i >= 0) {
        sum = s1[i] - '0' + flag;
        if (sum >= 10) {
            res.insert(res.begin(), sum - 10 + '0');
            flag = 1;
        }
        else {
            res.insert(res.begin(), sum + '0');
            flag = 0;
        }
        i--;
    }
    while (j >= 0) {
        sum = s2[j] - '0' + flag;
        if (sum >= 10) {
            res.insert(res.begin(), sum - 10 + '0');
            flag = 1;
        }
        else {
            res.insert(res.begin(), sum + '0');
            flag = 0;
        }
        j--;
    }
    if (flag) res.insert(res.begin(), '1');
    return res;
}


bool isCircleList(ListNode* head) {
    set<ListNode*> addresses;
    while (head) {
        if (addresses.end() != addresses.find(head->next))
            return true;
        addresses.insert(head);
        head = head->next;
    }
    return false;
}


int maxRemainder(vector<int>& nums, int m) {
    int n = nums.size();
    int res = 0;
    vector<bool> dp(m, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[j]) {
                int temp = (nums[i] + j) % m;
                dp[temp] = true;
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        if (dp[i]) return i;
    }
    return res;
}


int select(int N, int M) {
    int res = N;
    for (int i = N - 1; i > M; i--) {
        res *= i;
    }
    for (int j = N - M; j > 1; j--) {
        res /= j;
    }
    return res;
}

int numTrees(vector<int>& nums) {
    int N = nums.size();
    unordered_map<int, int> level_num;
    int depth = 0;
    for (int i = 0; i < N; i++) {
        auto it = level_num.find(nums[i]);
        depth = max(depth, nums[i]);
        if (it == level_num.end()) level_num.emplace(nums[i], 1);
        else it->second++;
    }
    int res = 1;
    int pre = 1;
    for (int i = 1; i <= depth; i++) {
        auto it = level_num.find(i);
        if (it == level_num.end()) return 0;
        if (it->second == 2 * pre) {
            pre = it->second;
            continue;
        }
        int multiple = select(2*pre, it->second);
        res *= multiple;
        pre = it->second;
    }
    return res % ((int)pow(10, 9) + 7);
}


string reverseStr(const string& str) {
    string res;
    int start = str.size() - 1, end = str.size() - 1;
    while (end >= 0) {
        if (str[end] != ' ') break;
        end--;
    }
    start = end;
    int i = end;
    while (i >= 0) {
        if (end >= start) {
            if (str[i] != ' ') start--;
            else {
                res.insert(res.end(), str.begin() + start + 1, str.begin() + end + 1);
                res.push_back(' ');
                end = start;
                start++;
                i++;
            }
        } else {
            if (str[i] != ' ') {
                start = end;
                i++;
            }
            else end--;
        }
        i--;
    }
    if (str[0] != ' ') res.insert(res.end(), str.begin() + start + 1, str.begin() + end + 1);
    return res;
}


pair<int, int> numGood(int num, vector<int>& nums) {
    vector<pair<int, int>> dp(num, make_pair(0, 0));
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) dp[0] = make_pair(nums[0], 1);
        else if (i == 1) dp[1] = make_pair(max(nums[0], nums[1]), 1);
        else {
            int temp = dp[i - 2].first + nums[i];
            if (temp > dp[i - 1].first) {
                dp[i].first = temp;
                dp[i].second = dp[i - 2].second + 1;
            } else if (temp == dp[i - 1].first) {
                dp[i].first = temp;
                dp[i].second = min(1 + dp[i - 2].second, dp[i - 1].second);
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[num - 1];
}


TreeNode* buildTree(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, l, mid - 1);
    root->right = buildTree(nums, mid + 1, r);
    return root;
}

vector<int> findVal(TreeNode* root, int val) {
    TreeNode* p = root;
    vector<int> res;
    while (p) {
        res.push_back(p->val);
        if (p->val == val) break;
        else if (p->val > val) p = p->left;
        else p = p->right;
    }
    return res;
}


/**
 * 思路：
 *      从前往后和从后往前分别求最长下降序列down[]和up[]
 *      for i = 0 : n - 1:
 *          for j = i + 1 : n - 1:
 *              if nums[i] == nums[j]:
 *                  res = max(res, 2 * min(down[i], up[j]))
 * @param nums
 * @return
 */
int maxValley(vector<int>& nums) {
    int n = nums.size();
    vector<int> down(n, 0);
    vector<int> up(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            down[0] = 1;
            up[n - 1] = 1;
        }
        else {
            int temp1 = 0;
            int temp2 = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) temp1 = max(down[j], temp1);
                if (nums[n - 1 - i] < nums[n - 1 - j]) temp2 = max(up[n - 1 - j], temp2);
            }
            down[i] = temp1 + 1;
            up[n - 1 - i] = temp2 + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                res = max(res, 2 * min(down[i], up[j]));
            }
        }
    }
    return res;
}


vector<vector<int>> directs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void dfs(int x, int y, int x2, int y2, int n, int cur_res, int& res, vector<vector<int>>& visited, vector<string>& matrix) {
    if (res >= 0 && cur_res >= res) return;
    if (x == x2 && y == y2) {
        if (res < 0) res = cur_res;
        else res = min(cur_res, res);
        return;
    }
    for (auto d : directs) {
        int a = x + d[0], b = y + d[1];
        if (a >= 0 && a < n && b >= 0 && b < n && !visited[a][b] && matrix[a][b] != '#' && matrix[a][b] != '@') {
            visited[a][b] = 1;
            dfs(a, b, x2, y2, n, cur_res + 1, res, visited, matrix);
            visited[a][b] = 0;
        }
    }
}


int bestPath(int x1, int y1, int x2, int y2, vector<string>& matrix) {
    int res = -1;
    int cur_res = 0;
    int n = matrix.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[x1][y1] = 1;
    dfs(x1, y1, x2, y2, n, cur_res, res, visited, matrix);
    return res;
}



vector<int> maxIncreaseSequence(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>());
    vector<int> res;
    for (int i = 0; i < n; i++) {
        dp[i] = {nums[i]};
    }
    for (int i = 0; i < n; i++) {
        int l = dp[i].size();
        for (int j = i + 1; j < n; j++) {
            if (nums[j] >= dp[i][l - 1] && dp[j].size() < l + 1) {
                vector<int> temp = dp[i];
                temp.push_back(nums[j]);
                dp[j] = temp;
            }
        }
    }
    int max_length = 0;
    for (const auto& d : dp) {
        if (d.size() > max_length) {
            max_length = d.size();
            res = d;
        }
    }
    return res;
}