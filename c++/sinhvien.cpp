#include<iostream>
#include<string>
using namespace std;

// ==========================================
// 1. KHAI BÁO C?U TRÚC D? LI?U
// ==========================================
struct sinhvien {
    int masv;
    string hoten;
    float diem;
};

struct Node {
    sinhvien data;
    Node *pNext;
};

struct singlelist {
    Node *pHead;
};

// ==========================================
// 2. CÁC HÀM H? TR? NH?P / XU?T 1 SINH VIÊN
// ==========================================
void nhapsv(sinhvien &sv) {
    cout << "  + Nhap ma SV: "; 
    cin >> sv.masv;
    cin.ignore(); // Xóa d?u enter th?a trong b? nh? ð?m
    
    cout << "  + Nhap ho ten: "; 
    getline(cin, sv.hoten);
    
    cout << "  + Nhap diem: "; 
    cin >> sv.diem;
}

void insv(sinhvien sv) {
    cout << "[Ma SV: " << sv.masv << " | Ho ten: " << sv.hoten << " | Diem: " << sv.diem << "]";
}

// ==========================================
// 3. CÁC HÀM QU?N L? DANH SÁCH LIÊN K?T ÐÕN
// ==========================================
void initialize(singlelist &L){
    L.pHead = NULL;
}

Node *createNode(sinhvien d){
    Node *p = new Node;
    p->data = d;
    p->pNext = NULL;
    return p;
}

// Thêm sinh viên vào cu?i danh sách
void insertLast(singlelist &L, sinhvien d){
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

// In toàn b? danh sách sinh viên
void printList(singlelist L){
    Node *p = L.pHead;
    if(L.pHead == NULL){
        cout << "Danh sach rong!";
    }else{
        cout << "\n";
        while(p != NULL){
            insv(p->data);
            cout << "\n";
            p = p->pNext;
        }
    }
}

// S?a thông tin sinh viên d?a vào M? SV
void EditNode(singlelist &L, int maCanSua) {
    Node *p = L.pHead;
    bool found = false;
    while(p != NULL) {
        if(p->data.masv == maCanSua) {
            cout << "-> Da tim thay sinh vien. Nhap thong tin moi:\n";
            nhapsv(p->data); // Nh?p ðè d? li?u m?i vào node hi?n t?i
            found = true;
            break; 
        }
        p = p->pNext;
    }
    if(found) cout << "-> Da sua thong tin thanh cong!\n";
    else cout << "-> Khong tim thay sinh vien co ma " << maCanSua << " de sua!\n";
}

// Xóa sinh viên d?a vào M? SV
void RemoveNode(singlelist &L, int maCanXoa) {
    Node *pDel = L.pHead;
    if (pDel == NULL) {
        cout << "-> Danh sach rong!\n";
    } else {
        Node *pPre = NULL;
        while (pDel != NULL) {
            if (pDel->data.masv == maCanXoa) break; 
            pPre = pDel;           
            pDel = pDel->pNext;    
        }
        if (pDel == NULL) {
            cout << "-> Khong tim thay sinh vien ma " << maCanXoa << " de xoa!\n";
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

// S?p x?p danh sách tãng d?n THEO ÐI?M
void SortList(singlelist &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return; 

    for (Node *p = L.pHead; p != NULL; p = p->pNext) {
        for (Node *q = p->pNext; q != NULL; q = q->pNext) {
            // So sánh d?a trên ði?m c?a sinh viên
            if (p->data.diem > q->data.diem) {
                // Hoán ð?i toàn b? c?c d? li?u sinh viên
                sinhvien temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    cout << "-> Danh sach da duoc sap xep tang dan THEO DIEM!\n";
}

// T?m ki?m sinh viên THEO M? SV
void SearchNode(singlelist L, int maCanTim) {
    Node *p = L.pHead;
    int pos = 0;
    bool found = false;
    while(p != NULL) {
        if(p->data.masv == maCanTim) {
            cout << "-> Tim thay tai vi tri (index) " << pos << ":\n  ";
            insv(p->data);
            cout << "\n";
            found = true;
        }
        pos++;
        p = p->pNext;
    }
    if(!found) cout << "-> Khong tim thay sinh vien ma " << maCanTim << "!\n";
}

// T?m sinh viên có ÐI?M TH?P NH?T (Min)
void FindMin(singlelist L) {
    if(L.pHead == NULL) {
        cout << "-> Danh sach rong!\n";
        return;
    }
    float minVal = L.pHead->data.diem;
    Node *pMin = L.pHead; // Gi? l?i con tr? ð? in thông tin SV ðó ra
    
    Node *p = L.pHead->pNext;
    while(p != NULL) {
        if(p->data.diem < minVal) {
            minVal = p->data.diem;
            pMin = p; 
        }
        p = p->pNext;
    }
    cout << "-> Sinh vien co diem thap nhat la:\n  ";
    insv(pMin->data);
    cout << "\n";
}

// ==========================================
// 4. HÀM MAIN - MENU CHÍNH
// ==========================================
int main(){
    singlelist L;
    initialize(L);
    int choice;
    int maTimKiem; // Dùng chung cho Xóa, S?a, T?m ki?m

    do {
        cout << "\n============== MENU QUAN LY SINH VIEN ==============\n";
        cout << "1. Them sinh vien vao cuoi danh sach\n";
        cout << "2. Sua thong tin sinh vien (Theo Ma SV)\n";
        cout << "3. Xoa sinh vien (Theo Ma SV)\n";
        cout << "4. Sap xep danh sach tang dan THEO DIEM\n";
        cout << "5. Tim kiem sinh vien (Theo Ma SV)\n";
        cout << "6. Tim sinh vien co diem thap nhat (Min Diem)\n";
        cout << "7. Thoat\n";
        cout << "====================================================\n";
        
        cout << "\n--- DANH SACH HIEN TAI ---"; 
        printList(L);
        cout << "--------------------------\n";
        
        cout << "Nhap lua chon cua ban (1-7): ";
        cin >> choice;

        switch(choice) {
            case 1: {
                sinhvien svMoi;
                cout << "-> Nhap thong tin sinh vien moi:\n";
                nhapsv(svMoi);
                insertLast(L, svMoi);
                break;
            }
            case 2:
                cout << "-> Nhap Ma SV can sua: "; 
                cin >> maTimKiem;
                EditNode(L, maTimKiem);
                break;
            case 3:
                cout << "-> Nhap Ma SV can xoa: ";
                cin >> maTimKiem;
                RemoveNode(L, maTimKiem);
                break;
            case 4:
                SortList(L);
                break;
            case 5:
                cout << "-> Nhap Ma SV can tim: ";
                cin >> maTimKiem;
                SearchNode(L, maTimKiem);
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
