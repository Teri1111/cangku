
#include <array>
#include <queue>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    static const int N = 110;
    array<int, N> a;
    using PII =  pair<TreeNode*, int>;
    int last_num;
    int deep = 1;
    int total_node = 1;

    void lev_order(TreeNode *p){
        a.fill(-1);
        int num = 1;
        queue<PII> lev_queue;
        lev_queue.push({p, num});
        while(!lev_queue.empty()){
            TreeNode *temp_node = lev_queue.front().first;
            int temp_num = lev_queue.front().second;
            lev_queue.pop();
            a[temp_num] = temp_node->val;
            last_num = temp_num;
            if(!temp_node->left) lev_queue.push({temp_node->left, 2 * temp_num});
            if(!temp_node->right) lev_queue.push({temp_node->right, 2 * temp_num + 1});
            
        }

    }

    void count_deep(){
        int i = 1;
        total_node = i;
        while(total_node < last_num){
            i *= 2;
            total_node += i;
            deep ++;
        }
    }

    string int_to_string(){
        string s;
        for(int i = 0; i < total_node; i ++){
            if(a[i] == -1) s += '#';
            else{
                s += to_string(a[i]);
            }
            s += ',';
        }
        s.pop_back();
        return s;
    }


    char* Serialize(TreeNode *root) {    
        lev_order(root);
        count_deep();
        string s = int_to_string();

        char *s1 = &s[0];
        return s1;
    }

    TreeNode* Deserialize(char *str) {
        if(*str == '#') return nullptr;
        string val;
        istringstream in(str);
        getline(in , val, ',');
        TreeNode *root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *r = q.front();
            q.pop();
            if(getline(in, val, ',')){
                if(val != "#"){
                    r->left = new TreeNode(stoi(val));
                    q.push(r->left);
                }
            }

            if(getline(in, val, ',')){
                if(val != "#"){
                    r->right = new TreeNode(stoi(val));
                    q.push(r->right);
                }
            }
        }

        
        return root;
    }
};

int main(){
    
    return 0;
}