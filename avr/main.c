#include <stdio.h>          /* Standard input output */
#include <avr/io.h>         /* https://github.com/vancegroup-mirrors/avr-libc/blob/master/avr-libc/include/avr/io.h */
#include <util/delay.h>     /* Util untuk delat */
#define F_CPU 16000000UL    /* Kecepatan Processor Arduino Uno (16Mhz) */

/*
    Untuk pembacaan lengkap tolong mereferensi ke
    datasheet resmi Arduino Uno,
    datasheet resmi ATMega328p
*/

void setup() {
    
    /*
        DDRB = 0000 0000

        DDRB Merupkan Data Direction Register B tujuan dari ini adalah
        membuat seluruh register bagian B menjadi OUTPUT / INPUT
        (Daftar DDRx PORTx PINx) mengacu pada referensi dari prosesor yang digunakan
        jika Arduino Uno maka ATMega328p

        Kode dibawah adalah membuat Pin 9 Pada Arduino uno menjadi OUTPUT
        sama halnya dengan yang dilakukan pinMode(9, OUTPUT)

        Bagaimana kode dibawah bekerja?

        DDRB itu valuenya 0000 0000
        kita melakukan operasi bitwise OR, dan mengassign nilai (1 << 1)
        
        apa itu (1 << 1)?
        (1 << 1) merupakan operasi bitwise yang menggeser bit ke kiri (Left Shift Operator)
        left shift di ekspresikan (nilai nya << berapa kali digeser)
        (1 << 1) berarti menginisiasi angka 1 kemudian menggesernya selama 1 kali
        
        bagaimana angka 1 itu digeser?
        angka 1 tersebut diubah terlebih dahulu menjadi bilangan biner dalam 8 bit
        yang berarti nilainya adalah 0000 0001 kemudian kita menggunakan bitwise left shift
        dan menggesernya sebanyak 1 kali ke kiri yang berarti
        
        0000 0001 => Left Shift Menjadi => 0000 0010

        Setelah itu nilai dari Left shift di assign ke DDRB menggunakan bitwise OR operator
        bitwise OR operator adalah melakukan operasi logika OR terhadap setiap bit. tapi,
        sebelum dari situ kita harus tahu dulu tabel kebenaran gerbang logika OR:

        -------------------------
        |   A   |   B   |   C   |
        -------------------------
        |   0   |   0   |   0   |
        |   1   |   0   |   1   |
        |   0   |   1   |   1   |
        |   1   |   1   |   1   |
        -------------------------

        Maka dari itu ekspresi DDRB |= (1 << 1)
        bisa kita anggap seperti ini

        DDRB    = 0000 0000 (A)
        LS      = 0000 0010 (B)
        -----------------------OR
        RESULT  = 0000 0010 (C)

        yang berati kita mensetting bit pertama menjadi OUPUT dimana bit pertama adalah PB1
        dan pada dokumentasi resmi Arduino dalam PIN Konfigurasi PB1 adalah Pin digital 9
    */
    DDRB |= (1 << 1);
}

int main() {
     /*
        Memanggil function setup() dimana akan mensetup pin 9 menjadi OUTPUT
     */
    setup();

    /*
        Looping forever agar program berjalan terus menerus
    */
    while (1)
    {
        /*
            PORTB merupakan PORT untuk mengatur apakah pin OUTPUT itu statusnya
            HIGH atau LOW (HIGH = 1) (LOW = 0)

            Dalam kasus dibawah kita akan menggunakan Bitwise Exclusive OR atau XOR
            (dibaca eks-OR)

            bagaimana kode ini bekerja?
            PORTB (B adalah letak dimana pin 9 berada karena kita menggunakan PIN 9 dan DDRB maka
            kita wajib menggunakan PORTB, jika PORT selain B maka DDR nya juga harus disesuaikan)

            PORTB   = 0000 0000
            LS      = 0000 0010 (cara menghitungnya sama seperti yang atas)

            kemudian kita menggunakan operator left shift lagi akan tetapi kita assign dengan
            operatori XOR. kita perlu terlebih dahulu mengetahui tabel kebenaran dari logika
            XOR

            -------------------------
            |   A   |   B   |   C   |
            -------------------------
            |   0   |   0   |   0   |
            |   1   |   0   |   1   |
            |   0   |   1   |   1   |
            |   1   |   1   |   0   |
            -------------------------

            maka dari itu kita lakukan operasi XOR untuk setiap bit PORTB dan LEFT SHIFT

            PORTB   = 0000 0000
            LS      = 0000 0010
            -------------------XOR
            RESULT  = 0000 0010
            PORTB = RESULT

            Maka dari itu PORTB adalah OUTPUT dimana kita akan menyalakan LED.
            
            TAPI perlu diketahui bahwa kita sedang berada didalam looping forever
            yang berarti kita akan lanjut ke iterasi selanjutnya.

            pada iterasi selanjutnya Operasi akan tetap sama menggunakan XOR operator tapi hasilnya
            akan berbeda. PORTB sudah berubah menjadi 0000 0010

            PORTB   = 0000 0010
            LS      = 0000 0010
            -------------------XOR
            RESULT  = 0000 0000
            PORTB   = RESULT

            dalam iterasi ini PORTB Bit 1 diubah menjadi 0 (LOW) dimana akan mematikan lampu LED
            dan karena ini looping forever maka cycle ini akan jalan terus menerus dengan interval
            500 milisekon
        */
        PORTB ^= (1 << 1);
        _delay_ms(500);
    }
    
}