#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *pNext;
};

struct singlelist{
    Node *pHead;
};

void initialize(singlelist &L){
    L.pHead = NULL;
}

Node *createNode(int d){
    Node *p = new Node;
    p->data = d;
    p->pNext = NULL;
    return p;
}

// 1. Hàm thêm vào cu?i danh sách
void insertLast(singlelist &L,int d){
    Node *p = createNode(d);
    if(L.pHead == NULL){
        L.pHead = p;
    }else{
        Node *p1 = L.pHead;
        while(p1->pNext != NULL){
            p1 = p1->pNext;
        }
        p1->pNext = p;
    }
}

// Hàm in danh sách
void printList(singlelist L){
    Node *p = L.pHead;
    if(L.pHead == NULL){
        cout << "Danh sach rong!";
    }else{
        while(p != NULL){
            cout << p->data << "\t";
            p = p->pNext;
        }
    }
    cout << endl;
}

// 2. Hàm s?a giá tr? Node (T?m giá tr? c? và thay b?ng giá tr? m?i)
void EditNode(singlelist &L, int oldVal, int newVal) {
    Node *p = L.pHead;
    bool found = false;
    while(p != NULL) {
        if(p->data == oldVal) {
            p->data = newVal;
            found = true;
            break; // S?a ph?n t? ð?u tiên t?m th?y
        }
        p = p->pNext;
    }
    if(found) cout << "-> Da sua thanh cong!\n";
    else cout << "-> Khong tim thay gia tri " << oldVal << " de sua!\n";
}

// 3. Hàm xóa Node
void RemoveNode(singlelist &L, int d) {
    Node *pDel = L.pHead;
    if (pDel == NULL) {
        cout << "-> Danh sach rong!\n";
    } else {
        Node *pPre = NULL;
        while (pDel != NULL) {
            if (pDel->data == d) break; 
            pPre = pDel;           
            pDel = pDel->pNext;    
        }
        if (pDel == NULL) {
            cout << "-> Khong tim thay " << d << " de xoa!\n";
        } else {
            if (pDel == L.pHead) {
                L.pHead = L.pHead->pNext; 
                pDel->pNext = NULL;       
                delete pDel;              
            } else {
                pPre->pNext = pDel->pNext; 
                pDel->pNext = NULL;        
                delete pDel;               
            }
            cout << "-> Da xoa thanh cong!\n";
        }
    }
}

// 4. Hàm s?p x?p tãng d?n
void SortList(singlelist &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return; 

    for (Node *p = L.pHead; p != NULL; p = p->pNext) {
        for (Node *q = p->pNext; q != NULL; q = q->pNext) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    cout << "-> Danh sach da duoc sap xep tang dan!\n";
}

// 5. Hàm t?m ki?m
void SearchNode(singlelist L, int d) {
    Node *p = L.pHead;
    int pos = 0;
    bool found = false;
    while(p != NULL) {
        if(p->data == d) {
            cout << "-> Tim thay " << d << " tai vi tri (index): " << pos << "\n";
            found = true;
        }
        pos++;
        p = p->pNext;
    }
    if(!found) cout << "-> Khong tim thay " << d << " trong danh sach!\n";
}

// 6. Hàm t?m giá tr? nh? nh?t (Min)
void FindMin(singlelist L) {
    if(L.pHead == NULL) {
        cout << "-> Danh sach rong!\n";
        return;
    }
    int minVal = L.pHead->data;
    Node *p = L.pHead->pNext;
    while(p != NULL) {
        if(p->data < minVal) {
            minVal = p->data;
        }
        p = p->pNext;
    }
    cout << "-> Gia tri nho nhat (Min) la: " << minVal << "\n";
}

int main(){
    singlelist L;
    initialize(L);
    int choice;
    int val, newVal;

    do {
        cout << "\n============== MENU ==============\n";
        cout << "1. Them phan tu vao cuoi\n";
        cout << "2. Sua phan tu\n";
        cout << "3. Xoa phan tu\n";
        cout << "4. Sap xep danh sach tang dan\n";
        cout << "5. Tim kiem phan tu\n";
        cout << "6. Tim phan tu nho nhat (Min)\n";
        cout << "7. Thoat\n";
        cout << "==================================\n";
        
        cout << "Hien tai: "; 
        printList(L);
        
        cout << "Nhap lua chon cua ban (1-7): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Nhap gia tri can them: ";
                cin >> val;
                insertLast(L, val);
                break;
            case 2:
                cout << "Nhap gia tri can sua: "; cin >> val;
                cout << "Nhap gia tri moi: "; cin >> newVal;
                EditNode(L, val, newVal);
                break;
            case 3:
                cout << "Nhap gia tri can xoa: ";
                cin >> val;
                RemoveNode(L, val);
                break;
            case 4:
                SortList(L);
                break;
            case 5:
                cout << "Nhap gia tri can tim: ";
                cin >> val;
                SearchNode(L, val);
                break;
            case 6:
                FindMin(L);
                break;
            case 7:
                cout << "Thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    } while(choice != 7);

    return 0;
}
