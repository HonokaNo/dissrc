#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	unsigned char token[65];
	char *ip;
	struct stat ist;
	const unsigned char *newline = "\n";
	unsigned char *run = calloc(65 + 14, 1);

	if(argc < 4 || argc > 4){
		printf("dissrc input.py token.txt output.py\n");
		exit(0);
	}

	/* トークン読み込み */
	FILE *tokens = fopen(argv[2], "r");
	if(tokens == NULL){
		fprintf(stderr, "token file open error:%s\n", argv[2]);
		exit(1);
	}
	fread(token, 65, 1, tokens);
	fclose(tokens);

	/* トークンを埋め込み */
	memcpy(run, "client.run('", 12);
	memcpy(run + 11, token, 59);
	memcpy(run + 11 + 59, "')", 2);

	/* input read */
	FILE *input = fopen(argv[1], "r");
	if(input == NULL){
		fprintf(stderr, "input file open error:%s\n", argv[1]);
		exit(1);
	}
	stat(argv[1], &ist);
	/* 全部バッファに入れる */
	ip = malloc(ist.st_size);
	fread(ip, ist.st_size, 1, input);

	FILE *output = fopen(argv[3], "w");
	if(output == NULL){
		fprintf(stderr, "output file open error:%s\n", argv[3]);
		exit(1);
	}
	/* 出力側にinputのデータをすべて入れる */
	fwrite(ip, ist.st_size, 1, output);
	fwrite(newline, 1, 1, output);
	fwrite(run, 59 + 12, 1, output);

	fclose(input);
	fclose(output);

	FILE *ignore = fopen(".gitignore", "w");
	if(ignore == NULL){
		fprintf(stderr, ".gitignore open error");
		exit(1);
	}

	fwrite(argv[0], strlen(argv[0]), 1, ignore);
	fwrite(".*", 2, 1, ignore);
	fwrite("\n", 1, 1, ignore);
	fwrite(argv[2], strlen(argv[2]), 1, ignore);
	fwrite("\n", 1, 1, ignore);
	fwrite(argv[3], strlen(argv[3]), 1, ignore);
	fwrite("\n", 1, 1, ignore);
	fwrite(".gitignore", 10, 1, ignore);
	fwrite("\n", 1, 1, ignore);

	fclose(ignore);

	return 0;
}
