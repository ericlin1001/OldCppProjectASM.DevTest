DATA	SEGMENT
DATA	ENDS

data  segment
data ends
;********************************end of data seg***************************

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

exit: mov ah,4ch    ;exit and return to dos.
int 21h

code ends
end start
