#include <iostream>
#include <queue>
#include <string>

using namespace std;

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah pelanggan ke antrian\n";
    cout << "2. Layani pelanggan dari antrian\n";
    cout << "3. Tampilkan antrian\n";
    cout << "4. Keluar\n";
    cout << "Pilih opsi: ";
}

void addCustomer(queue<string>& q) {
    string customer;
    cout << "Masukkan nama pelanggan: ";
    cin >> customer;
    q.push(customer);
    cout << customer << " telah ditambahkan ke antrian.\n";
}

void serveCustomer(queue<string>& q) {
    if (q.empty()) {
        cout << "Antrian kosong, tidak ada pelanggan untuk dilayani.\n";
    } else {
        cout << q.front() << " telah dilayani.\n";
        q.pop();
    }
}

void displayQueue(queue<string> q) {
    if (q.empty()) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "Antrian saat ini: ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
}

int main() {
    queue<string> q;
    string choice;
    
    while (true) {
        showMenu();
        int option;
        cin >> option;
        
        switch (option) {
            case 1:
                addCustomer(q);
                break;
            case 2:
                serveCustomer(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                cout << "Apakah Anda ingin keluar? (yes/no): ";
                cin >> choice;
                if (choice == "yes") {
                    cout << "Terima kasih, sampai jumpa!\n";
                    return 0;
                }
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }
    return 0;
}
