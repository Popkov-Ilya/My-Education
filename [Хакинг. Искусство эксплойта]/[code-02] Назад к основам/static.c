#include <stdio.h>
static int var1 = 1;
int j = 3;
void func1(){
    int i = 6;
    static int var2 = 2;
    printf("[funk] i = %d\tj = %d\tvar1 = %d\tvar2 = %d\n", i, j, var1, var2);
    printf("[funk] i = %08x\tj = %08x\tvar1 = %08x\tvar2 = %08x\n", &i, &j, &var1, &var2);
    var1 = var1 + 1;
    var2 = var2 + 2;
}

int main(){
    int x;
    int i = 5;
    static int var3 = 3;
    for (x=0; x < 5; x++)
    {
    printf("[main] i = %d\tj = %d\tvar1 = %d\tvar3 = %d\n", i, j, var1, var3);
    printf("[main] i = %08x\tj = %08x\tvar1 = %08x\tvar3 = %08x\n", &i, &j, &var1, &var3);
    var1 = var1 + 1;
    var3 = var3 + 3;
    func1();
    }
}