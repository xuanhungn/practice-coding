#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // B? sung thý vi?n này ð? dùng hàm swap

using namespace std;

// ==========================================
// 1. KHAI BÁO C?U TRÚC D? LI?U KHÁCH HÀNG
// ==========================================
struct KhachHang {
    string maKH;        
    string hoTen;       
    string sdt;         
    double soDu;        
    string email;       
    string diaChi;      
    string loaiKH;      
    int diemTichLuy;    
    bool trangThai;     
};

struct Node {
    KhachHang data;
    Node *pNext;
};

struct SingleList {
    Node *pHead;
};

// ==========================================
// 2. CÁC HÀM H? TR? NH?P / XU?T
// ==========================================
void khoiTao(SingleList &L) {
    L.pHead = NULL;
}

void nhapThongTinKH(KhachHang &kh) {
    cout << "  - Ma KH: "; cin >> kh.maKH;
    cin.ignore(); // Xóa b? ð?m trý?c khi nh?p chu?i có kho?ng tr?ng
    cout << "  - Ho ten: "; getline(cin, kh.hoTen);
    cout << "  - So dien thoai: "; cin >> kh.sdt;
    cout << "  - So du ban dau: "; cin >> kh.soDu;
    cin.ignore();
    cout << "  - Email: "; getline(cin, kh.email);
    cout << "  - Dia chi: "; getline(cin, kh.diaChi);
    kh.loaiKH = "Dong";
    kh.diemTichLuy = 0;
    kh.trangThai = true;
}

void xuatMotKH(KhachHang kh) {
    cout << left << setw(10) << kh.maKH 
         << setw(20) << kh.hoTen 
         << setw(15) << kh.sdt 
         << setw(15) << fixed << setprecision(0) << kh.soDu 
         << setw(10) << kh.loaiKH 
         << setw(8) << kh.diemTichLuy 
         << (kh.trangThai ? "[Active]" : "[Locked]") << endl;
}

// ==========================================
// 3. TRI?N KHAI 20 CH?C NÃNG H? TH?NG
// ==========================================

Node* createNode(KhachHang kh) {
    Node *p = new Node;
    p->data = kh;
    p->pNext = NULL;
    return p;
}

void insertLast(SingleList &L, KhachHang kh) {
    Node *p = createNode(kh);
    if (L.pHead == NULL) L.pHead = p;
    else {
        Node *temp = L.pHead;
        while (temp->pNext != NULL) temp = temp->pNext;
        temp->pNext = p;
    }
    cout << "-> Them khach hang thanh cong!\n";
}

void printList(SingleList L) {
    if (L.pHead == NULL) {
        cout << "Danh sach trong!\n";
        return;
    }
    cout << "\n" << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
    cout << left << setw(10) << "Ma KH" << setw(20) << "Ho Ten" << setw(15) << "SDT" 
         << setw(15) << "So Du" << setw(10) << "Hang" << setw(8) << "Diem" << "Trang Thai" << endl;
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
    for (Node *p = L.pHead; p != NULL; p = p->pNext) xuatMotKH(p->data);
}

Node* searchById(SingleList L, string id) {
    for (Node *p = L.pHead; p != NULL; p = p->pNext) {
        if (p->data.maKH == id) return p;
    }
    return NULL;
}

void updateInfo(SingleList &L, string id) {
    Node *p = searchById(L, id);
    if (p) {
        cout << "Nhap ten moi: "; cin.ignore(); getline(cin, p->data.hoTen);
        cout << "Nhap dia chi moi: "; getline(cin, p->data.diaChi);
        cout << "-> Cap nhat thanh cong!\n";
    } else cout << "-> Khong tim thay khach hang!\n";
}

void removeById(SingleList &L, string id) {
    Node *pDel = L.pHead, *pPre = NULL;
    while (pDel != NULL && pDel->data.maKH != id) {
        pPre = pDel; pDel = pDel->pNext;
    }
    if (pDel == NULL) {
        cout << "-> Khong tim thay khach hang!\n";
        return;
    }
    if (pPre == NULL) L.pHead = pDel->pNext;
    else pPre->pNext = pDel->pNext;
    delete pDel;
    cout << "-> Da xoa thanh cong!\n";
}

