#include <iostream>

// Fungsi untuk menghitung FPB dari dua bilangan
int hitungFPB(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int kpk = 2940;
    int fpb = 21;
    int jumlahPasangan = 0;

    for (int num1 = 1; num1 <= kpk; num1++) {
        if (kpk % num1 == 0) {
            for (int num2 = 1; num2 <= kpk; num2++) {
                if (kpk % num2 == 0) {
                    int current_fpb = hitungFPB(num1, num2);
                    if (current_fpb == fpb) {
                        jumlahPasangan++;
                    }
                }
            }
        }
    }

    std::cout << "Jumlah pasangan angka dengan KPK 2940 dan FPB 21 adalah: " << jumlahPasangan << std::endl;

    return 0;
}
