#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL


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

        DDRB
    */
    DDRB |= (1 << 1);
}

int main() {
    setup(); /*Membuat Pin 9 menjadi OUTPUT*/

    
    while (1)
    {
        PORTB ^= (1 << 1);
        _delay_ms(500);
    }
    
}