void deposit(SingleList &L, string id, double amount) {
    Node *p = searchById(L, id);
    if (p) {
        p->data.soDu += amount;
        p->data.diemTichLuy += (int)(amount / 100000); 
        cout << "-> Nap tien thanh cong!\n";
    } else cout << "-> Khong tim thay khach hang!\n";
}

void withdraw(SingleList &L, string id, double amount) {
    Node *p = searchById(L, id);
    if (p) {
        if (p->data.soDu >= amount) {
            p->data.soDu -= amount;
            cout << "-> Rut tien thanh cong!\n";
        } else cout << "-> So du khong du!\n";
    } else cout << "-> Khong tim thay khach hang!\n";
}

void transfer(SingleList &L, string idGui, string idNhan, double amount) {
    Node *nguoiGui = searchById(L, idGui);
    Node *nguoiNhan = searchById(L, idNhan);
    if (nguoiGui && nguoiNhan) {
        if (nguoiGui->data.soDu >= amount) {
            nguoiGui->data.soDu -= amount;
            nguoiNhan->data.soDu += amount;
            cout << "-> Chuyen khoan thanh cong!\n";
        } else cout << "-> So du nguoi gui khong du!\n";
    } else cout << "-> Thong tin nguoi gui hoac nhan khong ton tai!\n";
}

void sortByBalance(SingleList &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    for (Node *i = L.pHead; i != NULL; i = i->pNext) {
        for (Node *j = i->pNext; j != NULL; j = j->pNext) {
            if (i->data.soDu > j->data.soDu) swap(i->data, j->data);
        }
    }
    cout << "-> Da sap xep danh sach tang dan theo so du!\n";
}

void findMinBalance(SingleList L) {
    if (!L.pHead) { cout << "Danh sach trong!\n"; return; }
    Node *minNode = L.pHead;
    for (Node *p = L.pHead->pNext; p != NULL; p = p->pNext) {
        if (p->data.soDu < minNode->data.soDu) minNode = p;
    }
    cout << "-> KH co so du thap nhat:\n";
    xuatMotKH(minNode->data);
}

void findMaxBalance(SingleList L) {
    if (!L.pHead) { cout << "Danh sach trong!\n"; return; }
    Node *maxNode = L.pHead;
    for (Node *p = L.pHead->pNext; p != NULL; p = p->pNext) {
        if (p->data.soDu > maxNode->data.soDu) maxNode = p;
    }
    cout << "-> KH VIP nhat:\n";
    xuatMotKH(maxNode->data);
}

void lockAccount(SingleList &L, string id) {
    Node *p = searchById(L, id);
    if (p) { p->data.trangThai = false; cout << "-> Da khoa tai khoan!\n"; }
    else cout << "-> Khong tim thay!\n";
}

void unlockAccount(SingleList &L, string id) {
    Node *p = searchById(L, id);
    if (p) { p->data.trangThai = true; cout << "-> Da mo khoa tai khoan!\n"; }
    else cout << "-> Khong tim thay!\n";
}

void autoUpgrade(SingleList &L) {
    for (Node *p = L.pHead; p != NULL; p = p->pNext) {
        if (p->data.diemTichLuy >= 100) p->data.loaiKH = "Kim Cuong";
        else if (p->data.diemTichLuy >= 50) p->data.loaiKH = "Vang";
        else if (p->data.diemTichLuy >= 20) p->data.loaiKH = "Bac";
    }
    cout << "-> Da cap nhat hang cho toan bo danh sach!\n";
}

void redeemPoints(SingleList &L, string id) {
    Node *p = searchById(L, id);
    if (p) {
        if (p->data.diemTichLuy >= 10) {
            p->data.diemTichLuy -= 10;
            p->data.soDu += 50000;
            cout << "-> Da doi 10 diem lay 50.000 VND. So du moi: " << fixed << setprecision(0) << p->data.soDu << "\n";
        } else cout << "-> Khong du 10 diem de doi!\n";
    } else cout << "-> Khong tim thay!\n";
}

double getTotalSystemBalance(SingleList L) {
    double total = 0;
    for (Node *p = L.pHead; p != NULL; p = p->pNext) total += p->data.soDu;
    return total;
}

