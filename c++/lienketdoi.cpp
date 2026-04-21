#include<iostream>
using namespace std;

// cau truc node doi
struct DNode{
    int data;
    DNode *pNext; // con tro tro toi phan tu dung sau
    DNode *pPrev; // [diem khac biet dll]: them con tro tro nguoc ve phan tu dung truoc
};

struct doublelist{
    DNode *pHead;
    DNode *pTail; // [diem khac biet dll]: giu them duoi (tail) de them vao cuoi voi toc do o(1)
};

void initialize(doublelist &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

DNode *createDNode(int d){
    DNode *p = new DNode;
    p->data = d;
    p->pNext = NULL;
    p->pPrev = NULL; // [diem khac biet dll]: khoi tao con tro lui bang null
    return p;
}

// 1. them vao cuoi
void insertLast(doublelist &L, int d){
    DNode *p = createDNode(d);
    if(L.pHead == NULL){
        L.pHead = L.pTail = p;
    } else {
        // [diem khac biet dll]: khong can vong lap while de chay toi cuoi danh sach nua
        L.pTail->pNext = p;   // node duoi hien tai tro next toi node moi (p)
        p->pPrev = L.pTail;   // node moi (p) tro prev nguoc ve node duoi hien tai
        L.pTail = p;          // cap nhat lai: node moi (p) chinh thuc tro thanh duoi moi
    }
}

void printList(doublelist L){
    DNode *p = L.pHead;
    if(L.pHead == NULL){
        cout << "danh sach rong!";
    } else {
        while(p != NULL){
            cout << p->data << "\t";
            p = p->pNext;
        }
    }
    cout << endl;
}

// 2. sua node
void EditNode(doublelist &L, int oldVal, int newVal) {
    DNode *p = L.pHead;
    bool found = false;
    while(p != NULL) {
        if(p->data == oldVal) {
            p->data = newVal;
            found = true;
            break;
        }
        p = p->pNext;
    }
    if(found) cout << "-> da sua thanh cong!\n";
    else cout << "-> khong tim thay gia tri de sua!\n";
}

// 3. xoa node (xu ly lien ket 2 chieu)
void RemoveNode(doublelist &L, int d) {
    DNode *pDel = L.pHead;
    if (pDel == NULL) {
        cout << "-> danh sach rong!\n";
        return;
    }
    
    // tim node can xoa
    while (pDel != NULL && pDel->data != d) {
        pDel = pDel->pNext;
    }
    
    if (pDel == NULL) {
        cout << "-> khong tim thay " << d << " de xoa!\n";
        return;
    }
    
    // [diem khac biet dll]: khong can dung con tro ppre (previous) di theo sau nua.
    // vi ban than pdel da tu biet ai dung truoc no thong qua pdel->pprev.

    // truong hop 1: neu node can xoa la phan tu dau tien (head)
    if (pDel == L.pHead) {
        L.pHead = L.pHead->pNext;      // dich head sang node thu 2
        if(L.pHead != NULL) {
            L.pHead->pPrev = NULL;     // [diem khac biet dll]: cat dut soi day tro nguoc ve cai head cu vua bi xoa
        } else {
            L.pTail = NULL;            // neu danh sach chi co 1 phan tu, xoa xong tail cung ve null
        }
    } 
    // truong hop 2: neu node can xoa la phan tu cuoi cung (tail)
    else if (pDel == L.pTail) {
        L.pTail = L.pTail->pPrev;      // dich tail lui ve node ke chot
        L.pTail->pNext = NULL;         // [diem khac biet dll]: cat dut soi day tro toi cai tail cu vua bi xoa
    } 
    // truong hop 3: node can xoa nam o giua danh sach
    else {
        // [diem khac biet dll]: noi tat vong qua mat pdel bang ca 2 chieu
        pDel->pPrev->pNext = pDel->pNext; // nguoi dung truoc tro thang toi nguoi dung sau
        pDel->pNext->pPrev = pDel->pPrev; // nguoi dung sau tro thang ve nguoi dung truoc
    }
    
    delete pDel; // giai phong bo nho an toan
    cout << "-> da xoa thanh cong!\n";
}

// 4. sap xep (hoan doi gia tri data, khong doi con tro)
void SortList(doublelist &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return; 

    for (DNode *p = L.pHead; p != NULL; p = p->pNext) {
        for (DNode *q = p->pNext; q != NULL; q = q->pNext) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    cout << "-> danh sach da duoc sap xep tang dan!\n";
}

// 5. tim kiem
void SearchNode(doublelist L, int d) {
    DNode *p = L.pHead;
    int pos = 0;
    bool found = false;
    while(p != NULL) {
        if(p->data == d) {
            cout << "-> tim thay " << d << " tai vi tri (index): " << pos << "\n";
            found = true;
        }
        pos++;
        p = p->pNext;
    }
    if(!found) cout << "-> khong tim thay " << d << " trong danh sach!\n";
}

// 6. tim min
void FindMin(doublelist L) {
    if(L.pHead == NULL) {
        cout << "-> danh sach rong!\n";
        return;
    }
    int minVal = L.pHead->data;
    DNode *p = L.pHead->pNext;
    while(p != NULL) {
        if(p->data < minVal) minVal = p->data;
        p = p->pNext;
    }
    cout << "-> gia tri nho nhat (min) la: " << minVal << "\n";
}

int main(){
    doublelist L;
    initialize(L);
    int choice;
    int val, newVal;

    do {
        cout << "\n==== menu danh sach lien ket doi ====\n";
        cout << "1. them phan tu vao cuoi\n";
        cout << "2. sua phan tu\n";
        cout << "3. xoa phan tu\n";
        cout << "4. sap xep danh sach tang dan\n";
        cout << "5. tim kiem phan tu\n";
        cout << "6. tim phan tu nho nhat (min)\n";
        cout << "7. thoat\n";
        cout << "=====================================\n";
        
        cout << "hien tai: "; 
        printList(L);
        
        cout << "nhap lua chon cua ban (1-7): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "nhap gia tri can them: ";
                cin >> val;
                insertLast(L, val);
                break;
            case 2:
                cout << "nhap gia tri can sua: "; cin >> val;
                cout << "nhap gia tri moi: "; cin >> newVal;
                EditNode(L, val, newVal);
                break;
            case 3:
                cout << "nhap gia tri can xoa: "; cin >> val;
                RemoveNode(L, val);
                break;
            case 4:
                SortList(L);
                break;
            case 5:
                cout << "nhap gia tri can tim: "; cin >> val;
                SearchNode(L, val);
                break;
            case 6:
                FindMin(L);
                break;
            case 7:
                cout << "thoat chuong trinh...\n";
                break;
            default:
                cout << "lua chon khong hop le. vui long nhap lai!\n";
        }
    } while(choice != 7);

    return 0;
}
