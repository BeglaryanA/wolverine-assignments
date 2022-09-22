int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += arr[i];
    }
    return 0;
}

/*
main:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-32], 1
        mov     DWORD PTR [rbp-28], 2
        mov     DWORD PTR [rbp-24], 3
        mov     DWORD PTR [rbp-20], 4
        mov     DWORD PTR [rbp-16], 5
        mov     DWORD PTR [rbp-4], 0
        mov     DWORD PTR [rbp-8], 0
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-8]
        cdqe
        mov     eax, DWORD PTR [rbp-32+rax*4]
        add     DWORD PTR [rbp-4], eax
        add     DWORD PTR [rbp-8], 1
.L2:
        cmp     DWORD PTR [rbp-8], 4
        jle     .L3
        mov     eax, 0
        pop     rbp
        ret
*/