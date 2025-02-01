class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// input tree
Node *inputTree()
{

    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    };

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            Node *leftNewNode = new Node(l);
            f->left = leftNewNode;
        }
        if (r != -1)
        {
            Node *rightNode = new Node(r);
            f->right = rightNode;
        }

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return root;
};

// print outer tree
void outer_print_left(Node *root)
{

    if (root == NULL)
        return;

    if (root->left)
    {
        outer_print_left(root->left);
    }
    else
    {
        outer_print_left(root->right);
    }

    cout << root->val << " ";
};

void outer_print_right(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";

    if (root->right)
    {
        outer_print_right(root->right);
    }
    else
    {

        outer_print_right(root->left);
    }
}

void outer_print_right_without_left(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";

    if (root->right)
    {
        outer_print_right(root->right);
    }
    else
    {

        outer_print_right(root->left);
    }
}

int main()
{
    Node *root = inputTree();

    if (root->left)
    {
        outer_print_left(root);
    }

    if (root->right && root->left)
    {
        outer_print_right(root->right);
    }

    if (root->right && !root->left)
    {
        outer_print_right_without_left(root);
    }

    return 0;
}
