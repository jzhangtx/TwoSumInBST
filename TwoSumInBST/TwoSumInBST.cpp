// TwoSumInBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

bool Find(Node* pNode, Node* pCur, int k)
{
    if (pNode == nullptr)
        return false;

    if (pNode->data == k && pCur != pNode)
        return true;

    if (pNode->data >= k)
        return Find(pNode->right, pCur, k);
    else
        return Find(pNode->left, pCur, k);
}

bool PairExists(Node* root, Node* pNode, int k)
{
    if (pNode == nullptr)
        return false;

    if (pNode->data >= k)
        return PairExists(root, pNode->left, k);

    if (Find(root, pNode, k - pNode->data))
        return true;

    if (PairExists(root, pNode->left, k))
        return true;

    return PairExists(root, pNode->right, k);
}

bool PairExists(Node* root, int k)
{
    return PairExists(root, root, k);
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in BST: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;
        
        std::cout << "The nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
        {
            std::cin >> v[i];
        }

        Node* pRoot = ArrayToTree(v);

        std::cout << "The sum to pair: ";
        int k = 0;
        std::cin >> k;

        std::cout << "BST DOES " << (PairExists(pRoot, k) ? "" : "NOT ") << "have two nodes with sum of " << k << std::endl;

        FreeTree(pRoot);
    }
}
