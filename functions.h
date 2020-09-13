//
// Created by zyl on 2020/2/27.
//

#ifndef INTERVIEW_ACCUMULATE_FUNCTIONS_H
#define INTERVIEW_ACCUMULATE_FUNCTIONS_H

#include <vector>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;

/* definition of tree */
struct treeNode {
    treeNode* right = nullptr;
    treeNode* left = nullptr;
    int val = 0;
    explicit treeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

/* definition of list */
struct listNode {
    int val;
    listNode* next;
};

/* ByteDance 基础架构, 02/20/2020, 找到有序二叉树的第K大的元素, 似乎中序遍历就可以了... */
treeNode* findKMax(int k, treeNode* root);


/* DingDing 02/25/2020 */
// task 1 --> 假设一个很大数据，比如100万的vector<int>元素都是10以内的整数，写一个函数删除某个元素
//            注意在erase之后要保存it的位置
void erase(vector<int>& vctNums, int num);
// task 2 --> 写一个memcpy
void *memcpy(void* dest, const void* val, std::size_t count);


/* Tencent 02/25/2020 判断二叉树是否是对称二叉树 */
bool symmetryTree(treeNode* root);


/* ByteDance 客户端开发 03/02/2020 */
// task 1 --> 反转字符串, e.g. input > @@hello@world@, output > @world@hello@@
string reverseStr(string& strIn);
// task 2 --> 直接插入排序,
vector<int> insertSort(vector<int>& vctIn);


/* Baidu 基础架构 03/19/2020 */
listNode* deleteLastNNode(listNode* head, int n);
listNode* deleteLastNNodePlus(listNode* head, int n);
int binarySearch(vector<int> nums, int num);


/*******************************************/
/* Baidu 搜索架构 03/10/2020                */
/* 待解决                                   */
/*******************************************/
struct Dep {
    int task_id;
    int dep_task_id;
};
/*vector<int> task_execute(vector<Dep> deps) {
    if (deps.empty())
        return {};
    vector<int> result;
    result.push_back(deps[0].dep_task_id);
    result.push_back(deps[0].task_id);
    if (deps.size() == 1)
        return result;
    int dep_post = 0;
    int id_post = 0;
    bool dep_flag = false;
    bool id_flag = false;
    for (int i = 1; i < deps.size(); i++) {
        dep_flag = false;
        id_flag = false;
        for (int j = result.size()-1; j >= 0; j--) {
            if (deps[i].dep_task_id == result[j]) {
                if (!dep_flag) {
                    dep_post = j;
                    dep_flag = true;
                }
            }
            if (deps[i].task_id == result[j]) {
                if (!id_flag) {
                    id_post = j;
                    id_flag = true;
                }
            }
        }
        if (!dep_flag) {
            result.push_back(deps[i].dep_task_id);
            result.push_back(deps[i].task_id);
        } else if (id_flag && id_post >= dep_post) {
            result.insert(result.begin()+dep_post, deps[i].dep_task_id);
            result.insert(result.begin()+id_post+1, deps[i].task_id);
        } else {
            result.insert(result.begin()+dep_post, deps[i].dep_task_id);
            result.insert(result.begin()+dep_post+1, deps[i].task_id);
        }
    }
    return result;
}*/


/********************************************************************/
/* Alibaba inc 数据研发实习生 笔试 2020/03/20
 * 给定一组扑克牌从A--10 （A代表1），每张牌最多四张，随机从中抽取一些发给小明
 * 出牌方式如下：
 *              1. 单张牌
 *              2. 对子
 *              3. 三个连对
 *              4. 连续五张牌（顺子）
 * 求最少出牌次数
 * 例子: 输入{1, 1, 1, 2, 2, 2, 2, 2, 1, 1}, 每个元素代表相应的牌的数量
 * 最少次数为3: A 2 3 4 5, 4 5 6 7 8, 6 7 8 9 10 */
/*******************************************************************/
int minimumNumber(vector<int>& nums);

/********************************************************************/
/* 小红弹琴，每次都弹一个升序字符串，例如aaa bbb abc abcde
 * 给定弹琴次数，和每次谈的字符串，求用这些字符串所能组合出的最长升序字符串长度：
 * 例子: 输入4, {aaa, bcd, zzz, bcdef}, 每个元素代表每次弹的字符串
 * 最少次数为11: aaabcdefzzz */
/*******************************************************************/
int maxStringLength(vector<string>& Str, int num);


/******************************************************************/
/* 360 笔试, 2020/03/25
 * 1. Two string only contain 'T' and 'a', convert first string to
 * second string, you can only exchange two chars or change one char
 * to another at each time
 *
 * 2. 两个数字，第一个代表中奖彩票的数量，第二个代表没中奖的彩票的数量，A先抽，
 * A每次抽一张，B每次抽一张再仍一张，求A获胜概率 */
/******************************************************************/
int minOperations(string& str1, string& str2);

double rate(int a, int b);


/******************************************************************/
/* MSRA ASR --> 2020/04/07
 * Description: 给定一个矩阵，求从左上角走到右下角有多少种路径 */
/******************************************************************/
int numRoute(vector<vector<int>>& matrix);


/******************************************************************/
/* NetEase 2020/04/07
 * 1. Input a nums (all positive integers), length is N, find k
 * that a_i+1 - a_i = n * k, n, k are positive integers
 *
 * 2. k people numbered from 1 --> k, input N pairs, in which they
 * can not sit together, output all possible sit sequences
 *
 * 3. A man with defence value D, k monsters with value a and b,
 * if a > D, then the man will get b damage, (the man will always
 * beat a monster), if a <= D, then the man will not get damage,
 * once beat a monster, the man's D will add 1, the man can beat
 * monsters in any order, output the minimum damage in total */
/******************************************************************/


/*********************************************/
/* Baidu, 2020/04/13, machine learning
 * Description: add two string  */
/*********************************************/
string addStr(string& s1, string& s2);

/*********************************************************/
/* Aiqiyi, 2020/04/
 * 判断链表是否有环
 *      1. Hash_set
 *      2. 快慢指针*/
/*********************************************************/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) {}
};

