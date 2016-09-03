_DATA	SEGMENT
;_BSS	SEGMENT
head@@3PAUNode@@A 	DD 	01H 	DUP (?)			; head
pivot@@3PAUNode@@A	DD	01H 	DUP (?)			; pivot
food@@3PAUNode@@A 	DD 	01H 	DUP (?)			; food

isLose@@3DA		DB	01H 	DUP (?)			; isLose
ALIGN	4
isWin@@3DA		DB	01H 	DUP (?)			; isWin
ALIGN	4
len@@3EA		DB	01H 	DUP (?)			; len
ALIGN	4

heap@@3UHeap@@A 	DB 	0208H 	DUP (?)			; heap
graph@@3PAY07EA 	DB	040H 	DUP (?)			; graph
outputData@@3PAEA 	DB	08H 	DUP (?)			; outputData
;_BSS	ENDS

dirs@@3PAUDir@@A DB 00H				; dirs
DB	00H
DB	0ffH
DB	00H
DB	00H
DB	01H
DB	01H
DB	00H
DB	00H
DB	0ffH

idir@@3EA 	DB	03H					; idir
winLen@@3EA 	DB	012H					; winLen

c@@3HA		DD	07H					; c
_DATA	ENDS
;********************************end of data seg***************************

_TEXT	SEGMENT
assume cs:_TEXT,ds:_DATA
start:
mov ax,_DATA
mov ds,ax

jmp exit
_num$ = 4						; size = 2
myalloc@@YAPAXG@Z PROC					; myalloc
; Line 58
push	bp
mov	bp, sp
; Line 59
mov	ax, WORD PTR heap@@3UHeap@@A+200h	;next
add	ax, OFFSET heap@@3UHeap@@A		; heap
mov	WORD PTR heap@@3UHeap@@A+204h, ax	;lastp
; Line 60
mov	cx, WORD PTR _num$[bp]
mov	dx, WORD PTR heap@@3UHeap@@A+200h
add	dx, cx
mov	WORD PTR heap@@3UHeap@@A+200h, dx
; Line 61
mov	ax, WORD PTR heap@@3UHeap@@A+204h
; Line 62
pop	bp
ret	0
myalloc@@YAPAXG@Z ENDP					; myalloc
exit:
mov ah,4ch
int 21h
_TEXT	ENDS

end start
