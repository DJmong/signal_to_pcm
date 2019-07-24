#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "po_define.h"
#include "def_PI.h"


void file_write(short val[], int n){
	FILE *fp;
	fp = fopen("test.pcm", "wb");
	fwrite(val, sizeof(short), n, fp);
	fclose(fp);	
}

static void wav_header(FILE *fp, int n){
	/*
	Chunk ID "RIFF" ASCII 코드 Big-Endian
	+
	Chunk Size (Chunk ID + Size 제외 값) Little Endian
	+
	Format : "WAVE" Big-Endian
	+
	SubChunk1 ID "fmt " Big-Endian
	+
	SubChunk1 Size 실제 기록되는 포맷의 크기 Little Endian
	+
	AudioFormat : PCM이므로 1 Little Endian
	*/
	/*
	fopen(fp, "wb");
	fwrite("RIFF", sizeof(char), 4, fp);
	char chunk_size = 0;
	fwrite("WAVE", sizeof(char), 4, fp);
	
	fwrite("fmt ", sizeof(char), 4, fp);


	int sub_ch_size = a.t;
	short aud_format = 1;
*/
}
