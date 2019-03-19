/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    if(numRows <= 0) return NULL;
    
    *columnSizes = (int *)malloc(sizeof(int) * numRows);    
    int **p = (int **)malloc(sizeof(int *) * numRows);
    memset(p, 0, sizeof(int *) * numRows);
    
    for (int i = 1; i <= numRows; i++)
    {
        int *parray = (int *)malloc(sizeof(int) * i);
        memset(parray, 0, sizeof(int) * i);
        //now we set the values of row[i]...
        if (i == 1)
        {
            parray[0] = 1;
        }
        else if (i == 2)
        {
            parray[0] = 1;
            parray[1] = 1;
        }
        else
        {
            int* pPreArray = p[i - 2];
            for(int j = 1; j < i - 1; j++)
            {
                parray[j] = pPreArray[j-1] + pPreArray[j];
            }
            
            parray[0] = 1;
            parray[i - 1] = 1; 
        }

        
        p[i-1] = parray;
        (*columnSizes)[i-1] = i;
    }
    
    return p;
}
