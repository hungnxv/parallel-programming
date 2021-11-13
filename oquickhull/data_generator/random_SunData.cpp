/* Ma lap trinh nay duoc su dung trong luan van cao hoc cua Nguyen Kieu Linh.
 Copyright @ Nguyen Kieu Linh. */
 
 /* Chuong trinh nay sinh ngau nhien cac diem tren mat phang.
So luong cac diem duoc nhap vao tu ban phim.
So luong diem va toa do cac diem duoc ghi vao file. */


#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>


int main()
{   
	int N, p;         		// So luong cac diem se duoc tao ngau nhien.
    int i;   		// Tham so su dung trong qua trinh sinh ngau nhien cac diem.
	int IsContinue;		// Tham so lua chon viec chay lai chuong trinh
	float alpha, BanKinh, a, b; // Toa do cuc cua cac diem.
	//int choice; 		// Cach thuc tao ngau nhien cac diem.
	double k;
	
   	FILE *fp;
    char fname[50];
    
	do 	
    {
    	printf("Nhap so luong diem can tao ngau nhien: N = ");
    	scanf("%d", &N);
    	        
	    // Dat ten cho file se duoc dung de ghi lai thong tin ve tap hop diem
		sprintf(fname, "%d.csv", N); 
		k = N * 0.4; 
		p = (int) k;
		
  	
			fp = fopen(fname, "w+");
		    	//fprintf(fp, "%d \n", N);
		             
        for (i = 0; i < N; i++)
        
        
			{
				alpha = rand()%100;  // goc
				BanKinh = rand()%300; // ban kinh
				a = (float) (BanKinh*sin(alpha));
				b = (float) (BanKinh*cos(alpha));
				fprintf(fp, "\t%5.1lf, %5.1lf\n", a, b);
			}
			fclose(fp);
		
		
	   	/* Tiep tuc tao bo du lieu moi hay khong? */
    	printf("Ban co muon sinh ngau nhien mot tap hop diem khac hay khong?\n");
    	printf("Nhap vao 1 neu co, 0 neu khong.\n");
    	printf("Lua chon cua ban la: ");
    	scanf("%d", &IsContinue);
    	
    } while (IsContinue == 1);
	
    //getch();
    return 0;
} 
