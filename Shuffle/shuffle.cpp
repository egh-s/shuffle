#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>

char files[20][100] = {
   "test1.binpack",
   "test2.binpack",
   "xxx" };

FILE *fpc;
char w[200],fn[200],buf1[100],buf2[100],buf3[100];
int count=0;
unsigned long long binpacks=0;
unsigned long long verify = 0;
int x, y;
unsigned long long zettel;
unsigned long long k1,k2,k3,k4,k5;
int n = 0;
int t1, t2, time_taken;
FILE* fp, * fp1, * fp2, * fp3, * fp4, * fp5, * fp6, * fp7, * fp8, * fp9, * fp10, * fp11, * fp12;

void puntjes(void);
void display_time(void);

int main(int argc, char *argv[]) {   

		clock_t t1;
		t1 = clock();
		clock_t t2;

		strcpy(fn, files[n]);
        fpc=fopen(fn,"rb");	          
        if (fpc==0) { printf("File %s not present, do your homework ",fn);  gets_s(w); exit(1); }
	  	
		fp1 = fopen("p1.bin", "wb");
		fp2 = fopen("p2.bin", "wb");
		fp3 = fopen("p3.bin", "wb");
		fp4 = fopen("p4.bin", "wb");
		fp5 = fopen("p5.bin", "wb");
		fp6 = fopen("p6.bin", "wb");
		fp7 = fopen("p7.bin", "wb");
		fp8 = fopen("p8.bin", "wb");
		fp9 = fopen("p9.bin", "wb");
		fp10 = fopen("p10.bin", "wb");
		fp11 = fopen("p11.bin", "wb");
		fp12 = fopen("p12.bin", "wb");

		printf("\nShuffling %s\n",fn);

lees:   x=fread(&k1,8,1,fpc); if (x<1) { fclose(fpc); goto klaar; }
	    fread(&k2,8,1,fpc);
	    fread(&k3,8,1,fpc);
	    fread(&k4,8,1,fpc);
	    fread(&k5,8,1,fpc);
		binpacks++;
		count++; if (count > 12) count = 1;

		if (binpacks % 1000000 == 0) { zettel = binpacks; puntjes(); printf("Shuffling %s\n", buf2); }	// each one million

		if (binpacks % 100000000 == 0) display_time();	// each 100 million

		switch (count) {
		case 1: { fwrite(&k1, 8, 1, fp1); fwrite(&k2, 8, 1, fp1); fwrite(&k3, 8, 1, fp1); fwrite(&k4, 8, 1, fp1); fwrite(&k5, 8, 1, fp1); goto lees; }
		case 2: { fwrite(&k1, 8, 1, fp2); fwrite(&k2, 8, 1, fp2); fwrite(&k3, 8, 1, fp2); fwrite(&k4, 8, 1, fp2); fwrite(&k5, 8, 1, fp2); goto lees; }
		case 3: { fwrite(&k1, 8, 1, fp3); fwrite(&k2, 8, 1, fp3); fwrite(&k3, 8, 1, fp3); fwrite(&k4, 8, 1, fp3); fwrite(&k5, 8, 1, fp3); goto lees; }
		case 4: { fwrite(&k1, 8, 1, fp4); fwrite(&k2, 8, 1, fp4); fwrite(&k3, 8, 1, fp4); fwrite(&k4, 8, 1, fp4); fwrite(&k5, 8, 1, fp4); goto lees; }
		case 5: { fwrite(&k1, 8, 1, fp5); fwrite(&k2, 8, 1, fp5); fwrite(&k3, 8, 1, fp5); fwrite(&k4, 8, 1, fp5); fwrite(&k5, 8, 1, fp5); goto lees; }
		case 6: { fwrite(&k1, 8, 1, fp6); fwrite(&k2, 8, 1, fp6); fwrite(&k3, 8, 1, fp6); fwrite(&k4, 8, 1, fp6); fwrite(&k5, 8, 1, fp6); goto lees; }
		case 7: { fwrite(&k1, 8, 1, fp7); fwrite(&k2, 8, 1, fp7); fwrite(&k3, 8, 1, fp7); fwrite(&k4, 8, 1, fp7); fwrite(&k5, 8, 1, fp7); goto lees; }
		case 8: { fwrite(&k1, 8, 1, fp8); fwrite(&k2, 8, 1, fp8); fwrite(&k3, 8, 1, fp8); fwrite(&k4, 8, 1, fp8); fwrite(&k5, 8, 1, fp8); goto lees; }
		case 9: { fwrite(&k1, 8, 1, fp9); fwrite(&k2, 8, 1, fp9); fwrite(&k3, 8, 1, fp9); fwrite(&k4, 8, 1, fp9); fwrite(&k5, 8, 1, fp9); goto lees; }
		case 10: { fwrite(&k1, 8, 1, fp10); fwrite(&k2, 8, 1, fp10); fwrite(&k3, 8, 1, fp10); fwrite(&k4, 8, 1, fp10); fwrite(&k5, 8, 1, fp10); goto lees; }
		case 11: { fwrite(&k1, 8, 1, fp11); fwrite(&k2, 8, 1, fp11); fwrite(&k3, 8, 1, fp11); fwrite(&k4, 8, 1, fp11); fwrite(&k5, 8, 1, fp11); goto lees; }
		case 12: { fwrite(&k1, 8, 1, fp12); fwrite(&k2, 8, 1, fp12); fwrite(&k3, 8, 1, fp12); fwrite(&k4, 8, 1, fp12); fwrite(&k5, 8, 1, fp12); goto lees; }
		}

        goto lees;


klaar:  n++;
		strcpy(fn, files[n]);
		if (strcmp(fn, "xxx") == 0) goto done;

		fpc = fopen(fn, "rb");
		if (fpc == 0) { printf("File %s not present, do your homework ", fn);  gets_s(w); exit(1); }

		goto lees;


done:  	fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		fclose(fp5);
		fclose(fp6);
		fclose(fp7);
		fclose(fp8);
		fclose(fp9);
		fclose(fp10);
		fclose(fp11);
		fclose(fp12);
		fclose(fpc);

		zettel = binpacks; puntjes(); strcpy(buf3, buf2);

		display_time();
		
		printf("\nWriting 'shuffled.binpack'");

		system("copy /b p1.bin + p2.bin + p3.bin + p4.bin + p5.bin + p6.bin + p7.bin + p8.bin + p9.bin + p10.bin + p11.bin + p12.bin shuffled.binpack");

		printf("\nDone, shuffled : %s binpacks, saved as 'shuffled.binpack'\n\n",buf2);

		display_time();

		remove("p1.bin");
		remove("p2.bin");
		remove("p3.bin");
		remove("p4.bin");
		remove("p5.bin");
		remove("p6.bin");
		remove("p7.bin");
		remove("p8.bin");
		remove("p9.bin");
		remove("p10.bin");
		remove("p11.bin");
		remove("p12.bin");

		printf("\nPress 'enter' to exit program  ");
        gets_s(w);

		return 0;
}

