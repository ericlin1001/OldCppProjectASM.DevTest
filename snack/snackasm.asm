_BSS	SEGMENT
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
_BSS	ENDS

_DATA	SEGMENT
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
_num$ = 4						; size = 2
myalloc@@YAPAXG@Z PROC					; myalloc
; Line 58
push	bp
mov	bp, sp
; Line 59
movzx	ax, WORD PTR heap@@3UHeap@@A+512
add	ax, OFFSET heap@@3UHeap@@A		; heap
mov	DWORD PTR heap@@3UHeap@@A+516, ax
; Line 60
movzx	cx, WORD PTR _num$[bp]
movzx	dx, WORD PTR heap@@3UHeap@@A+512
add	dx, cx
mov	WORD PTR heap@@3UHeap@@A+512, dx
; Line 61
mov	ax, DWORD PTR heap@@3UHeap@@A+516
; Line 62
pop	bp
ret	0
myalloc@@YAPAXG@Z ENDP					; myalloc
_TEXT	ENDS
PUBLIC	newNode@@YAPAUNode@@EEPAU1@@Z			; newNode
; Function compile flags: /Odtp

_TEXT	SEGMENT
_node$ = -4						; size = 4
_tx$ = 4						; size = 1
_ty$ = 6						; size = 1
_p$ = 8						; size = 4
newNode@@YAPAUNode@@EEPAU1@@Z PROC			; newNode
; Line 63
push	bp
mov	bp, sp
push	cx
; Line 64
push	8
call	myalloc@@YAPAXG@Z			; myalloc
add	sp, 4
mov	DWORD PTR _node$[bp], ax
; Line 65
mov	ax, DWORD PTR _node$[bp]
mov	cl, BYTE PTR _tx$[bp]
mov	BYTE PTR [ax], cl
; Line 66
mov	dx, DWORD PTR _node$[bp]
mov	al, BYTE PTR _ty$[bp]
mov	BYTE PTR [dx+1], al
; Line 67
mov	cx, DWORD PTR _node$[bp]
mov	dx, DWORD PTR _p$[bp]
mov	DWORD PTR [cx+4], dx
; Line 68
mov	ax, DWORD PTR _node$[bp]
; Line 69
mov	sp, bp
pop	bp
ret	0
newNode@@YAPAUNode@@EEPAU1@@Z ENDP			; newNode
_TEXT	ENDS
PUBLIC	getRand@@YAHXZ					; getRand
; Function compile flags: /Odtp

_TEXT	SEGMENT
getRand@@YAHXZ PROC					; getRand
; Line 75
push	bp
mov	bp, sp
; Line 76
mov	ax, DWORD PTR c@@3HA			; c
imul	ax, DWORD PTR an@@3HA			; an
add	ax, 1
cdq
mov	cx, 65535				; 0000ffffH
idiv	cx
mov	DWORD PTR an@@3HA, dx			; an
; Line 77
mov	ax, DWORD PTR an@@3HA			; an
; Line 78
pop	bp
ret	0
getRand@@YAHXZ ENDP					; getRand
_TEXT	ENDS
PUBLIC	setSeed@@YAXH@Z				; setSeed
; Function compile flags: /Odtp
_TEXT	SEGMENT
_t$ = -4						; size = 4
_k$ = 4							; size = 4
setSeed@@YAXH@Z PROC					; setSeed
; Line 79
push	bp
mov	bp, sp
push	cx
; Line 81
mov	ax, DWORD PTR _k$[bp]
mov	DWORD PTR _t$[bp], ax
; Line 82
cmp	DWORD PTR _k$[bp], 6
je	SHORT $LN4@setSeed
mov	cx, DWORD PTR _k$[bp]
lea	dx, DWORD PTR [cx+cx+1]
mov	DWORD PTR _k$[bp], dx
$LN4@setSeed:
; Line 83
mov	ax, DWORD PTR _k$[bp]
and	ax, -2147483641			; 80000007H
jns	SHORT $LN7@setSeed
dec	ax
or	ax, -8					; fffffff8H
inc	ax
$LN7@setSeed:
mov	DWORD PTR _k$[bp], ax
; Line 84
cmp	DWORD PTR _k$[bp], 1
jne	SHORT $LN3@setSeed
mov	DWORD PTR _k$[bp], 7
$LN3@setSeed:
; Line 85
mov	cx, DWORD PTR _k$[bp]
mov	DWORD PTR c@@3HA, cx			; c
mov	dx, DWORD PTR c@@3HA			; c
mov	DWORD PTR an@@3HA, dx			; an
$LN2@setSeed:
; Line 86
mov	ax, DWORD PTR _t$[bp]
mov	cx, DWORD PTR _t$[bp]
sub	cx, 1
mov	DWORD PTR _t$[bp], cx
test	ax, ax
je	SHORT $LN5@setSeed
call	getRand@@YAHXZ				; getRand
jmp	SHORT $LN2@setSeed
$LN5@setSeed:
; Line 87
mov	sp, bp
pop	bp
ret	0
setSeed@@YAXH@Z ENDP					; setSeed

