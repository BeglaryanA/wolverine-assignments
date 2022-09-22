//Greatest
int main() 
{
    int num_1 = 5;
    int num_2 = 25;
    if (num_1 >= num_2) 
    {
        std::cout << num_1;
    }else {
        std::cout << num_2;   
    }
}


/*
main:
    push rbp
    mov rbp,rsp
    mov DWORD PTR[rbp - 4],5
    mov DWORD PTR[rbp - 8],25
    mov eax,DWORD PTR[rbp - 4]
    cmp eax,DWORD PTR[rbp - 8]
    jle L2
    add DWORD PTR[rbp - 4],1
L2:
    add DWORD PTR[rbp - 8],1
L3:
    mov eax,0
    pop rbp
    ret
*/
