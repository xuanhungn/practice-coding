#include<iostream>
#include<string>
using namespace std;

struct Sach{
    string TenSach;
    double GiaBan;
};

void invao(Sach *ds, int n){
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sach :";
        cout << "  + Nhap ten sach : ";
        getline(cin>>ws,ds[i].TenSach);
        cout << "  + Nhap gia sach : ";
        cin >> ds[i].GiaBan;
    }
}


void nhapvao(Sach *ds, int n){
    double tong = 0;
    for(int i = 0; i < n; i++){
        cout << i + 1 << " . " << ds[i].TenSach << " | " << " Gia : " << ds[i].GiaBan << endl;
        tong = tong + ds[i].GiaBan;

}
      double tbtong = tong / n;
     
      cout << "====> Gia trung binh cac cuan sach la : " << tbtong << endl;
}


int main (){
    int n;

    cout << "nhap so luong cau sach :";

    cin >> n;

    Sach *ds = new Sach[n];

    invao (ds, n);

    nhapvao(ds, n);

    delete []ds;




    return 0;
}