_TEXT	ENDS
PUBLIC	init@@YAXXZ					; init
; Function compile flags: /Odtp
_TEXT	SEGMENT
init@@YAXXZ PROC					; init
; Line 90
push	bp
mov	bp, sp
; Line 91
push	0
push	1
push	2
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	DWORD PTR head@@3PAUNode@@A, ax	; head
; Line 92
mov	ax, DWORD PTR head@@3PAUNode@@A	; head
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR [ax+4], cx
; Line 93
mov	dx, DWORD PTR head@@3PAUNode@@A	; head
mov	ax, DWORD PTR [dx+4]
push	ax
push	1
push	1
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR [cx+4], ax
; Line 94
mov	dx, DWORD PTR head@@3PAUNode@@A	; head
mov	ax, DWORD PTR [dx+4]
push	ax
push	1
push	0
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR [cx+4], ax
; Line 95
mov	BYTE PTR len@@3EA, 3			; len
; Line 96
push	0
push	0
push	0
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	DWORD PTR food@@3PAUNode@@A, ax	; food
; Line 98
mov	dx, DWORD PTR head@@3PAUNode@@A	; head
mov	ax, DWORD PTR [dx+4]
push	ax
push	0
push	0
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	DWORD PTR pivot@@3PAUNode@@A, ax	; pivot
; Line 99
mov	BYTE PTR isWin@@3DA, 0			; isWin
mov	cl, BYTE PTR isWin@@3DA		; isWin
mov	BYTE PTR isLose@@3DA, cl		; isLose
; Line 100
pop	bp
ret	0
init@@YAXXZ ENDP					; init
_TEXT	ENDS

