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
    Solution slu;
    cout << 1 << endl;
    string input_tree = "1,2,3,#,#,6,7";
    slu.Deserialize(input_tree);
    // TreeNode *root = 

    cout << 3 << endl;
    return 0;
}