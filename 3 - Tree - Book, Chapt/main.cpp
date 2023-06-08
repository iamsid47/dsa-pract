#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
	public:
	    string name;
	    vector<Node*> children;
	
	    Node(const string& nodeName) : name(nodeName) {}
	
	    void printNode(int depth = 0) {
	        cout << string(depth, '-') << name << endl;
	        for (size_t i = 0; i < children.size(); ++i) {
	            children[i]->printNode(depth + 1);
	        }
	    }
};

int main() {
    Node* book = new Node("Book");

    Node* chapter1 = new Node("Chapter 1");
    book->children.push_back(chapter1);

    Node* section1_1 = new Node("Section 1.1");
    chapter1->children.push_back(section1_1);

    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    section1_1->children.push_back(subsection1_1_1);

    Node* subsection1_1_2 = new Node("Subsection 1.1.2");
    section1_1->children.push_back(subsection1_1_2);

    Node* section1_2 = new Node("Section 1.2");
    chapter1->children.push_back(section1_2);

    Node* chapter2 = new Node("Chapter 2");
    book->children.push_back(chapter2);

    Node* section2_1 = new Node("Section 2.1");
    chapter2->children.push_back(section2_1);

    book->printNode();

    delete book;
    return 0;
}