PUBLIC	lose@@YAXXZ					; lose
; Function compile flags: /Odtp
_TEXT	SEGMENT
lose@@YAXXZ PROC					; lose
; Line 102
push	bp
mov	bp, sp
movsx	ax, BYTE PTR isWin@@3DA		; isWin
test	ax, ax
jne	SHORT $LN2@lose
mov	BYTE PTR isLose@@3DA, 1		; isLose
$LN2@lose:
pop	bp
ret	0
lose@@YAXXZ ENDP					; lose
_TEXT	ENDS
PUBLIC	win@@YAXXZ					; win
; Function compile flags: /Odtp
_TEXT	SEGMENT
win@@YAXXZ PROC					; win
; Line 103
push	bp
mov	bp, sp
; Line 104
movsx	ax, BYTE PTR isLose@@3DA		; isLose
test	ax, ax
jne	SHORT $LN2@win
mov	BYTE PTR isWin@@3DA, 1			; isWin
$LN2@win:
; Line 105
pop	bp
ret	0
win@@YAXXZ ENDP					; win
_TEXT	ENDS
PUBLIC	createGraph@@YAXXZ				; createGraph
; Function compile flags: /Odtp
_TEXT	SEGMENT
_pg$ = -12						; size = 4
_i$ = -5						; size = 1
_p$ = -4						; size = 4
createGraph@@YAXXZ PROC				; createGraph
; Line 106
push	bp
mov	bp, sp
sub	sp, 12					; 0000000cH
; Line 108
mov	DWORD PTR _pg$[bp], OFFSET graph@@3PAY07EA ; graph
; Line 109
mov	BYTE PTR _i$[bp], 0
jmp	SHORT $LN6@createGrap
$LN5@createGrap:
mov	al, BYTE PTR _i$[bp]
add	al, 1
mov	BYTE PTR _i$[bp], al
$LN6@createGrap:
movzx	cx, BYTE PTR _i$[bp]
cmp	cx, 64					; 00000040H
jge	SHORT $LN4@createGrap
mov	dx, DWORD PTR _pg$[bp]
mov	BYTE PTR [dx], 0
mov	ax, DWORD PTR _pg$[bp]
add	ax, 1
mov	DWORD PTR _pg$[bp], ax
jmp	SHORT $LN5@createGrap
$LN4@createGrap:
; Line 111
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR _p$[bp], cx
$LN3@createGrap:
; Line 113
mov	dx, DWORD PTR _p$[bp]
movzx	ax, BYTE PTR [dx]
mov	cx, DWORD PTR _p$[bp]
movzx	dx, BYTE PTR [cx+1]
mov	BYTE PTR graph@@3PAY07EA[dx+ax*8], 1
; Line 114
mov	ax, DWORD PTR _p$[bp]
mov	cx, DWORD PTR [ax+4]
mov	DWORD PTR _p$[bp], cx
; Line 115
mov	dx, DWORD PTR _p$[bp]
cmp	dx, DWORD PTR head@@3PAUNode@@A	; head
jne	SHORT $LN3@createGrap
; Line 116
mov	ax, DWORD PTR food@@3PAUNode@@A	; food
movzx	cx, BYTE PTR [ax]
mov	dx, DWORD PTR food@@3PAUNode@@A	; food
movzx	ax, BYTE PTR [dx+1]
mov	BYTE PTR graph@@3PAY07EA[ax+cx*8], 2
; Line 117
mov	sp, bp
pop	bp
ret	0
createGraph@@YAXXZ ENDP				; createGraph
_TEXT	ENDS
PUBLIC	move@@YAXE@Z					; move
; Function compile flags: /Odtp
_TEXT	SEGMENT
_ipg$2662 = -17						; size = 1
_pg$2661 = -16						; size = 4
_index$2660 = -9					; size = 1
_dir$ = -8						; size = 2
_p$ = -4						; size = 4
_tdir$ = 4						; size = 1
move@@YAXE@Z PROC					; move
; Line 118
push	bp
mov	bp, sp
sub	sp, 20					; 00000014H
push	si
; Line 119
movzx	ax, BYTE PTR _tdir$[bp]
test	ax, ax
jle	SHORT $LN13@move
movzx	cx, BYTE PTR _tdir$[bp]
cmp	cx, 5
jl	SHORT $LN14@move
$LN13@move:
; Line 120
mov	dl, BYTE PTR idir@@3EA			; idir
mov	BYTE PTR _tdir$[bp], dl
$LN14@move:
; Line 122
movzx	ax, BYTE PTR _tdir$[bp]
mov	cx, WORD PTR dirs@@3PAUDir@@A[ax*2]
mov	WORD PTR _dir$[bp], cx
; Line 123
mov	dx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR _p$[bp], dx
; Line 125
mov	ax, DWORD PTR head@@3PAUNode@@A	; head
movzx	cx, BYTE PTR [ax]
movzx	dx, BYTE PTR _dir$[bp]
add	cx, dx
and	cx, -2147483641			; 80000007H
jns	SHORT $LN17@move
dec	cx
or	cx, -8					; fffffff8H
inc	cx
$LN17@move:
mov	ax, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	BYTE PTR [ax], cl
; Line 126
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
movzx	dx, BYTE PTR [cx+1]
movzx	ax, BYTE PTR _dir$[bp+1]
add	dx, ax
and	dx, -2147483641			; 80000007H
jns	SHORT $LN18@move
dec	dx
or	dx, -8					; fffffff8H
inc	dx
$LN18@move:
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	BYTE PTR [cx+1], dl
; Line 128
mov	dx, DWORD PTR food@@3PAUNode@@A	; food
movzx	ax, BYTE PTR [dx]
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
movzx	dx, BYTE PTR [cx]
cmp	ax, dx
jne	$LN12@move
mov	ax, DWORD PTR food@@3PAUNode@@A	; food
movzx	cx, BYTE PTR [ax+1]
mov	dx, DWORD PTR pivot@@3PAUNode@@A	; pivot
movzx	ax, BYTE PTR [dx+1]
cmp	cx, ax
jne	$LN12@move
; Line 131
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	dx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	DWORD PTR [cx+4], dx
mov	ax, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	DWORD PTR head@@3PAUNode@@A, ax	; head
; Line 132
mov	cl, BYTE PTR len@@3EA			; len
add	cl, 1
mov	BYTE PTR len@@3EA, cl			; len
; Line 133
movzx	dx, BYTE PTR len@@3EA			; len
movzx	ax, BYTE PTR winLen@@3EA		; winLen
cmp	dx, ax
jl	SHORT $LN11@move
call	win@@YAXXZ				; win
$LN11@move:
; Line 135
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	dx, DWORD PTR [cx+4]
push	dx
push	0
push	0
call	newNode@@YAPAUNode@@EEPAU1@@Z		; newNode
add	sp, 12					; 0000000cH
mov	DWORD PTR pivot@@3PAUNode@@A, ax	; pivot
; Line 137
call	getRand@@YAHXZ				; getRand
movzx	cx, BYTE PTR len@@3EA			; len
mov	si, 64					; 00000040H
sub	si, cx
cdq
idiv	si
mov	BYTE PTR _index$2660[bp], dl
; Line 138
mov	dl, BYTE PTR _index$2660[bp]
add	dl, 1
mov	BYTE PTR _index$2660[bp], dl
; Line 139
call	createGraph@@YAXXZ			; createGraph
; Line 140
mov	DWORD PTR _pg$2661[bp], OFFSET graph@@3PAY07EA ; graph
; Line 141
mov	BYTE PTR _ipg$2662[bp], 0
$LN10@move:
; Line 142
movzx	ax, BYTE PTR _index$2660[bp]
test	ax, ax
je	SHORT $LN9@move
movzx	cx, BYTE PTR _ipg$2662[bp]
mov	dx, DWORD PTR _pg$2661[bp]
movzx	ax, BYTE PTR [dx+cx]
mov	cl, BYTE PTR _ipg$2662[bp]
add	cl, 1
mov	BYTE PTR _ipg$2662[bp], cl
test	ax, ax
jne	SHORT $LN8@move
mov	dl, BYTE PTR _index$2660[bp]
sub	dl, 1
mov	BYTE PTR _index$2660[bp], dl
$LN8@move:
jmp	SHORT $LN10@move
$LN9@move:
; Line 143
mov	al, BYTE PTR _ipg$2662[bp]
sub	al, 1
mov	BYTE PTR _ipg$2662[bp], al
; Line 145
movzx	ax, BYTE PTR _ipg$2662[bp]
cdq
and	dx, 7
add	ax, dx
sar	ax, 3
mov	cx, DWORD PTR food@@3PAUNode@@A	; food
mov	BYTE PTR [cx], al
; Line 146
movzx	dx, BYTE PTR _ipg$2662[bp]
and	dx, -2147483641			; 80000007H
jns	SHORT $LN19@move
dec	dx
or	dx, -8					; fffffff8H
inc	dx
$LN19@move:
mov	ax, DWORD PTR food@@3PAUNode@@A	; food
mov	BYTE PTR [ax+1], dl
; Line 148
jmp	$LN15@move
; Line 149
jmp	$LN15@move
$LN12@move:
; Line 150
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	DWORD PTR _p$[bp], cx
$LN6@move:
; Line 151
mov	dx, DWORD PTR _p$[bp]
mov	ax, DWORD PTR [dx+4]
mov	DWORD PTR _p$[bp], ax
mov	cx, DWORD PTR _p$[bp]
cmp	cx, DWORD PTR head@@3PAUNode@@A	; head
je	SHORT $LN5@move
mov	dx, DWORD PTR _p$[bp]
movzx	ax, BYTE PTR [dx]
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
movzx	dx, BYTE PTR [cx]
cmp	ax, dx
jne	SHORT $LN4@move
mov	ax, DWORD PTR _p$[bp]
movzx	cx, BYTE PTR [ax+1]
mov	dx, DWORD PTR pivot@@3PAUNode@@A	; pivot
movzx	ax, BYTE PTR [dx+1]
cmp	cx, ax
jne	SHORT $LN4@move
jmp	SHORT $LN5@move
$LN4@move:
; Line 152
jmp	SHORT $LN6@move
$LN5@move:
mov	cx, DWORD PTR _p$[bp]
mov	dx, DWORD PTR [cx+4]
cmp	dx, DWORD PTR head@@3PAUNode@@A	; head
jne	SHORT $LN3@move
; Line 154
mov	al, BYTE PTR idir@@3EA			; idir
mov	BYTE PTR _tdir$[bp], al
; Line 155
movzx	cx, BYTE PTR _tdir$[bp]
mov	dx, WORD PTR dirs@@3PAUDir@@A[cx*2]
mov	WORD PTR _dir$[bp], dx
; Line 156
mov	ax, DWORD PTR head@@3PAUNode@@A	; head
movzx	cx, BYTE PTR [ax]
movzx	dx, BYTE PTR _dir$[bp]
add	cx, dx
and	cx, -2147483641			; 80000007H
jns	SHORT $LN20@move
dec	cx
or	cx, -8					; fffffff8H
inc	cx
$LN20@move:
mov	ax, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	BYTE PTR [ax], cl
; Line 157
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
movzx	dx, BYTE PTR [cx+1]
movzx	ax, BYTE PTR _dir$[bp+1]
add	dx, ax
and	dx, -2147483641			; 80000007H
jns	SHORT $LN21@move
dec	dx
or	dx, -8					; fffffff8H
inc	dx
$LN21@move:
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	BYTE PTR [cx+1], dl
jmp	SHORT $LN2@move
$LN3@move:
; Line 158
mov	dx, DWORD PTR _p$[bp]
cmp	dx, DWORD PTR head@@3PAUNode@@A	; head
je	SHORT $LN2@move
; Line 159
call	lose@@YAXXZ				; lose
; Line 160
jmp	SHORT $LN15@move
$LN2@move:
; Line 162
mov	al, BYTE PTR _tdir$[bp]
mov	BYTE PTR idir@@3EA, al			; idir
; Line 165
mov	cx, DWORD PTR head@@3PAUNode@@A	; head
mov	dx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	DWORD PTR [cx+4], dx
mov	ax, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	DWORD PTR head@@3PAUNode@@A, ax	; head
; Line 166
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	dx, DWORD PTR [cx+4]
mov	DWORD PTR pivot@@3PAUNode@@A, dx	; pivot
; Line 167
mov	ax, DWORD PTR head@@3PAUNode@@A	; head
mov	cx, DWORD PTR pivot@@3PAUNode@@A	; pivot
mov	dx, DWORD PTR [cx+4]
mov	DWORD PTR [ax+4], dx
$LN15@move:
; Line 171
pop	si
mov	sp, bp
pop	bp
ret	0
move@@YAXE@Z ENDP					; move
_TEXT	ENDS
PUBLIC	print@@YAXXZ					; print
; Function compile flags: /Odtp
_TEXT	SEGMENT
_j$ = -2						; size = 1
_i$ = -1						; size = 1
print@@YAXXZ PROC					; print
; Line 173
push	bp
mov	bp, sp
push	cx
; Line 175
call	createGraph@@YAXXZ			; createGraph
; Line 176
mov	BYTE PTR _i$[bp], 0
jmp	SHORT $LN6@print
$LN5@print:
mov	al, BYTE PTR _i$[bp]
add	al, 1
mov	BYTE PTR _i$[bp], al
$LN6@print:
movzx	cx, BYTE PTR _i$[bp]
cmp	cx, 8
jge	SHORT $LN7@print
; Line 177
mov	BYTE PTR _j$[bp], 0
jmp	SHORT $LN3@print
$LN2@print:
mov	dl, BYTE PTR _j$[bp]
add	dl, 1
mov	BYTE PTR _j$[bp], dl
$LN3@print:
movzx	ax, BYTE PTR _j$[bp]
cmp	ax, 8
jge	SHORT $LN1@print
; Line 179
jmp	SHORT $LN2@print
$LN1@print:
; Line 181
jmp	SHORT $LN5@print
$LN7@print:
; Line 182
mov	sp, bp
pop	bp
ret	0
print@@YAXXZ ENDP					; print
_TEXT	ENDS
PUBLIC	converToHex@@YAEE@Z				; converToHex
; Function compile flags: /Odtp
_TEXT	SEGMENT
_ch$ = 4						; size = 1
converToHex@@YAEE@Z PROC				; converToHex
; Line 183
push	bp
mov	bp, sp
; Line 185
movzx	ax, BYTE PTR _ch$[bp]
cmp	ax, 9
jg	SHORT $LN2@converToHe
movzx	ax, BYTE PTR _ch$[bp]
add	ax, 48					; 00000030H
jmp	SHORT $LN3@converToHe
jmp	SHORT $LN3@converToHe
$LN2@converToHe:
; Line 186
movzx	ax, BYTE PTR _ch$[bp]
add	ax, 55					; 00000037H
$LN3@converToHe:
; Line 188
pop	bp
ret	0
converToHex@@YAEE@Z ENDP				; converToHex
_TEXT	ENDS
PUBLIC	createOutputData@@YAXXZ			; createOutputData
; Function compile flags: /Odtp
_TEXT	SEGMENT
_j$ = -2						; size = 1
_i$ = -1						; size = 1
createOutputData@@YAXXZ PROC				; createOutputData
; Line 189
push	bp
mov	bp, sp
push	cx
push	si
; Line 191
call	createGraph@@YAXXZ			; createGraph
; Line 192
mov	BYTE PTR _i$[bp], 0
jmp	SHORT $LN6@createOutp
$LN5@createOutp:
mov	al, BYTE PTR _i$[bp]
add	al, 1
mov	BYTE PTR _i$[bp], al
$LN6@createOutp:
movzx	cx, BYTE PTR _i$[bp]
cmp	cx, 8
jge	SHORT $LN7@createOutp
; Line 193
movzx	dx, BYTE PTR _i$[bp]
mov	BYTE PTR outputData@@3PAEA[dx], 0
; Line 194
mov	BYTE PTR _j$[bp], 0
jmp	SHORT $LN3@createOutp
$LN2@createOutp:
mov	al, BYTE PTR _j$[bp]
add	al, 1
mov	BYTE PTR _j$[bp], al
$LN3@createOutp:
movzx	cx, BYTE PTR _j$[bp]
cmp	cx, 8
jge	SHORT $LN1@createOutp
; Line 195
movzx	dx, BYTE PTR _i$[bp]
mov	al, BYTE PTR outputData@@3PAEA[dx]
shl	al, 1
movzx	cx, BYTE PTR _i$[bp]
mov	BYTE PTR outputData@@3PAEA[cx], al
; Line 196
movzx	dx, BYTE PTR _i$[bp]
movzx	ax, BYTE PTR _i$[bp]
movzx	cx, BYTE PTR _j$[bp]
mov	si, 7
sub	si, cx
movzx	ax, BYTE PTR graph@@3PAY07EA[si+ax*8]
neg	ax
sbb	ax, ax
neg	ax
movzx	cx, BYTE PTR outputData@@3PAEA[dx]
add	cx, ax
movzx	dx, BYTE PTR _i$[bp]
mov	BYTE PTR outputData@@3PAEA[dx], cl
; Line 197
jmp	SHORT $LN2@createOutp
$LN1@createOutp:
; Line 200
jmp	$LN5@createOutp
$LN7@createOutp:
; Line 203
pop	si
mov	sp, bp
pop	bp
ret	0
createOutputData@@YAXXZ ENDP				; createOutputData
_TEXT	ENDS
PUBLIC	convert@@YAEE@Z				; convert
; Function compile flags: /Odtp
_TEXT	SEGMENT
tv65 = -4						; size = 4
_ch$ = 4						; size = 1
convert@@YAEE@Z PROC					; convert
; Line 205
push	bp
mov	bp, sp
push	cx
; Line 206
movzx	ax, BYTE PTR _ch$[bp]
mov	DWORD PTR tv65[bp], ax
mov	cx, DWORD PTR tv65[bp]
sub	cx, 1
mov	DWORD PTR tv65[bp], cx
cmp	DWORD PTR tv65[bp], 4
ja	SHORT $LN5@convert
mov	dx, DWORD PTR tv65[bp]
jmp	DWORD PTR $LN9@convert[dx*4]
$LN4@convert:
; Line 207
mov	al, 1
jmp	SHORT $LN7@convert
$LN3@convert:
; Line 208
mov	al, 4
jmp	SHORT $LN7@convert
$LN2@convert:
; Line 209
mov	al, 3
jmp	SHORT $LN7@convert
$LN1@convert:
; Line 210
mov	al, 2
jmp	SHORT $LN7@convert
$LN5@convert:
; Line 212
xor	al, al
$LN7@convert:
; Line 213
mov	sp, bp
pop	bp
ret	0
npad	2
$LN9@convert:
DD	$LN4@convert
DD	$LN3@convert
DD	$LN2@convert
DD	$LN5@convert
DD	$LN1@convert
convert@@YAEE@Z ENDP					; convert
_TEXT	ENDS
PUBLIC	_main
; Function compile flags: /Odtp
_TEXT	SEGMENT
_idir$ = -1						; size = 1
_main	PROC
; Line 215
push	bp
mov	bp, sp
push	cx
; Line 216
push	1000					; 000003e8H
call	setSeed@@YAXH@Z			; setSeed
add	sp, 4
; Line 217
call	init@@YAXXZ				; init
; Line 218
mov	BYTE PTR _idir$[bp], 0
$LN2@main:
; Line 219
mov	ax, 1
test	ax, ax
je	SHORT $LN1@main
; Line 221
movzx	cx, BYTE PTR _idir$[bp]
push	cx
call	move@@YAXE@Z				; move
add	sp, 4
; Line 222
call	print@@YAXXZ				; print
; Line 223
call	createOutputData@@YAXXZ		; createOutputData
; Line 226
movzx	dx, BYTE PTR _idir$[bp]
sub	dx, 48					; 00000030H
mov	BYTE PTR _idir$[bp], dl
; Line 227
movzx	ax, BYTE PTR _idir$[bp]
push	ax
call	convert@@YAEE@Z			; convert
add	sp, 4
mov	BYTE PTR _idir$[bp], al
; Line 228
jmp	SHORT $LN2@main
$LN1@main:
; Line 229
xor	ax, ax
; Line 230
mov	sp, bp
pop	bp
ret	0
_main	ENDP
; Function compile flags: /Odtp
_TEXT	ENDS
;	COMDAT __Ean@@YAXXZ
text$yc	SEGMENT
__Ean@@YAXXZ PROC					; `dynamic initializer for 'an'', COMDAT
; Line 74
push	bp
mov	bp, sp
mov	ax, DWORD PTR c@@3HA			; c
mov	DWORD PTR an@@3HA, ax			; an
pop	bp
ret	0
__Ean@@YAXXZ ENDP					; `dynamic initializer for 'an''
text$yc	ENDS
PUBLIC	an@@3HA					; an
_BSS	SEGMENT
an@@3HA DD	01H DUP ()				; an
_BSS	ENDS
CRT$XCU	SEGMENT
_an$initializer$ DD FLAT:__Ean@@YAXXZ
CRT$XCU	ENDS
END
