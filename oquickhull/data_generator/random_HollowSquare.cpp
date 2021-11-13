/* Ma lap trinh nay duoc su dung trong luan van cao hoc cua Nguyen Kieu Linh.
 Copyright @ Nguyen Kieu Linh. */
 
 /* Chuong trinh nay sinh ngau nhien cac diem tren mat phang.
So luong cac diem duoc nhap vao tu ban phim.
So luong diem va toa do cac diem duoc ghi vao file. */


#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>

int random_sign()
{
	return (rand()%2) - 1;
}

int main()
{   
	int N;         		// So luong cac diem se duoc tao ngau nhien.
	int i, s1, s2;		// Tham so su dung trong qua trinh sinh ngau nhien cac diem.
	int IsContinue;		// Tham so lua chon viec chay lai chuong trinh
	float x, y; 			// Toa do cuc cua cac diem.
	int choice; 		// Cach thuc tao ngau nhien cac diem.
    float scale1, scale2, scale3, scale4;
    
    FILE *fp;
    char fname[50];
    
	do 	
    {
    	printf("Nhap so luong diem can tao ngau nhien: N = ");
    	scanf("%d", &N);
    	        
	    // Dat ten cho file se duoc dung de ghi lai thong tin ve tap hop diem
		sprintf(fname, "%d.csv", N);
		fp = fopen(fname, "w+");
        {

        for (i = 0; i < N/4; i++)
        {   scale1 = rand()/(float) RAND_MAX;
            scale2 = rand()/(float) RAND_MAX;
            y = scale1 * 100;
            x = 75 + scale2 * 25;
            fprintf(fp, "\t%5.1lf, %5.1lf\n", x, y);
        }
        for (i = N/4+1; i < N/2; i++)
            {   scale1 = rand()/(float) RAND_MAX;
                scale2 = rand()/(float) RAND_MAX;
                y = scale2 * 100;
                x = scale1 * 25;
                fprintf(fp, "\t%5.1lf, %5.1lf\n", x, y);
            }

            
        for (i = N/2 + 1; i < 3*N/4; i++)
        {   scale3 = rand()/(float) RAND_MAX;
            scale4 = rand()/(float) RAND_MAX;
            x = scale3 * 100;
            y = 75 + scale4 * 25;
            fprintf(fp, "\t%5.1lf, %5.1lf\n", x, y);
        }
    
        for (i = 3*N/4 + 1; i < N; i++)
            
            {   scale3 = rand()/(float) RAND_MAX;
                scale4 = rand()/(float) RAND_MAX;
                x = scale3 * 100;
                y = scale4 * 25;
                fprintf(fp, "\t%5.1lf, %5.1lf\n", x, y);
            }
        }

        fclose(fp);
	   	/* Tiep tuc tao bo du lieu moi hay khong? */
    	printf("Ban co muon sinh ngau nhien mot tap hop diem khac hay khong?\n");
    	printf("Nhap vao 1 neu co, 0 neu khong.\n");
    	printf("Lua chon cua ban la: ");
    	scanf("%d", &IsContinue);
    	
    } while (IsContinue == 1);
	
   // getch();
    return 0;
} 
