/*
 *=======================================================================================
 *yuri file systems
 *=======================================================================================
 */
#include "../../include/yrfs.h"
#include "../../include/sh.h"

struct block_info blocks_info[__INODE_LIMIT__];

void init_yrfs() {
	u32_t i = 0;
	struct i_node inode;

	puts("Start Initializing yurifs...");
	for(;i < __INODE_LIMIT__;i++){
		iread(&inode, i);
		/*
		 *ファイル名の先頭がヌル文字のとき空と定義する
		 */
		blocks_info[i].empty = (inode.file_name[0] == '\0');
	}
	puts("Complete Initializing yurifs.");
}
