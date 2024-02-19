// ***Problem Desc***: given a binary tree, write functions to serialize it and then deserialize it
// ***using o and i stringstreams for preorder serialization and deserialization [O() time | O() space]***:
void encode(TreeNode* root, ostringstream &out) {
    if (!root) {out << "N "; return;}
    out << root->val << " ";
    encode(root->left, out);
    encode(root->right, out);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    ostringstream out;
    encode(root, out);
    return out.str();
}

TreeNode* decode(istringstream &in) {
    string s; in >> s;
    if (s == "N") return NULL;
    TreeNode *root = new TreeNode(stoi(s));
    root->left = decode(in); root->right = decode(in);
    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream in(data);
    return decode(in);
}
