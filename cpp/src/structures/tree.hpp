#pragma once

#include <vector>

template<class T>
struct TreeNode
{
    T contents;
    std::vector<TreeNode> children;

    TreeNode(T contents) : contents(contents) {}
    TreeNode(T contents, std::vector<TreeNode> children) : contents(contents), children(children) {}

};

template<class T>
inline std::vector<std::reference_wrapper<TreeNode<T>>> retrive_leaf_nodes(TreeNode<T> & node)
{
    std::vector<std::reference_wrapper<TreeNode<T>>> leafs;
    retrive_leaf_nodes(node, leafs);
    return leafs;
}


template<class T>
inline void retrive_leaf_nodes(TreeNode<T> & node, std::vector<std::reference_wrapper<TreeNode<T>>> & leafs)
{
    if (node.children.empty())
    {
        leafs.push_back(std::reference_wrapper<TreeNode<T>>(node));
        return;
    }
    for (auto & c : node.children)
    {
        retrive_leaf_nodes(c, leafs);
    }
}
