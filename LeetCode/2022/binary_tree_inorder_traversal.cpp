// Given the root of a binary tree, return the inorder traversal of its nodes' values.

#include <iostream>
#include <string>
#include <vector>

std::string vectorToString(std::vector<int>& vec)
{
    std::string result;
    for (size_t i = 0; i < vec.size(); i++)
    {
        result += (std::to_string(vec[i]) + ", ");
    }
    return result;
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val (0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode ()
    {
        delete left;
        delete right;
    }
    TreeNode(const TreeNode& object)
    {
        this->val = object.val;
        this->left = object.left;
        this->right = object.right;
    }
    TreeNode& operator = (const TreeNode& other)
    {
        this->val = other.val;
        this->left = other.left;
        this->right = other.right;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& out, TreeNode* node)
    {
        out << node->toStringInFix(node);
        return out;
    }
    std::string toStringInFix(TreeNode* node)
    {
        if (node)
        {
            return toStringInFix(node->left) + ", " + std::to_string(node->val) + ", " + toStringInFix(node->right);
        }
        return "";
    }
};

class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (root)
        {
            std::vector<int> left = inorderTraversal(root->left);
            std::vector<int> middle = std::vector<int>{root->val};
            std::vector<int> right = inorderTraversal(root->right);
            left.insert(left.end(), middle.begin(), middle.end());
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
        return result;
    }
};

class UnitTest
{
public:
    UnitTest()
    {
        root = nullptr;
        expected = std::vector<int>{};
    }
    UnitTest(TreeNode* root, std::vector<int> expected)
    {
        this->root = root;
        this->expected = expected;
    }
    UnitTest(const UnitTest& object)
    {
        this->root = object.root;
        this->expected = object.expected;
    }
    ~UnitTest()
    {
        delete root;
    }
    UnitTest& operator = (UnitTest other)
    {
        this->root = other.root;
        this->expected = other.expected;
        return *this;
    }
    void test()
    {
        Solution solution;
        std::vector<int> result = solution.inorderTraversal(root);
        if (expected == result)
        {
            std::cout << "Passed: ";
        }
        else
        {
            std::cout << "Failed: ";
        }
        std::cout << "Got " << vectorToString(result) << ", expected " << vectorToString(expected) << std::endl;
    }
private:
    TreeNode* root;
    std::vector<int> expected;
};

int main()
{
    UnitTest test (new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr)), std::vector<int> {1, 3, 2});
    test.test();
    return 0;
}