DATA SEGMENT
    ARR DB 5,10,50,30,40,20
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX
    
    XOR CX, CX
    XOR BX, BX
    XOR AX, AX
    
    LEA BX, ARR
    MOV CL, [BX] ; loading size of the array into CX
    ADD BX, 1
    MOV AL,[BX]
    
FIND_LARGEST:
    CMP CL,0
    JNZ COMPARE_NEXT
    JMP END_PROGRAM

COMPARE_NEXT:
    CMP AL, [BX]
    JL SET_LARGEST
    INC BL
    DEC CL
    JMP FIND_LARGEST    
    
    
SET_LARGEST:
    MOV AL,[BX]
    JMP FIND_LARGEST                  
    
    
END_PROGRAM:
            


CODE ENDS
END START