int countActive(SingleList L) {
    int count = 0;
    for (Node *p = L.pHead; p != NULL; p = p->pNext) if (p->data.trangThai) count++;
    return count;
}

void changePassword(SingleList &L, string id) {
    Node *p = searchById(L, id);
    if (p) cout << "-> Da gui yeu cau cap lai mat khau cho KH " << id << ".\n";
    else cout << "-> Khong tim thay!\n";
}

void searchByName(SingleList L, string name) {
    bool found = false;
    for (Node *p = L.pHead; p != NULL; p = p->pNext) {
        // T?m ki?m chu?i con (không phân bi?t n?u nh?p ðúng in hoa/thý?ng)
        if (p->data.hoTen.find(name) != string::npos) {
            xuatMotKH(p->data);
            found = true;
        }
    }
    if (!found) cout << "-> Khong co ket qua phu hop!\n";
}

// ==========================================
// 4. HÀM MAIN - MENU
// ==========================================
int main() {
    SingleList L;
    khoiTao(L);
    int choice;
    string id1, id2, str;
    double soTien; // Bi?n chuyên d?ng cho ti?n b?c

    do {
        cout << "\n======= MENU QUAN LY KHACH HANG (20 CHUC NANG) =======\n";
        cout << " 1. Them KH       |  2. Xem DS        |  3. Sua thong tin \n";
        cout << " 4. Xoa KH        |  5. Tim theo Ma   |  6. Nap tien      \n";
        cout << " 7. Rut tien      |  8. Chuyen tien   |  9. Sap xep So du \n";
        cout << "10. Tim Min So du | 11. Tim Max So du | 12. Khoa TK       \n";
        cout << "13. Mo khoa TK    | 14. Cap nhat Hang | 15. Doi diem      \n";
        cout << "16. Tong tien HT  | 17. Dem Active    | 18. Doi mat khau  \n";
        cout << "19. Tim theo ten  | 20. Thoat                           \n";
        cout << "======================================================\n";
        cout << "Nhap lua chon (1-20): "; 
        cin >> choice;

        switch(choice) {
            case 1: { KhachHang kh; nhapThongTinKH(kh); insertLast(L, kh); break; }
            case 2: printList(L); break;
            case 3: cout << "Ma KH can sua: "; cin >> id1; updateInfo(L, id1); break;
            case 4: cout << "Ma KH can xoa: "; cin >> id1; removeById(L, id1); break;
            case 5: cout << "Ma KH can tim: "; cin >> id1; 
                    if(searchById(L, id1)) xuatMotKH(searchById(L, id1)->data); 
                    else cout << "Khong tim thay!\n"; 
                    break;
            case 6: cout << "Ma KH: "; cin >> id1; cout << "So tien nap: "; cin >> soTien; deposit(L, id1, soTien); break;
            case 7: cout << "Ma KH: "; cin >> id1; cout << "So tien rut: "; cin >> soTien; withdraw(L, id1, soTien); break;
            case 8: cout << "Ma KH Gui: "; cin >> id1; cout << "Ma KH Nhan: "; cin >> id2; cout << "So tien: "; cin >> soTien; transfer(L, id1, id2, soTien); break;
            case 9: sortByBalance(L); break;
            case 10: findMinBalance(L); break;
            case 11: findMaxBalance(L); break;
            case 12: cout << "Ma KH can khoa: "; cin >> id1; lockAccount(L, id1); break;
            case 13: cout << "Ma KH can mo khoa: "; cin >> id1; unlockAccount(L, id1); break;
            case 14: autoUpgrade(L); break;
            case 15: cout << "Ma KH doi diem: "; cin >> id1; redeemPoints(L, id1); break;
            case 16: cout << "Tong tien he thong: " << fixed << setprecision(0) << getTotalSystemBalance(L) << endl; break;
            case 17: cout << "So KH dang hoat dong: " << countActive(L) << endl; break;
            case 18: cout << "Ma KH doi pass: "; cin >> id1; changePassword(L, id1); break;
            case 19: cout << "Ten can tim: "; cin.ignore(); getline(cin, str); searchByName(L, str); break;
            case 20: cout << "Dang thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le, vui long nhap tu 1 den 20!\n";
        }
    } while(choice != 20);

    return 0;
}
