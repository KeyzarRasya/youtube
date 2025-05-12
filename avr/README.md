DDRx    =   Menentukan Pin mana yang akan dijadikan INPUT/OUTPUT (1 = OUTPUT | 0 = INPUT)
PORTx   =   Mengubah Port Output menjadi HIGH/LOW (1 = HIGH | 0 LOW)
PINx    =   Membaca Nilai INPUT

[NOTE]
Register di Arduino itu 8 bit = 0000 0000

Untuk Compile dan Flash ada tiga langkah :
1. avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf main.c   : compile .c menjadi .elf
2. avr-objcopy -O ihex -R .eeprom main.elf main.hex                     : mengubah .elf menjadi .hex file
3. avrdude -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex:i  : Flash ke Arduino
