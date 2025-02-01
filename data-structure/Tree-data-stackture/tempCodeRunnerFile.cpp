    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // keep value queue front value
        Node *p = q.front();
        q.pop();

        // value assign in left and right
        Node *left_leaf, *rightLeaf;
        int l, r;
        cin >> l >> r;
        if (l != -1)
            left_leaf = new Node(l);
        if (r != 1)
            rightLeaf = new Node(r);

        p->left = left_leaf;
        p->right = rightLeaf;

        // queue push
        if (p->left)
            q.push(left_leaf);
        if (p->right)
            q.push(rightLeaf);
    }

    return root;
}