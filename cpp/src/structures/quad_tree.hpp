#pragma once
#include "linalg.h"

template<typename T>
struct Image<T>
{
    unique_ptr<T> data;
    linalg::aliases::uint2 size;
};

std::vector<TreeNode<Rect>> build_quad_tree(const cv::Mat &depth, const Rect &rect, int tree_depth = 0)
{
    if (tree_depth > 5)
        return {};
    if (rect.width < 1 || rect.height < 1 || rect.x >= depth.cols || rect.y >= depth.rows)
    {
        return {};
    }

    auto subimage = cv::Mat(depth, rect);
    if (split_based_on_depth(subimage))
    {
        auto quadrect = rect;
        quadrect.width /= 2;
        quadrect.height /= 2;

        auto tl = TreeNode<cv::Rect>(quadrect, build_quad_tree(depth, quadrect, tree_depth + 1));
        quadrect.x = rect.x + quadrect.width;
        quadrect.y = rect.y + 0;
        auto tr = TreeNode<cv::Rect>(quadrect, build_quad_tree(depth, quadrect, tree_depth + 1));
        quadrect.x = rect.x + 0;
        quadrect.y = rect.y + quadrect.height;
        auto bl = TreeNode<cv::Rect>(quadrect, build_quad_tree(depth, quadrect, tree_depth + 1));
        quadrect.x = rect.x + quadrect.width;
        quadrect.y = rect.y + quadrect.height;
        auto br = TreeNode<cv::Rect>(quadrect, build_quad_tree(depth, quadrect, tree_depth + 1));

        return { tl, tr, bl, br };
    }
    return {};
}
