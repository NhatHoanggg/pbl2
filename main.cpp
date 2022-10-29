#include <iostream>
#include <fstream>
#include <iomanip>
#include "khach.h"

using namespace std;

room x;

void xuly1(int sl) {
    guest g;
    g.getInfo1(sl, x);
}

void xuly2(int sl) {
    guest g;
    g.getInfo2(sl, x);
}

void xuly3(int sl) {
    guest g;
    g.getInfo3(sl, x);
}

void xuly4(int sl) {
    guest g;
    g.getInfo4(sl, x);
}

void xuly5(int sl) {
    guest g;
    g.getInfo5(sl, x);
}

void xuly6(int sl) {
    guest g;
    g.getInfo6(sl, x);
}

void phimdangchieu() {
    system("cls");
    cout << "\t\t+===================================================================================================================+" << endl;
    cout << "\t\t|                                                ** PHIM DANG CHIEU **                                              |" << endl;
    cout << "\t\t+===+=========================================+=================+===================================================+" << endl;
    cout << "\t\t| Ma|        Ten Phim                         |    Thoi Luong   |       The Loai                                    |" << endl;
    cout << "\t\t+===+=========================================+=================+===================================================+" << endl;
    cout << "\t\t|MV1| Minions: The Rise of Gru                |        87 min   | Hoat Hinh, Hai Huoc                               |" << endl;
    cout << "\t\t|MV2| Bong Dung Trung So                      |       113 min   | Hai Huoc                                          |" << endl;
    cout << "\t\t|MV3| Black Adam                              |       125 min   | Phieu Luu, Hanh Dong                              |" << endl;
    cout << "\t\t|MV4| Quai Vat Song Mekong                    |       105 min   | Hanh Dong, Bi An,                                 |" << endl;
    cout << "\t\t|MV5| Co Gai Tu Qua Khu                       |       105 min   | Tam Ly, Ly Ki                                     |" << endl;
    cout << "\t\t|MV6| Mon Phai Vo Meo                         |        97 min   | Hanh Dong, Hoat Hinh, Hai                         |" << endl;
    cout << "\t\t+===+=========================================+=================+===================================================+" << endl << endl;
}


int main()
{
    x.setData();
    
    char stop = 'N';
    do
    {
        system("cls");
        cout << "\t\t\tNHAP LUA CHON CUA BAN: " << endl;
        cout << "\t\t\t\t 1:Mua ve xem phim." << endl;
        cout << "\t\t\t\t 2:Huy ve xem phim." << endl;
        cout << "\t\t\t\t -> Lua chon cua ban la : "; 
        int chon; 
        cin >> chon;
        if (chon == 1) {
            phimdangchieu();
            string c;
            cout << "\t\tNhap ma phim ban muon xem: ";
            cin >> c;
            int sl = 0;
            sl = int(c[2]) - 48; // chon film . 
            switch (sl) {
            case(1):
                xuly1(sl);
                break;
            case(2):
                xuly2(sl);
                break;
            case(3):
                xuly3(sl);
                break;
            case(4):
                xuly4(sl);
                break;
            case(5):
                xuly5(sl);
                break;
            case(6):
                xuly6(sl);
                break;
            }
        }
    cout << "\t\tBAN CO MUON TIEP TUC CHUONG TRINH BAN VE XEM PHIM HAY KHONG? [Y/N]    ";
    cin >> stop;
    stop = toupper(stop); // stop conditions;
    } while (stop == 'Y');

    cout << endl;
    cout << "\t\t______________________________________CHUONG TRINH BAN VE XEM PHIM KET THUC______________________________________________" << endl;

    
    return 0;
}



/*


*/



