// SegmentTree.cpp

module segmentree;

TreeNode::TreeNode(int s, int e) : start(s), end(e), sum(0), add(0), left(nullptr), right(nullptr) {}

void SegmentTree::updateRange(std::shared_ptr<TreeNode>& node, int L, int R, long long val) {
    if (!node) {
        node = std::make_shared<TreeNode>(L, R);
    }
    if (node->start == L && node->end == R) {
        updater(node, L, R, val); // 用户定义的更新操作
        return;
    }

    pushDown(node, L, R); // 用户定义的向下推操作
    int mid = (node->start + node->end) / 2;
    if (L <= mid) {
        updateRange(node->left, L, std::min(R, mid), val);
    }
    if (R > mid) {
        updateRange(node->right, std::max(L, mid + 1), R, val);
    }
    pushUp(node); // 用户定义的向上合并操作
}

long long SegmentTree::queryRange(std::shared_ptr<TreeNode> node, int L, int R) {
    if (!node || L > node->end || R < node->start) return 0;
    if (node->start >= L && node->end <= R) return node->sum;
    pushDown(node, L, R);
    int mid = (node->start + node->end) / 2;
    long long sum = 0;
    if (L <= mid) {
        sum += queryRange(node->left, L, std::min(R, mid));
    }
    if (R > mid) {
        sum += queryRange(node->right, std::max(L, mid + 1), R);
    }
    return sum;
}

SegmentTree::SegmentTree(int start, int end, std::function<void(std::shared_ptr<TreeNode>)> up, std::function<void(std::shared_ptr<TreeNode>, int, int)> down, std::function<void(std::shared_ptr<TreeNode>&, int, int, long long)> updateFunc)
    : pushUp(up), pushDown(down), updater(updateFunc) {
    root = std::make_shared<TreeNode>(start, end);
}

SegmentTree::SegmentTree(int start, int end, enum Operation op) {
    setOperation(op);
    root = std::make_shared<TreeNode>(start, end);
}

void SegmentTree::update(int L, int R, long long val) {
    updateRange(root, L, R, val);
}

long long SegmentTree::query(int L, int R) {
    return queryRange(root, L, R);
}

void SegmentTree::setOperation(enum Operation op) {
    switch (op) {
    case ADD:
        setAdd();
        break;
    case MAX:
        // setMax();
        break;
    case MIN:
        // setMin();
        break;
    default:
        throw "Invalid Operation";
    }
}

void SegmentTree::setAdd() {
    pushUp = [](std::shared_ptr<TreeNode> node) {
        node->sum = (node->left ? node->left->sum : 0) + (node->right ? node->right->sum : 0);
    };

    pushDown = [](std::shared_ptr<TreeNode> node, int L, int R) {
        int mid = (node->start + node->end) / 2;
        if (!node->left)
            node->left = std::make_shared<TreeNode>(node->start, mid);
        if (!node->right)
            node->right = std::make_shared<TreeNode>(mid + 1, node->end);
        if (node->add != 0) {
            node->left->sum += (mid - node->start + 1) * node->add;
            node->left->add += node->add;
            node->right->sum += (node->end - mid) * node->add;
            node->right->add += node->add;
            node->add = 0;
        }
    };

    updater = [](std::shared_ptr<TreeNode>& node, int L, int R, long long val) {
        node->sum += (R - L + 1) * val;
        node->add += val;
    };

    mergeResult = [](long long& sum, long long val) {
        sum += val;
    };
}
