#ifndef TYPES_H
#define TYPES_H

#ifndef uchar
#define uchar 		unsigned char
#endif

#ifndef byte
#define byte 		unsigned char
#endif

#ifndef uint
#define uint		unsigned int
#endif

#ifndef int32
#define int32		int
#endif

#ifndef u32int
#define u32int		unsigned int
#endif

#ifndef word
#define word		unsigned short
#endif

#ifndef ushort
#define ushort		unsigned short
#endif

#define B_0000  0
#define B_0001  1
#define B_0010  2
#define B_0011  3
#define B_0100  4
#define B_0101  5
#define B_0110  6
#define B_0111  7
#define B_1000  8
#define B_1001  9
#define B_1010  a
#define B_1011  b
#define B_1100  c
#define B_1101  d
#define B_1110  e
#define B_1111  f

#define _B2H(bits)  B_##bits
#define B2H(bits)   _B2H(bits)
#define _HEX(n)     0x##n
#define HEX(n)      _HEX(n)
#define _CCAT(a,b)  a##b
#define CCAT(a,b)   _CCAT(a,b)

#define BYTE(a,b)       HEX( CCAT(B2H(a),B2H(b)) )
#define WORD(a,b,c,d)   HEX( CCAT(CCAT(B2H(a),B2H(b)),CCAT(B2H(c),B2H(d))) )
#define DWORD(a,b,c,d,e,f,g,h)  HEX( CCAT(CCAT(CCAT(B2H(a),B2H(b)),CCAT(B2H(c),B2H(d))),CCAT(CCAT(B2H(e),B2H(f)),CCAT(B2H(g),B2H(h)))) )

#define __native__ extern

struct list_head {
    struct list_head* next;
    struct list_head* prev;
};

/**                                                                             
* container_of - cast a member of a structure out to the containing structure  
* @ptr:        the pointer to the member.                                      
* @type:       the type of the container struct this is embedded in.           
* @member:     the name of the member within the struct.                       
*                                                                              
*/                                                                             
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#endif
