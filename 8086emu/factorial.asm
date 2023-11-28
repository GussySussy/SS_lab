DATA SEGMENT
    MSG1 DB 0AH,0DH,"ENTER THE NUMBER:$"
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    SUB AL, 30H         

    CMP AL, 01H         
    JE END_PROGRAM     
    CMP AL, 00H         
    JE END_PROGRAM     
    
    XOR AH, AH
    MOV BX, AX         
    MOV AX, 0001h        

FACTORIAL_LOOP:
    MUL BX              
    DEC BX              
    JNZ FACTORIAL_LOOP  

END_PROGRAM:
    INT 20H          

CODE ENDS
END START
