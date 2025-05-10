#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <functional>
#include <iomanip>

struct Word {
    std::string word;
    int frequency;

    Word(const std::string& w, int f) : word(w), frequency(f) {}

    bool operator<(const Word& other) const { return word < other.word; }
    bool operator>(const Word& other) const { return word > other.word; }
    bool operator==(const Word& other) const { return word == other.word; }

    Word& operator++() {
        ++frequency;
        return *this;
    }

    Word operator--() {
        --frequency;
        return *this;
    }
};


class WordData {
    int total_word_count; // Total word count in the corpus
    int unique_word_count; // Unique word count in the corpus

    struct Node {
        Word word;
        Node* left;
        Node* right;
        Node(const Word& w) : word(w), left(nullptr), right(nullptr) {}
    };

    Node* root;
private:
    void insert(Node*& node, const Word& word) {
        if (!node) {
            node = new Node(word);
            ++unique_word_count;
            total_word_count += word.frequency;
        }
        else if (word < node->word) insert(node->left, word);
        else if (word > node->word) insert(node->right, word);
        else {
            node->word.frequency += word.frequency;
            total_word_count += word.frequency;
        }
    }

    void cleanUp(Node* node) {
        if (!node) return;
        cleanUp(node->left);
        cleanUp(node->right);
        delete node;
    }

    Node* find(Node* node, const std::string& word) const {
        if (!node) return nullptr;
        if (word < node->word.word) return find(node->left, word);
        else if (word > node->word.word) return find(node->right, word);
        else return node;
    }

    Node* prefixSearch(Node* node, const std::string& prefix) const {
        if (!node) return nullptr;
        else if (node->word.word.compare(0, prefix.size(), prefix) < 0) return prefixSearch(node->right, prefix);
        else if (node->word.word.compare(0, prefix.size(), prefix) > 0) return prefixSearch(node->left, prefix);
        else return node;
    }

    void inOrder(Node* node, std::function<void(const Word&)> func) const {
        if (!node) return;
        inOrder(node->left, func);
        func(node->word);
        inOrder(node->right, func);
    }

    void postOrder(Node* node, std::function<void(const Word&)> func) const {
        if (!node) return;
        postOrder(node->left, func);
        postOrder(node->right, func);
        func(node->word);
    }

    void preOrder(Node* node, std::function<void(const Word&)> func) const {
        if (!node) return;
        func(node->word);
        preOrder(node->left, func);
        preOrder(node->right, func);
    }


public:
    WordData(const std::string& filePath) : root(nullptr), total_word_count(0), unique_word_count(0) {
        std::ifstream file(filePath);
        if (!file.is_open()) throw std::runtime_error("Could not open file: " + filePath);

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                word = normalize(word);
                if (!word.empty()) insert(root, Word(word, 1));
            }
        }
        file.close();
    }

    ~WordData() { cleanUp(root); }


    void insert(const Word& word) { insert(root, word); }

    void inOrder(std::function<void(const Word&)> func) const { inOrder(root, func); }
    void postOrder(std::function<void(const Word&)> func) const { postOrder(root, func); }
    void preOrder(std::function<void(const Word&)> func) const { preOrder(root, func); }

    std::string prefixSearch(const std::string& prefix) const {
        Node* node = prefixSearch(root, normalize(prefix));
        if (!node) return ""; // No match found
        return node->word.word; // Return the first word that matches the prefix
    }

    std::string find(const std::string& word) const {
        Node* node = find(root, normalize(word));
        if (!node) return ""; // No match found
        return node->word.word; // Return the word if found
    }

    int getFrequency(const std::string& word) const {
        Node* node = find(root, normalize(word));
        return node ? node->word.frequency : 0;
    }

    bool containsWord(const std::string& word) const { return find(root, normalize(word)) != nullptr; }

    int getTotalWordCount() const { return total_word_count; }
    int getUniqueWordCount() const { return unique_word_count; }

    void exportToFile(const std::string& path) const {
        std::ofstream file(path);
        if (!file.is_open()) throw std::runtime_error("Could not open file: " + path);

        auto writeWord = [&file](const Word& word) { file << std::left << std::setw(20) << word.word << word.frequency << "\n";};
        inOrder(root, writeWord);
        file.close();
    }

    std::string normalize(const std::string& word) const {
        std::string normalized = word;
        normalized.erase(std::remove_if(normalized.begin(), normalized.end(), [](char c) { return !std::isalpha(c); }), normalized.end());
        std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
        return normalized;
    }

    std::vector<std::string> starts_with(const std::string& prefix) const {
        std::vector<std::string> result;
        Node* prefixNode = prefixSearch(root, normalize(prefix));
        if (!prefixNode) return result;  // No match found
        preOrder(prefixNode, [&](const Word& word) {
            if (word.word.find(prefix) == 0) result.push_back(word.word); // Add words that start with the prefix
            });
        return result;
    }

    std::vector<std::string> most_frequent() const {
        std::vector<std::string> result;
        int maxFrequency = 0;
        preOrder([&](const Word& word) {
            if (word.frequency > maxFrequency) {
                maxFrequency = word.frequency;
                result.clear(); // Clear previous results
                result.push_back(word.word); // Add new most frequent word
            }
            else if (word.frequency == maxFrequency) result.push_back(word.word);
            });
        return result;
    }

    std::vector<std::string> longest_word() const {
        std::vector<std::string> result;
        size_t maxLength = 0;
        preOrder([&](const Word& word) {
            if (word.word.length() > maxLength) {
                maxLength = word.word.length();
                result.clear(); // Clear previous results
                result.push_back(word.word); // Add new longest word
            }
            else if (word.word.length() == maxLength) result.push_back(word.word);
            });
        return result;
    }

    std::vector<std::string> top_k(int k) const {
        std::vector<std::string> result;
        std::vector<Word> words;
        preOrder([&](const Word& word) { words.push_back(word); });
        std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) { return a.frequency > b.frequency; });
        for (int i = 0; i < k && i < static_cast<int>(words.size()); ++i) result.push_back(words[i].word);
        return result;
    }

    std::vector<std::string> bottom_k(int k) const {
        std::vector<std::string> result;
        std::vector<Word> words;
        preOrder([&](const Word& word) { words.push_back(word); });
        std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) { return a.frequency < b.frequency; });
        for (int i = 0; i < k && i < static_cast<int>(words.size()); ++i) result.push_back(words[i].word);
        return result;
    }

};


void print(std::vector<std::string> words) {
    for (const auto& word : words) std::cout << word << std::endl;
    std::cout << std::endl;
}

void print_frequencies(const std::vector<std::string>& words, const WordData& wordData) {
    for (const auto& word : words) std::cout << word << ": " << wordData.getFrequency(word) << std::endl;
    std::cout << std::endl;
}

int main() {

    WordData wordData("data/small-text.txt");

    std::cout << "Total word count: " << wordData.getTotalWordCount() << std::endl;
    std::cout << "Unique word count: " << wordData.getUniqueWordCount() << std::endl;
    std::cout << std::endl;


    auto words = wordData.starts_with("juli");
    std::cout << "Words starting with 'juli':" << std::endl;
    print(words);

    words = wordData.most_frequent();
    std::cout << "Most frequent word:" << std::endl;
    print_frequencies(words, wordData);

    words = wordData.top_k(5);
    std::cout << "Top 5 words:" << std::endl;
    print_frequencies(words, wordData);


    words = wordData.bottom_k(5);
    std::cout << "Bottom 5 words:" << std::endl;
    print_frequencies(words, wordData);


    wordData.exportToFile("output.txt");

    return 0;
}