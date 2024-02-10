/*
STM32 Startup
By : Prof. Yehia
*/
.global _reset
.section .vectors  //compiler-specific command

.word   0x20001000 //Address of stack initial value
.word   _reset    //Reset Handler INTERRUPT #1
.word   default_handler  //INTERRUPT #2
.word   default_handler  //INTERRUPT #3
.word   default_handler  //INTERRUPT #4
.word   default_handler  //INTERRUPT #5
.word   default_handler  //INTERRUPT #6
.word   default_handler  //INTERRUPT #7
.word   default_handler  //INTERRUPT #8
.word   default_handler  //INTERRUPT #9
.word   default_handler  //INTERRUPT #10
.word   default_handler  //INTERRUPT #11
.word   default_handler  //INTERRUPT #12
.word   default_handler  //INTERRUPT #13
.word   default_handler  //INTERRUPT #14


.section .text //compiler-specific command
_reset:
    bl main
    b .

.thumb_func  //enable thumb instructions also compiler-specific command

default_handler:
    b _reset

