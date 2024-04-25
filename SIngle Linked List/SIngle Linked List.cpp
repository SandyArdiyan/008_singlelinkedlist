#include <iostream>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
};

Node* START = NULL;

void addNode() {
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukan NIM: ";
    cin >> nim;
    cout << "Masukan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;

    if (START == NULL || nim <= START->noMhs) {
        if (START != NULL && nim == START->noMhs) {
            cout << "NIM sudah ada " << endl;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }

    Node* previous = START;
    Node* current = START;

    while (current != NULL && nim >= current->noMhs) {
        if (nim == current->noMhs) {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    nodeBaru->next = current;
    previous->next = nodeBaru;
}

bool searchNode(int nim) {
    Node* current = START;

    while (current != NULL) {
        if (current->noMhs == nim) {
            return true; // Found the node
        }
        current = current->next;
    }

    return false; // Node not found
}

int main() {
    // Usage example
    addNode(); // Add a new node to the list
    int nimToSearch;
    cout << "Masukkan NIM untuk dicari: ";
    cin >> nimToSearch;
    if (searchNode(nimToSearch)) {
        cout << "NIM ditemukan" << endl;
    }
    else {
        cout << "NIM tidak ditemukan" << endl;
    }

    return 0;
}