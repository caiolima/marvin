/*This file is part of Marvin OS project.
* 
*Marvin OS is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*Marvin OS is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.
*
*You should have received a copy of the GNU General Public License
*along with Marvin OS.  If not, see <http://www.gnu.org/licenses/>.
*
*	Description: Storage Blocks Buffer Implementation
*	Author: Caio Lima
*	Date: 31 - 05 - 2015
*/

#ifndef STORAGE_BLOCKS_H_
#define STORAGE_BLOCKS_H_

#include <types.h>

typedef struct blk_buffer {
  u32int block_num;
  u32int device_num;
  byte status; // This status should follow a bytewise operations
  //TODO: Add Hash Queue lists
  //TODO: Add Free Buffers List
  //TODO: Add a pointer to data
};

blk_buffer* blk_hash_search(u32int block_num, u32int device_num);
blk_buffer* get_blk(u32int block_num, u32int device_num);
blk_buffer* bread(u32int block_num, u32int device_num);
void bwrite(blk_buffer* blk);
void brlese(blk_bugger* blk);

#endif /* STORAGE_BLOCKS_H_ */
