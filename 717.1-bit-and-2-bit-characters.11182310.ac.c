bool isOneBitCharacter(int* bits, int bitsSize) {
    int bit = 0;
    int isOneBit = 0;
    for (int i = 0; i < bitsSize; ) {
        bit = bits[i];
        if(bit == 0) {
            i++;
            isOneBit = 1;
        }
        if(bit == 1) {
            i=i+2;
            isOneBit = 0;
        }
    }
    
    return isOneBit;
}
