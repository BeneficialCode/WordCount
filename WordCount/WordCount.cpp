#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
	int n, m = 0;
	FILE *fp = NULL;
	errno_t err;
	char c;
	if (argc != 3) {
		printf("parameter error!\n");
		exit(0);
	}
	err = fopen_s(&fp, argv[2], "rb");
	if (err) {
		printf("can not open the file\n");
		exit(0);
	}

	if (!strcmp("-c", argv[1])) {
		fseek(fp, 0, SEEK_END);
		n = ftell(fp);
		printf("字符数：%d\n", n);
	} else if (!strcmp("-w", argv[1])) {
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp)) {
			c = fgetc(fp);
			if (c == ',' || c == ' ') {
				do {
					c = fgetc(fp);
					if (c == ',' || c == ' ')
						continue;
					else {
						if (!feof(fp))
							m++;
						break;
					}
				} while (1);
			}
		}
		printf("单词数：%d\n", m);
	}
	fclose(fp);
	return 0;
}