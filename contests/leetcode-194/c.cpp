#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    set<int> ch;
    unordered_map<int, int> mp;
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        int n = rains.size();
        for (int i = 0; i < n; ++i){
            int t = rains[i];
            if (t == 0){
                ans.push_back(1);
                ch.insert(i);
            }else {
                if (mp.count(t)){
                    if (ch.empty()){
                        return vector<int>();
                    }
                    int tm = mp[t];
                    auto iter = ch.upper_bound(tm);
                    if (iter == ch.end()){
                        return vector<int>();
                    }
                    int tmm = *iter;
                    ans[tmm] = t;
                    ch.erase(tmm);
                }
                mp[t] = i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
