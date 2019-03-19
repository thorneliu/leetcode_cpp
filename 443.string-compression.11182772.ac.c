int compress(char* chars, int charsSize) {
    int j = -1, cnt = 0;
    char curChar = 0;
    
    for (int i = 0; i < charsSize; i++)
    {
        if (chars[i] != curChar)
        {
            // now we have a new one char, fill the old char contents
            if(curChar != 0)
            {
                chars[++j] = curChar;
                //printf("A: chars[%d] = %c\n", j, curChar);
            }
            //printf("B: cnt = %d, j = %d, curChar = %c\n", cnt, j, curChar);
            if (cnt > 1)
            {
                // we need to fill in the numbers if cnt ones of curchars
                char *p1 = chars + j + 1;
                //printf("%x\n", p1);
                while(cnt)
                {
                    chars[++j] = '0' + cnt % 10;
                    cnt = cnt / 10;
                    //printf("C: char[%d] = %c\n", j, chars[j]);
                }
                char *p2 = chars + j;
                //printf("%x\n", p2);
                char temp;
                while(p1 < p2)
                {
                    temp = *p1;
                    *p1 = *p2;
                    *p2 = temp;
                    p1++;
                    p2--;
                }
            }
            
            curChar = chars[i];
            cnt = 1;
            //printf("D: chars[%d] = %c, cnt = %d, j = %d, curChar = %c\n", i, chars[i], cnt, j, curChar);
        }
        else
        {
            cnt++;
            //printf("E: curChar = %c -> cnt++ = %d\n", curChar, cnt);
        }
    }
    
    // when we reach the end, we should fill in the last one, right?
    chars[++j] = curChar;
    if (cnt > 1)
    {
        // we need to fill in the numbers if cnt ones of curchars
        char *p1 = chars + j + 1;
        //printf("%x\n", p1);
        while(cnt)
        {
            chars[++j] = '0' + cnt % 10;
            cnt = cnt / 10;
            //printf("F: char[%d] = %c\n", j, chars[j]);
        }
        char *p2 = chars + j;
        //printf("%x\n", p2);
        char temp;
        while(p1 < p2)
        {
            temp = *p1;
            *p1 = *p2;
            *p2 = temp;
            p1++;
            p2--;
        }
    }
    
    return j+1;
}
