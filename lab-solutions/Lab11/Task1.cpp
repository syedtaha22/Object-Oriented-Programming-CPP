/**************************************************************************************************
    Task 1:
        You are required to implement a binary search tree (BST) to simulate a basic file
        management system. Each node in the BST must represent a file, storing its name, size
        (in megabytes), and type (e.g., "txt", "pdf", "exe"). The BST should be ordered based on
        file names using lexicographic comparison.

        You must support standard BST operations including insertion, deletion, and traversal. The
        tree must also allow searching for files whose size exceeds a given threshold.

        You are expected to handle the following error conditions: inserting a duplicate file name,
        deleting a non-existent file, or performing operations on an empty tree.

        • Each file node must contain:
          -	string fileName
          -	int fileSize
          -	string fileType
        • Functionality to implement:
            - Insert a new file node
            - Delete a file by name
            - Rename a file
            - Search for a file by name
            - Retrieve all files with size > given threshold
            - Inorder, preorder, and postorder traversals
        • Constraints:
            - Must handle the following cases:
                - Duplicate insertions
                - Invalid deletions
                - Operations on an empty tree

***************************************************************************************************/

#include <iostream>
#include <vector>


struct File {
    std::string file_name;
    std::string file_type;
    int file_size;

    File* left;
    File* right;

    File(std::string _fn, std::string _ft, int _fs) :
        file_name(_fn), file_type(_ft), file_size(_fs), left(nullptr), right(nullptr) {
    }

    friend std::ostream& operator<<(std::ostream& os, const File& file) {
        os << "File Name: " << file.file_name << ", Type: " << file.file_type << ", Size: " << file.file_size << "MB";
        return os;
    }
};

class FileSystem {
    File* root;

private:

    void insert(File*& root, const std::string& file_name, const std::string& file_type, int file_size) {
        if (root == nullptr) root = new File(file_name, file_type, file_size);
        else if (file_name < root->file_name) insert(root->left, file_name, file_type, file_size);
        else if (file_name > root->file_name) insert(root->right, file_name, file_type, file_size);
        else std::cout << "File already exists!" << std::endl; // Duplicate insertion
    }

    void delete_file(File*& root, const std::string& file_name) {
        if (root == nullptr) return;

        auto delete_and_assign = [&](File*& node, File*& to_assign)
            {
                File* temp = node;
                node = to_assign;
                delete temp;
            };

        if (file_name < root->file_name) delete_file(root->left, file_name);
        else if (file_name > root->file_name) delete_file(root->right, file_name);
        else {
            // File found
            if (!root->left && !root->right) {
                delete root;
                root = nullptr;
            }
            else if (root->left == nullptr) delete_and_assign(root, root->right);
            else if (root->right == nullptr) delete_and_assign(root, root->left);
            else {
                File* minNode = root->right;
                while (minNode->left != nullptr) minNode = minNode->left;

                // Copy successor data to current node
                root->file_name = minNode->file_name;
                root->file_type = minNode->file_type;
                root->file_size = minNode->file_size;
                delete_file(root->right, minNode->file_name);
            }
        }
    }

    File* search(File* root, const std::string& file_name) {
        if (root == nullptr || root->file_name == file_name) return root;
        if (file_name < root->file_name) return search(root->left, file_name);
        return search(root->right, file_name);
    }

    // Preorder traversal to search for files by size
    void search_by_size(File* root, int threshold, std::vector<File*>& result) {
        if (root == nullptr) return;
        if (root->file_size > threshold) result.push_back(root);
        search_by_size(root->left, threshold, result);
        search_by_size(root->right, threshold, result);
    }

    void inorder(File* root, std::vector<File*>& result) {
        if (root == nullptr) return;
        inorder(root->left, result);
        result.push_back(root);
        inorder(root->right, result);
    }

    void preorder(File* root, std::vector<File*>& result) {
        if (root == nullptr) return;
        result.push_back(root);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    void postorder(File* root, std::vector<File*>& result) {
        if (root == nullptr) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root);
    }

    void clear(File*& root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }


public:
    FileSystem() : root(nullptr) {}

    ~FileSystem() { clear(root); }

    void insert(const std::string& file_name, const std::string& file_type, int file_size) {
        insert(root, file_name, file_type, file_size);
    }

    void delete_file(const std::string& file_name) { delete_file(root, file_name); }

    void rename_file(const std::string& old_name, const std::string& new_name) {
        File* file = search(root, old_name);
        File* new_name_exists = search(root, new_name);

        if (!file) return; // File not found
        if (new_name_exists) return; // New name already exists

        insert(new_name, file->file_type, file->file_size);
        delete_file(old_name);
    }

    File* search(const std::string& file_name) { return search(root, file_name); }

    std::vector<File*> search_by_size(int threshold) {
        std::vector<File*> result;
        search_by_size(root, threshold, result);
        return result;
    }

    std::vector<File*> inorder() {
        std::vector<File*> result;
        inorder(root, result);
        return result;
    }

    std::vector<File*> preorder() {
        std::vector<File*> result;
        preorder(root, result);
        return result;
    }

    std::vector<File*> postorder() {
        std::vector<File*> result;
        postorder(root, result);
        return result;
    }
};

void print(std::vector<File*>& files) {
    for (const auto& file : files) std::cout << *file << std::endl;
    std::cout << std::endl;
}

int main() {
    FileSystem fs;

    fs.insert("file2.pdf", "pdf", 20);
    fs.insert("file1.txt", "txt", 10);
    fs.insert("file3.exe", "exe", 30);

    std::cout << "Inorder Traversal:" << std::endl;
    std::vector<File*> inorder_files = fs.inorder();
    print(inorder_files);

    std::cout << "Preorder Traversal:" << std::endl;
    std::vector<File*> preorder_files = fs.preorder();
    print(preorder_files);

    std::cout << "Postorder Traversal:" << std::endl;
    std::vector<File*> postorder_files = fs.postorder();
    print(postorder_files);

    std::cout << "Searching for file2.pdf:" << std::endl;
    File* file = fs.search("file2.pdf");
    if (file) std::cout << *file << std::endl;
    else std::cout << "File not found!" << std::endl;
    std::cout << std::endl;

    // Searching for files larger than 15MB
    std::cout << "Files larger than 15MB:" << std::endl;
    std::vector<File*> large_files = fs.search_by_size(15);
    print(large_files);

    // Deleting a file
    std::cout << "Deleting file2.pdf:" << std::endl;
    fs.delete_file("file2.pdf");
    std::cout << "Inorder Traversal after deletion:" << std::endl;
    inorder_files = fs.inorder();
    print(inorder_files);

    // Research for deleted file
    std::cout << "Searching for file2.pdf after deletion:" << std::endl;
    file = fs.search("file2.pdf");
    if (file) std::cout << *file << std::endl;
    else std::cout << "File not found!" << std::endl;
    std::cout << std::endl;

    // Renaming a file
    std::cout << "Renaming file1.txt to renamed_file1.txt:" << std::endl;
    fs.rename_file("file1.txt", "renamed_file1.txt");
    std::cout << "Inorder Traversal after renaming:" << std::endl;
    inorder_files = fs.inorder();
    print(inorder_files);

    return 0;
}