void display_time()					// input  = time_taken in seconds
									// output = buf1 -> time + NPS
{
	int h, m, s;
	
	t2 = clock();
	t2 = t2 - t1;
	time_taken = t2 / CLOCKS_PER_SEC;

	zettel = binpacks / time_taken;
	puntjes();

	h = time_taken / 3600;
	if (h) time_taken -= (h * 3600);

	m = time_taken / 60;
	if (m) time_taken -= (m * 60);

	s = time_taken;

	sprintf(buf1, "%d:%02d:%02d NPS : %s\n", h, m, s,buf2); 

	printf("Elapsed time %s", buf1);
}

void puntjes()						// input = zettel
									// output= string buf2
{
	int l, x;						// uses string buf1
									// max = 111.234.567.890
	sprintf(buf1, "%lld", zettel);

	l = strlen(buf1);

	if (l > 9) {
		strncpy(buf2, buf1, l - 9); buf2[l - 9] = 0;
		for (x = l - 9; x <= l; x++) buf1[x - (l - 9)] = buf1[x]; buf1[9] = 0;
		strcat(buf2, ".");
		strncat(buf2, buf1, 3);
		strcat(buf2, ".");
		for (x = 0; x <= 6; x++) buf1[x] = buf1[x + 3]; buf1[6] = 0;
		strncat(buf2, buf1, 3);
		strcat(buf2, ".");
		for (x = 0; x <= 3; x++) buf1[x] = buf1[x + 3]; buf1[3] = 0;
		strcat(buf2, buf1); return;
	}

	if (l > 6) {
		strncpy(buf2, buf1, l - 6); buf2[l - 6] = 0;
		for (x = l - 6; x <= l; x++) buf1[x - (l - 6)] = buf1[x]; buf1[6] = 0;
		strcat(buf2, ".");
		strncat(buf2, buf1, 3);
		strcat(buf2, ".");
		for (x = 0; x <= 3; x++) buf1[x] = buf1[x + 3]; buf1[3] = 0;
		strcat(buf2, buf1); return;
	}

	if (l > 3) {
		strncpy(buf2, buf1, l - 3); buf2[l - 3] = 0;
		for (x = l - 3; x <= l; x++) buf1[x - (l - 3)] = buf1[x]; buf1[3] = 0;
		strcat(buf2, ".");
		strcat(buf2, buf1);
		return;
	}

	strcpy(buf2, buf1);

}