#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>

char outfile[256] = "c:/temp/shuffled-benjamin.binpack";	// output binpack
char tempdir[256] = "c:/temp/";

char files[20][100] = {						// put your to shuffle binpacks here
   "c:/temp/benjamin-001.binpack",
   "c:/temp/benjamin-002.binpack",
   "xxx" };							// end of table marker

FILE *fpc;
char w[200],fn[200],buf1[100],buf2[100],buf3[100];
int count=0;
unsigned long long binpacks=0;
unsigned long long verify = 0;
int x, y;
unsigned long long zettel;
unsigned long long k1,k2,k3,k4,k5;
int n = 0;
int p = 0;
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
	  	
		p++;  sprintf(w, "%sp%d.bin", tempdir,p);	fp1 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp2 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp3 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp4 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp5 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp6 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp7 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp8 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp9 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp10 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp11 = fopen(w, "wb");
		p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp12 = fopen(w, "wb");

		printf("\nShuffling %s\n",fn);

lees:   x=fread(&k1,8,1,fpc); if (x<1) { fclose(fpc); goto klaar; }
	    fread(&k2,8,1,fpc);
	    fread(&k3,8,1,fpc);
	    fread(&k4,8,1,fpc);
	    fread(&k5,8,1,fpc);
		binpacks++;
		count++; if (count > 12) count = 1;

		if (binpacks % 1000000 == 0) { zettel = binpacks; puntjes(); printf("Shuffling %s\n", buf2); }	// each one million

		if (binpacks % 100000000 == 0) {
			display_time();	// each 100 million
			fclose(fp1); fclose(fp2);	fclose(fp3); fclose(fp4); fclose(fp5); 	fclose(fp6); fclose(fp7);
			fclose(fp8); fclose(fp9);	fclose(fp10); fclose(fp11); fclose(fp12);
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp1 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp2 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp3 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp4 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp5 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp6 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp7 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp8 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp9 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp10 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp11 = fopen(w, "wb");
			p++;  sprintf(w, "%sp%d.bin", tempdir, p);	fp12 = fopen(w, "wb"); }

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

		printf("\nShuffling %s\n", fn);

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
		
		printf("\nEnd of of Phase One, created %d shuffled binpacks\n",p);
		printf("Phase Two now will merge them together into %s\n", outfile);
		printf("Feel free to abort if this is unwanted\n\n");

		printf("Writing %s\n",outfile);

//		printf(w, "copy /b p* xxx.binpack");	works as copied .exe in folder but not when started under Visual Studio
//		printf("%s\n", w);
//		system(w);

		fpc = fopen(outfile, "wb");

		for (y = 1; y <= p; y++) {
			sprintf(w, "%sp%d.bin", tempdir, y);
			fp1 = fopen(w, "rb");
			while (feof(fp1) == 0) {
			    x = fread(&k1, 8, 1, fp1);  if (x < 1) break;
				fread(&k2, 8, 1, fp1);  fread(&k3, 8, 1, fp1);  fread(&k4, 8, 1, fp1);  fread(&k5, 8, 1, fp1); verify++;
				fwrite(&k1, 8, 1, fpc); fwrite(&k2, 8, 1, fpc); fwrite(&k3, 8, 1, fpc); fwrite(&k4, 8, 1, fpc); fwrite(&k5, 8, 1, fpc);	}
			fclose(fp1);
			zettel = verify; puntjes(); printf("Stored %s of %s\n", buf2, buf3); }

		fclose(fpc);

		printf("\nDone, shuffled : %s binpacks, saved as %s\n\n",buf3,outfile);

		display_time();

		printf("Removing temp files\n");
		for (x = 1; x <= p; x++) { sprintf(w, "%sp%d.bin",tempdir,x); remove(w); }

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

	if (time_taken == 0) time_taken++;

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
	int l, x;					// uses string buf1
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
