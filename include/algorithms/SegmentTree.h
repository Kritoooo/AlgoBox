// SegmentTree.h
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>
#include <memory>
#include <functional>

class TreeNode {
public:
    int start, end;
    long long sum, add; // 支持区间和与懒增量
    std::shared_ptr<TreeNode> left, right;

    TreeNode(int s, int e);
};

class SegmentTree {
public:
    enum Operation {
        ADD,
        MAX,
        MIN
    };

    SegmentTree(int start, int end, std::function<void(std::shared_ptr<TreeNode>)> up, std::function<void(std::shared_ptr<TreeNode>, int, int)> down, std::function<void(std::shared_ptr<TreeNode>&, int, int, long long)> updateFunc);
    SegmentTree(int start, int end, enum Operation op);

    void update(int L, int R, long long val);
    long long query(int L, int R);

private:
    std::shared_ptr<TreeNode> root;
    std::function<void(std::shared_ptr<TreeNode>)> pushUp;
    std::function<void(std::shared_ptr<TreeNode>, int, int)> pushDown;
    std::function<void(std::shared_ptr<TreeNode>&, int, int, long long)> updater;
    std::function<void(long long&, long long)> mergeResult;

    void updateRange(std::shared_ptr<TreeNode>& node, int L, int R, long long val);
    long long queryRange(std::shared_ptr<TreeNode> node, int L, int R);
    void setOperation(enum Operation op);
    void setAdd();
};
#endif // SEGMENT_TREE_H