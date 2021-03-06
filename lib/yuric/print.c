#include "../../include/yuri/yuri.h"

/*
 *=======================================================================================
 *puts関数
 *文字列を表示する関数
 *=======================================================================================
 */
void puts(char *string){
	while(*string) {
		write(stdout, string, 1);
		string++;
	}
	newline();
}

/*
 *=======================================================================================
 *getline関数
 *改行で区切ってファイルの中身を返す
 *=======================================================================================
 */
void getline(int fd, char *line) {

	u32_t  i, p;
	static u32_t box[128];
	static char buffer[256];

	p = 0;

	stat(fd, box);
	i = box[4];

	while(1){
		read(fd, buffer, 512);
		for(;i < 512; i++, p++ ){
			switch(buffer[i]){
				//改行
			case 0x0a:
			case '\0':
				line[p] = '\0';
				seek(fd, i+1, SEEK_CUR);
				return;
			default:
				line[p] = buffer[i];
			}
		}
	}

}
