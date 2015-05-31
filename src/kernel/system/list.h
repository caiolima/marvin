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
 *	Description: List datastruct implementation
 *	Author: Caio Lima
 *	Date: 31 - 05 - 2015
*/

#ifndef LIST_H_
#define LIST_H_

#include <types.h>

#define LIST_HEAD_INIT(name) { &(name), &(name) }                               

#define LIST_HEAD(name) \
  struct list_head name = LIST_HEAD_INIT(name)                            

static inline void INIT_LIST_HEAD(struct list_head *list)                       
{                                                                               
  list->next = list;                                                      
  list->prev = list;                                                      
}                                                                               

/*                                                                              
 * Insert a new entry between two known consecutive entries.                    
 *                                                                              
 * This is only for internal list manipulation where we know                    
 * the prev/next entries already!                                               
 */                                                                             
static inline void __list_add(struct list_head *new,                            
                              struct list_head *prev,                           
                              struct list_head *next)                           
{                                                                               
  next->prev = new;                                                       
  new->next = next;                                                       
  new->prev = prev;                                                       
  prev->next = new;                                                       
} 

/**                                                                             
* list_add - add a new entry                                                   
* @new: new entry to be added                                                  
* @head: list head to add it after                                             
*                                                                              
* Insert a new entry after the specified head.                                 
* This is good for implementing stacks.                                        
*/                                                                             
static inline void list_add(struct list_head *new, struct list_head *head)      
{                                                                               
  __list_add(new, head, head->next);                                      
}                                                                               
                                                                                
                                                                                
/**                                                                             
* list_add_tail - add a new entry                                              
* @new: new entry to be added                                                  
* @head: list head to add it before                                            
*                                                                              
* Insert a new entry before the specified head.                                
* This is useful for implementing queues.                                      
*/                                                                             
static inline void list_add_tail(struct list_head *new, struct list_head *head) 
{                                                                               
  __list_add(new, head->prev, head);                                      
} 

#endif /* LIST_H_ */