bool IsCircleList(ListNode* head);

/**
 * 字节跳动秋招2021届
 * 在n个正整数中，任意挑选k(0<=k<=n)个数字的和记位sum, 另有一个正整数m，请问sum % m最大是多少
 * 输入：
 *      第一行是两个正整数，分别为n, m
 *      第二行为n个正整数
 * @param nums
 * @param m
 * @return
 */
int maxRemainder(vector<int>& nums, int m);


/**
 * 华为校招2021届
 * 输入：第一行为二叉树的节点数量N，
 *      第二行为每个节点的深度
 * 输出：可能的二叉树的数量
 * @param nums
 * @return
 */
int numTrees(vector<int>& nums);


/**
 * 小红书2020届校招
 * 薯队长带着小红薯参加密室逃脱团建游戏，首先遇到了反转游戏，小红薯们根据游戏提示收集了多个单词线索，
 * 并将单词按要求加一个空格组 成了句子，最终要求把句子按单词反转解密。 说明：收集的时候单词前后可能会有多个空格，反转后单词不能有多个空格
 * @param str
 * @return
 */
string reverseStr(const string& str);


/**
 * 小红书2020届校招
 * 输入n篇笔记，编号从1-n和每篇的点赞数
 * 输出笔记数量和最高点赞数
 * 要求：不能出现连续编号的笔记
 * @param num
 * @param nums
 * @return
 */
pair<int, int> numGood(int num, vector<int>& nums);


/**
 * 猿辅导2021校招
 * 给定数字n，表示从1-n猜数，k表示有k次免费猜的机会，当不免费的时候，猜一个数，如果猜对了可以知道数字猜大了还是小了，但是要花费
 * 这个数字对应的金币数量。现在给定n，k，求需要多少金币可以确保游戏胜利
 */


/**
 * 百度地图2021校招二面
 * 给定一个无序的数组，写一个建立平衡二叉树的函数，和一个查找元素并打印查找路径的函数
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* buildTree(vector<int>& nums, int l, int r);
vector<int> findVal(TreeNode* root, int val);

/**
 * 百度2021校招笔试
 * 一个NXN棋盘，从左上角走到右下角，每次可以走上下左右四个方向中的一步，每个格子有一个1，2，3，4中的值，每走一步的消耗是两个格子中的差值的绝对值
 * 求问最小消耗值
 */

/**
 * 腾讯2021校招笔试
 * 求数组的最长山谷序列，山谷序列例如 5 4 2 1 1 4 6 7
 */
int maxValley(vector<int>& nums);

/**
 * vivo2021校招笔试
 * 一个NXN的棋盘，除了‘#’和‘@’是障碍其他地方可以随意走，可以走上下左右，现在给定起点和终点，求最短路径
 */
int bestPath(int x1, int y1, int x2, int y2, vector<string>& matrix);


#endif //INTERVIEW_ACCUMULATE_FUNCTIONS_H
