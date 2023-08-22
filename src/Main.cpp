#include <iostream>
#include "DoubleLinkedList.cpp"
//#include "LinkedLIst.cpp"

using namespace std;

int main() {

    //LinkedList listOne;
    DoubleLinkedList listOne;

    listOne.pushNode(true, 1);
    listOne.pushNode(true, 2);
    listOne.pushNode(false, 3);
    listOne.pushNode(true, 4);
    listOne.pushNode(false, 5);
    listOne.pushNode(false, 6);
    listOne.pushNode(true, 7);
    listOne.pushNode(false, 8);

    listOne.display(true);
    listOne.display(false);

    std::cout << "Number of nodes: " << listOne.nodeCount << std::endl;

    std::cout << "Popping head and tail." << std::endl;

    listOne.popHead();
    listOne.popTail();

    std::cout << "Number of nodes: " << listOne.nodeCount << std::endl;

    listOne.display(true);
    listOne.display(false);

    
    return 0;

}

